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
		
		Point lineIntersect(Point p1, Point p2, Point p3, Point p4) {
			double x1 = p1.getX(), x2 = p2.getX(), x3 = p3.getX(), x4 = p4.getX();
			double y1 = p1.getY(), y2 = p2.getY(), y3 = p3.getY(), y4 = p4.getY();
 			Point p(-1.0, -1.0);
			double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
			if (d == 0) return p;
			
			float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
			float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
			float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
				 
		    if ( x < min(x1, x2) || x > max(x1, x2) ||
				 x < min(x3, x4) || x > max(x3, x4) ) return p;
			if ( y < min(y1, y2) || y > max(y1, y2) ||
				 y < min(y3, y4) || y > max(y3, y4) ) return p;
				 
			p.setX(x);
			p.setY(y);
			return p;
		}
		
		Rectangle intersect(Rectangle r){
			//na ugul gore vlqvo
			Point ip = lineIntersect(r.bl_, r.br_, ul_, bl_);
			Point ip2 = lineIntersect(r.ur_, r.br_, ul_, ur_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
				r.bl_.setX(ip.getX());
				r.bl_.setY(ip.getY());
				r.ur_.setX(ip2.getX());
				r.ur_.setY(ip2.getY());
				r.calcPoints();
				return r;
			}
			//po sredata otgore
			ip = lineIntersect(ul_, ur_, r.ul_, r.bl_);
			ip2 = lineIntersect(ul_, ur_, r.ur_, r.br_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
				r.ur_.setX(ip2.getX());
				r.ur_.setY(ip2.getY());
				r.bl_.setX(ip.getX());
				r.bl_.setY(ip.getY());
				r.calcPoints();
				return r;
			}
			//na ugul gore vdqsno
			ip = lineIntersect(r.ul_, r.bl_, ul_, ur_);
			ip2 = lineIntersect(r.bl_, r.br_, ur_, br_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
			
				r.ur_ = ur_;
				r.calcPoints();
				return r;
			}
			//po sredata otdqsno
			ip = lineIntersect(ur_, br_, r.ul_, r.ur_);
			ip2 = lineIntersect(ur_, br_, r.bl_, r.br_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
			
				r.ur_.setX(ip.getX());
				r.ur_.setX(ip.getY());
				r.calcPoints();
				return r;
			}
			//na ugul dolu vdqsno
			ip = lineIntersect(ur_, br_, r.ur_, r.ul_);
			ip2 = lineIntersect(br_, bl_, r.ul_, r.bl_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
			
				r.bl_.setX(ip2.getX());
				r.bl_.setY(ip2.getY());
				r.ur_.setX(ip.getX());
				r.ur_.setY(ip.getY());
				r.calcPoints();
				return r;
			}
			//po sredata otdolu
			ip = lineIntersect(br_, bl_, r.br_, r.ur_);
			ip2 = lineIntersect(br_, bl_, r.ul_, r.bl_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
			
				cout << r.bl_.getX() <<r.bl_.getY()<<endl;
				cout << r.ur_.getX() <<r.ur_.getY()<<endl;
				r.bl_.setX(ip2.getX());
				r.bl_.setY(ip2.getY());
				r.calcPoints();
				return r;
			}
			//na ugul dolu vlqvo
			ip = lineIntersect(bl_, br_, r.ur_, r.br_);
			ip2 = lineIntersect(bl_, ul_, r.ul_, r.ur_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
			
				r.bl_ = bl_;
				r.calcPoints();
				return r;
			}
			//po sredata otlqvo
			ip = lineIntersect(bl_, ul_, r.bl_, r.br_);
			ip2 = lineIntersect(bl_, ul_, r.ul_, r.ur_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(isInside(r.bl_) || isInside(r.br_) || isInside(r.ur_) || isInside(r.ul_))){
			
				r.bl_.setX(ip.getX());
				r.bl_.setY(ip.getY());
				r.calcPoints();
				return r;
			}
			//presi4a na krust m/u ur i br
			ip = lineIntersect(ur_, br_, r.ul_, r.ur_);
			ip2 = lineIntersect(ur_, br_, r.bl_, r.br_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(!isInside(r.bl_) && !isInside(r.br_) && !isInside(r.ur_) && !isInside(r.ul_)) ){
				
				r.ur_.setX(ip.getX());
				r.ur_.setY(ip.getY());
				ip2 = lineIntersect(ul_, bl_, r.bl_, r.br_);
				r.bl_.setX(ip2.getX());
				r.bl_.setY(ip2.getY());
				r.calcPoints();
				return r;
			}
			//presi4a na krust m/u ul i ur
			ip = lineIntersect(bl_, br_, r.ul_, r.bl_);
			ip2 = lineIntersect(ul_, ur_, r.ur_, r.br_);
			if( (ip.getX() > 0 && ip.getY() > 0) && (ip2.getX() > 0 && ip2.getY() > 0) &&
				(!isInside(r.bl_) && !isInside(r.br_) && !isInside(r.ur_) && !isInside(r.ul_)) ){
				r.bl_.setX(ip.getX());
				r.bl_.setY(ip.getY());
				r.ur_.setX(ip2.getX());
				r.ur_.setY(ip2.getY());
				r.calcPoints();
				return r;
			}
			if( isInside(r.bl_) && isInside(r.ur_) ){
				cout << "Dvata pravougulnika sa 1 v drug!" << endl;
			}
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
