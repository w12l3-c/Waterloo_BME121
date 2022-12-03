#include <iostream>
using namespace std;

struct myStr{
	// Data component
	char letter;
	// Linked list component
	myStr* next;
};

void printList(myStr* curr){
	for (; curr->next != NULL; curr=curr->next)
		cout << curr->letter;
	cout << endl;
	return;
}

int main(){
	
	// Create a list head
	myStr* head = new myStr;
	head->letter = '\0';
	head->next = NULL;

	// Start expanding the list
	myStr* curr = head;
	while (cin.peek() != '\n'){

	  // STEP 1: UPDATE CURRENT ENTRY
		curr->letter = cin.get();

	  // STEP 2: CREATE NEW LIST ENRY
		curr->next = new myStr;
		curr = curr->next; // Moce the pointer to the new list entry
		curr->next = NULL; // This indicate that this entry is the end of the list

	}
	// Flush past the line return detected
	cin.get(); // to get the line return '\n'
	curr->letter = '\0';

	// Display the list
	cout << endl << "You have entered: ";
	printList(head);
	
	return 0;
}
