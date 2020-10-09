#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>


int main(int argc, char *argv[])
{
#ifdef RUN_ON_ARM
    QTextCodec *codec = QTextCodec::codecForName("GBK");//设置成GBK是为了打印的时候能直接转换
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBk"));
    QApplication a(argc, argv,QApplication::GuiServer);
#else
    QApplication a(argc, argv);
#endif
    MainWindow w;
    w.show();

    return a.exec();
}
