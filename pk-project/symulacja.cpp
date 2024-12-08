#include "symulacja.h"

Symulacja::Symulacja(Zegar clk, SygGen& s_gen, ModelARX& arx)
    : m_Clk{ clk }
    , m_GenWartZad{ s_gen }
    , m_ARX{ arx }
{}
