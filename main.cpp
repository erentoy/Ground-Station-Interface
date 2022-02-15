#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon("D:/Projects/Interface/resources/icon2.png"));
    w.show();
    return a.exec();
}
