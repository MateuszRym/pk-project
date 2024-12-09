#ifndef SYGKWAD_H
#define SYGKWAD_H

#include "syggen.h"

class SygKwad : public SygGen
{
    double m_wypelnienie;   // wsp. podawania sygnalu w skali jednego okresu
    int m_okres;
public:
    SygKwad(double amp, double wyp, int okr);
    double sygnal(const Zegar clk);
    void setWypeln(double wyp);
    void setOkres(int okr);
    double getWypeln() const { return m_wypelnienie; }
    int getOkres() const { return m_okres; }
};

#endif // SYGKWAD_H
