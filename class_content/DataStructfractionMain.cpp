#include <iostream>
#include "DataStructfraction.h"
#include "DataStructstrFunctions.h"

using namespace std;

void usage(char *progname); 
	// PURPOSE:
	//	- An error routine that tells the user how to use this program properly
	// INPUT:
	//	- The text string for the program name typed by the user when calling the executable
	// RETURN:
	//	- None (purely an error output function)

// MAIN ROUTINE
int main(int argc, char *v[]) {
	
	// Note: The user should input two numbers, one for numerator and the other for denominator
	// Thus, if the number of input arguments is not equal to three, something is wrong
	// In this case, terminate the program after calling the usage() routine
    if(argc != 3) {
		usage(v[0]);	// v[0] is the text string of the program name
		return -1;
    }

	// 1. Define an instance of the fraction data type
    Fraction f;
	
	// 2. Store the two command-line arguments respectively as the numerator and denominator of the fraction
    int convertErr1 = strToInt(f.numerator,v[1]);
    int convertErr2 = strToInt(f.denominator,v[2]);
	if (convertErr1 || convertErr2){
		cerr << "Convert error.\n";
		return -1;
	}
	
	// ERROR CHECK: If the denominator is zero, then the fraction is undefined.
	// In this case, terminate the program after calling the usage() routine
    if(f.denominator == 0) {
		usage(v[0]);
		return -1;
    }

	// 3. Perform the fraction simplification operation, and then display results on the screen
    simplifyFraction(f);
    printFraction(f);

    return 0;
}

void usage(char *progname){
	
	// Use cerr to output the error message to the screen
    cerr << "Usage: " << progname << " numerator denominator" << endl;
}
