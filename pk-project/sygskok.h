#ifndef SYGSKOK_H
#define SYGSKOK_H

#include "syggen.h"

class SygSkok : public SygGen
{
    int m_zegar_akt;
public:
    SygSkok(double amp, int akt_clk);
    double sygnal(const Zegar clk);
    void setZegarAkt(int z_akt);
    int getZegarAkt() const { return m_zegar_akt; }
};

#endif // SYGSKOK_H
