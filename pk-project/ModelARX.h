#ifndef MODELARX_H
#define MODELARX_H

#include "zegar.h"
#include <queue>
#include <vector>

class ModelARX
{
    std::deque<double> m_u_buffer;
    std::deque<double> m_u_delay;
    std::deque<double> m_y_buffer;
    std::vector<double> m_a;
    std::vector<double> m_b;
    int m_k_opozn;
    bool m_zakl_rng;

public:
    ModelARX();
    ModelARX(std::vector<double> wsp_a, std::vector<double> wsp_b, int k = 1, bool z = true);
    void addA(const double a);
    void removeA(int index);
    void clearA();
    void addB(const double b);
    void removeB(int index);
    void clearB();
    void setOpozn(int k);
    int getOpozn() const { return m_k_opozn; }
    bool getCzyZakl() const { return m_zakl_rng; }

    double symuluj(const Zegar clk, const double sygn_wej);
};

#endif // MODELARX_H
