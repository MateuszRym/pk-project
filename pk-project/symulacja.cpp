#include "symulacja.h"

Symulacja::Symulacja(Zegar clk, SygGen& s_gen, ModelARX& arx, PID& pid, SprZwr& s_zwr)
    : m_Clk{ clk }
    , m_GenWartZad{ s_gen }
    , m_ARX{ arx }
    , m_PID{ pid }
    , m_Uchyb{ s_zwr }
{}
