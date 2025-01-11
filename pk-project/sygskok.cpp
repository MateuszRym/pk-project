#include "sygskok.h"
#include <QException>


SygSkok::SygSkok(double amp, int clk_aktyw)
    : SygGen{ amp }
    , m_krok_aktyw{ clk_aktyw }
{}

double SygSkok::sygnal()
{
    if (getKrok() >= m_krok_aktyw) {
        setSygn(getAmp());
        return getAmp();
    }
    else {
        krokDalej();
        setSygn(0.0);
        return 0.0;
    }
}

void SygSkok::setZegarAkt(int z_akt)
{
    if (z_akt >= 0)
        m_krok_aktyw = z_akt;
    else
        throw std::out_of_range("Ujemny krok aktywacji!");
}
