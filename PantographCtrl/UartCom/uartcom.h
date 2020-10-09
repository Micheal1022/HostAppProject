#ifndef UARTCOM_H
#define UARTCOM_H

#include <QObject>

class UartCom : public QObject
{
    Q_OBJECT
public:
    explicit UartCom(QObject *parent = 0);

signals:

public slots:
};

#endif // UARTCOM_H
