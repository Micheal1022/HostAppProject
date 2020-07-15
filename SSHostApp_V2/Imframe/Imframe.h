#ifndef IMFRAME_H
#define IMFRAME_H

#include <QRect>
#include <QDebug>
#include <QPoint>
#include <QWidget>
#include <QLineEdit>
#include <QWSInputMethod>


class KeyBoard;
class IMFrame:public QWSInputMethod
{
    Q_OBJECT
public:
    ~IMFrame();
    void updateHandler(int);
    void getCurrentWgt();
    static IMFrame * getIMFrame();
    static void deleteimframe();

protected:
    static IMFrame * m_imf;

public slots:
    void sendContent(const QString&);
    void slotBtnClose();
    void slotBtnDel();

private:
    IMFrame();
    void confirmContent();

    int m_xPos,m_yPos;
    QWidget *m_wgt;
    KeyBoard *m_keyBoard;
    QString m_content;
    QWidget *m_currentWgt;
};

#endif // IMFRAME_H
