#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "syggen.h"
#include "pid.h"
#include "ModelARX.h"
#include "sprzwr.h"

class Symulacja
{
    SygGen* m_sygnal;
    ModelPID m_pid;
    ModelARX m_arx;
    SprZwr m_uchyb;
public:
    Symulacja();
    Symulacja(
        SygGen& sygn,
        double pid_k, double pid_ti, double pid_td,
        std::vector<double> arx_a, std::vector<double> arx_b, int arx_k, bool arx_z);

    void setSygnal(SygGen& sygn);
    double symulujKrok();
};

#endif // SYMULACJA_H
