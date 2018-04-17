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
	cout << hour << endl;							//1
	cout << (hour)++ << endl;                     // 2
	hour -= 4;  cout << hour << endl;			//1 because 2-4<MIN so we return MIN 
	cout << (tmp4-=4) << endl;
	cout << (hour==tmp) << endl;				//0 because objects hour and tmp are not equal
	cout << (hour==tmp2) << endl;				//1 because obj are equal
	cout << hour+17 << endl;						//6 because 1+17=18%12=6
	cout << (hour > tmp3) << endl;				//1 because 1/47 < 1/12
	cout << (hour < tmp2) << endl;				//0 because they both=1/12
	cout << (tmp4/=4) << endl;					//2 because 8/4 
	// hour += 4;  cout << hour << endl;         // 5
	// (hour += 2)++;  cout << hour << endl;     // 8
	// hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	// cout << -hour << endl;                    // 10  (2 hours before midnight)
	// hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
	// cout << hour+hour << endl;                // 10 (11 hours after 11)
	// hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
	// cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

	// try {
	// 	cout << hour/3;
	// } catch (const string& message) {
	// 	cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	// }

	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}