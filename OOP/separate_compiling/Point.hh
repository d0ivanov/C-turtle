#ifndef POINT_HH__
#define POINT_HH__

#include <iostream>


class Point{
  double x_, y_;
  
  public:
    Point(double x, double y);
	
	double getX() const {
	  return x_; 
	}

	double getY() const {
      return y_;
	}
};

std::ostream& operator<<(std::ostream& out , const Point& p);

#endif
