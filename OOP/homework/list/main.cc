//--------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XIb
// NUMBER: 15
// PROBLEM: #3
// FILE NAME: main.cc
// FILE PURPOSE: contains program entry point
//---------------------------------------------

#include "list.cc"
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
void dump(List<T>& l, string name) {
	cout << name << ": {";
	for(typename List<T>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << ",";
	}
	cout << "}" << endl;
}


int main(int argc, char** argv) {

	if(argc < 4) {
		cout << "Not enough arguments!" << endl;
		return 0;
	}

	List<int> l1(0), l2(0);

	for(int i = atoi(argv[1]); i < atoi(argv[2]); i++){
		l1.push_back(i);
	}

	for(int i = atoi(argv[3]); i < atoi(argv[4]); i++){
		l2.push_back(i);
	}

	dump<int>(l1, "l1");
	dump<int>(l2, "l2");

	int eq_elems = 0;

	for(typename List<int>::iterator it1 = l1.begin(); it1 != l1.end(); it1++) {
		for(typename List<int>::iterator it2 = l2.begin(); it2 != l2.end(); it2++) {
			if(*it1 == *it2) {
				eq_elems++;
			}
		}
	}

	cout << "Equal elements in l1 and l2: " << eq_elems << endl;

	l1.push_back(-100);
	l2.push_back(-100);

	dump<int>(l1, "l1");
	dump<int>(l2, "l2");

	List<int> l(l2);
	dump<int>(l, "l");

	for(typename List<int>::reverse_iterator it = l1.rbegin(); it != l1.rend(); it++) {
		l.push_front(*it);
	}

	dump<int>(l, "l");

	typename List<int>::iterator bit = l.begin();
	for(; bit != l.end(); bit++) {
		if(*bit == -100) {
			break;
		}
	}
	l.erase(bit, l.end());
	dump<int>(l, "l");

	return 0;
}
