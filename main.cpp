#include <mainwindow.h>
#include <framregister.h>
#include <QTextCodec>
#include <QApplication>
#include <iostream>
using namespace std;

class CommonHelper
{
public:
    static void setStyle(const QString &style) {
        qDebug()<<"hello";
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CommonHelper::setStyle(":/new/oop_project/ui.qss");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));//solve the encoding problem
    MainWindow s;
    s.show();
    return a.exec();

}

