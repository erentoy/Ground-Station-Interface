#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon("D:/Projects/Interface/resources/dik.png"));
    w.setWindowFlags(Qt::Window |Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
    w.setWindowState(Qt::WindowMaximized);
    w.show/*FullScreen*/();
    return a.exec();
}
