#include <climits>
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int median (int data[], const int N)
{
    for (int i=0;i<N;i++) {
        for (int j=0;j<N-i-1;j++){
            if (data[j]>data[j+1])
                swap(data[j], data[j+1]);
        }
    }
    return data[N/2];
}

