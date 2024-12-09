#include "ModelARX.h"
#include <numeric>
#include <iostream>
#include <algorithm>
#include <QException>

ModelARX::ModelARX()
    : m_u_buffer{}
    , m_u_delay{}
    , m_y_buffer{}
    , m_a{}
    , m_b{}
    , m_k_opozn{ 1 }
    , m_zakl{ 0.0 }
{}

ModelARX::ModelARX(std::vector<double> wsp_a, std::vector<double> wsp_b, int k, double z)
    : m_u_buffer{}
    , m_u_delay{}
    , m_y_buffer{}
    , m_a{ wsp_a }
    , m_b{ wsp_b }
    , m_zakl{ z }
{
    setOpozn(k);
}

void ModelARX::addA(const double a)
{
    m_a.push_back(a);
}

void ModelARX::removeA(int index)
{
    if (index < m_a.size())
        m_a.erase(m_a.begin() + index);
    else
        throw std::out_of_range("Invalid index!");
}

void ModelARX::clearA()
{
    m_a.clear();
}

void ModelARX::addB(const double b)
{
    m_b.push_back(b);
}

void ModelARX::removeB(int index)
{
    if (index < m_b.size())
        m_b.erase(m_b.begin() + index);
    else
        throw std::out_of_range("Invalid index!");
}

void ModelARX::clearB()
{
    m_b.clear();
}

void ModelARX::setOpozn(int k)
{
    if (k >= 1)
        m_k_opozn = k;
    else
        throw std::out_of_range("K musi wynosić min. 1!");
}

double ModelARX::symuluj(const Zegar clk, const double sygn_wej)
{
    if (getOpozn() <= clk.getKrok())
    {
        m_u_buffer.push_front(m_u_delay.front());
        m_u_delay.pop_front();
    }

    if (m_u_buffer.size() > m_b.size()) m_u_buffer.pop_back();

    m_u_delay.push_back(sygn_wej);

    double splot_u_b = std::inner_product(m_u_buffer.begin(), m_u_buffer.end(), m_b.begin(), 0.0);
    double splot_y_a = std::inner_product(m_y_buffer.begin(), m_y_buffer.end(), m_a.begin(), 0.0);
    double y = splot_u_b - splot_y_a;

    m_y_buffer.push_front(y);
    if(m_y_buffer.size() > m_a.size()) m_y_buffer.pop_back();

    return y;
}

void ModelARX::wypiszY()    // sprawdzenie
{
    std::deque<double> kopia_y = m_y_buffer;
    while(!kopia_y.empty())
    {
        std::cout << kopia_y.front() << '\t';
        kopia_y.pop_front();
    }
    std::cout << '\n';
}
