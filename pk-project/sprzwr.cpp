#include "sprzwr.h"

SprZwr::SprZwr()
    : m_poprz_y{ 0.0 }
{}

SprZwr::SprZwr(double y)
    : m_poprz_y{ y }
{}

double SprZwr::liczUchyb(SygGen wejscie)
{
    return (wejscie.sygnal() - getPoprzY());
}

void SprZwr::setPoprzY(double y)
{
    m_poprz_y = y;
}

void SprZwr::reset()
{
    setPoprzY(0.0);
}
