#include <iostream>
#include "CircularInt.hpp"
using namespace std;

CircularInt::CircularInt(int minNum, int maxNum){
    this->min=minNum;
    this->max=maxNum;
}

CircularInt::~CircularInt(){
    delete this->min;
    delete this->max;
}