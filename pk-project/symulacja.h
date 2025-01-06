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
    ModelPID m_PID;
    SprZwr m_Uchyb;
public:
    Symulacja();
    Symulacja(const SygGen& baseGen, const ModelARX& baseARX, const ModelPID& basePID, const SprZwr& baseUchyb);

    SygGen& GenSygn() { return m_GenWartZad; }
    ModelARX& ARX() { return m_ARX; }
    ModelPID& PID() { return m_PID; }
    SprZwr& Uchyb() { return m_Uchyb; }
};

#endif // SYMULACJA_H
