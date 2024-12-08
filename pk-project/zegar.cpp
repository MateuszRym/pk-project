#include "zegar.h"

Zegar::Zegar()
    : m_krok{ 0 }
{}

void Zegar::krokDalej()
{
    m_krok++;
}
