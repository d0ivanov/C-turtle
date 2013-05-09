#include<iostream>
using namespace std;

class Point{
  double x_, y_;

public:
  Point(double x=0.0, double y=0.0)
  :x_(x), y_(y)
  {}

  double get_x() const {
    return x_;
  }

  double get_y() const {
    return y_;
  }

  void print() const;
  Point& add(const Point& other);
  Point& sub(const Point& other);
  Point& operator+=(const Point& other);
};

void Point::print() const{
  cout << "P(" << x_ << ","<< y_ << ")" << endl;
}

Point& Point::add(const Point& other){
  x_+=other.x_;
  y_+= other.y_;
  return *this;
}

Point& Point::sub(const Point& other){
  x_-=other.x_;
  y_-=other.y_;
  return *this;
}

Point& Point::operator+=(const Point& other){
  x_+=other.x_;
  y_+=other.y_;
  return *this;
}

Point operator+(const Point& p1, const Point &p2){
  Point p(p1.get_x()+p2.get_x(),
          p1.get_y()+p2.get_y());
  return p;
}

Point operator-(const Point& other){
  Point p(-other.get_x(), -other.get_y());
  return p;
}

ostream& operator<<(ostream& out, const Point& p){
  out << '(' << p.get_x() << ',' << p.get_y() << ')';
  return out;
}

int main(){
  Point p1(1,1), p2(2,2);

  p1.sub(p2);
  p1.print();
  p2 = p1+p2;
  cout << p1 << endl;
  Point p4 = -p2;
  p4.print();
  return 0;
}
