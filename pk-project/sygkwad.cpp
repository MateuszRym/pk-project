#include "sygkwad.h"

#include <Qexception>

SygKwad::SygKwad(double amp, double wyp, int okr)
    : SygGen{ amp }
    , m_wypelnienie{ wyp }
    , m_okres{ okr }
{}

double SygKwad::sygnal(const Zegar clk)
{
    if ((clk.getKrok() % getOkres()) < (getWypeln() * getOkres()))
        return getAmp();
    else
        return 0.0;
}

void SygKwad::setWypeln(double wyp)
{
    if (0.0 <= wyp && wyp <= 1.0)
        m_wypelnienie = wyp;
    else
        throw std::out_of_range("Wypelnienie poza zakresem");
}

void SygKwad::setOkres(int okr)
{
    if (okr > 0)
        m_okres = okr;
    else
        throw std::out_of_range("Ujemny okres!");
}