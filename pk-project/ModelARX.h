#ifndef MODELARX_H
#define MODELARX_H

#include <queue>
#include <vector>

class ModelARX
{
public:
    ModelARX();

    void addB(const double b);
    //void removeB(double& b);

    void symulujKrok(const double sygn_wej);
    void wypiszY();

private:
    std::deque<double> m_u_buffer;
    std::deque<double> m_u_delay;
    std::deque<double> m_y_buffer;
    std::vector<double> m_a;
    std::vector<double> m_b;
};

#endif // MODELARX_H
