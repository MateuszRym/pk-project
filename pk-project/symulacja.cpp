#include "symulacja.h"

Symulacja::Symulacja()
    : m_GenWartZad{ SygGen() }
    , m_ARX{ ModelARX() }
    , m_PID{ PID() }
    , m_Uchyb{ SprZwr() }
{}

Symulacja::Symulacja(const SygGen& baseGen, const ModelARX& baseARX, const ModelPID& basePID, const SprZwr& baseUchyb)
    : m_GenWartZad{baseGen}
    , m_ARX{baseARX}
    , m_PID{basePID}
    , m_Uchyb(baseUchyb)
{}
