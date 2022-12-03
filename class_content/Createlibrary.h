#ifndef STAT
#define STAT

// List of functions in statistics library
// min- return the minimum value in the array
//      data: input array
//      N: number of elements of input array
int min(int data[], const int N);

// max- return the maximum value in the array
//      data: input array
//      N: number of elements of input array
int max(int data[], const int N);
// median- sort data and return the median value of the array
//      data: input array
//      N: number of elements of input array
int median(int data [], const int N);

// average- return the average value of the array
//      data: input array
//      N: number of elements of input array
float average(int data[], const int N);


#endif