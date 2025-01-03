#include "PID.h"

PID::PID()
    : k{}
    , tI{}
    , tD{}
{}

PID::PID(double tempK, double tempTI, double tempTD) : k{tempK}, tI{tempTI}, tD{tempTD}{

}

PID::~PID(){

}

void PID::ustawK(double tempK){
    k = tempK;
}

void PID::ustawTI(double tempTI){
    tI = tempTI;
}

void PID::ustawTD(double tempTD){
    tD = tempTD;
}

void PID::resetujPamiecCalk(){
    pamiecCalk = 0;
}

void PID::resetujPamiecRozn(){
    pamiecRozn = 0;
}

void PID::resetujPamiec(){
    resetujPamiecCalk();
    resetujPamiecRozn();
}

double PID::czescProp(double eI){
    return k * eI;
}

double PID::czescCalk(double eI){
    pamiecCalk += eI;
    return pamiecCalk / tI;
}

double PID::czescRozn(double eI){
    if (pamiecRozn == 0.0){
        pamiecRozn += eI;
        return 0.0;
    }else{
        double temp = tD * (eI - pamiecRozn);
        pamiecRozn = eI;
        return temp;
    }
}

double PID::symulujKrokPID(double eI){
    double p_, i_, d_;
    p_ = czescProp(eI);
    i_ = czescCalk(eI);
    d_ = czescRozn(eI);
    return p_ + i_ + d_;
}
