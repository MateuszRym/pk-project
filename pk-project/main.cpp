#include "mainwindow.h"
#include "ModelARX.h"
#include "sygsin.h"
#include "zegar.h"
#include <QApplication>
#include <iostream>

#ifdef MAIN

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#endif
