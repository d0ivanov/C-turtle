#include<iostream>
#include<list>

using namespace std;

class Shape {
  public:
    virtual void draw() const = 0;
  
};

class Point {
  private:
    double x_;
	double y_;
  public:
    
	double get_x() const {
	  return x_;  
	}

	void set_x(double x) {
	  x_ = x;
	}

	double get_y() const {
	  return y_;
	}

	void set_y(double y) {
	  y_ = y;  
	}
};

class Circle: public Shape {
  private:
    Point c;
	double r_;

  public:
    Circle(const Point &c, double r)
	: c_(c), r_(r)
	{}

	void draw() const {
	  cout << "Circle(" << c_ << "," << r_ ")" << endl;  
	}
}


ostream& operator<< () {
  
}

class Rectangle: public Shape {
  private:
    Point orig_;
	double w_;
	double h_;

  public:
    Rectangle(const Point& p, double w, double h)
	: orig_(p), w_(w), h_(h)
	{}

	void draw() const {
	  cout << "Rectangle(" << orig_ << "," << w_ << "," << h_ <<")" << endl;  
	  
	}
}


int main() {

  Rectangle r(Point(-10, -10), 20, 10);
  Circle c(Point(10, 20), 30);

  list<Shape*> drawing;
  drawing.push_back(&c);
  drawing(&r);

  for(list<Shape*>::iterator it = drawing.begin();
      it != drawing.end(); ++it)  {
	  
	  (*it)->draw();
	}
  
}
