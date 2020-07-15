#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QTranslator>
#include "SQLite/mysqlite.h"
#define DEV_ZH  1
#define DEV_EN  2

int main(int argc, char *argv[])
{
#ifdef RUN_ON_ARM
    QTextCodec *codec = QTextCodec::codecForName("GBK");//设置成GBK是为了打印的时候能直接转换
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBk"));
    QApplication a(argc, argv,QApplication::GuiServer);

    QSqlDatabase db = MySQLite::openConnection();
    int type = MySQLite::getLanguageType(db);
    MySQLite::closeConnection(db);

    if (DEV_EN == type){
        QTranslator *translator = new QTranslator;
        QString load = "APP_ZH_US.qm";
        translator->load(load);
        a.installTranslator(translator);
    }
#else
    QApplication a(argc, argv);
    if (DEV_EN == type){
        QTranslator *translator = new QTranslator;
        QString load = "APP_ZH_US.qm";
        translator->load(load);
        a.installTranslator(translator);
    }
#endif
    MainWindow w;
    w.show();

    return a.exec();
}
