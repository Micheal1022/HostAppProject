#ifndef CONFNODE_H
#define CONFNODE_H

#include <QWidget>

namespace Ui {
class ConfNode;
}
class QButtonGroup;
class QGraphicsDropShadowEffect;
class ConfNode : public QWidget
{
    Q_OBJECT

public:
    explicit ConfNode(QWidget *parent = 0);
    ~ConfNode();
    void setValue(int cmd, int type, int value);

private:
    Ui::ConfNode *ui;
    QButtonGroup *m_tbtnGroup;
    QButtonGroup *m_btnTypeGroup;
    QButtonGroup *m_btnKeyGroup;
    QList<bool> m_btnSelect;
    QString m_selectStr;
    QString m_unSelectStr;
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
private slots:
    void slotBtnTypeIndex(int index);
    void slotTBtnIndex(int index);
    void slotBtnKeyIndex(int index);
};

#endif // CONFNODE_H
