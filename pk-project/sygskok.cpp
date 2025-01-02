#include "sygskok.h"
#include <QException>


SygSkok::SygSkok(double amp, int akt_clk)
    : SygGen{ amp }
    , m_zegar_akt{ akt_clk }
{}

double SygSkok::sygnal()
{
    if (getKrok() >= m_zegar_akt)
        return getAmp();
    else
        return 0.0;
}

void SygSkok::setZegarAkt(int z_akt)
{
    if (z_akt >= 0)
        m_zegar_akt = z_akt;
    else
        throw std::out_of_range("Ujemny krok aktywacji!");
}
