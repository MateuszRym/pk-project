#include "mainwindow.h"
#include "ModelARX.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ModelARX test;
    test.symulujKrok(0.0);
    test.wypiszY();
    test.symulujKrok(1.0);
    test.wypiszY();
    test.symulujKrok(1.0);
    test.wypiszY();
    test.symulujKrok(1.0);
    test.wypiszY();
    test.symulujKrok(1.0);
    test.wypiszY();
    test.symulujKrok(1.0);
    test.wypiszY();
    test.symulujKrok(1.0);
    test.wypiszY();

    return a.exec();
}
