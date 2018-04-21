#include <iostream>
#include <map>
#include <cmath>
#include <list>
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
    //Copying constructor
    CircularInt(CircularInt &a){
        min=a.min;
        max=a.max;
        actual=a.actual;
    }
    //Destructor
    ~CircularInt(){
        delete &min;
        delete &max;
        delete &actual;
    }
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

    int getInRange()
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
    //+ add an int to actual size
    friend int operator+(CircularInt a, int num){
        a.actual = a.actual+num;//(std::operator+(a.actual,num))%a.max;
        return a.getInRange();
    }
    //+ object + object JUST A DECLERATION
    //friend int operator+(CircularInt &a,CircularInt &b);

    //- subtract an int from the object
    friend int operator-(CircularInt& a, int num){
        int range = a.max-a.min+1;
        int tmp =(a.actual-a.min-num)%range;
        int ans = (tmp+range)%range+a.min;
        a.actual = ans;
        return a.actual; 
    }
    //- subtract CircularInt from int JUST A DECLERATION
    //friend int operator-(int num, CircularInt& a);

    //- if you want to do -CircularInt JUST A DECLERATION
    //CircularInt operator-();

    //*
    friend int operator*(CircularInt& a, int b){//
        int ans = (a.actual*b)%a.max;
        if(ans > a.min && ans < a.max){
            a.actual=ans;
        }
        else if(ans<a.min){
            a.actual=ans+a.min;
        }
        return a.actual;
    }
    //*=
    friend int operator*=(CircularInt& a, int b){
        int ans = (a.actual*b)%a.max;
        if(ans > a.min && ans < a.max){
            a.actual=ans;
        }
        else if(ans<a.min){
            a.actual=ans+a.min;
        }
        return a.actual;
    }
    //+=
    CircularInt& operator+=(int num){//DONE
        int ans = actual+num;
        if(ans > max){
            actual=min+(ans%max);
        }
        else{
            actual=ans;
        }
        return *this;
    }
    // / Divides then puts in range
    friend int operator/(CircularInt a, int num){
        if(num == 0){
             cerr << "Can't divide by zero" << endl;
             return 0;
        }
        a.actual/=num; 
        a.actual = a.getInRange();
        return a.actual;
    }

    //-= updates this->actual's real value after -num
    friend int operator-=(CircularInt& a, int num){
        int range = a.max-a.min+1;
        int tmp =(a.actual-a.min-num)%range;
        int ans = (tmp+range)%range+a.min;
        a.actual = ans;

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
        a.actual = a.actual+1;
        a.actual = a.getInRange();
        return a.actual;
    }
    ///=
    friend int operator/=(CircularInt& a, int num){
        if(num == 0){
             cerr << "Can't divide by zero" << endl;
             return 0;
        }
        a.actual/=num; 
        a.actual = a.getInRange();
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
    //<< "cout" to obj 
    friend ostream& operator<< (ostream& out, const CircularInt& v) {
        out << v.actual;
        return out;
    }
    //<= uses the < operator and == operator
    friend bool operator<=(CircularInt& a, CircularInt& b){
        if((a < b) || (a == b)){
            return true;
        }
        else{
            return false;
        }
    }
    //>= uses the > operator and == operator
    friend bool operator >=(CircularInt& a, CircularInt& b){
        if((a > b)||(a == b)){
            return true;
        }
        else{
            return false;
        }
    }
    //= 
    CircularInt& operator= (const CircularInt& b){
        this->min = b.min;
        this->max = b.max;
        this->actual = b.actual;
        return *this;
    }
    //= if you want to do CircularInt=int JUST THE DECLERATION
    //CircularInt operator=(const int b);

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