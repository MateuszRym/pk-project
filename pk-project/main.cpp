#include <QApplication>
//#include <iostream>

#include "compile.h"
#include "mainwindow.h"
// #include "ModelARX.h"
// #include "sygsin.h"

#ifdef MAIN

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#endif
