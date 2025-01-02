#include "sygsin.h"
#include <QtMath>
#include <QException>

SygSin::SygSin(double amp, int okr)
    : SygGen{ amp }
    , m_okres{ okr }
{}

double SygSin::sygnal()
{
    return (getAmp() * qSin(2 * M_PI * (getKrok() % getOkres())/getOkres() - (M_PI/2)) + 1.0) / 2.0;
}

void SygSin::setOkres(int okr)
{
    if (okr > 0)
        m_okres = okr;
    else
        throw std::out_of_range("Ujemny okres!");
}
