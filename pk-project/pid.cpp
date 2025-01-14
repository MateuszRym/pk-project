#include "PID.h"

ModelPID::ModelPID()
    : k{}
    , tI{}
    , tD{}
{}

ModelPID::ModelPID(double tempK, double tempTI, double tempTD) : k{tempK}, tI{tempTI}, tD{tempTD}{

}

ModelPID::~ModelPID(){

}

void ModelPID::ustawK(double tempK){
    k = tempK;
}

void ModelPID::ustawTI(double tempTI){
    tI = tempTI;
}

void ModelPID::ustawTD(double tempTD){
    tD = tempTD;
}

void ModelPID::resetujPamiecCalk(){
    pamiecCalk = 0;
}

void ModelPID::resetujPamiecRozn(){
    pamiecRozn = 0;
}

void ModelPID::resetujPamiec(){
    resetujPamiecCalk();
    resetujPamiecRozn();
}

double ModelPID::czescProp(double eI){
    return k * eI;
}

double ModelPID::czescCalk(double eI){
    if (tI != 0) {
        pamiecCalk += eI;
        return pamiecCalk / tI;
    }
    else
        return 0.0;
}

double ModelPID::czescRozn(double eI){
    double temp = tD * (eI - pamiecRozn);
    pamiecRozn = eI;
    return temp;
}

double ModelPID::symulujKrokPID(double eI){
    double p_, i_, d_;
    p_ = czescProp(eI);
    i_ = czescCalk(eI);
    d_ = czescRozn(eI);
    return p_ + i_ + d_;
}
