#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main () {
    // 1. Create arrays to store the info
    const int NUMPATIENT = 10;
    int Age[NUMPATIENT];
    int ID[NUMPATIENT];
    char first[NUMPATIENT][20];
    char last[NUMPATIENT][20];
    char gender[NUMPATIENT];
    char line[20];
    
    // 2. Open input file using ifstream
    ifstream inFile;
    inFile.open("patientInfo.txt");

    // 3. Read from file using iteration
    for(int i = 0; i < NUMPATIENT; i++){
        inFile.getline(line, 20);
        Age[i] = atoi(line);
        inFile.getline(line, 20);
        ID[i] = atoi(line);
        inFile.getline(line, 20);
        strcpy(first[i], line);
        inFile.getline(line, 20);
        strcpy(last[i], line);
        inFile.getline(line, 20);
        gender[i] = line[0];
    }
    

    // 4. Open output file using ofstream
    ofstream outFile;
    outFile.open("patientOut.txt");


    // 5. Write to file using iteration in reverse order
    for(int i = NUMPATIENT-1; i >= 0; i--){
        outFile << 
        outFile << 
        outFile << 
        outFile << 
        outFile << 
    }


    inFile.close();
    outFile.close();
}