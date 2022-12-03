/* 
Wallace Lee 
---------------------------------
Program: Summing large numbers
Create Date: 2022-10-05
---------------------------------
*/
#include <iostream> // include iostream library
#include <cstring>  // include cstring library
#include <cstdlib>  // include cstdlib library

using namespace std;    // using std namespace for cin cout cerr

void swap(char* a, char* b){    // function to swap two characters
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(const int argc, const char *argv[])
{
    // declare variables
    int sum = 0;    // store the sum of two numbers for each digit
    int len1 = strlen(argv[1]); // store the length of the first number
    int len2 = strlen(argv[2]); // store the length of the second number
    char string1[len1+1];  // store the first number
    char string2[len2+1];  // store the second number
    bool add1 = false;  // boolean for carry the 1 to the next digit
    bool oneDigit = false;  // boolean for when there is a need for an extra digit
    
    // reverse list of 1st number
    for (int i = len1; i > 0; i--){
        string1[len1 - i] = argv[1][i - 1];
    }

    // reverse list of 2nd number
    for (int i = len2; i > 0; i--){
        string2[len2 - i] = argv[2][i - 1];
    }

    // swap the two number if the second number has more digits, just for convenience
    if (len2 > len1){
        swap(string1, string2);
        len1 = strlen(argv[2]);
        len2 = strlen(argv[1]);
    }

    char ans[len1+1];  // store the answer

    // add the digits individually
    for (int i = 0; i < len2; i++){
        // check the carryover condition first
        if (add1){
            sum += 1;
            add1 = false;
        }
        // add the two digits together while deducting their ascii value into mathematical values
        sum += (int(string1[i]) - 48 + int(string2[i]) - 48);
        // check if it is needed to carry over
        if (sum >= 10){
            sum -= 10;
            add1 = true;
        }
        // convert back to ascii value
        sum += 48;
        // append into array
        ans[i] = sum;
        //reset the sum
        sum = 0;
    }

    // the remaining digits of the longer number
    for (int i = len2; i < len1; i++){
        // check the carryover condition first as well 
        if (add1){
            // check whether it will continue to make the next digit carryover, ie. 9+1=10
            if (int(string1[i]) - 48 + 1 >= 10){
                ans[i] = 48;
            }
            // turn carryover to false until the next digit will not carry over with the added 1
            else{
                ans[i] = char(int(string1[i]) + 1);
                add1 = false;
            }
        } else {
            // just append the number
            ans[i] = string1[i];
        }
        // sometimes the last digit is 9 and will carry over, so an extra digit is required
        if (i+1==len1 && add1){
            ans[i+1] = 49;
            oneDigit = true;
        }
    }

    // reverse the answer for the correct order for an extra digit 
    if (oneDigit){
        cout << "Sum: ";
        for (int i = len1; i >= 0; i--)
        {
            cout << ans[i];
        }
    } 
    // reverse the answer for the correct order
    else{
        cout << "Sum: ";
        for (int i = len1 - 1; i >= 0; i--)
        {
            cout << ans[i];
        }
    }
    cout << endl;

    return 0;
}