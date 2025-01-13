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

void Symulacja::setPID_k(double k) {
    m_pid.ustawK(k);
}

void Symulacja::setPID_tI(double tI) {
    m_pid.ustawTI(tI);
}

void Symulacja::setPID_tD(double tD) {
    m_pid.ustawTD(tD);
}

void Symulacja::resetPID_I() {
    m_pid.resetujPamiecCalk();
}

void Symulacja::resetPID_D() {
    m_pid.resetujPamiecRozn();
}

double Symulacja::getPID_output() {
    return m_pid.symulujKrokPID(m_uchyb.getUchyb());
}

double Symulacja::getPID_P() {
    return m_pid.czescProp(m_uchyb.getUchyb());
}

double Symulacja::getPID_I() {
    return m_pid.czescCalk(m_uchyb.getUchyb());
}

double Symulacja::getPID_D() {
    return m_pid.czescRozn(m_uchyb.getUchyb());
}

void Symulacja::addARX_a(double single_a) {
    m_arx.addA(single_a);
}

void Symulacja::addARX_b(double single_b) {
    m_arx.addB(single_b);
}

// void Symulacja::delARX_a(double index_a) {
//     // m_arx.removeA(index_a);
// }

// void Symulacja::delARX_b(double single_b) {
//     // m_arx.removeB(single_b);
// }

void Symulacja::clearARX_a() {
    m_arx.clearA();
}

void Symulacja::clearARX_b() {
    m_arx.clearB();
}

void Symulacja::setARX_k(int k) {
    m_arx.setOpozn(k);
}

void Symulacja::setARX_z(bool z) {
    m_arx.setZakl(z);
}

double Symulacja::getUchyb() {
    return m_uchyb.getUchyb();
}

