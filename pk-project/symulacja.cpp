#include "symulacja.h"

Symulacja::Symulacja()
    : m_GenWartZad{ SygGen() }
    , m_ARX{ ModelARX() }
    , m_PID{ PID() }
    , m_Uchyb{ SprZwr() }
{}
