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
    
    int getInRange(){
        if(this->actual<this->min){
            return this->max-((-this->actual)%this->max);
        }
        else if(this->actual > this->max){
            int tmp = (this->actual%this->max);
            if(tmp==0){
                return this->max;
            }
            return tmp;
        }
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
        CircularInt tmp(this->min,this->max);
        tmp.actual=this->max-(this->actual%this->max);
        return tmp;
    }

    //object - int
    friend CircularInt operator-(const CircularInt& a, int b){
        /*a.actual=a.actual-b;
        a.actual=a.getInRange();
        return a;*/
        CircularInt tmp(a.min,a.max);
        tmp.actual=tmp.actual-b;
        tmp.actual=tmp.getInRange();
        return tmp;
    }
    //CircularInt - CircularInt
    CircularInt operator-(const CircularInt& a){
        CircularInt tmp(this->min,this->max);
        tmp.actual=this->actual-a.actual;
        tmp.actual=tmp.getInRange();
        return tmp;
    }

    //int-object
    friend CircularInt operator-(int b,const CircularInt& a){
        CircularInt tmp(a.min,a.max);
        tmp.actual=b-a.actual;
        tmp.actual=tmp.getInRange();
        return tmp;
        
    }
 /*
    // obj * int
    friend int operator*(CircularInt& a, int b){
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
    */

    //int * obj
    friend CircularInt operator*(int a, const CircularInt& b){
        CircularInt tmp(b.min,b.max);
        tmp.actual=b.actual*a;
        tmp.actual=tmp.getInRange();
        return tmp;
    }
    //obj * obj
    friend CircularInt operator*(const CircularInt& a,const CircularInt& b){
        CircularInt tmp(a.min,a.max);
        tmp.actual=a.actual*b.actual;
        tmp.actual=tmp.getInRange();
        return tmp;
    }
    //obj * int
    friend CircularInt operator*(const CircularInt& b, int a){
        CircularInt tmp(b.min,b.max);
        tmp.actual=b.actual*a;
        tmp.actual=tmp.getInRange();
        return tmp;
    }
    //*= obj int
    friend int operator*=(CircularInt& a, int b){
        a.actual*=b;
        a.actual=a.getInRange();
        return a.actual;
    }

    //*= obj obj
    friend int operator*=(CircularInt& a,CircularInt& b){
        a.actual*=b.actual;
        a.actual=a.getInRange();
        return a.actual;
    }

    //+= obj int
    CircularInt& operator+=(int n){
        this->actual=this->actual+n;
        this->actual=this->getInRange();
        return *this;
    }
    //+= obj obj
    CircularInt& operator+=(const CircularInt& a){
        return *this+=a.actual;
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


    //-= obj int
    CircularInt& operator-=(int n){
        this->actual=this->actual-n;
        this->getInRange();
        return *this;
    }
    //-= obj obj
    CircularInt& operator-=(const CircularInt& b){
        this->actual=this->actual-b.actual;
        this->getInRange();
        return *this;
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
    
    // prefix ++ 
	CircularInt operator++(){
		this->actual++;
		this->actual =this->getInRange();
		return 	*this;
	}
	
	// postfix ++ 
	CircularInt operator++(int){
		CircularInt H(*this); // saves the original value
		this->actual++;
		this->actual = this->getInRange();
		return H; // returns the original value	
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
    

    //object!=Object
    friend bool operator!=(CircularInt a, CircularInt b){
        return !(a==b);
    }
    //object!=int
    friend bool operator!=(CircularInt a, int b){
        return (a.actual!=b);
    }
    //int!=object
    friend bool operator!=(int a, CircularInt b){
        return (b.actual!=a);
    }
    //==
    friend bool operator==(CircularInt a, CircularInt b){
        return ((a.min == b.min) && (a.max == b.max) && (a.actual == b.actual));
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
    //<= obj<=obj
    friend bool operator<=(CircularInt& a, CircularInt& b){
        return a.actual<=b.actual;
    }

    //obj<=int
    friend bool operator<=(CircularInt& a, int b){
        return a.actual<=b;
    }
    //int<=obj
    friend bool operator<=(int a,CircularInt& b){
        return b.actual<=a;
    }

    //>= obj>=obj
    friend bool operator >=(CircularInt& a, CircularInt& b){
        return a.actual>=b.actual;
    }

    //obj>=int
    friend bool operator>=(CircularInt& a,int b){
        return a.actual>=b;
    }

    //int>=obj
    friend bool operator>=(int a,CircularInt& b){
        return a>=b.actual;
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
        return (this->actual > a.actual);
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
        return (this->actual < a.actual);
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
    //////////////////////////////////
    // istream& operator>> (istream& is, CircularInt &a){
	// 	is >> a.actual >> a.min >> a.max;
	// 	return is;
	// }
	
	int& operator>>(int& n){
		n = this->actual;
		return n;
	}
	
	friend CircularInt& operator>>(int n,CircularInt& a){
		a.actual=n;
		a.actual=a.getInRange();
		return a;
	}
	/*
	string& operator>>(string& n){
		string str=to_string(this->actual);
		n=str;
		return n;
	}
	float& operator>>(float& n){
		n=(float)this->actual;
		return n;
	}
	double& operator>>(double& n){
		n=(double)this->actual;
		return n;
}
*/
    /////////////////////////////////////
    //% Object%Object
    CircularInt operator%(const CircularInt &a){
    	CircularInt tmp(this->min,this->max);
    	tmp.actual=this->actual%a.actual;
    	tmp.actual=tmp.getInRange();
    	return tmp;
    }
    // int%Object
    friend CircularInt operator%(int a,const CircularInt &b){
    	CircularInt tmp(b.min,b.max);
    	tmp.actual= a % b.actual;
    	tmp.actual=tmp.getInRange();
    	return tmp;
    }
    //Object%int
    friend CircularInt operator%(const int a, CircularInt &b)
    {
        // a.actual = a.actual%x;
        // return a.getInRange();
        CircularInt tmp(b.min,b.max);
    	tmp.actual= a % b.actual;
    	tmp.actual=tmp.getInRange();
    	return tmp;
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


