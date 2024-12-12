#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "zegar.h"
#include "syggen.h"
#include "ModelARX.h"
#include "pid.h"
#include "sprzwr.h"

class Symulacja
{
    const Zegar m_Clk;
    const SygGen& m_GenWartZad;
    const ModelARX& m_ARX;
    const PID& m_PID;
    const SprZwr& m_Uchyb;
public:
    Symulacja(Zegar clk, SygGen& s_gen, ModelARX& arx, PID& pid, SprZwr& s_zwr);
    int getKrokSymulacji() const { return m_Clk.getKrok(); }
};

#endif // SYMULACJA_H
