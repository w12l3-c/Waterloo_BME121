#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int a;
    int b;
    int h;
    int area;

    //for (int i = 0; i < 8; i++){}
    cout << "\nPlease enter the length of the first parallel side (a) [in cm]: "; // << writing in
    cin >> a;
    cout << "\nPlease enter the length of the second parallel side (b) [in cm]: ";
    cin >> b; 
    cout << "\nPlease enter the height (h) [in cm]: ";
    cin >> h;

    area = (a+b)*h/2;
    
    cout << "\nThe area of the trapezoid is " << area << " squared centimeters." << endl;
    
    return 0;
}