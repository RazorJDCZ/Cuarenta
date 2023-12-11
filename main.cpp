#include "mainwindow.h"
#include "ventainicio.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentaInicio i;
    i.show();
    //MainWindow w;
    //w.show();
    return a.exec();
}
