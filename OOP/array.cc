#include<iostream>

using namespace std;

class ArrayError{};

class Array {

  private:
    int capacity_;
    int size_;
    int *data_;

  public:
    Array(int size);

    ~Array(void);

    Array(const Array& other);

    const int& operator[] (int index) const;

    Array& operator=(const Array& other);

    int& operator[] (int index);

    int size() const {
      return size_;
    }

    void push_front(int data);
    void push_back(int data);

    void front();
    void back();
};

Array::Array(int size)
  :capacity_(size),
  size_(size),
  data_(new int [capacity_])
{
  for (int i = 0; i < size_; i++){
    data_[i] = 0;
  }
}

Array::~Array(void) {
  delete [] data_;
}

Array::Array(const Array& other)
  :capacity_(other.capacity_),
   size_(other.size_),
   data_(new int [capacity_])
{
  for (int i = 0; i < other.size(); ++i){
    data_[i] = other[i];
  }
}

const int& Array::operator[](int index) const {
  if(index < 0 || index >=size_) {
    throw ArrayError();
  }
  return data_[index];
}

int& Array::operator[](int index) {
  if(index < 0 || index >= size_) {
    throw ArrayError();
  }
  return data_[index];
}

Array& Array::operator=(const Array& other) {
  if(this != &other) {
    delete [] data_;

    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = new int [size_];

    for(int i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }
}

void Array::push_front(int data) {
 int temp[size_];
  for (int i = 0; i < size_; ++i){
    temp[i] = data_[i];
  }
  data_ = new int [capacity_ + 1];
  size_ += 1;
  capacity_ += 1;
  data_[0] = data;
  for (int i = 1; i < size_; i++) {
    data_[i] = temp[i-1];
  }
}

void Array::push_back(int data) {
 int temp[size_];
  for (int i = 0; i < size_; ++i){
    temp[i] = data_[i];
  }
  data_ = new int [capacity_ + 1];
  size_ += 1;
  capacity_ += 1;
  for (int i = 0; i < size_; i++) {
    data_[i] = temp[i];
  }
  data_[size_] = data;
}

void dump(const Array& a) {
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
  }
}

int main() {
  Array a(20);
  dump(a);
  Array b(20);
  Array c(20);

  b = a;
  dump(b);
}

