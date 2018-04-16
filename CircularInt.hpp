#include <iostream>
#include <map>
using namespace std;
#pragma once


class CircularInt{
    int min;
    int max;


    //Constructor
    CircularInt(int minNum ,int maxNum){}
    //Destructor
    ~CircularInt(){}
    //returns the minimum number
    int getMin(){}
    //returns the maximum number
    int getMax(){}
    //+
    friend int operator+(CircularInt a, CircularInt b){
        return (a.min + b.min)%a.max;
    }
    //-
    friend int operator-(CircularInt a, CircularInt b){}    
    //*
    // /
    //+=
    int operator+=(const CircularInt& b);
    //-=
    int operator-=(const CircularInt& b);
    //--
    //++
    //*=
    ///=
    //!=
    //==

    //>>
    //<<
    friend ostream& operator<< (ostream& out, const CircularInt& v) {
        out << "{";
        out << v.min << v.max;
        out << "}";
        return out;
    }
    //<=
    //>=
    //=
    //>
    //<


};