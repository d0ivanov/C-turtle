#include<iostream>

using namespace std;

template<typename T>
void copy1(T dst[], T src[], int size) {
  for(int i = 0; i < size; i ++) {
    dst[i] = src[i];
  }
}

int main() {

  int a [10] = {1,2,3,4,5,6,7,8,9,10}, b[10];
  double c[10] = {1.2,3.2,4.2,5.2,6.2,7.2,8.2,9.2,1.3,4.5}, d[10];

  copy1<int>(b, a, 10);
  copy1<double>(d, c, 10);

  for(int i = 0; i < 10; i++) {
    cout << "a[" << i << "]=" << a[i] << "\td[" << i << "]=" << d[i] << endl;
  }

  return 0;
}
