#include<iostream>

using namespace std;

class Person {
  
private: 
  int age_;

public:
  Person(int age)
  :age_(age)
  {}

  int getAge() const {
    return age_;
  }

  bool operator==(Person other) {
    if(age_ == other.age_){
	  return true;
	}
	return false;
  }

  void setAge(int age) {
    age_ = age;
  }
};

int main(){

  Person p1(11), p2(12);
  if(p1 == p2) {
    cout << "BALKAAAAAAAAAAAAAN!!!!";
  }
}
