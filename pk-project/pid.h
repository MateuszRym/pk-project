#ifndef ModelPID_H
#define ModelPID_H

class ModelPID
{
    double k;
    double tI;
    double tD;
    double pamiecCalk;
    double pamiecRozn;
public:
    ModelPID();
    ModelPID(double tempK, double tempTI, double tempTD);
    ~ModelPID();
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

#endif // ModelPID_H
