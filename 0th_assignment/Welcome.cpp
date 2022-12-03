// Skeleton code for BME 121 Assignment 0 Part 2
#include <iostream>

using namespace std;

int main(const int argc, const char* const argv[]) {
  
  // Print out the number or arguments argc
  cout << "The value stored in argc is " << argc << "." << endl;
  
  // Print out the user name input from command-line arguments 
  cout << "Student Full name: " << argv[1] << " " << argv[2] << "." << endl; // add argv[2]
  // Print out the input WatIAM from command-line arguments 
  cout << "Student's E-mail address: " << argv[3] << "@uwaterloo.ca" << endl; // change to argv[3]

  return 0;
}

