

#include "Imframe.h"
#include "KeyBoard/keyboard.h"
#include <QWSInputMethod>
IMFrame * IMFrame::m_imf = NULL;

IMFrame::IMFrame()
{
    m_keyBoard = new KeyBoard(this);
    connect(m_keyBoard,SIGNAL(sigDel()),this,SLOT(slotBtnDel()));
    connect(m_keyBoard,SIGNAL(sigClose()),this,SLOT(slotBtnClose()));
    m_xPos = 232;
    m_yPos = 250;
}

IMFrame::~IMFrame()
{
    delete m_keyBoard;
    delete m_currentWgt;
    delete m_wgt;
    deleteimframe();
}

IMFrame* IMFrame::getIMFrame()
{
    if(m_imf==NULL)
        m_imf = new IMFrame();
    return m_imf;
}

void IMFrame::deleteimframe()
{
    if(m_imf!=NULL)
    {
        delete m_imf;
        m_imf=NULL;
    }
}

void IMFrame::slotBtnClose()
{
    m_keyBoard->hide();
}

void IMFrame::slotBtnDel()
{
    QWSServer::sendKeyEvent(0x01000003,Qt::Key_Backspace,Qt::NoModifier,true,false);
}

void IMFrame::sendContent(const QString& newcontent)
{
    m_content += newcontent;
    sendPreeditString(m_content,0);
    confirmContent();
}

void IMFrame::getCurrentWgt()
{
    m_currentWgt = QApplication::activeWindow();
    if(m_currentWgt)
    {
        m_wgt = m_currentWgt->focusWidget();
        if(m_wgt)
        {
            QString objName = m_wgt->objectName();
            if("lineEditPwd" == objName || "lineEditAcd" == objName)
            {
                m_xPos = 232;
                m_yPos = 250;
            }
            m_wgt = NULL;
        }
    }
}

void IMFrame::confirmContent()
{
    sendCommitString(m_content);
    m_content.clear();
}

void IMFrame::updateHandler(int type)
{
    switch(type)
    {
    case QWSInputMethod::FocusOut:
        m_content.clear();
        m_keyBoard->hide();
        break;
    case QWSInputMethod::FocusIn:
        m_content.clear();
        //获取到当前聚焦控件的位置
        getCurrentWgt();
        m_keyBoard->setGeometry(m_xPos,m_yPos,m_keyBoard->width(),m_keyBoard->height());
        m_keyBoard->show();
        m_currentWgt = NULL;
        break;
    default:
        break;
    }
}

