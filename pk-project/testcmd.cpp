#include <iostream>
#include <iomanip>

#include "compile.h"
#include "sygkwad.h"
#include "sygskok.h"
#include "sygsin.h"
#include "pid.h"
#include "ModelARX.h"
#include "sprzwr.h"
//#include "symulacja.h"

#ifdef TESTCMD

int main()
{
    // SygKwad sygnal{1.0, 0.5, 8};
    // SygSin sygnal{1.0, 8};
    SygSkok sygnal{1.0, 4};

    ModelPID pid{0.5, 10.0, 0.2};

    ModelARX arx{{-0.4, -0.2}, {0.6, 0.2}};

    SprZwr sprz{};

    for (int i = 0; i < 30; i++)
    {
        double uchyb = sprz.liczUchyb(sygnal);
        double regulacja = pid.symulujKrokPID(uchyb);
        double wyjscie = arx.symuluj(regulacja);
        sprz.setPoprzY(wyjscie);

        std::cerr << "=========================================================================================\n"
                  << "i: " << i << "\t||\tX = " << std::setprecision(3) << std::fixed << sygnal.getSygn() << "\tY = " << wyjscie << "\t||\t"
                  << "e = " << uchyb << "\treg = " << regulacja << '\n';
    }

    return 0;
}

#endif
