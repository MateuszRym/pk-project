#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "syggen.h"
#include "ModelARX.h"
#include "pid.h"
#include "sprzwr.h"

class Symulacja
{
    const SygGen m_GenWartZad;
    const ModelARX m_ARX;
    const PID m_PID;
    const SprZwr m_Uchyb;
public:
    Symulacja();

};

#endif // SYMULACJA_H
