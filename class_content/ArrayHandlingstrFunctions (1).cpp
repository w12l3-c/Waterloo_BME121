// strFunctions.cpp: File containing the actual function implementation of the code library
#include <iostream>
#include <climits>
using namespace std;

// DETAILS OF THE strToInt function
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
		if (currDigitChar < '0' || currDigitChar > '9')
			return -1;
		
		// B. Update the number via: 
		//		(1) multiplying current value by 10
		//		(2) Add the value of the current digit 
		//				(found by subtracting the ASCII value of 0 from the current digit's ASCII value)

		// Note: Premature function end if the number is going to be larger than the limits of int variables
		if ( number > maxValue/10 )
			return -1;
		else
			number *= 10;
		
		unsigned int currDigitIntValue = currDigitChar - '0';
		if ( currDigitIntValue > maxValue-number )
			return -1;
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

	// 2. Get one line of input text from the user
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

// List out the steps of strDisplay()
void strDisplay(char **ptr, int size){
	
	// Set a loop to cout each line on a line-by-line basis
	for (int i=0; i<size; i++)
		cout << ptr[i] << endl;
}

// Overloaded version of loadStr()
// Note: Placed within strFunctions.cpp
char* loadStr()
{
	// Define a new char pointer and initialize it to be a single character with null termination
	char *name = new char;
	*name = '\0';

	// Define a size counter and initialize it to 0
	int size = 0;

	// Read the character on a char-by-char basis
	// Note: End of string detected if the detected letter is either line return
	char letter = cin.get();
	while(letter != '\n'){
		
		// A. Increment the size counter by 1
		size++;
		
		// B. Copy the old name array into a temporary buffer
		char *buffer = new char[size];
		for (int k=0; k<size; k++)
			buffer[k] = name[k];
		
		// C. Release the old name memory, and create a new one with size+1 entries
		//    (Plus one needed to accomodate the null character)
		delete name;
		name = new char[size+1];
		
		// D. Copy the letters in the buffer to the new name array
		//	  (Loop stops at size-2 because the second last entry is the new letter, and last entry is null character)
		for (int k=0; k <= size-2; k++)
			name[k] = buffer[k];

		// E. Append the new letter to the end of the name array
		name[size-1] = letter;

		// F. End the new name array with a null character
		name[size] = '\0';

		// G. Delete the memory allocation for the old name
		delete buffer;

		// H. Get the next letter in the cin stream
		letter = cin.get();
	}

	return name;
}