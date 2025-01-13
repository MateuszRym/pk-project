#include "symulacja.h"

Symulacja::Symulacja()
    // : m_sygnal{nullptr}
    : m_pid{}
    , m_arx{}
    , m_uchyb{}
{}

Symulacja::Symulacja(//SygGen& sygn,
                     double pid_k, double pid_ti, double pid_td,
                     std::vector<double> arx_a, std::vector<double> arx_b, int arx_k, bool arx_z)
    // : m_sygnal{ &sygn }
    : m_pid{ pid_k, pid_ti, pid_td }
    , m_arx{ arx_a, arx_b, arx_k, arx_z }
    , m_uchyb{}
{}

// void Symulacja::setSygnal(SygGen& sygn) {
//     m_sygnal = &sygn;
// }

double Symulacja::symulujKrok(SygGen& sygn) {
    double wynik = m_arx.symuluj(m_pid.symulujKrokPID(m_uchyb.liczUchyb(sygn)));
    m_uchyb.setPoprzY(wynik);

    return wynik;
}
