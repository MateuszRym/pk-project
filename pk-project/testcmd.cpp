#include <iostream>

#include "compile.h"
#include "sygkwad.h"
#include "sygskok.h"
#include "sygsin.h"
#include "symulacja.h"

#ifdef TESTCMD

int main()
{
    // SygKwad sygnal{1.0, 0.5, 4};
    // SygSin sygnal{1.0, 4};
    SygSkok sygnal{1.0, 4};

    ModelPID pid{0.4, 1.2, 0.3};

    ModelARX arx{{-0.4, -0.2}, {0.6, 0.2}};

    return 0;
}

#endif
