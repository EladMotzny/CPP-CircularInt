#include <iostream>
using namespace std;

#include "CircularInt.hpp"


int main() {
	//CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
	CircularInt hour (1, 12);
	CircularInt tmp (3, 15);
	CircularInt tmp2 (1, 12);
	CircularInt tmp3 (7, 54);
	CircularInt tmp4 (8, 54);
	CircularInt tmp5 (1,14);
	CircularInt tmp6 (3,10);
	CircularInt tmp7 (5,14);
	cout << (tmp7*=3) << endl;// should be 11
	cout << tmp6-3 << endl;
	cout << (hour <= tmp2) << endl;//should be 1 because they are equal
	cout << (hour <= tmp4) << endl;//should be 1 because hour<tmp
	cout << (hour >=tmp2) << endl;//should be 1 because hour equals tmp2
	cout << (tmp4 >= hour) << endl;//should be 1 because tmp4>hour
	cout << (tmp5!=tmp4) << endl; //should return 1 becaseu they are NOT equal
	cout << (hour!=tmp2)<<endl;//should return 0 because they ARE equal
	cout << (tmp5)++ << endl;
	cout << (tmp5)-- << endl;
	cout << hour << endl;							//1
	cout << (hour)++ << endl;                     // 2
	cout << (hour-4) << endl;	//DELETE THIS BEFORE COMMIT NEED TO FIX
	hour -= 4;  cout << hour << endl;			//1 because 2-4<MIN so we return MIN 
	cout << (tmp4-=4) << endl;
	//CircularInt tmp5 (8,54);
	cout << hour << endl;							//1
	cout << (hour)++ << endl;                     // 2
	hour -= 4;  cout << hour << endl;			//10 because 2-4 
	cout << (tmp4-=4) << endl;					//51 because 8-4
	cout << (hour==tmp) << endl;				//0 because objects hour and tmp are not equal
	cout << (hour==hour) << endl;				//1 because obj are equal
	cout << (hour==tmp3) << endl;				//0 actual in hour changed
	cout << (hour+17) << endl;					//6 because 1+17=18%12=6
	cout << (hour > tmp3) << endl;				//1 because 1/47 < 1/12
	cout << (hour < tmp2) << endl;				//0 because they both=1/12
	cout << (tmp5/=4) << endl;					//47 because 8/4 
	cout << tmp2 << endl;
	cout << (tmp2 = tmp5) << endl;
	// hour += 4;  cout << hour << endl;         // 5
	// (hour += 2)++;  cout << hour << endl;     // 8
	// hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	// cout << -hour << endl;                    // 10  (2 hours before midnight)
	// hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	// cout << hour+hour << endl;                // 10 (11 hours after 11)
	// hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	// cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

	try {
		cout <<  "Actual value "<< hour.getActual()<< endl;
		cout << hour/3 << endl;
		cout <<  "Actual value "<< tmp5.getActual()<< endl;
		cout << tmp5/8 << endl;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}

	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}