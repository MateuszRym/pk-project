#include "ModelARX.h"
#include <numeric>
#include <iostream>
#include <algorithm>

ModelARX::ModelARX()
    : m_u_buffer{}
    , m_u_delay{}
    , m_y_buffer{}
    , m_a{-0.4}
    , m_b{0.6}
{
}

void ModelARX::addB(const double b)
{
    m_b.push_back(b);
}

void ModelARX::removeB(const double b)
{
    m_b.erase(std::remove(m_b.begin(), m_b.end(), b), m_b.end());
}

void ModelARX::symulujKrok(const double sygn_wej)
{
    m_u_buffer.push_back(m_u_delay.front());
    m_u_buffer.pop_front();
    m_u_delay.push_back(sygn_wej);
    m_u_delay.pop_front();
    double splot_u_b = std::inner_product(m_u_buffer.begin(), m_u_buffer.end(), m_b.begin(), 0.0);
    double splot_y_a = std::inner_product(m_y_buffer.begin(), m_y_buffer.end(), m_a.begin(), 0.0);
    double y = splot_u_b + splot_y_a;
    m_y_buffer.push_back(y);
    m_y_buffer.pop_front();
}

void ModelARX::wypiszY()    //deque zamiast kopii ?
{
    std::deque<double> kopia_y = m_y_buffer;
    while(!kopia_y.empty())
    {
        std::cout << kopia_y.front() << '\t';
        kopia_y.pop_front();
    }
    std::cout << '\n';
}
