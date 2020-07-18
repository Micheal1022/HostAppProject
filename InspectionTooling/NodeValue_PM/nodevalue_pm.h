#ifndef NODEVALUE_PM_H
#define NODEVALUE_PM_H

#include <QLabel>
#include <QWidget>

namespace Ui {
class NodeValue_PM;
}
class QTimer;
class NodeValue_PM : public QWidget
{
    Q_OBJECT

public:
    explicit NodeValue_PM(QWidget *parent = 0);
    ~NodeValue_PM();
    void updateValue(QList <int> valueList);
    void initWidget(int loopNum, int type);
    enum RESULT{
        Unqualified = 0x00,
        Qualified = 0x01
    };
    void cleanValue();
private:

    void confResult(int index, NodeValue_PM::RESULT type);
    void confNodeType(int nodeType);
    void confNodeState(int nodeState);
    void confNodeValue(int pass, int nodeType, int nodeValue1, int nodeValue2, int nodeValue3);

private:
    Ui::NodeValue_PM *ui;
    bool m_testVolFlag_01;
    bool m_testVolFlag_02;
    bool m_testVolFlag_03;
    bool m_testVolFlag_04;
    bool m_testVolFlag_05;
    bool m_testVolFlag_06;
    bool m_testVolFlag_07;
    bool m_testVolFlag_08;
    bool m_testVolFlag_09;
    bool m_testCurFlag_01;
    bool m_testCurFlag_02;
    bool m_testCurFlag_03;
    int m_testVolTimes_01;
    int m_testVolTimes_02;
    int m_testVolTimes_03;
    int m_testVolTimes_04;
    int m_testVolTimes_05;
    int m_testVolTimes_06;
    int m_testVolTimes_07;
    int m_testVolTimes_08;
    int m_testVolTimes_09;
    int m_testCurTimes_01;
    int m_testCurTimes_02;
    int m_testCurTimes_03;
    int m_baseCurValue;
    int m_baseVolValue;
    int m_testTimes;
    int m_curLoopNum;
    QList <QLabel *> m_labelList;

private slots:

    void slotCleanValue();
    void slotUpdateValue(QList <int> valueList);
};

#endif // NODEVALUE_PM_H
