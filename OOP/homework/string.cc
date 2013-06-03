#include "string.hh"

#include<iostream>
#include<string.h>

using namespace std;

String::String(int size)
	:size_(size),
	 capacity_(size + 1),
	 buffer_(new char [capacity_])
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
	capacity_ = 10;
	delete [] buffer_;
	buffer_ = new char [capacity_];
}

char& String::at(int index) {
	return buffer_[index];
}

void String::resize(int chars) {
	char* temp = buffer_;
	capacity_ += chars;
	buffer_ = new char [capacity_];
	for(int i = 0; i < (size_ + 1); i++) {
		buffer_[i] = temp[i];
	}
	delete [] temp;
}

String& String::append(const String& other) {
	if(other.length() > capacity_) {
		resize(other.length() + 1);
	}

	for(int i = size_, n = 0; n < other.size(); i++, n++) {
		buffer_[i] = other[n];
	}
	return *this;
}

void String::push_back(char ch) {
	if(capacity_ < (size_ + 2)) {
		resize(1);
		capacity_++;
	}
	buffer_[size_] = ch;
	buffer_[size_ + 1] = '\0';
	size_++;
}

unsigned String::find(const String& str, unsigned pos) {
	for(int i = pos, n = 0; i < size_; i++) {
		while(buffer_[i++] == str[n++]) {
			if(n == str.length())
				return i;
		}
		n = 0;
	}
	return -1;
}

unsigned String::find_first_of(const String& str, unsigned pos) {
	for(int i = pos; i < size_; i++) {
		for(int n = 0; n < str.length(); n++) {
			if(buffer_[i] == str[n])
				return i;
		}
	}
	return -1;
}

String String::substring(unsigned pos, unsigned n) {
	String str(n);
	if( pos >= 0 && pos < size_ && n > 0 && n < size_ ) {
		for(int i = pos, n = 0; i < n; i++, n++) {
			str[n] = buffer_[i];
		}
	}
	str[str.capacity_] = '\0';
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
	String str(size() + other.size());
	for(int i = 0; i < size(); i++) {
		str.buffer_[i] = buffer_[i];
	}
	for(int i = str.size(), n = 0; n < other.size(); i++, n++) {
		str.buffer_[i] = other.buffer_[n];
	}
	return str;
}

char& String::operator[](int index) {
	if(index > size_ || index < 0)
		throw StringError();
	return buffer_[index];
}

const char& String::operator[](int index) const {
	if(index > size_ || index < 0)
		throw StringError();
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
