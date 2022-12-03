#include "circleClass.h"
#include <cmath>

Circle::Circle(){ 
    // constructor
    radius = 0;
    ptr = new double [10];
}

Circle::~Circle(){
    // destructor
    delete ptr;
}

Circle::Circle(double init){
    // instantiate
    radius = init;
}

double Circle::area(){
    // functions
    return M_PI*pow(radius, 2);
}

double Circle::circumference(){
    return M_PI*2*radius;
}

void Circle::setRadius(double value){
    radius = value;
}

double Circle::getRadius(){
    return radius;
}
