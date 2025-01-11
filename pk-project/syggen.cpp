#include "syggen.h"

SygGen::SygGen(double amp)
    : m_amp{ amp }
    , m_krok{ 0 }
    , m_sygn{ 0.0 }
{}

double SygGen::sygnal() {
    setSygn(m_amp);
    return m_amp;
}
