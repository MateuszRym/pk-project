#ifndef SYGGEN_H
#define SYGGEN_H

class SygGen
{
    double m_amp;
    int m_krok;
    double m_sygn;

protected:
    void setSygn(double sygnal) { m_sygn = sygnal; }

public:
    SygGen(double amp = 1.0);
    virtual double sygnal();
    double getAmp() const { return m_amp; }
    int getKrok() const { return m_krok; }
    double getSygn() const { return m_sygn; }
    void krokDalej() { ++m_krok; }
};

#endif // SYGGEN_H
