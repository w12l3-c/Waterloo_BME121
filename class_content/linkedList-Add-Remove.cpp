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
	  curr = curr->next;
	  curr->next = NULL;

	}
	cin.get(); // Flush past the line return detected
	curr->letter = '\0';

	// Display the list
	cout << endl << "You have entered: ";
	printList(head);
	
	// Add an item between 1st and 2nd entry
	myStr* newItem = new myStr;		// STEP 1: Create a new list item
	newItem->letter = 'x';
	curr = head;					// STEP 2: Reset curr to point to Item 1
	for (int i=0; i<1; i++)
		curr = curr->next;
	newItem->next = curr->next;		// STEP 3: Set new item's next pointer to curr's next pointer
	curr->next = newItem;			// STEP 4: Set curr's next pointer to newItem

	// Display the updated list
	cout << endl << "After insertion, the list contains: ";
	printList(head);
	
	// Delete the 3nd item in the list
	curr = head;					// STEP 1: Reset curr to point to the item before the to-kill item (i.e. Item 2)
	for (int i=0; i<2; i++)
		curr = curr->next;
	myStr* toKill = curr->next;		// STEP 2: Define a temp variable to identify the to-kill item
	curr->next = toKill->next;		// STEP 3: Update curr's next pointer to the to-kill item's next pointer
	delete toKill;					// STEP 4: Delete the memory allocation for the to-kill item

	// Display the updated list again
	cout << endl << "After deletion, the list contains: ";
	printList(head);
	
	return 0;
}
