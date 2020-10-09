#include "recvfile.h"
#include "ui_recvfile.h"
#include <QBitmap>
#include <QPainter>

RecvFile::RecvFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecvFile)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setModal(true);
    //设置关于窗体为圆角
    QBitmap bmp(size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.drawRoundedRect(bmp.rect(),4,4);
    setMask(bmp);

    startMonitor();
    connect(&m_tcpServer,SIGNAL(newConnection()),this,SLOT(slotAcceptConnection()));
    connect(ui->pBtnClose,SIGNAL(clicked(bool)),this,SLOT(hide()));

}

RecvFile::~RecvFile()
{
    delete ui;
}

void RecvFile::startMonitor()
{
    m_totalBytes = 0;
    m_fileNameSize = 0;
    m_bytesReceived = 0;
    m_tcpServer.listen(QHostAddress::Any,6666);
}



void RecvFile::slotAcceptConnection()
{
    m_tcpServerConnection = m_tcpServer.nextPendingConnection();
    connect(m_tcpServerConnection,SIGNAL(readyRead()),this,SLOT(slotRecvFile()));
    m_tcpServer.close();
}

void RecvFile::slotRecvFile()
{
    show();
    QDataStream in(m_tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);
    if (m_bytesReceived <= sizeof(qint64)*2) {
        if ((m_tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2) && (m_fileNameSize == 0)) {
            in >> m_totalBytes >> m_fileNameSize;
            m_bytesReceived += sizeof(qint64) * 2;
        }
        if ((m_tcpServerConnection->bytesAvailable() >= m_fileNameSize)&& (m_fileNameSize != 0)) {
            in >> m_fileName;
            ui->lbServerStatus->setText(tr("接收文件: %1 ").arg(m_fileName));
            m_bytesReceived += m_fileNameSize;
            m_localFile = new QFile(m_fileName);
            if (!m_localFile->open(QFile::WriteOnly)) {
                startMonitor();
                return;
            }
        } else {
            startMonitor();
            return;
        }
    }
    if (m_bytesReceived < m_totalBytes) {
        m_bytesReceived += m_tcpServerConnection->bytesAvailable();
        m_inBlock = m_tcpServerConnection->readAll();
        m_localFile->write(m_inBlock);
        m_inBlock.resize(0);
    }
    ui->serverProgressBar->setMaximum(m_totalBytes);
    ui->serverProgressBar->setValue(m_bytesReceived);

    if (m_bytesReceived == m_totalBytes) {
        m_tcpServerConnection->close();
        m_localFile->close();
        delete m_localFile;
        ui->lbServerStatus->setText(tr("接收文件: %1 成功").arg(m_fileName));
        startMonitor();
    }
}


void RecvFile::slotDisplayError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError)
    m_tcpServerConnection->close();
    ui->serverProgressBar->reset();
}
