#ifndef SPRZWR_H
#define SPRZWR_H

#include "syggen.h"

class SprZwr
{
    double m_poprz_y;

public:
    SprZwr();
    SprZwr(double y);
    double liczUchyb(const Zegar clk, const SygGen wejscie);
    void setPoprzY(double y);
    double getPoprzY() const { return m_poprz_y; }
    void reset();
};

#endif // SPRZWR_H