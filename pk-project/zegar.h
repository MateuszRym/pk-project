#ifndef ZEGAR_H
#define ZEGAR_H

class Zegar
{
    int m_krok;
public:
    Zegar();
    void krokDalej();
    int getKrok() const { return m_krok; }
};

#endif // ZEGAR_H
