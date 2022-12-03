#ifndef FRACTION_H
#define FRACTION_H

// STRUCT DATA TYPE
struct Fraction{
	int numerator;
	int denominator;
};

// FUNCTION HEADERS
void printFraction(Fraction f);
	// PURPOSE:
	//	- Display a fraction on the screen
	// INPUT:
	//	- a fraction with numerator and denominator components stored in one data structure
	// RETURN:
	//	- None (purely an output function)

void simplifyFraction(Fraction &f);
	// PURPOSE:
	//	- Simplify a fraction via dividing the numerator and denominator by their GCD 
	// INPUT:
	//	- A fraction variable, transferred as "call-by-reference"
	// RETURN:
	//	- None (the fraction components would be modified within the function)

int gcd(int a, int b);
	// PURPOSE:
	//	- Derive the greatest common divisor between two integers
	// INPUT:
	//	- Two integer values
	// RETURN:
	//	- GCD of the two integer values

#endif