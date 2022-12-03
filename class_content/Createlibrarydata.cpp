#include <iostream>
#include "createlibrary.h"
using namespace std;

int main () {
    const int N = 10;
    int data[N] = {68, 30, 92, 44, 86, 63, 73, 6, 27, 55 };

    cout << "The minimum value of the number sequence is " << min(data, N) << endl;
    cout << "The maximum value of the number sequence is " << max(data, N) << endl;
    cout << "The median of the number sequence is " << median(data, N) << endl;

    for (int i=0;i<N;i++) {
        cout << data[i] << endl;
    }

    cout << "The average of the number sequence is " << average(data, N) << endl;


    return 0;
}