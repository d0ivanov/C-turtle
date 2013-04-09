#include<iostream>

using namespace std;

class ArrayError{};

class Array {

  private:
    int capacity_;
    int size_;
    int *data_;

  private:
    void resize();

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

    void push_back(int data);
    void pop_front(int data);

    int front() const;
    int back() const;

  public:
    class iterator {
      private:
          Array& array_;
          int pos_;

      friend class Array;
      private:
        iterator(Array& array, int pos)
          : array_(array),
            pos_(pos)
        {}

      public:

         iterator& operator++(){
          pos_++;
          return *this;
         }

         iterator& operator++(int){
          //hw
          pos_++;
          return *this;
         }

         int& operator*() {
          return array_[pos_];
         }

         bool operator==(const iterator& other) const {
          return pos_ == other.pos_;
         }

         bool operator!=(const iterator& other) const {
          return pos_ != other.pos_;
         }
    };

    iterator begin() {
      return iterator(*this, 0);
    }

    iterator end() {
      return iterator(*this, size());
    }

    //hw
    const_interator begin() const;
    const_iterator end() const;

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

void Array::resize(){
  int* temp = data_;
  capacity_ *= 2;
  data_ = new int [capacity_];
  for(int  i = 0; i < size_; i++) {
    data_[i] = temp[i];
  }

  delete [] temp;
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

void Array::push_back(int val) {
  if(size_ >= capacity_) {
    resize();
  }
  data_[size_++] = val;
}

int Array::back() const {
  return data_[size_-1];
}

int Array::front() const {
  return data_[0];
}

void dump(const Array& a) {
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
  }
}

int main() {

}

