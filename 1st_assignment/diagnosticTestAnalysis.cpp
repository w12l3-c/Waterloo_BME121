/* 
Wallace Lee 
---------------------------------
Program: Anchor Problem Diagnostic Accuracy Calculation
Create Date: 2022-09-26
---------------------------------
*/
// include iostream and math library
#include <iostream>
#include <cmath>

// using namspace to represent cin cout and cerr
using namespace std;

int main(const int argc, const char* const argv[]) {
    // declare variables
    float tpr, fpr, score;
    float bestscore = 0;    // best score
    float bestcase = 0;     // best case correspondent to best score
    float counter = 1;      // counter for each case   
    bool tprCheck = true;   // check if tpr is valid, false means it passed the test
    bool fprCheck = true;   // check if fpr is valid, false means it passed the test
    bool tprNegative = false;   // check if tpr is negative, true means it is negative
    bool fprNegative = false;   // check if fpr is negative, true means it is negative

    // loop indefinitely, for doesn't work here because there is no set amount of iterations
    while(true){
        // ask user for tpr 
        while(tprCheck){
            cout << "Please enter the diagnostic test's true positive rate: ";
            cin >> tpr;
            // if larger than 1, it is invalid and print error message and request for input again
            if(tpr > 1){
                cerr << "\nWarning: invalid input to true positive rate. Please enter an input <= 1." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            // if less than 0, it will accept the value and set a exiting flag to true
            }else if (tpr < 0){
                tpr = 0;
                tprCheck = false;
                tprNegative = true;
            // if it is character or boolean, it is invalid will print error message and request for input again
            }else if (!cin.good()){
                cerr << "\nWarning: invalid input to true positive rate. Please enter a numeric input." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            // if the value is [0, 1], it is valid and continues
            }else{
                // exit loop
                tprCheck = false;
            }
        }

        // ask user for fpr
        while(fprCheck){
            cout << "Please enter the diagnostic test's false positive rate: ";
            cin >> fpr;
            // if larger than 1, it is invalid and print error message and request for input again
            if(fpr > 1){
                cerr << "\nWarning: invalid input to false positive rate. Please enter an input <= 1." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            // if less than 0, it will accept the value and set a exiting flag to true
            }else if (fpr < 0){
                fpr = 0;
                fprCheck = false;
                fprNegative = true;
            // if it is character or boolean, it is invalid will print error message and request for input again
            }else if (cin.fail()){
                cerr << "\nWarning: invalid input to false positive rate. Please enter a numeric input." << endl;
                cin.clear();
                cin.ignore(100, '\n');
            // if the value is [0, 1], it is valid and continues
            }else{
                fprCheck = false;
            }
        }

        // when user input both negative number, break the entire while loop by setting it false
        if (tprNegative && fprNegative){
            break;
        }

        // calculate the score
        score = 1 - sqrt(pow(1-tpr,2)+pow(fpr,2));
        cout << "The score for diagnostic test " << counter << " is " << score << endl;

        // only enter when a new value is larger or equal to other existing values 
        if (score >= bestscore){
            // update the best score and best case number
            bestscore = score;
            bestcase = counter;
        }

        // recording test case number
        counter += 1;

        // return to default condition for the new iteration
        tprCheck = true;
        fprCheck = true;
        tprNegative = false;
        fprNegative = false;

    }

    // printing the best case number and highest score
    cout << "\nDiagonstic test " << bestcase <<" has the best score of " << bestscore << endl;
    cout << "Exiting program" << endl;

    return 0;
}