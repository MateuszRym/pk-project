#ifndef SYGGEN_H
#define SYGGEN_H

#include "zegar.h"

class SygGen
{
    double m_amp;
public:
    SygGen(double amp);
    // virtual double sygnal(const Zegar clk);
    double sygnal(const Zegar clk);
    double getAmp() const { return m_amp; }
};

#endif // SYGGEN_H
