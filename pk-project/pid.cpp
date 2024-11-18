#include "pid.h"

pid::pid(int tempK, int tempTI, int tempTD) : k{tempK}, tI{tempTI}, tD{tempTD}{

}

pid::~pid(){

}

void pid::ustawK(int tempK){
    k = tempK;
}

void pid::ustawTI(int tempTI){
    tI = tempTI;
}

void pid::ustawTD(int tempTD){
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

float pid::symulujKrokPID(float eI){

}
