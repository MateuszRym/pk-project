#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "zegar.h"
#include "syggen.h"
#include "ModelARX.h"

class Symulacja
{
    const Zegar m_Clk;
    const SygGen& m_GenWartZad;
    const ModelARX& m_ARX;
public:
    Symulacja(Zegar clk, SygGen& s_gen, ModelARX& arx);
};

#endif // SYMULACJA_H
