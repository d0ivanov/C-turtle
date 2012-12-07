#include "Point.hh"

Point::Point(double x, double y)
	: x_(x), y_(y)
	{}  

std::ostream& operator<<(std::ostream& out, const Point& p) {
  std::cout << "Point(" << p.getX() << "," << p.getY() << ")" << std::endl;
  return out;
}
