#ifndef CIRCLE_CLASS_H
#define CIRCLE_CLASS_H

class Circle{
  private:
    double radius;
    double *ptr;
  public:
    Circle();
    Circle(double initValue);
	  ~Circle();
    double area();
    double circumference();
	void setRadius(double value);
	double getRadius();
};

#endif