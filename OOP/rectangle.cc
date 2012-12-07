#include<iostream>
#include<algorithm>

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
			y_ = 0.0;	
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
		Point ul_;
		Point br_;
	public:
		Rectangle( Point p1, Point p2 ){
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
			
			calcPoints();
		}
		
		Rectangle( double x, double y, double h, double w ){
			bl_.setX(x);
			bl_.setY(y);
			ur_.setX(x+w);
			ur_.setY(y+h);
			
			calcPoints();
		}
		
		void setBl(Point bl){
			bl_ = bl;
		}
		
		void setUr(Point ur){
			ur_ = ur;
		}
		
		Point getBl(){
			return bl_;
		}
		
		Point getUr(){
			return ur_;
		}
		
		void calcPoints(){
			br_.setX(ur_.getX());
			br_.setY(bl_.getY());
			ul_.setX(bl_.getX());
			ul_.setY(ur_.getY());
		}
		
		bool isInside(Point p){
			if( p.getY() >= bl_.getY() && p.getY() <= ur_.getY() ){
				if( p.getX() >= bl_.getX() && p.getX() <= ur_.getX() ){
					return true;
				}
			}
			return false;
		}
				
		Rectangle intersect(Rectangle r){
			Rectangle temp(0.0,0.0,0.0,0.0);
			Point bl(0.0, 0.0);
			Point ur(0.0, 0.0);

			bl.setX( max(bl_.getX(), r.getBl().getX()) );
			bl.setY( max(bl_.getY(), r.getBl().getY()) );

			ur.setX( min(ur_.getX(), r.getUr().getX()) );
			ur.setY( min(ur_.getY(), r.getUr().getY()) );

			temp.setBl(bl);
			temp.setUr(ur);

			return temp;
		
		}
		
		Rectangle unite(Rectangle r){
			Point bl, ur;
			bl = bl_;
			ur = ur_;
			if(bl_.getX() > r.bl_.getX()){
				bl.setX(r.bl_.getX());
			}
			if(bl_.getY() > r.bl_.getY()){
				bl.setY(r.bl_.getY());
			}
			if(ur_.getX() < r.ur_.getX()){
				ur.setX(ur_.getX());
			}
			if(ur_.getY() < r.ur_.getY()){
				ur.setY(r.ur_.getY());
			}
			Rectangle rect(bl, ur);
			return rect;
		}
		
		void dump(){
			cout << "bl(x):" << bl_.getX() << "bl(y)" << bl_.getY() << "ur(x)" << ur_.getX() << "ur(Y)" << ur_.getY() << endl;
		}
};

int main(){
	
	Point p, p1(3.0, 3.0), p2(6.0, 6.0), p3(1.0, 8.0), p4(16.0, 16.0);
	Rectangle r1(p1, p2);
	Rectangle r2(p3, p4);
	Rectangle r = r1.unite(r2);
	r.dump();
	return 0;
}
