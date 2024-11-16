#include "mainwindow.h"
#include "ModelARX.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ModelARX test(1.0, -0.2, 0.5, 1);
    std::cerr << "u: " << test.getWejscie() << '\n';
    std::cerr << "a: " << test.getA() << '\n';
    std::cerr << "b: " << test.getB() << '\n';
    std::cerr << "k: " << test.getK() << '\n';

    test.setWejscie(0.7);
    test.setA(0.1);
    test.setB(0.3);
    test.setK(2);
    //test.setK(0);

    std::cerr << "po zmianie:\n";
    std::cerr << "u: " << test.getWejscie() << '\n';
    std::cerr << "a: " << test.getA() << '\n';
    std::cerr << "b: " << test.getB() << '\n';
    std::cerr << "k: " << test.getK() << '\n';

    return a.exec();
}
