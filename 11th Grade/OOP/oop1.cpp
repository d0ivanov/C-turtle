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

class Rectangle{
	private:
	
		Point bl_;
		Point ur_;
		
	public:
	
		Rectangle(Point p1, Point p2){
			if (p1.getX() < p2.getX()){
				bl_.setX(p1.getX());
				bl_.setY(p1.getY());
				ur_.setX(p2.getX());
				ur_.setY(p2.getY());
			}else{
				bl_.setX(p2.getX());
				bl_.setY(p2.getY());
				ur_.setX(p1.getX());
				ur_.setY(p1.getY());
			}
		}
		
		Rectangle(double x, double y, double w, double h){
			bl_.setX(x);
			bl_.setY(y);
			ur_.setX(x+w);
			ur_.setY(y+h);
		}
		
		bool isInside(Point p){
			if ( p.getX() > bl_.getX() && p.getX() < ur_.getX() ){
				if (p.getY() > bl_.getY() && p.getY() < ur_.getY()){
					return true;
				}
			}
			return false;
		}		
		
		Rectangle intersect(Rectangle r){
			Rectangle temp(0.0,0.0,0.0,0.0);
			Point bl(0.0, 0.0);
			Point ur(0.0, 0.0);
			
			if (bl_.getX() > r.getBl().getX() ){ // left
				if (bl_.getY() > r.getUr().getY() ){ 
					//ul					
					bl.setX(bl_.getX());
					bl.setY(r.getBl().getY());
					temp.setBl(bl);
					ur.setX(r.getUr().getX());
					ur.setY(ur_.getY());
					temp.setUr(ur);
				}else{
					// bl
					bl.setX(bl_.getX());
					bl.setY(bl_.getY());
					ur.setX(r.getUr().getX());
					ur.setY(r.getUr().getY());
					temp.setBl(bl);
					temp.setUr(ur);
				}
			}else{ // right
				if (bl_.getY() > r.getUr().getY() ){ 
					//ul
					bl.setX(r.getBl().getX());
					bl.setY(r.getBl().getY());
					ur.setX(ur_.getX());
					ur.setY(ur_.getY());
					temp.setBl(bl);
					temp.setUr(ur);
				}else{
					// bl
					bl.setX(r.getBl().getX());
					bl.setY(bl_.getY());
					ur.setX(ur_.getX());
					ur.setY(r.getBl().getX());
					temp.setBl(bl);
					temp.setUr(ur);
				}
			}
		}
		
		void setBl(Point p){
			bl_.setX(p.getX());
			bl_.setY(p.getY());
		}
		
		void setUr(Point p){
			ur_.setX(p.getX());
			ur_.setY(p.getY());
		}
		
		Point getBl(){
			return bl_;
		}
		
		Point getUr(){
			return ur_;
		}
		
		void dump(){
			cout << "blX: "<< bl_.getX() << "blY: " << bl_.getY() <<endl;
			cout << "urX: "<< ur_.getX() << "urY: " << ur_.getY() <<endl;
		}
};

//Point sum(Point p1, Point p2) {
//	p1.add(p2);
//	return p1;		
//}

//Point sub( Point p1, Point p2 ){
//	
//	p1.sub(p2);
//	return p1;	
//}

bool isCorner( Rectangle r1, Rectangle r2 ){
	if (r1.isInside(r2.getBl().getX()))

}

int main() {
	Point blR(1,1), urR(3,3);
	Rectangle R(blR, urR);
	Rectangle r(2, 0, 2, 2);
	Rectangle rRes(0, 0, 0, 0);
	
	rRes = R.intersect(r);
	rRes.dump();v
	
	
	return 0;	
}
