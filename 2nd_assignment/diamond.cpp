/* 
Wallace Lee 
---------------------------------
Program: diamond
Create Date: 2022-10-05
---------------------------------
*/
#include <iostream>     // include iostream library
#include <string>    // include string library

using namespace std;    // using std namespace for cin cout cerr

int main(){
    int x = 0;  // declare the vaivle x for user input
    char space = 32; // store the ascii value of space

    // prompt the user to input a number
    cout << "How large do you want the diamond to be: " ;
    cin >> x;
    cout << endl;

    // top part of pyramid
    for(int i = 0; i<x; i++){
        // print space, then frontslash, then more space and then backslash
        cout << string((x-i), space) << '/' << string((i*2), space) << '\\' << endl;
    }
    // bottom part of inverse pyramid
    for(int i = x-1; i>=0; i--){
        // print space, then backslash, then more space and then frontslash
        cout << string((x-i), space) << '\\' << string((i*2), space) << '/' << endl;
    }
    return 0;
}