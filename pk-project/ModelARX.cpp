#include "ModelARX.h"
#include <Qexception>

ModelARX::ModelARX(double wej, double wsp_a, double wsp_b, int opozn)
    : m_a{wsp_a}
    , m_b{wsp_b}
    , m_k{opozn}
    // , m_u{wej}
{}

// void ModelARX::setWejscie(double u)
// {
//     m_u = u;
// }

void ModelARX::setA(double a)
{
    m_a = a;
}

void ModelARX::setB(double b)
{
    m_b = b;
}

void ModelARX::setK(int k)
{
    if(k >= 1)
        m_k = k;
    else
        throw std::domain_error("k musi byc rowne lub wieksze niz 1!");
}

void ModelARX::symulujKrok(const double sygn_wej)
{
    double u = getB() * sygn_wej;
}
