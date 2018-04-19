#include <iostream>
#include <map>
#include <cmath>
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
            this->actual=minNum;
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
    //- subtract an int from the object
    friend int operator-(CircularInt a, int num){//NEED TO FIX, DOESNT WORK PROPERLY
        if((a.actual-num)>0){
            a.actual = a.actual-num;
        }
        else{//formula
            int abso = abs(a.actual-num);
            a.actual = a.max-(abso%a.min);
        }
        return a.actual;
    }

    //- subtract an object from the object
    //friend int operator-(CircularInt a, CircularInt b){}
    
    //*
    friend int operator*(CircularInt& a, int b){//TESTING DOESNT WORK
        int ans = a.actual*b;
        if(ans > a.max){
            a.actual = a.min+(ans%a.max);
        }
        else{
            a.actual=ans;
        }
        return a.actual;
    }
    // /
    //+=
    friend int operator+=(CircularInt& a, int num){//DONE
        int ans = a.actual+num;
        if(ans > a.max){
            a.actual=a.min+(ans%a.max);
        }
        else{
            a.actual=ans;
        }
        return a.actual;
    }

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
    friend int operator--(CircularInt& a, int i){//DONE
        if(a.actual==a.min){
            a.actual=a.max;
            return a.actual;
        }
        else{
            a.actual--;
            return a.actual;
        }
    }
    //++
    friend int operator++(CircularInt& a, int i){
        a.actual = (a.actual+1)%a.max;
        return a.actual;
    }
    //*=
    ///=
    friend int operator/=(CircularInt& a, int num){
        if(num == 0)
            return 0;
        int ans = (int)(a.actual/num);
        a.actual = ans;
        if(ans > a.max)
            a.actual = ans%a.max;
        else if(ans == a.max)
            a.actual = a.max;
        else if(ans <= a.min)
            a.actual = a.min; 
        return a.actual;  
    }
    //!=
    friend bool operator!=(CircularInt a, CircularInt b){//DONE
        if(a==b){
            return false;
        }
        else{
            return true;
        }
    }
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
    bool operator>(CircularInt& a){
        double a_d = (double)(a.actual/(a.max-a.min));
        double b_d = (double)(this->actual/(this->max-this->min));
        // if(a_d>b_d)
            return true;
        return false;
    }
    //< We compare two actuals as the "part they take" compared to their "whole"(=the bound)
    bool operator<(CircularInt& a){
        double a_d = (double)(a.actual/(a.max-a.min));//
        double b_d = (double)(this->actual/(this->max-this->min));
        if(a_d<b_d)
            return true;
        return false;
    }

};