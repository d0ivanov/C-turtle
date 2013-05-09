#include<iostream>
#include "string.hh"

using namespace std;

class ArgumentError{};

int main(int argc, char** argv) {

	if(argc < 3) {
		throw ArgumentError();
	}

	String str1(argv[1]), str2(argv[2]);
	cout << "String1: " << str1 << endl
			 << "String2: " << str2 << endl
			 << "String1 length: " << str1.length() << endl
			 << "String2 length: " << str2.length() << endl
			 << "String1 spaces: " << "not implemented" << endl
			 << "String2 spaces: " << "not implemented" << endl;
	string compar_result = "";
	if(str1 > str2){
		compar_result = "is grater than";
	} else {
		compar_result = "is lesser than";
	}
	cout << "<" << str1 << "> " << compar_result << " <" << str2 << ">" << endl;
	str1.push_back('!'); str2.push_back('!');
	cout << "String1: " << str1 << endl
			 << "String2: " << str2 << endl
			 << "Concatenation: <" << (str1+str2) << ">" << endl
			 << "Concatenation length " << (str1+str2).length() << endl;
	return 0;
}
