#include <climits>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Function header for a string set routine and a custom-made atoi() routine
// NOTE: Call by value!
void strSet(char destStr[], char srcStr[]);
int strToInt(int &result, char* str);

// A copy of the loadStr function from last time
char* loadStr(int maxSize);

int main (){
  const int MAX_LENGTH = 20;
  
  // Define pointer variables to store new text strings
  char *text1 = loadStr(MAX_LENGTH);
  char *text2 = loadStr(MAX_LENGTH);
  
  // Try changing the string and display output
  cout << "Initially, String #1 is " << text1 << " and String #2 is " << text2 << endl;
  strSet(text1,text2);
  cout << "After calling strSet(), String #1 is " << text1 << " and String #2 is " << text2 << endl;
  
  // Convert text1 to a number
  int number;
  int errorFlag = strToInt(number, text1);
  if (!errorFlag)
	cout << "After converting text1 to an int, the number is " << number << endl;
   
  return 0;
}

// List out the steps of strToInt()
void strSet(char destStr[], char srcStr[]){
	
	// Determine the destination and source string sizes
	int nDest = 0;
	while (destStr[nDest] != '\0')
		nDest++;
	int nSrc = 0;
	while (srcStr[nSrc] != '\0')
		nSrc++;

	// Only copy array entries within legitimate sizes 
	// (i.e. not beyond the destination string dimension)
	nDest = (nDest <= nSrc) ? nDest : nSrc;

	// First nDest-1 characters would be for the actual characters
	for (int i=0; i<nDest; i++)
		destStr[i] = *(srcStr+i);
	
	// Last character should be a null character by definition
	*(destStr+nDest) = '\0';
}

// List out the steps of strToInt()
int strToInt(int &result, char* str){
	// Define variables to store the number to be converted, the current digit position, and the char value of the current digit  
	unsigned int number = 0;
	unsigned int currDigit = 0;
	char currDigitChar = str[0];

	// 1. Check if there is a minus or plus sign at the front
	//    If yes, move to the next digit position
	bool minusSign = (currDigitChar == '-');
	bool plusSign = (currDigitChar == '+');
	if (minusSign || plusSign){
		currDigit = 1;
		currDigitChar = str[1];
	}

	// Define a maximum magnitude that can be converted into an integer
	// NOTE: If input is a -ve number, max magnitude is 1 greater than max magnitude in +ve range
	//		 Reason: max magnitude in +ve range is 2147483647, while that in -ve range is 2147483648
	//			     since INT_MAX is 2147483647 and INT_MIN is -2147483648
	unsigned int maxValue = (unsigned int)INT_MAX + (minusSign?1:0);
	
	// 2. Calculate the number on a digit-by-digit basis using base-10 arithmetic
	//	  Repeat the process until end of text string is reached
	while (currDigitChar != '\0'){
		
		// A. If the current digit string is not between 0 to 9, something is wrong
		//    In this case, simply return -1 as an error code
		if (currDigitChar < '0' || currDigitChar > '9'){
			cerr << "Error in integer string conversion" << endl;
			return -1;
		}
		
		// B. Update the number via: 
		//		(1) multiplying current value by 10
		//		(2) Add the value of the current digit 
		//				(found by subtracting the ASCII value of 0 from the current digit's ASCII value)

		// Note: Premature function end if the number is going to be larger than the limits of int variables
		if ( number > maxValue/10 ){
			cerr << "Error: Numerical value of text string is beyond limits of int variables" << endl;
			return -1;
		}
		else
			number *= 10;

		unsigned int currDigitIntValue = currDigitChar - '0';
		if ( currDigitIntValue > maxValue-number ){
			cerr << "Error: Numerical value of text string is beyond limits of int variables" << endl;
			return -1;
		}
		else
			number += currDigitIntValue;
		
		// C. Move to the next digit and update the digit's char value accordingly 
		currDigit++;
		currDigitChar = str[currDigit];
	}
	
	// 3. If there is a minus sign, return the negated value of the number; 
	//	  otherwise, just set the final result as the number value
	result = minusSign? (-number) : number;
	return 0;
}

// List out the steps of loadStr()
char* loadStr(int maxSize){
	// 1. Create a string buffer
	char buffer[maxSize];

	// 2. Get one line of input text from the user (note: NULL termination not included)
	int size = 0;
	while (cin.peek() != '\n' && size < maxSize){
		buffer[size] = cin.get();
		size++;
	}
	while (cin.get() != '\n');	// Extra cin.get() calls to flush past the end of line
	
	// 3. Define a new char pointer variable
	char *strPtr;
	
	// 4. Dynamically allocate a char array with size equal to length of input text line
	//    (Include an extra character for the NULL character)
	strPtr = new char[size+1];
	
	// 5a. Copy the text line from the buffer to the char pointer
	for (int i = 0; i < size; i++)
		strPtr[i] = buffer[i];
	
	// 5b. Add a null character to the end of string
	strPtr[size] = '\0';
	
	// 6. Return the address of the char pointer as the function output
	return strPtr;
}
