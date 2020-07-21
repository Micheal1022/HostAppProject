#ifndef KEYCHECK_H
#define KEYCHECK_H

#include <QObject>
class QTimer;
class GPIOKeyPin
{
public:
    GPIOKeyPin();
    int m_fdVal;
    void initKeyPin(const char *devValue);
    void readKeyPin(char *buf, const char *devValue);
};

class KeyCheck : public QObject
{
    Q_OBJECT
public:
    explicit KeyCheck(QObject *parent = 0);
    char readKeyState();
private:
    QTimer *m_timer;
    GPIOKeyPin *m_keyCheck;          //复位按钮
signals:
    void sigkeyCheck();
public slots:
    void slotTimeOut();
};

#endif // KEYCHECK_H
