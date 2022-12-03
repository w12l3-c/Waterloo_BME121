#include <iostream>
using namespace std;

// DECLARATION OF ENUMERATED DATA TYPE 
// Note: By default, the seven labels of the enum type are respectively assigned
//		 the values: SUN = 0, MON = 1, TUE = 2, WED = 3, 
//					 THU = 4, FRI = 5, SAT = 6
enum DayType { SUN, MON, TUE, WED, THU, FRI, SAT };

// SAMPLE CODE FOR LISTING NOVEMBER'S BME 121 SCHEDULE
int main (){
	// 1. Define a constant enum variable called FIRST_DAY
	//    (assigned value is first day of Nov 2017, i.e. Wed)
	const DayType FIRST_DAY = WED; // Fill in the week of the day for Nov 1st
	
	// 2. Set up a for-loop to count through 30 days of the month
	for ( int day = 1; day <= 30; day++ ){
		
		// 3. Find out the name of the current day
		// ** Notes: a) an enum variable need to be typecasted first before using
		//			    its value for fixed-point arithmetic
		// 			 b) a fixed-point arithmetic result needs to be typecasted into
		//				the enum data type in order to match it to one of the labels
		int dayInWeek = ( day - 1 + (int)FIRST_DAY)%7;
		DayType dayName = (DayType)dayInWeek;

		// 4. Output the current date and use a switch statement to output the
		//    the corresponding day schedule for BME 121
		cout << "Nov " << day << ": ";
		switch (dayName){
			case SAT: case SUN:
				cout << "Weekend!";
				break;
			case MON:
				cout << "BME 121 Class";
				break;
			case TUE: case THU:
				cout << "No Class for BME 121";
				break;
			case WED:
				cout << "BME 121 Lab";
				break;
			case FRI:
				cout << "BME 121 Class";
				break;
			default:
				cerr << "Invalid day" << endl;
				return -1;
		}
		cout << endl;
	} 
	// End of for loop
	
	return 0;
}
