#ifndef MYPRINT_H
#define MYPRINT_H

#include <QObject>
class QSerialPort;
class MyPrint :public QObject
{

public:
    static char m_lf[2];
    static QSerialPort *m_myCom;
    static MyPrint *m_print;
    static void initSerialPort();
    static MyPrint *getInstance();
    static void selfCheckFinished();
    static void printData(QString loop, QString canId, QString pass, QString type, QString state, QString value, QString time, QString addr);
    //static void dataPring(int pass, int canId, int type, int state, int value, QString time, QString addr);
private:

    MyPrint();
   ~MyPrint();


};

#endif // MYPRINT_H
