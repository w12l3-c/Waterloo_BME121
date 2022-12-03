/* 
Wallace Lee 
---------------------------------
Program: Case Convert
Create Date: 2022-10-3
---------------------------------
*/
// include iostream 
#include <iostream>

// using std namespace for cin cout cerr
using namespace std;

int main(const int argc, const char* const argv[]){
    char x;    // declare variable x for user input
    char org;   // declare variable org for original character

    // prompt the user to input a character
    cout << "Please input a character: ";
    cin >> x;

    org = x;    // save the original value of x 

    // check if the character is a lowercase letter, convert to upper case
    if (65 <= x && x <= 90){
        x += 32;
    } 
    // check if the character is a upper case letter, convert it to lower case
    else if (97 <= x && x <= 122){
        x -= 32;
    } 
    // for every other symbol that is not an alphabet, print the original value and exit program
    else {
        cout << "The input character is " << org << endl;
        return 0;
    }

    // print the converted value
    cout << "The upper-case of " << org << " is " << x << endl;

    return 0;
}
