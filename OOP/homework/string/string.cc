//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #1
// FILE NAME: string.cc
// FILE PURPOUSE: Contains all method implementations
//----------------------------------------------

#include "string.hh"

#include<iostream>
#include<string.h>

using namespace std;

String::String(int capacity)
	:capacity_(capacity),
	 size_(0),
	 buffer_(new char [capacity])
{}

String::String(const char* str)
	:size_(0),
	 capacity_(0),
	 buffer_(0)
{
	size_ = strlen(str);
	capacity_ = size_ + 1;
	buffer_ = new char [capacity_];
	strcpy(buffer_, str);
}

String::String(const String& other)
	:size_(other.size_),
	 capacity_(other.capacity_),
	 buffer_(new char [capacity_])
{
	strcpy(buffer_, other.buffer_);
}
String::~String() {
	delete [] buffer_;
}

int String::size() const {
	return strlen(buffer_);
}

int String::length() const {
	return size();
}

int String::capacity() const {
	return capacity_;
}

bool String::empty() const {
	return size_ == 0;
}

void String::clear() {
	size_ = 0;
	capacity_ = 0;
	delete [] buffer_;
	buffer_ = new char [capacity_];
}

char& String::at(int index) {
	if(index < 0 || index > size_) {
		throw StringError();
	}
	return buffer_[index];
}

void String::resize(int chars) {
	char* temp = buffer_;
	capacity_ += chars;
	buffer_ = new char [capacity_];
	strcpy(buffer_, temp);
	delete [] temp;
}

String& String::append(const String& other) {
	if((size_ + other.size_) >= capacity_) {
		resize(other.length());
	}
	strcat(buffer_, other.buffer_);
	size_+=other.size_;
	return *this;
}

void String::push_back(char ch) {
	if((size_ + 1) >= capacity_) {
		resize(1);
	}
	buffer_[size_++] = ch;
	buffer_[size_] = '\0';
}

int String::find(const String& str, unsigned pos) {
	int overlap = 0;
	for(int i = pos, j = 0; i < size_; i++, j++) {
		while(buffer_[i++] == str[j++]) {
			overlap++;
			if(overlap == (str.size_ -1)) {
				return ++i - str.size_;
			}
		}
		overlap = 0;
		j = -1;
	}
	return -1;
}

int String::find_first_of(const String& str, unsigned pos) {
	for(int i = pos; i < size_; i++) {
		for(int j = 0; j < str.size_; j++) {
			if(buffer_[i] == str[j]) {
				return i;
			}
		}
	}
	return -1;
}

String String::substring(unsigned pos, unsigned n) {
	String str(n);
	str.size_ = n;
	if(pos + n <= size_) {
		for(int i = pos, j = 0; j < n; i++, j++) {
			str[j] = buffer_[i];
		}
		str[str.size_] = '\0';
	}
	return str;
}

String& String::operator=(const String& other){
	if(this != &other) {
		delete [] buffer_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		buffer_ = new char [capacity_];
		strcpy(buffer_, other.buffer_);
	}
}

String& String::operator+=(const String& other) {
	append(other);
}

String String::operator+(const String& other) {
	String str(buffer_);
	str += other;
	return str;
}

char& String::operator[](int index) {
	return at(index);
}

const char& String::operator[](int index) const {
	if(index < 0 || index > size_) {
		throw StringError();
	}
	return buffer_[index];
}

ostream& operator<<(ostream& out, const String& str) {
	for(int i = 0; i < str.size(); i++) {
		cout << str[i];
	}
	return out;
}

bool String::operator==(const String& other) {
	return strcmp(buffer_, other.buffer_) == 0;
}

bool String::operator!=(const String& other) {
	return !operator==(other);
}

bool String::operator>(const String& other) {
	return strcmp(buffer_, other.buffer_) > 0;
}

bool String::operator<(const String& other) {
	return strcmp(buffer_, other.buffer_) < 0;
}

bool String::operator>=(const String& other) {
	return strcmp(buffer_, other.buffer_) >= 0;
}

bool String::operator<=(const String& other) {
	return strcmp(buffer_, other.buffer_) <= 0;
}

String::iterator String::begin() {
	return iterator(*this, 0);
}

String::iterator String::end() {
	return iterator(*this, size_);
}

String::iterator::iterator(String& str, int pos)
	:str_(str),
	 pos_(pos)
{}

String::iterator& String::iterator::operator++() {
	pos_++;
	return *this;
}

String::iterator& String::iterator::operator++(int) {
	++pos_;
	return *this;
}

bool String::iterator::operator==(const String::iterator& other) const {
	return pos_ == other.pos_;
}

bool String::iterator::operator!=(const String::iterator& other) const {
	return !operator==(other);
}

char& String::iterator::operator*() {
	return str_[pos_];
}
