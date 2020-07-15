#ifndef CONFTIME_H
#define CONFTIME_H

#include <QWidget>

namespace Ui {
class ConfTime;
}
class QButtonGroup;
class QGraphicsDropShadowEffect;
class ConfTime : public QWidget
{
    Q_OBJECT

public:
    explicit ConfTime(QWidget *parent = 0);
    ~ConfTime();

private:
    Ui::ConfTime *ui;
    void initKey();
    QButtonGroup *m_btnKeyGroup;
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
private slots:

    void slotSetSystemTime();
    void slotBtnKey(int index);
};


#endif // CONFTIME_H
