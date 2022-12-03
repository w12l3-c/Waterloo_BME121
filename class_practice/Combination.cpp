#include <iostream>

using namespace std;

int factorial(int n){
    if (n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int options = 10;
    int selection = 4;
    cout << factorial(options)/(factorial(selection)*factorial(options-selection));
}