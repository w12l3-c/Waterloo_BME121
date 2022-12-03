#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std; 
// use to simply the names used in the main

int average (int arr[]){
    // auto will automatic assign the type of variable it is
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    // int arrSize = *(&arr + 1) - arr;
    int value = 0;
    for(int i = 0; i <= arrSize; i++){
        value += arr[i];
    }
    value /= arrSize;
    return value;
}

// int main is the entry point of c++
int main(const int argc, const char* const argv[]){
    int x;
    int y;
    float avg;

    cout << "Please type in first number \n" << endl; // << writing in
    cin >> x;
    cout << "Please type in the second number " << endl;
    cin >> y; // >> is for registering

    avg = (x+y)/2;
    
    cout << "The average of " << x << " and " << y <<" is " << avg << endl;

    return 0;
}


