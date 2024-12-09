#ifndef SYGSIN_H
#define SYGSIN_H

#include "syggen.h"

class SygSin : public SygGen
{
    int m_okres;
public:
    SygSin(double amp, int okr);
    double sygnal(const Zegar clk);
    void setOkres(int okr);
    int getOkres() const { return m_okres; }
};

#endif // SYGSIN_H
