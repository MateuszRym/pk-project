#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "syggen.h"
#include "ModelARX.h"
#include "pid.h"
#include "sprzwr.h"

class Symulacja
{
    SygGen m_GenWartZad;
    ModelARX m_ARX;
    PID m_PID;
    SprZwr m_Uchyb;
public:
    Symulacja();

    SygGen& GenSygn() { return m_GenWartZad; }
    ModelARX& ARX() { return m_ARX; }
    PID& PID() { return m_PID; }
    SprZwr& Uchyb() { return m_Uchyb; }
};

#endif // SYMULACJA_H
