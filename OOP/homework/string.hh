#ifndef STRING_HH_
#define STRING_HH_

#include<iostream>

using namespace std;

class StringError{};

class String {
	private:
		int capacity_;
		int size_;
		char *buffer_;
	public:
		String(int capacity);
		String(const char* str);
		String(const String& other);
		~String();

		int size() const;
		int length() const;
		int capacity() const;
		bool empty() const;
		void clear();
		char& at(int index);

		String& append(const String& other);
		void push_back(char ch);
		unsigned find(const String& str, unsigned pos);
		unsigned find_first_of(const String& str, unsigned pos);
		String substring(unsigned pos, unsigned n);

		String& operator=(const String& other);
		String& operator+=(const String& other);
		String operator+(const String& other);
		friend ostream& operator<<(ostream& out, const String& str);
		char& operator[](int index);
		const char& operator[](int index) const;
		bool operator==(const String& other);
		bool operator!=(const String& other);
		bool operator<(const String & other);
		bool operator>(const String & other);
		bool operator<=(const String & other);
		bool operator>=(const String & other );

		class iterator {
			friend class String;
			private:
				int pos_;
				String& str_;
				iterator(String& str, int pos_);
			public:
				iterator& operator++();
				iterator& operator++(int);
				bool operator==(const iterator& other) const;
				bool operator!=(const iterator& other) const;
				char& operator*();
		};

		iterator begin();
		iterator end();
	private:
		void resize(int chars);
};

#endif
