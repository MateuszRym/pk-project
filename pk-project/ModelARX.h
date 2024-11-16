#ifndef MODELARX_H
#define MODELARX_H

#include <queue>

class ModelARX
{
public:
    ModelARX(double wej, double wsp_a, double wsp_b, int opozn);

    // const double& getWejscie() const {return m_u;}
    const double& getAktU() const {return m_u_buffer.front();}
    const double& getA() const {return m_a;}
    const double& getB() const {return m_b;}
    const int& getK() const {return m_k;}

    // void setWejscie(double u);
    void setA(double a);
    void setB(double b);
    void setK(int k);

    void symulujKrok(const double sygn_wej);

private:
    std::queue<double> m_u_buffer;
    std::queue<double> m_u_delay;
    std::queue<double> m_y_buffer;
    std::queue<double> m_y_delay;

    // double m_u;
    // double m_y;
    //double z;
    double m_a;
    double m_b;
    int m_k;
};

#endif // MODELARX_H
