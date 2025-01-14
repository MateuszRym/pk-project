// #include "sygsin.h"
// #include <QtMath>
// #include <QException>

// SygSin::SygSin(double amp, int okr)
//     : SygGen{ amp }
//     , m_okres{ okr }
// {}

// double SygSin::sygnal()
// {
//     double wyjscie = (getAmp() * qSin(2 * M_PI * (getKrok() % getOkres())/getOkres() - (M_PI/2)) + 1.0) / 2.0;
//     setSygn(wyjscie);
//     krokDalej();
//     return wyjscie;
// }

// void SygSin::setOkres(int okr)
// {
//     if (okr > 0)
//         m_okres = okr;
//     else
//         throw std::out_of_range("Ujemny okres!");
// }
