#include <iostream>
#include <fstream>
using namespace std;

// Define a struct type to hold info about a person
struct Person {
  char firstName[20];
  char lastName[20];
  int age;
};

// A data read function to get info about an array of persons
int read(ifstream &fin, Person* patient, int size){
	
	// Keep track of the number of people read from the file
	int i = 0;

	// Attempts to read an entry from file using an instruction syntax similar to cin 
	// NOTE: Integrative syntax used here 
	// (similar to cin.good(), (fin >> variable) would return a TRUE value if the operation was successful)
	while (i < size &&
		   fin >> patient[i].firstName && 
		   fin >> patient[i].lastName && 
		   fin >> patient[i].age)
		i++;	// Add one to the data count if a new entry has been read successfully
	
	// If something is wrong, 
	if ( fin.fail() && !EOF )
		return -1;
	else
		return i;
}

int main() {
	
	// Define objects for input file, and directly attempt to open the file
	ifstream infile("members.txt");
	if (infile.fail()) {
		cerr << "Error: file not open.\n";
		return -1;
	}
	  
	// Define a multi-element patient array
	const int MAX_LENGTH = 3;
	Person patient[MAX_LENGTH];
	
	// Read the data from file
	int numPeople = read(infile, patient, MAX_LENGTH);
	
	// Close infile, as it is not needed anymore
	infile.close();
	
	// Output the loaded results to the screen
	if (numPeople < 0){
		cerr << "Error in file read operation." << endl;
		return -1;
	}
	else{
		cout << "Here is the list of names loaded from the file:\n";
		for (int i=0; i<numPeople; i++)
			cout << patient[i].firstName << " " << patient[i].lastName << ", Age " << patient[i].age << endl;
	}
	return 0;
}
