#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

enum MonthType {
    JAN=1, FEB=2, MAR=3, APR=4, MAY=5, JUN=6, JUL=7, AUG=8, SEP=9, OCT=10, NOV=11, DEC=12
};

enum DayType { SAT, SUN, MON, TUE, WED, THU, FRI };


int main()
{
    // unordered_map<int, int> month_key = {{1, 1}, {2, 4}, {3, 4}, {4, 0}, {5, 2}, {6, 5}, {7, 0}, {8, 3}, {9, 6}, {10, 1}, {11, 4}, {12, 6}};
    unordered_map<int, int> month_key;// = {{1, 1}, {2, 4}, {3, 4}, {4, 0}};
    month_key[1] = 1; month_key[2] = 4; month_key[3] = 4; month_key[4] = 0; month_key[5] = 2; month_key[6] = 5; month_key[7] = 0; month_key[8] = 3; month_key[9] = 6; month_key[10] = 1; month_key[11] = 4; month_key[12] = 6; 
    // Define the date we want to determine the day of week
    int year = 2022;    // Has to be between 2000 and 2099
    MonthType month = OCT;
    int day = 31;

    // Determine if year is a leap year
    bool leapYear = false; //leapYear flag initialization
    if (year%4 == 0)
        leapYear = true;

    //Find Month Key
    int key = month_key[int(month)];
    if (int(month)<=2 && int(month)>0 && leapYear){
        key--;
    }

    // Calculate the day of week
    // Step 1
    int sum = year%2000;
    // Step 2
    sum += 0.25*sum;
    // Step 3
    sum += day + key;
    // Step 4
    sum -= 1;

    // Create a DayType variable to convert the result to day of week
    DayType date = (DayType)(sum%7);

    // Print out the result based on date
    switch(date){
        case SUN: 
            cout << "Day of the week is Sunday" << endl; 
        break;
        case MON: 
            cout << "Day of the week is Monday" << endl; 
        break;
        case TUE: 
            cout << "Day of the week is Tuesday" << endl;
        break;
        case WED: 
            cout << "Day of the week is Wednesday" << endl;
        break; 
        case THU: 
            cout << "Day of the week is Thursday" << endl;
        break; 
        case FRI: 
            cout << "Day of the week is Friday" << endl;
        break; 
        case SAT: 
            cout << "Day of the week is Saturday" << endl;
        break;
        default: 
            cerr << "Invalid Result" << endl;
            return -1; 
    }
}