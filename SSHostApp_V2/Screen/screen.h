#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>

namespace Ui {
class Screen;
}
class QTimer;
class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = 0);
    ~Screen();
    void startScreen();
private:
    Ui::Screen *ui;
    int m_index;
    QTimer *m_colorTimer;
    void setColor(int num);
private slots:
    void slotTimeOut();
};

#endif // SCREEN_H
