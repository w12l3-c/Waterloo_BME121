#include <iostream>
#include "circleClass.h"
using namespace std;

int main(){
	Circle x[3];
	x[0].setRadius(2);
	x[1].setRadius(3);
	x[2].setRadius(6);
	x[0].setRadius( x[1].getRadius() + x[2].getRadius() );
	
	cout << "The area of a circle with radius of 2 is " << x->area() << endl;
	// x->area here is equivilent to x[0].area();
}
