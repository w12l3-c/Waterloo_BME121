#include <stdlib.h>
#include <iostream>
using namespace std;

// FUNCTION HEADERS
void mergeSort(int* list, int start, int end);
	// PURPOSE:
	//	- Sort a list of numbers in ascending order via the merge sort algorithm
	// INPUT:
	//	- The base address of a number list array
	//  - Starting and ending index positions of the array entries to be sorted
	// RETURN:
	//	- None (values in the array list are modified via pointer dereferencing)

void merge(int* list, int start, int split, int end);
	// PURPOSE:
	//	- Merge list subsets in an array of numbers
	// INPUT:
	//	- The base address of a number list array
	//  - Starting, splitting, ending index positions of the array entries
	// RETURN:
	//	- None (values in the array list are modified via pointer dereferencing)
	
void printCurrSortStep(int* list, int &indexStart, int &indexEnd);
	// PURPOSE:
	//	- Provides screen feedback on the current sort step
	// INPUT:
	//	- The base address of a number list array
	//  - Starting and ending index positions of the array entries
	// RETURN:
	//	- None (Screen display updated)
	
void printCurrMergeStep(int* list, int &indexStart, int &indexSplit, int &indexEnd);
	// PURPOSE:
	//	- Provides screen feedback on the current merge step
	// INPUT:
	//	- The base address of a number list array
	//  - Starting, splitting, ending index positions of the array entries
	// RETURN:
	//	- None (Screen display updated)
	
void printListSubset(int* list, int &indexStart, int &indexEnd);
	// PURPOSE:
	//	- Outputs a subset of numbers in the array to the screen
	// INPUT:
	//	- The base address of a number list array
	//  - Starting and ending index positions of the array entries
	// RETURN:
	//	- None (Screen display updated)

	
// MAIN FUNCTION	
int main(const int argc, const char **argv) {

	// If less than 1 argument, then it means no number has been entered
	// In this case, it should be an error case
    if(argc < 2){
		cerr << "Please enter some numbers" << endl;
		return -1;
	}

	// 1a. Define a number list array with argc-1 entries
	int listSize = argc-1;
	int *numList = new int[listSize];
	//int numList[listSize];

	// 1b. Load each number into the array via an in-house number string conversion function
    for(int i = 1; i <= listSize; i++) {
		numList[i-1] = atoi(argv[i]);
    }

	// 2. Perform the mergeSort routine from first to last entries of the array
    mergeSort(numList, 0, listSize-1);
    return 0;
}

// FUNCTION	DEFINITIONS
void mergeSort(int* list, int start, int end){
	// 0. Prompt the user about current step in the merge sort 
	// Info displayed: 1) array entries considered, 2) start & end index positions
    printCurrSortStep(list, start, end);

	// 1a. If started and ending index positions are the same, there is nothing to sort
	// In this case, just end the routine
    if(end <= start) 
		return;

	// 1b. Define a midpoint variable, and set it equal to the average of the starting and ending index positions
    int mid = (start+end)/2;
	
	// 2. Perform mergeSort on the first half of the list
    mergeSort(list, start, mid);

	// 3. Perform mergeSort on the second half of the list
    mergeSort(list, mid+1, end);

	// 4. Merge the sorted numbers from the two halves
    merge(list, start, mid, end);
}

void merge(int* list, int start, int split, int end) {

	// 0. Prompt the user about current merge step 
	// Info displayed: 1) array entries considered, 2) start, split, and end index positions
    printCurrMergeStep(list, start, split, end);

	// 1a. If split index position is less than starting position or is greater than ending position, there is nothing to merge
	// In this case, just end the routine
    if(split < start || split > end) 
		return;

	// 1b. Define a sorted list array, as well as various index positions
	int listSize = end-start+1;
    //int sortedList[listSize];
	int *sortedList = new int[listSize];
    int indexLeftHalf = start, indexRightHalf = split+1, indexSortedList = 0;

	// 2. Populate the sorted list by comparing the values in the two splitted lists
	//		General rule: Smaller value of the two splitted lists at the respective positions would enter the sorted list first
    while(indexLeftHalf <= split && indexRightHalf <= end) {
		
		// A. If the value in the current index position of the left-side list is smaller than that in the right-side list,
		//	  enter that number into the sorted list
		if (list[indexLeftHalf] < list[indexRightHalf]){
			
			// Copy the array value from the left-side list's current index position,
			// and then increment the left-side list index to the next element
			sortedList[indexSortedList] = list[indexLeftHalf];
			indexLeftHalf++;
		}
		else{
			// Copy the array value from the right-side list's current index position,
			// and then increment the right-side list index to the next element
			sortedList[indexSortedList] = list[indexRightHalf];
			indexRightHalf++;
		}
		
		// B. Increment the sorted list index position to the next element
		indexSortedList++;
    }
	// While loop is repeated until one of the two splitted list reached its end
	

	// 3a. If the left-side list has not reached the end yet, copy its remaining entries into the sorted list
    while(indexLeftHalf <= split) {
		sortedList[indexSortedList] = list[indexLeftHalf];
		indexLeftHalf++;
		indexSortedList++;
    }

	// 3b. If the right-side list has not reached the end yet, copy its remaining entries into the sorted list
    while(indexRightHalf <= end) {
		sortedList[indexSortedList] = list[indexRightHalf];
		indexRightHalf++;
		indexSortedList++;
    }

	// 4. Through a pointer dereferencing operation, copy the values from the sorted list to the original list
	//		NOTE: Starting entry position in the original list should be at "start"
    for(int i = 0; i < listSize; i++)
		list[i+start] = sortedList[i];

	// 5. Display the post-merge results to the screen
    cout << "After merge: ";
    printListSubset(list, start, end);
    cout << endl;
}

void printCurrSortStep(int* list, int &indexStart, int &indexEnd) {
    cout << "mergeSort(";
    printListSubset(list, indexStart, indexEnd);
    cout <<", " << indexStart << ", " << indexEnd;
    cout << ")" << endl;
}

void printCurrMergeStep(int* list, int &indexStart, int &indexSplit, int &indexEnd) {
    cout << "merge(";
    printListSubset(list, indexStart, indexEnd);
    cout <<", " << indexStart << ", " << indexSplit << ", " << indexEnd;
    cout << ")" << endl;
}

void printListSubset(int* list, int &indexStart, int &indexEnd) {
    cout << "[";
    for(int i = indexStart; i <= indexEnd; i++) {
		cout << list[i];
		if (i < indexEnd)
			cout << ", ";
	}
    cout << "]";
}
