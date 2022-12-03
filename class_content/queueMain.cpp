#include <iostream>
#include "queue.h"
using namespace std;

int main(){
	
	// Create a queue object
	Queue q;

	// Start expanding the list
	int x;
	while (cin.peek() != '\n'){
		cin >> x;
		if ( cin.good() && 
			(cin.peek() == ' ' || cin.peek() == '\n') )
			q.enqueue(x);
		else{
			cerr << "Error in input!\n";
			return -1;
		}
	}
	while (cin.get() != '\n');	// Flush past the line return in the cin stream

	// Print the queue items without removing them from the list
	cout << endl << "The queue contains: ";
	q.print();

	// Dequeue one by one, and print result
	cout << endl << "Stepwise dequeued list entries: ";
	int y;
	while ( q.dequeue(y) )
		cout << y << " ";
	cout << endl;
	
	return 0;
}
