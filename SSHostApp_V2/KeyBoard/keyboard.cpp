#include "keyboard.h"
#include "ui_keyboard.h"
#include <QLineEdit>
#include <QSignalMapper>
#include "Imframe/Imframe.h"
KeyBoard::KeyBoard(IMFrame *im) :
    QWidget(NULL),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool| Qt::WindowStaysOnTopHint| Qt::FramelessWindowHint|Qt::Dialog);
    m_imf = im;
    //this->setWindowOpacity(0.5);//设置透明度

    m_signalMapper= new QSignalMapper(this);
    connect(ui->pBtn_1,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_2,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_3,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_4,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_5,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_6,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_7,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_8,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_9,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_10, SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_del,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_gb,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_a,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_b,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_c,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_d,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_e,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_f,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_g,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_h,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_i,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_j,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_k,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_l,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_m,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_n,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_o,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_p,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_q,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_r,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_s,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_t,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_u,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_v,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_w,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_x,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_y,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pBtn_z,SIGNAL(clicked()),m_signalMapper,SLOT(map()));

    m_signalMapper->setMapping(ui->pBtn_1, ui->pBtn_1->text());
    m_signalMapper->setMapping(ui->pBtn_2, ui->pBtn_2->text());
    m_signalMapper->setMapping(ui->pBtn_3, ui->pBtn_3->text());
    m_signalMapper->setMapping(ui->pBtn_4, ui->pBtn_4->text());
    m_signalMapper->setMapping(ui->pBtn_5, ui->pBtn_5->text());
    m_signalMapper->setMapping(ui->pBtn_6, ui->pBtn_6->text());
    m_signalMapper->setMapping(ui->pBtn_7, ui->pBtn_7->text());
    m_signalMapper->setMapping(ui->pBtn_8, ui->pBtn_8->text());
    m_signalMapper->setMapping(ui->pBtn_9, ui->pBtn_9->text());
    m_signalMapper->setMapping(ui->pBtn_10,ui->pBtn_10->text());
    m_signalMapper->setMapping(ui->pBtn_del,ui->pBtn_del->text());
    m_signalMapper->setMapping(ui->pBtn_gb,ui->pBtn_gb->text());
    m_signalMapper->setMapping(ui->pBtn_a,ui->pBtn_a->text());
    m_signalMapper->setMapping(ui->pBtn_b,ui->pBtn_b->text());
    m_signalMapper->setMapping(ui->pBtn_c,ui->pBtn_c->text());
    m_signalMapper->setMapping(ui->pBtn_d,ui->pBtn_d->text());
    m_signalMapper->setMapping(ui->pBtn_e,ui->pBtn_e->text());
    m_signalMapper->setMapping(ui->pBtn_f,ui->pBtn_f->text());
    m_signalMapper->setMapping(ui->pBtn_g,ui->pBtn_g->text());
    m_signalMapper->setMapping(ui->pBtn_h,ui->pBtn_h->text());
    m_signalMapper->setMapping(ui->pBtn_i,ui->pBtn_i->text());
    m_signalMapper->setMapping(ui->pBtn_j,ui->pBtn_j->text());
    m_signalMapper->setMapping(ui->pBtn_k,ui->pBtn_k->text());
    m_signalMapper->setMapping(ui->pBtn_l,ui->pBtn_l->text());
    m_signalMapper->setMapping(ui->pBtn_m,ui->pBtn_m->text());
    m_signalMapper->setMapping(ui->pBtn_n,ui->pBtn_n->text());
    m_signalMapper->setMapping(ui->pBtn_o,ui->pBtn_o->text());
    m_signalMapper->setMapping(ui->pBtn_p,ui->pBtn_p->text());
    m_signalMapper->setMapping(ui->pBtn_q,ui->pBtn_q->text());
    m_signalMapper->setMapping(ui->pBtn_r,ui->pBtn_r->text());
    m_signalMapper->setMapping(ui->pBtn_s,ui->pBtn_s->text());
    m_signalMapper->setMapping(ui->pBtn_t,ui->pBtn_t->text());
    m_signalMapper->setMapping(ui->pBtn_u,ui->pBtn_u->text());
    m_signalMapper->setMapping(ui->pBtn_v,ui->pBtn_v->text());
    m_signalMapper->setMapping(ui->pBtn_w,ui->pBtn_w->text());
    m_signalMapper->setMapping(ui->pBtn_x,ui->pBtn_x->text());
    m_signalMapper->setMapping(ui->pBtn_y,ui->pBtn_y->text());
    m_signalMapper->setMapping(ui->pBtn_z,ui->pBtn_z->text());

    connect(m_signalMapper, SIGNAL(mapped(const QString &)),this,SLOT(slotInputText(QString)));
}

KeyBoard::~KeyBoard()
{
    delete ui;
}

void KeyBoard::slotInputText(QString str)
{
    if(tr("删\n除") == str)
    {
        emit sigDel();
    }
    else if(tr("关闭") == str)
    {
        emit sigClose();
    }
    else
    {
        m_imf->sendContent(str);
    }
}
