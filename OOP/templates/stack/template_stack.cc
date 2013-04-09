#include<iostream>

using namespace std;

class StackError {};

template<typename T>
class Stack{

  private:
    static const int CHUNK = 10;

    int size_;
    int top_;
    T* data_;

    bool full() {
      return size_ == top_;
    }

    void resize() {
      T* old_data = data_;
      size_ += CHUNK;
      data_ = new T[size_];

      for(int i = 0; i < size_; i++){
        data_[i] = old_data[i];
      }
      delete [] old_data;
    }

  public:

    Stack()
      : top_(0),
        size_(CHUNK),
        data_(new T[size_])
    {}

    ~Stack(){
      delete [] data_;
    }

    Stack(const Stack& other);

    bool empty() const {
      return top_ == 0;
    }

    void push(T val) {
      if(full())
        resize();
      data_[top_++] = val;
    }

    T pop() {
      if(empty()) {
        throw StackError();
      }
      return data_[--top_];
    }

    int capacity() const;

    Stack& operator=(const Stack& other);

};

template<typename T>
int Stack<T>::capacity() const {
  return size_;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other) {
  size_ = other.size_;
  top_ = other.top_;
  data_ = new T[size_];

  for(int i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {

  if(&other != this){
    delete [] data_;
    size_ = other.size_;
    top_ = other.top_;
    data_ = new T[size_];

    for(int i = 0; i < size_; i++) {
      data_[i] = other.data_[i];
    }
  }

  return *this;
}

int main() {

  Stack<int> st1;
  Stack<int> st3;
  Stack<double> st2;

  cout << "st1.empty() " << st1.empty() << endl;
  cout << "st2.empty() " << st2.empty() << endl;

  st1.push(1);
  st2.push(3.14);

  cout << "st1.empty() " << st1.empty() << endl;
  cout << "st2.empty() " << st2.empty() << endl;

  cout << "st1.pop() " << st1.pop() << endl;
  cout << "st2.pop() " << st2.pop() << endl;

  for(int i = 0; i < 200; i++){
    st1.push(i);
    st2.push(i*2.34);
  }

  st3 = st1;


  return 0;
}
