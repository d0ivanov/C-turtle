#include <iostream>
using namespace std;

class Rational{

  long n_, d_;

  public:

    Rational(long num=0, long den=1)
	:n_(num), d_(den){
	  normalize();
	}

	long getN() const {
	  return n_;
	}

	long getD() const {
	  return d_;
	}

    long gcd(long r, long s);
	void normalize();
	void add(const Rational& r);
	void subtract(const Rational& r);
	void divide(const Rational& r);
	void multiply(const Rational& r);
	void dump();
	Rational& operator+=(const Rational& other);
	Rational& operator-=(const Rational& other);

	Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

};

long Rational::gcd(long r, long s){
  while( s != 0  ){
    long temp = r;
	r = s;
	s = temp % s;
  }
  return r;
}
void Rational::normalize(){
  long g = gcd(n_, d_);
  if(d_ < 0){
    n_ *= -1;
	d_ *= -1;
  }
  n_ /= g;
  d_ /= g;
}
void Rational::add(const Rational& r){
  n_ = n_*r.d_+r.n_*d_;
  d_ *= r.d_;
}
void Rational::subtract(const Rational& r){
  n_ = n_*r.d_-r.n_*d_;
  d_ *= r.d_;
  normalize();
  if(n_ == 0){
	d_ = 0;
  }
}
void Rational::divide(const Rational& r){
  n_ *= r.d_;
  d_ *= r.d_;

  normalize();
}

void Rational::multiply(const Rational& r){
  n_ *= r.n_;
  d_ *= r.d_;

  normalize();
}

void Rational::dump(){
  cout << n_ << "/" << d_ << endl;
}

Rational& Rational::operator+=(const Rational& other){
  add(other);
  return *this;
}
Rational& Rational::operator-=(const Rational& other){
  subtract(other);
  return *this;
}

Rational& Rational::operator*=(const Rational& other){
  multiply(other);
  return *this;
}

Rational& Rational::operator/=(const Rational& other ){
  divide(other);
  return *this;
}

Rational operator+(Rational& r1, const Rational& r2){
 r1 += r2;
 return r1;
}

Rational operator-(Rational& r1, const Rational& r2){
  r1 -= r2;
  return r1;
}

Rational operator*(Rational& r1, const Rational& r2){
  r1 *= r2;
  return r1;
}
Rational operator/(Rational& r1, const Rational& r2){
  r1 /= r2;
  return r1;
}

bool operator==(Rational& r1, Rational& r2){
  if( r1.getN() == r2.getN() && r1.getD() == r2.getD() ){
    return true;
  }
  return false;
}

bool operator!=(Rational& r1, Rational& r2){
  if(r1 == r2){
    return false;
  }
  return true;
}

bool operator>(Rational& r1, Rational& r2){
  r1.normalize();
  r2.normalize();
  if(r1.getN() > r2.getN()){
    return true;
  }
  return false;
}

bool operator<(Rational& r1, Rational& r2){
  if(r1 > r2){
    return false;
  }
  return true;
}

bool operator>=(Rational& r1, Rational r2){
  if(r1 > r2 || r1 == r2){
    return true;
  }
  return false;
}

bool operator<=(Rational& r1, Rational r2){
  if(r1 < r2 || r1 == r2){
    return true;
  }
  return false;
}


int main(){


  return 0;
}
