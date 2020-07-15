#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
class IMFrame;
class QLineEdit;
class QSignalMapper;
namespace Ui {
class KeyBoard;
}

class KeyBoard : public QWidget
{
    Q_OBJECT

public:
    explicit KeyBoard(IMFrame* im);
    ~KeyBoard();

private:
    Ui::KeyBoard *ui;
    IMFrame *m_imf;
    QSignalMapper *m_signalMapper;

signals:
    void sigKey(QString key);
    void sigDel();
    void sigClose();

public slots:
    void slotInputText(QString str);

};

#endif // KEYBOARD_H
