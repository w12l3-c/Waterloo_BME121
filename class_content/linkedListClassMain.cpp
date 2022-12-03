#include <iostream>
#include "linkedListClass.h"
using namespace std;

int main(){
	
	// Create a stack object
	numList stack;

	// Start expanding the list
	int x;
	while (cin.peek() != '\n'){
		cin >> x;
		if ( cin.good() ){
			stack.addItem(stack, x);
		}
		else{
			cerr << "Error in input!\n";
			return -1;
		}
	}
	while (cin.get() != '\n');	// Flush past the line return in the cin stream

	// Print the stack items
	cout << endl << "The stack contains: ";
	stack.print();

	return 0;
}
