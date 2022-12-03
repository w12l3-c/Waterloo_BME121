// strFunctions.h: File with all the function headers of the code library
#ifndef STR_FUNCTIONS
#define STR_FUNCTIONS

int strToInt(int &result, char* str);
// Purpose:
//	   - Converts a number text string into an integer
// Parameter:
//	   - The base address of the text string
//	   - A call-by-reference alias to an int variable
// Returns:
//	   - An error check code on whether the conversion is successful
//		 (0 for success; -1 for error)

char* loadStr(int maxSize);
// Purpose:
//     - Get a dynamically sized text string from the keyboard
// Parameter:
//     - maximum size of text string to be accepted
// Returns:
//     - the base address of the text string

void strDisplay(char **ptr, int size);
// Purpose:
//     - Output an array of text strings to the screen
// Parameters:
//     - Base address of the string array (a double pointer, or 2D array)
//	   - Number of strings present in the array
// Returns:
//     - None

// OVERLOADED STRING LOADING FUNCTION
char* loadStr();
// Purpose:
//     - Get a dynamically sized text string from the keyboard without any size specification
// Parameter:
//     - None
// Returns:
//     - the base address of the text string

#endif