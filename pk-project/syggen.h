#ifndef SYGGEN_H
#define SYGGEN_H

class SygGen
{
    int m_krok;
    double m_sygn;

// protected:
//     void setSygn(double sygnal) { m_sygn = sygnal; }

public:
    SygGen();
    void setSygn(double sygnal) { m_sygn = sygnal; }
    //virtual double sygnal();
    double sygnalSkok(double amp, int krok_aktyw);
    double sygnalKwad(double amp, int okr, double wyp);
    double sygnalSin(double amp, int okr);
    //double getAmp() const { return m_amp; }
    int getKrok() const { return m_krok; }
    double getSygn() const { return m_sygn; }
    void krokDalej() { ++m_krok; }
};

#endif // SYGGEN_H
