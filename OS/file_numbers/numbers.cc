#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

int main() {
  int i = 0, total = 0, input = 0;
  string search;
  ifstream infile("test.txt");

  cout << "tursi: ";
  cin >> &search;

  while (infile >> input) {
    string buff;
    i++;
    total += input;
  }
  cout << "Sredno arit: " << total/i << endl;
  return 0;
}
