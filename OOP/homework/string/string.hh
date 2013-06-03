//----------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XI B
// NUMBER: 15
// PROBLEM: #1
// FILE NAME: string.hh
// FILE PURPOUSE: Holds all class and method declarations
//----------------------------------------------

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
		//----------------------------------------------
		// FUNCTION: class constructor
		// PARAMETERS:
		// 	int capacity of the new string
		//----------------------------------------------
		String(int capacity);
		
		//----------------------------------------------
		// FUNCTION: class constructor
		// PARAMETERS:
		// 	const char* c-string with which we would like
		// 	to construct the class
		//----------------------------------------------
		String(const char* str);
		
		//----------------------------------------------
		// FUNCTION: copy constructor
		// PARAMETERS:
		// 	String& the string to copy
		//----------------------------------------------
		String(const String& other);
		
		//----------------------------------------------
		// FUNCTION: destructor
		//	free all alocated memory, thus destroying
		//  the object
		// PARAMETERS:
		// NONE
		//----------------------------------------------
		~String();

		//----------------------------------------------
		// FUNCTION: size
		// 	Const method. Getter for the size_ member-variable
		// PARAMETERS:
		// NONE
		//----------------------------------------------
		int size() const;
		
		//----------------------------------------------
		// FUNCTION: length
		// 	Equivalent to size()
		// PARAMETERS:
		// NONE
		//----------------------------------------------
		int length() const;
		
		//----------------------------------------------
		// FUNCTION: capacity
		// 	Const method. Getter for the capacity_ member-variable
		// PARAMETERS:
		// NONE
		//----------------------------------------------
		int capacity() const;
		
		//----------------------------------------------
		// FUNCTION: empty
		// 	Const method. Check if string is empty
		// PARAMETERS:
		// NONE
		// RETURNS:
		//	true if string is empty
		//	false otherwise
		//----------------------------------------------
		bool empty() const;
		
		//----------------------------------------------
		// FUNCTION: clear
		// 	Clear the string, thus making it an empty string.
		// PARAMETERS:
		// NONE
		//----------------------------------------------
		void clear();
		
		//----------------------------------------------
		// FUNCTION: at
		// 	Get the character at a given index
		// PARAMETERS:
		// 	int index of wanted character
		// RETURNS:
		//	reference to the character found
		// ERRORS:
		//	throws an instance of StringError if index is not valid
		//----------------------------------------------
		char& at(int index);

		//----------------------------------------------
		// FUNCTION: append
		// 	Adds given string to the tail of the current
		// PARAMETERS:
		// 	const String& the string to be added
		// RETURNS:
		//	Reference to self
		//----------------------------------------------
		String& append(const String& other);
		
		//----------------------------------------------
		// FUNCTION: push_back
		// 	Push single character at the end of the string
		// PARAMETERS:
		// 	char the character to be pushed
		// RETURNS:
		// 	void
		//----------------------------------------------
		void push_back(char ch);
		
		//----------------------------------------------
		// FUNCTION: find
		// 	Searches for the substring str, starting from
		//  position pos.
		// PARAMETERS:
		// 	const String& the substring to search
		//	unsigned position to start from
		// RETURNS:
		//	the index of the first substring found
		//	-1 if substring not found
		//----------------------------------------------
		int find(const String& str, unsigned pos);
		
		//----------------------------------------------
		// FUNCTION: find_first_of
		// 	Searches for the first occurance of any character
		//  in the given substring
		// PARAMETERS:
		// 	const String& the substring to perform the search with
		//	unsigned position to start the search from
		// RETURNS:
		//	the index of the character found
		//	-1 if no characters found
		//----------------------------------------------
		int find_first_of(const String& str, unsigned pos);
		
		//----------------------------------------------
		// FUNCTION: substring
		// 	Creates asubstring from the string, starting
		//  at position pos and copying n characters
		// PARAMETERS:
		// 	unsigned pos the position to start from
		//	unsigned n number of characters to copy
		// RETURNS:
		//	new instance of type String
		//----------------------------------------------
		String substring(unsigned pos, unsigned n);

		//----------------------------------------------
		// FUNCTION: operator=
		// 	Assigns right value to left value
		// PARAMETERS:
		// 	const String& right value of assignment
		// RETURNS:
		//	Reference to self
		//----------------------------------------------
		String& operator=(const String& other);
		
		//----------------------------------------------
		// FUNCTION: operator+=
		// 	Appends right value to left value
		// PARAMETERS:
		// 	const String& right value of assignment
		// RETURNS:
		//	Reference to self
		//----------------------------------------------
		String& operator+=(const String& other);
		
		//----------------------------------------------
		// FUNCTION: operator+
		// 	Performs string concatenation
		// PARAMETERS:
		// 	const String& string to perform th concatenation with
		// RETURNS:
		//	New instance of type string which contains the
		// 	the result of the two concatenated strings
		//----------------------------------------------
		String operator+(const String& other);
		
		//----------------------------------------------
		// FUNCTION: operator<<
		// 	Prints the string to a standart output stream
		// PARAMETERS:
		// 	ostream& the stream to output to
		// 	const String& the string to be printed
		// RETURNS:
		//	reference to the output stream so that we can
		//	chain many output operations
		//----------------------------------------------
		friend ostream& operator<<(ostream& out, const String& str);
		
		//----------------------------------------------
		// FUNCTION: operator[]
		// 	Equivalent of at(int)
		// PARAMETERS:
		// 	int index of the character we want
		// RETURNS:
		//	reference to the found character
		//----------------------------------------------
		char& operator[](int index);
		const char& operator[](int index) const;
		
		//----------------------------------------------
		// FUNCTION: operator==
		// 	Performs equality check
		// PARAMETERS:
		// 	const String& string to compare with
		// RETURNS:
		//	true if strings are equal
		//	false otherwise
		//----------------------------------------------
		bool operator==(const String& other);
		
		//----------------------------------------------
		// FUNCTION: operator!=
		// 	Oposite of operator==
		// PARAMETERS:
		// 	const String& string to compare with
		// RETURNS:
		//	false if strings are equal
		//	true otherwise
		//----------------------------------------------
		bool operator!=(const String& other);
		
		//----------------------------------------------
		// FUNCTION: operator<
		// 	Checks if left operand is lexicographically
		//	lesser than the right
		// PARAMETERS:
		// 	const String& string to compare with
		// RETURNS:
		//	true if left string is lexicographically lesser
		//			 than the right
		//	false otherwise
		//----------------------------------------------		
		bool operator<(const String & other);
		
		//----------------------------------------------
		// FUNCTION: operator>
		// 	Checks if left operand is lexicographically
		//	"bigger" than the right
		// PARAMETERS:
		// 	const String& string to compare with
		// RETURNS:
		//	true if left string is lexicographically bigger
		//			 than the right
		//	false otherwise
		bool operator>(const String & other);
		
		//----------------------------------------------
		// FUNCTION: operator<=
		// 	Checks if left operand is lexicographically
		//	lesser than or equal to the right
		// PARAMETERS:
		// 	const String& string to compare with
		// RETURNS:
		//	true if left string is lexicographically lesser
		//			 than or equal to the right
		//	false otherwise
		//----------------------------------------------
		bool operator<=(const String & other);
		
		//----------------------------------------------
		// FUNCTION: operator>=
		// 	Checks if left operand is lexicographically
		//	bigger than or equal to the right
		// PARAMETERS:
		// 	const String& string to compare with
		// RETURNS:
		//	true if left string is lexicographically bigger
		//			 than or equal to the right
		//	false otherwise
		//----------------------------------------------
		bool operator>=(const String & other );

		class iterator {
			friend class String;
			private:
				int pos_;
				String& str_;
				iterator(String& str, int pos_);
			public:
			
				//----------------------------------------------
				// FUNCTION: operator++
				// 	Postfix incrementation
				// PARAMETERS:
				//	NONE
				// RETURNS:
				//	reference to self
				//----------------------------------------------
				iterator& operator++();
				
				//----------------------------------------------
				// FUNCTION: operator++
				// 	Prefix incrementation
				// PARAMETERS:
				// 	int fictive
				// RETURNS:
				//	reference to self
				//----------------------------------------------
				iterator& operator++(int);
				
				//----------------------------------------------
				// FUNCTION: operator==
				// 	Check if two iterators are equal
				// PARAMETERS:
				// 	const iterator& iterator to compare with
				// RETURNS:
				//	false if iterators are equal
				//	true otherwise
				//----------------------------------------------
				bool operator==(const iterator& other) const;
				
				//----------------------------------------------
				// FUNCTION: operator!=
				// 	Oposite of operator==
				// PARAMETERS:
				// 	const iterator& iterator to compare with
				// RETURNS:
				//	false if iterators are equal
				//	true otherwise
				//----------------------------------------------
				bool operator!=(const iterator& other) const;
				
				//----------------------------------------------
				// FUNCTION: operator*
				// 	Get the iterator value
				// PARAMETERS:
				//	NONE
				// RETURNS:
				//	char& Reference to iterator value
				//----------------------------------------------
				char& operator*();
		};

		//----------------------------------------------
		// FUNCTION: begin
		// 	Create an iterator pointing at the begining of the string
		// PARAMETERS:
		// 	NONE
		// RETURNS:
		//	iterator pointing at begining of the string
		//----------------------------------------------
		iterator begin();
		
		//----------------------------------------------
		// FUNCTION: end
		// 	Create an iterator, pointing one element after
		// 	the end of the string
		// PARAMETERS:
		//	NONE
		// RETURNS:
		//	iterator pointing one element after the end of the string
		//----------------------------------------------
		iterator end();
	private:
	
		//----------------------------------------------
		// FUNCTION: resize
		// 	Resize the buffer_, extending its capacity
		//	with a given number of characters
		// PARAMETERS:
		// 	int number of chars to extend the buffer with
		// RETURNS:
		// 	void
		//----------------------------------------------
		void resize(int chars);
};

#endif
