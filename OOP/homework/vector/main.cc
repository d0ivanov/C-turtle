//--------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XIb
// NUMBER: 15
// PROBLEM: #2
// FILE NAME: vector.cc
// FILE PURPOSE: contains program entry point
//---------------------------------------------

#include "vector.hh"
#include "vector.cc"
#include <iostream>
#include <cstdlib>

using namespace std;

//--------------------------
// function: dump_vec
// 	Prints the vector elements
// 	on screen
// parameters: Vector<T>
// 	the vector to print
// 	string name of the vector
// 	that will be printed before
// 	the elements
//--------------------------
template <class T>
void dump_vec(Vector<T>& vec, string vec_name) {
	cout << vec_name << ": {";
	for(typename Vector<T>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << ",";
	}
	cout << "}" << endl;
}

int main(int argc, char** argv) {

	if(argc < 4) {
		cout << "Not enough arguments!" << endl;
		return 0;
	}

	Vector<int> v1(5), v2(5);

	for(int i = atoi(argv[1]); i < atoi(argv[2]); i++){
		v1.push_back(i);
	}

	for(int i = atoi(argv[3]); i < atoi(argv[4]); i++){
		v2.push_back(i);
	}

	dump_vec<int>(v1, "v1");
	dump_vec<int>(v2, "v2");

	int eql_elems = 0;
	for(Vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		for(Vector<int>::iterator it2 = v2.begin(); it2 != v2.end(); it2++) {
			if(*it == *it2)
				eql_elems++;
		}
	}
	cout << "Equal elements in v1 and v2: " << eql_elems << endl;

	v1.push_back(-100);
	v2.push_back(-100);

	dump_vec<int>(v1, "v1");
	dump_vec<int>(v2, "v2");

	Vector<int>v(v2);
	dump_vec<int>(v, "v");

	for(Vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++) {
		v.insert(v.begin(), *it);
	}
	dump_vec<int>(v, "v");

	Vector<int>::iterator bit = v.begin();
	for(bit = v.begin(); bit != v.end(); bit++) {
		if(*bit == -100) {
			break;
		}
	}

	v.erase(bit, v.end());
	dump_vec<int>(v, "v");
	return 0;
}
