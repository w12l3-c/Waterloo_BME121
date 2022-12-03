/* 
Wallace Lee 
---------------------------------
Program: binaryRep.cpp
Create Date: 2022-09-25
---------------------------------
*/
// include iostream and math library 
#include <cmath>
#include <iostream>

// using namspace to represent cin cout and cerr
using namespace std;

int main(const int argc, const char* const argv[]) {
    // declare x as user input and ans as the output
    double x;
    double ans;

    // ask user for number
    cout << "Please input a positive integer: ";
    cin >> x;

    // cannot log 0, but 0 is a valid input
    if (x==0){
        cout << "0 can be represented using 1 bit." << endl;
        return 0;
    }

    // find the log base 2 of x, add 0.0001 in case it results in a integer value as they need an extra bit
    ans = (log10(x) / log10(2)) + 0.0001;
    // round up because it requires a integar amount of bits to represent and has to be larger than the float value 
    ans = ceil(ans);

    // output the amount of bits to hold the user input
    cout << x << " can be represented using " << ans << " bits." << endl;

    return 0;
}

