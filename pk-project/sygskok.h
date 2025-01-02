#ifndef SYGSKOK_H
#define SYGSKOK_H

#include "syggen.h"

class SygSkok : public SygGen
{
    int m_krok_aktyw;
public:
    SygSkok(double amp, int akt_clk);
    double sygnal() override;
    void setZegarAkt(int z_akt);
    int getZegarAkt() const { return m_krok_aktyw; }
};

#endif // SYGSKOK_H
