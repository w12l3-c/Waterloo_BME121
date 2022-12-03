#include <iostream>
#include "DataStructfraction.h"
using namespace std;

void printFraction(Fraction f){

	// 1. Print the numerator part of the fraction
    cout << f.numerator;

	// 2. Print the denominator part of the fraction
	//	Note: Only do so if it is not 1 (i.e. whole number) and not 0 (i.e. undefined)
    if(f.denominator != 1 && f.numerator != 0)
		cout << "/" << f.denominator;
	
	// 3. Line return
    cout << endl;
}

void simplifyFraction(Fraction &f) {
	
	// 1. Find the greatest common divisor between the two components of the fraction
    int g = gcd(f.numerator, f.denominator);

	// 2. Divide the numerator by the greatest common divisor
    f.numerator /= g;

	// 3. Divide the denominator by the greatest common divisor
    f.denominator /= g;
	
	// 4. If the denominator is negative, move the negative sign to the numerator
    if(f.denominator < 0) {
       	f.numerator *= -1;
		f.denominator *= -1;
    }
}

int gcd(int a, int b) {
	
    int large = a > 0 ? a : -a;
	int small = b > 0 ? b : -b;
	bool nve = false;
	
	// Based upon the Euclidean algorithm
    do {
		// 1. Define two variables for the magnitude of a and b (for step 2)

		// 2. If the magnitude of B is smaller than the magnitude of A, 
		//	  swap the values of A and B, such that in Step 3 the larger number is divided by the smaller number
		if (small>large){
			int temp = large;
			large = small;
			small = temp;
		}
		// 3. Update the value of the larger number as the remainder of the division between 
		//	  the larger number and the smaller number
		large = small;
		small = large%small;
		
    } while(small != 0); 
	// Iterate until the larger number is a multiple of the smaller number

	// Return the smaller number (including its sign)
	return  (a>0||b>0) ? small:-small;
}
