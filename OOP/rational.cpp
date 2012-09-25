#include<iostream>

using namespace std;

class Rational{
	private:
		long n_;
		long d_;
	
	public:
		Rational( long n, long d ){
			n_ = n;
			d_ = d;
			
			normalize();
		}
	
		long gcd( long r, long s ){
			while( s != 0 ){
				long temp = r;
				r = s;
				s = temp % s;			
			}
			return r;
		}

		void normalize(){
			long g = gcd(n_, d_);
			
			if( d_ < 0 ){
				n_ *= -1;
				d_ *= -1;	
			}
			n_ /= g;
			d_ /= g;	
		}
		//n/d
		void add(Rational r){
			n_ = n_*r.d_+r.n_*d_;
			d_ *= r.d_;
			normalize();	
		}
		
		void sub(Rational r){
			n_ = n_*r.d_-r.n_*d_;
			d_ *= r.d_;
			normalize();
			if( n_ == 0 ){
				d_ = 0;
			}
		}		
		
		void div(Rational r){
			n_ *= r.d_;
			d_ *= r.n_;
			
			normalize();
		}
		
		void mul(Rational r){
			n_ *= r.n_;
			d_ *= r.d_;
			
			normalize();
		}
				
		void dump(){
			cout << "R(" << n_ << ", " << d_ << ")" << endl;	
		}
	
};

int main(){
	
	Rational rat1(1, 2), rat2(1, 4);
	
	cout << "add" <<endl;
	rat1.add(rat2);
	rat1.dump();
	
	cout << "subtract" << endl;
	rat1.sub(rat2);
	rat1.dump();
	
	cout << "divide" << endl;
	rat1.div(rat2);
	rat1.dump();
	
	cout << "multiply" << endl;
	rat1.mul(rat2);
	rat1.dump();
	
	
	return 0;	
}
