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
			
			bl.setX( max(bl_.getX(), r.getBl().getX()) );
			bl.setY( max(bl_.getY(), r.getBl().getY()) );
			
			ur.setX( min(ur_.getX(), r.getUr().getX()) );
			ur.setY( min(ur_.getY(), r.getUr().getY()) );
			
			temp.setBl(bl);
			temp.setUr(ur);
			
			return temp;
		}
		
		Rectangle rectUnion(Rectangle r){
			Rectangle temp(0,0,0,0);
			Point points[8], bl, ur;
			Point br_, ul_;
			Point rbr_, rul_;
			
			rbr_.setX(r.getUr().getX());
			rbr_.setY(r.getBl().getY());
			rul_.setX(r.getBl().getX());
			rul_.setY(r.getUr().getY());
			
			br_.setX(ur_.getX());
			br_.setY(bl_.getY());
			ul_.setX(bl_.getX());
			ul_.setY(ur_.getY());
			
			points[0] = bl_;
			points[1] = br_;
			points[2] = ur_;
			points[3] = ul_;
			
			points[4] = r.bl_;
			points[5] = rbr_;
			points[6] = r.ur_;
			points[7] = rul_;
			
			bl = points[0];
			ur = points[0];
			for (int i = 0; i < 7; i++){
				if (bl.getX() > points[i].getX()){
					bl.setX(points[i].getX());
				}
				if (bl.getY() > points[i].getY()){
					bl.setY(points[i].getY());
				}
				if (ur.getX() < points[i].getX()){
					ur.setX(points[i].getX());
				}
				if (ur.getY() < points[i].getY()){
					ur.setY(points[i].getY());
				}
			}
			
			temp.setBl(bl);
			temp.setUr(ur);
			
			return temp;
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
			cout << "blX: "<< bl_.getX() << "   blY: " << bl_.getY() <<endl;
			cout << "urX: "<< ur_.getX() << "   urY: " << ur_.getY() <<endl;
		}
};

int main() {
	Point blR(1,1), urR(3,3);
	Rectangle R(blR, urR);
	Rectangle r(2, 0, 2, 2);
	Rectangle rRes(0, 0, 0, 0);
	
	cout << "Rectangle made from intersection: " << endl << endl;
	rRes = R.intersect(r);
	if (R.getBl().getX() == 0 && R.getUr().getX() == 0){
		cout << "Bad coordinates, bad coordinates. No matching found." << endl;
	}else {
		rRes.dump();
	}
	
	cout << endl << "Rectangle made from uniting: " << endl << endl;
	
	rRes = R.rectUnion(r);
	rRes.dump();
	
	return 0;	
}
