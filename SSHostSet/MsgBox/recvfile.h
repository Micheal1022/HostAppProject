#ifndef RECVFILE_H
#define RECVFILE_H

#include <QDialog>
#include <QDebug>
#include <QFile>
#include <QTcpServer>
#include <QTcpSocket>
namespace Ui {
class RecvFile;
}
class RecvFile : public QDialog
{
    Q_OBJECT

public:
    explicit RecvFile(QWidget *parent = 0);
    ~RecvFile();

private:
    Ui::RecvFile *ui;

    QTcpServer m_tcpServer;
    QTcpSocket *m_tcpServerConnection;
    qint64 m_totalBytes;    //存放总大小信息
    qint64 m_bytesReceived; //已收到数据的大小
    qint64 m_fileNameSize;  //文件名的大小信息
    QString m_fileName;     //存放文件名
    QFile *m_localFile;     //本地文件
    QByteArray m_inBlock;   //数据缓冲区

    void startMonitor();    //开始监听
public slots:
    void slotAcceptConnection();//建立连接
    void slotRecvFile();    //更新进度条，接收数据
    void slotDisplayError(QAbstractSocket::SocketError socketError);
};

#endif // RECVFILE_H
