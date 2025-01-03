#ifndef PID_H
#define PID_H

class PID
{
    double k;
    double tI;
    double tD;
    double pamiecCalk;
    double pamiecRozn;
public:
    PID();
    PID(double tempK, double tempTI, double tempTD);
    ~PID();
    void ustawK(double tempK);
    void ustawTI(double tempTI);
    void ustawTD(double tempTD);
    void resetujPamiecCalk();
    void resetujPamiecRozn();
    void resetujPamiec();
    double czescProp(double eI);
    double czescCalk(double eI);
    double czescRozn(double eI);
    double symulujKrokPID(double eI);
};

#endif // PID_H
