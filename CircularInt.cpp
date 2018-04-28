#include <iostream>
#include <map>
#include <cmath>
#include <list>
using namespace std;
#include "CircularInt.hpp"

/*
    //Constructor
    CircularInt::CircularInt(int minNum ,int maxNum){
        if(minNum>=maxNum){
            cout << "Error! Right number need to be bigger the the left one"<<endl;
        }
        else{
            this->min=minNum;
            this->max=maxNum;
            this->actual=minNum;
        }
    }
    //Copying constructor
    CircularInt::CircularInt(CircularInt &a){
        min=a.min;
        max=a.max;
        actual=a.actual;
    }
    //Destructor
    CircularInt::~CircularInt(){
        delete &min;
        delete &max;
        delete &actual;
    }
    //returns the minimum number
    int CircularInt::getMin(){
        return this->min;
    }
    //returns the maximum number
    int CircularInt::getMax(){
        return this->max;
    }
    int CircularInt::getActual(){
        return this->actual;
    }

    int CircularInt::getInRange()
    {
        if(this->actual < this->min){
            return this->max - (this->min - this->actual +1);
        }
        else if(this->actual > this->max){
            //return  this->min + (this->actual-this->max +1);
            return this->min + (this->actual%this->max);
        }
        else
            return this->actual;
    }
*/