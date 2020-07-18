#ifndef NODEVALUE_EF_H
#define NODEVALUE_EF_H

#include <QWidget>

namespace Ui {
class NodeValue_EF;
}
class QTimer;
class QLabel;
class NodeValue_EF : public QWidget
{
    Q_OBJECT

public:
    explicit NodeValue_EF(QWidget *parent = 0);
    ~NodeValue_EF();

    void clearValue();
    void updateValue(QList<int> valueList);
private:
    Ui::NodeValue_EF *ui;
    void initWidget(int loopNum, int type);
    enum RESULT{
        Unqualified = 0x00,
        Qualified = 0x01,
        ToBeTested= 0x02
    };
private:

    void confResult(int index, NodeValue_EF::RESULT type);
    void confNodeType(int nodeType);
    void confNodeState(int nodeState);
    void confNodeValue(int pass, int nodeType, int leakValue, int alarmValue);

private:

    bool m_testLeakFlag_01;
    bool m_testLeakFlag_02;
    bool m_testLeakFlag_03;
    bool m_testLeakFlag_04;
    bool m_testLeakFlag_05;
    bool m_testLeakFlag_06;
    bool m_testLeakFlag_07;
    bool m_testLeakFlag_08;
    bool m_testLeakFlag_09;
    bool m_testLeakFlag_10;
    bool m_testLeakFlag_11;
    bool m_testLeakFlag_12;

    int m_testLeakTimes_01;
    int m_testLeakTimes_02;
    int m_testLeakTimes_03;
    int m_testLeakTimes_04;
    int m_testLeakTimes_05;
    int m_testLeakTimes_06;
    int m_testLeakTimes_07;
    int m_testLeakTimes_08;
    int m_testLeakTimes_09;
    int m_testLeakTimes_10;
    int m_testLeakTimes_11;
    int m_testLeakTimes_12;
    int m_testTempTimes_01;
    int m_testTempTimes_02;
    int m_testTempTimes_03;
    int m_testTempTimes_04;
    int m_baseLeakValue;
    int m_baseAlarmValue;
    int m_baseTempValue;
    int m_testTimes;
    int m_curLoopNum;
    QTimer *m_timer;
    QList <QLabel *> m_labelList;

};

#endif // NODEVALUE_EF_H
