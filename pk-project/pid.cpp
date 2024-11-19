#include "pid.h"

pid::pid(double tempK, double tempTI, double tempTD) : k{tempK}, tI{tempTI}, tD{tempTD}{

}

pid::~pid(){

}

void pid::ustawK(double tempK){
    k = tempK;
}

void pid::ustawTI(double tempTI){
    tI = tempTI;
}

void pid::ustawTD(double tempTD){
    tD = tempTD;
}

void pid::resetujPamiecCalk(){
    pamiecCalk = 0;
}

void pid::resetujPamiecRozn(){
    pamiecRozn = 0;
}

void pid::resetujPamiec(){
    resetujPamiecCalk();
    resetujPamiecRozn();
}

double pid::czescProp(double eI){
    return k * eI;
}

double pid::czescCalk(double eI){
    pamiecCalk += eI;
    return pamiecCalk / tI;
}

double pid::czescRozn(double eI){
    if (pamiecRozn == 0.0){
        pamiecRozn += eI;
        return 0.0;
    }else{
        double temp = tD * (eI - pamiecRozn);
        pamiecRozn = eI;
        return temp;
    }
}

double pid::symulujKrokPID(double eI){
    return czescProp(eI) + czescCalk(eI) + czescRozn(eI);
}
