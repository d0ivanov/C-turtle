#include <iostream>

using namespace std;

class Point {
	private:
	
	double x_, y_;
	
	public:
	
	Point(double x, double y){
		x_ = x;
		y_ = y;	
	}
	
	Point() {
		x_ = 0.0;
		x_ = 0.0;	
	}
	
	double getX(){
		return x_;	
	}
	
	double getY(){
		return y_;	
	}
	
	void setX(double x){
		x_ = x;	
	}
	
	void setY(double y){
		y_ = y;	
	}
	
	void add(Point p){
		x_ += p.x_;
		y_ += p.y_;	
	}
	
	void sub(Point p){
		x_ -= p.x_;
		y_ -= p.y_;	
	}
	
	void mul(double a){
		x_ *= a;
		y_ *= a;	
	}
	
	void dump(){
		cout << "(" << x_ << ", " << y_ << ")" << endl;	
	}
};

Point sum(Point p1, Point p2) {
	p1.add(p2);
	return p1;		
}

Point sub( Point p1, Point p2 ){
	
	p1.sub(p2);
	return p1;	
}

int main() {
	Point p1(10,20), p2(30,40);
	
	p1.dump();
	p2.dump();
	p1.add(p2);
	p1.sub(p2);
	p1.dump();
	p2.dump();
	p1.mul(2);
	p1.dump();
	
	Point p;
	p = sum(p1, p2);
	p1.dump();
	p2.dump();
	p.dump();
	p1.dump();
	
	return 0;	
}