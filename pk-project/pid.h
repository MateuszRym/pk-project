#ifndef PID_H
#define PID_H

class pid
{
    int k;
    int tI;
    int tD;
    float pamiecCalk;
    float pamiecRozn;
public:
    pid(int tempK, int tempTI, int tempTD);
    ~pid();
    void ustawK(int tempK);
    void ustawTI(int tempTI);
    void ustawTD(int tempTD);
    void resetujPamiecCalk();
    void resetujPamiecRozn();
    void resetujPamiec();
    float symulujKrokPID(float eI);
};

#endif // PID_H
