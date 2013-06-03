//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #1
// FILE NAME: main.cc
// FILE PURPOUSE: Main program file.
// Contains the program entry point, e.g. main function
//----------------------------------------------

#include<iostream>
#include "string.hh"

using namespace std;

class ArgumentError{};

int main(int argc, char** argv) {

	//We nead at least 3 arguments passed
	if(argc < 3) {
		throw ArgumentError();
	}
	String str1(argv[1]), str2(argv[2]);
	cout << "String1: " << str1 << endl
			 << "String2: " << str2 << endl
			 << "String1 length: " << str1.length() << endl
			 << "String2 length: " << str2.length() << endl;
	//Counting spaces
	int str1_spaces = 0, str2_spaces = 0;
	for(String::iterator i = str1.begin(); i != str1.end(); i++) {
		if (*i == ' ') {
			str1_spaces++;
		}
	}
	for(String::iterator i = str2.begin(); i != str2.end(); i++) {
		if (*i == ' ') {
			str2_spaces++;
		}
	}
	cout << "String1 spaces: " << str1_spaces << endl
			 << "String2 spaces: " << str2_spaces << endl;
	//Which is grater?
	string compar_result = "";
	if(str1 > str2){
		compar_result = "is grater than";
	} else if(str1 < str2) {
		compar_result = "is lesser than";
	} else if(str1 == str2) {
		compar_result = "is equal to";
	}
	cout << "<" << str1 << "> " << compar_result << " <" << str2 << ">" << endl;
	str1.push_back('!'); str2.push_back('!');
	cout << "String1: " << str1 << endl
			 << "String2: " << str2 << endl;
	String str3 = str1 + str2;
	cout << "Concatenation: <" << str3 << ">" << endl
			 << "Concatenation length " << str3.length() << endl;
	//Concatenation spaces
	int str3_spaces = 0;
	for(String::iterator i = str3.begin(); i != str3.end(); i++) {
		if (*i == ' ') {
			str3_spaces++;
		}
	}
	cout << "Concatenation spaces: " << str3_spaces << endl
			 << "index of '!': " << str3.find_first_of("!", 0) << endl
			 << "substring: " << "<" << str3.substring(12, 4) << ">" << endl;
	return 0;
}
