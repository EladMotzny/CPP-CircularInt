#include <iostream>
#include <map>
#include <cmath>
#include <list>
#include <cerrno>
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
    // int + Object
    friend int operator+(int num, CircularInt a){
        a.actual = a.actual+num;
                return a.getInRange();
    }
    // Object + Object
    friend int operator+(CircularInt a, CircularInt b){
        a.actual = a.actual+b.actual;
                return a.getInRange();
    }
    //-OBJECT 
    CircularInt operator-(){
        this->actual=this->max-this->actual;
        return *this;
    }

    //object - int
    friend CircularInt operator-(CircularInt& a, int b){
        int range = a.max - a.min +1;
        int tmp = (a.actual - a.min - b)%range;
        int ans = (tmp+range)%range+a.min;
        a.actual=ans;
        return a;
    }
    //CircularInt - CircularInt
    friend int operator-(CircularInt& a, CircularInt& b){
        a-b.actual;
        return a.actual;
    }

    //int-object
    friend CircularInt operator-(int b, CircularInt& a){
        a-b;
        return a;
    }
 
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
    //int * obj
    friend int operator*(int a, CircularInt& b){
        return b*a;
    }

    //obj * obj
    friend int operator*(CircularInt& a, CircularInt& b){
        return a*b.actual;
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
    CircularInt& operator+=(int num){
        int ans = this->actual+num;
        if(ans > max){
            this->actual=this->min+(ans%this->max);
        }
        else{
            this->actual=ans;
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
    // / Int/Object
    friend int operator/(int num, CircularInt a){
        if(num == 0){
             cerr << "Can't divide by zero" << endl;
             return 0;
        }
        a.actual/=num; 
        a.actual = a.getInRange();
        return a.actual;
    }
    // / Object/Object
    friend int operator/(CircularInt a, CircularInt b){
        if(b.actual == 0){
             cerr << "Can't divide by zero" << endl;
             return 0;
        }
        a.actual/=b.actual; 
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
    //-- postfix
    CircularInt operator--(int){
        if(this->actual==this->min){
            this->actual=this->max;
            return *this;
        }
        else{
            this->actual--;
            return *this;
        }
    }

    //-- prefix
    CircularInt operator--(){
        if(this->actual==this->min){
            this->actual=this->max;
            return *this;
        }
        else{
            this->actual--;
            return *this;
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
    // Object == int
    friend bool operator==(CircularInt a,int b){
        return (a.actual == b);
    }
    // int == Object
    friend bool operator==(int b, CircularInt a){
        return (a.actual == b);
    }
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

    //obj<=int
    friend bool operator<=(CircularInt& a, int b){
        if((a.actual<b)||(a.actual==b)){
            return true;
        }
        else{
            return false;
        }
    }
    //int<=obj
    friend bool operator<=(int a,CircularInt& b){
        return b<=a;
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

    //obj>=int
    friend bool operator>=(CircularInt& a,int b){
        if((a.actual>b) || (a.actual==b)){
            return true;
        }
        else{
            return false;
        }
    }

    //int>=obj
    friend bool operator>=(int a,CircularInt& b){
        return b>=a;
    }

    //= 
    CircularInt& operator= (const CircularInt& b){
        this->min = b.min;
        this->max = b.max;
        this->actual = b.actual;
        return *this;
    }
    //Object = int
    CircularInt& operator= (const int a){
        this->actual = a;
        return *this;
    }
    

    //> We compare two actuals as the "part they take" compared to their "whole"(=the bound)
    bool operator>(CircularInt& a){
        double a_d = (double)(a.actual/(a.max-a.min));
        double b_d = (double)(this->actual/(this->max-this->min));
         if(a_d>b_d)
            return true;
        return false;
    }
    //Object > int
    friend bool operator>(CircularInt& a, int b){
        return (a.actual > b);
    }
    //int > Object
    friend bool operator>(int b, CircularInt& a){
        return (b > a.actual);
    }
    //< We compare two actuals as the "part they take" compared to their "whole"(=the bound)
    bool operator<(CircularInt& a){
        double a_d = (double)(a.actual/(a.max-a.min));//
        double b_d = (double)(this->actual/(this->max-this->min));
        if(a_d<b_d)
            return true;
        return false;
    }
    // Object < int
    friend bool operator<(CircularInt& a, int b){
        return (a.actual < b);
    }
    // int < Object 
    friend bool operator<(int b, CircularInt& a){
        return (b < a.actual);
    }
    //>>
    friend istream& operator>> (istream& in, CircularInt& v){
        try{
            in >> v.min >> v.actual >> v.max;
            if(v.min < v.max && (v.actual<=v.max && v.actual>=v.min))
                return in;
        }
        catch(const string& message){
            throw std::invalid_argument("Incorrect values! eneter a minimum then an actual value between the range and then a maximu value!");
        }
    }
    //%
    friend int operator%(CircularInt a, const int x)
    {
        a.actual = a.actual%x;
        return a.getInRange();
    }
    //%=
    friend int operator%=(CircularInt& a, const int x)
    {
        a.actual = a.actual%x;
        a.actual = a.getInRange();
        return a.actual;
    }
    //^ operator xor
    friend int operator^ (CircularInt a,CircularInt b)
    {
        try{
            if(a.actual<=0 && b.actual<=0){
                a.actual = a.actual^b.actual;
                return a.getInRange();
            }
        }
        catch(const string& message){
            throw std::invalid_argument( "Can't be a negative value" );
        }
    }
    
};
