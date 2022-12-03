/* 
Wallace Lee 
---------------------------------
Program: logicOp.cpp
Create Date: 2022-09-25
---------------------------------
*/
// include iostream and math library
#include <cmath>
#include <iostream>

// using namspace to represent cin cout and cerr
using namespace std;

int main(const int argc, const char* const argv[]) {
    // declare P and Q
    int P;
    int Q;

    // convert P and Q into integers
    P = atoi(argv[1]);
    Q = atoi(argv[2]);

    
    cout << "P: " << P << endl;
    cout << "Q: " << Q << endl;
    // P and Q are both true
    cout << "P AND Q: " << (P && Q) << endl;
    // P or Q are true
    cout << "P OR Q: " << (P || Q) << endl;
    // Negation of P
    cout << "NOT P: " << (!P) << endl;
    // Negation of Q
    cout << "NOT Q: " << (!Q) << endl;

    return 0;
}