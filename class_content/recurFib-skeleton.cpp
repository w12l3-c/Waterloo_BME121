#include <iostream>
using namespace std;

unsigned int fibo(unsigned int n) {
    if (n == 0){
        return 0;
    }
        // return base case 1
    else if (n == 1){
        return 1;
    }
        // return base case 2
    else{
        return fibo(n-1) + fibo(n-2);
    }
        // return normal base
}

int main () {
    unsigned int n = 5;
    cout << fibo(n);
}