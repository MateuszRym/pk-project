#ifndef PID_H
#define PID_H

class pid
{
    int k;
    int tI;
    int tD;
public:
    pid(int tempK, int tempTI, int tempTD);
};

#endif // PID_H
