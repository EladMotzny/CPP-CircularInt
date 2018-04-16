#include <iostream>
#include <map>
using namespace std;
#pragma once


class CircularInt{
    int min;
    int max;
    int actual;


    //Constructor
    CircularInt(int minNum ,int maxNum){
        if(minNum>=maxNum){
            cout << "Error! Right number need to be bigger the the left one"<<endl;
        }
        else{
            this->min=minNum;
            this->max=maxNum;
            this->actual=minNum;//this is for the test commit
        }
    }
    //Destructor
    ~CircularInt(){}
    //returns the minimum number
    int getMin(){
        return this->min;
    }
    //returns the maximum number
    int getMax(){
        return this->max;
    }
    int getActual(){
        return this->actual;
    }
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