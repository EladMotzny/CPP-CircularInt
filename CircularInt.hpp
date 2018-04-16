#include <iostream>
#include <map>
using namespace std;
#pragma once


 class CircularInt{
    public:
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
    //+ add an int to actual size
    friend int operator+(CircularInt& a, int num){
        a.actual = (a.actual+num)%a.max;//(std::operator+(a.actual,num))%a.max;
        return a.actual;
    }
    //-
    friend int operator-(CircularInt a, CircularInt b){}    
    //*
    // /
    //+=
    int operator+=(const CircularInt& b){}

    //-= updates this->actual's real value after -num
    friend int operator-=(CircularInt& a, int num){
        int ans = a.actual-num;
        if(ans > a.max)
            a.actual = ans%a.max;
        if(ans == a.max)
            a.actual = a.max;
        if(ans <= a.min)
            a.actual = a.min;

        return a.actual; 
    }
    //--
    //++
    friend int operator++(CircularInt& a, int i){
        a.actual = (a.actual+1)%a.max;
        return a.actual;
    }
    //*=
    ///=
    //!=
    //==
    friend bool operator==(CircularInt a, CircularInt b){
        if(a.min == b.min && a.max == b.max && a.actual == b.actual)
            return true;
        return false;
    }
    //>>
    //<<
    friend ostream& operator<< (ostream& out, const CircularInt& v) {
        out << v.actual;
        return out;
    }
    //<=
    //>=
    //=
    //> We compare two actuals as the "part they take" compared to their "whole"(=the bound)
    friend bool operator>(CircularInt& a, CircularInt& b){
        double a_d = a.actual/(a.max-a.min);
        double b_d = b.actual/(b.max-b.min);
        if(a_d>b_d)
            return true;
        return false;
    }
    //< We compare two actuals as the "part they take" compared to their "whole"(=the bound)
    friend bool operator<(CircularInt& a, CircularInt& b){
        double a_d = a.actual/(a.max-a.min);
        double b_d = b.actual/(b.max-b.min);
        if(a_d<b_d)
            return true;
        return false;
    }

};