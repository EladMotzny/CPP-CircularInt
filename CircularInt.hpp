#include <iostream>
using namespace std;
#pragma once


class CircularInt{
    int min;
    int max;


    //Constructor
    CircularInt(int minNum ,int maxNum);
    //Destructor
    ~CircularInt();
    //returns the minimum number
    int getMin();
    //returns the maximum number
    int getMax();
    //+
    int operator+(CircularInt a, CircularInt b);
    int operator-(CircularInt a, CircularInt b);    


}