//--------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XIb
// NUMBER: 15
// PROBLEM: #2
// FILE NAME: vector.hh
// FILE PURPOSE: contains all class and method
// 	declarations
//---------------------------------------------

#ifndef __VECTOR_HH__
#define __VECTOR_HH__

#include <cstddef>

template <class T>
class Vector {
	private:
		int capacity_;
		int size_;
		T* buffer_;
	public:
		Vector(int capacity = 10);
		Vector(const Vector& other);
		~Vector();

		//--------------------------
		// function: size
		// 	Returns the size of the vector
		// parameters: NONE
		//--------------------------
		int size() const;

		//--------------------------
		// function: empty
		// 	Checks if vector is empty
		// parameters: NONE
		//--------------------------
		bool empty() const;

		//--------------------------
		// function: operator[]
		// 	Returns the Nth element
		// 	of the vector
		// parameters: int the element
		// 	index we want
		//--------------------------
		T& operator[](size_t index);

		//--------------------------
		// function: operator=
		// 	Assignment operator
		// parameters: const Vector&
		// 	rvalue of the assignment
		//--------------------------
		Vector& operator=(const Vector& other);

		//--------------------------
		// function: operator[]
		// 	Returns const reference
		// 	to the Nth element of the vector
		// parameters: int the element
		// 	index we want
		//--------------------------
		const T& operator[](size_t index) const;

		//--------------------------
		// function: clear
		// 	Deletes all elements of
		// 	the vector
		// parameters: none
		//--------------------------
		void clear();

		//--------------------------
		// function: capacity
		// 	Returns the amount of
		// 	for which there is allocated
		// 	memory. Capacity is always >= size
		// parameters: none
		//--------------------------
		int capacity() const;

	public:
		class iterator {
			friend class Vector<T>;

			private:
				int position_;
				Vector<T> vector_;
				iterator(Vector& vec, int pos);
			public:

				//--------------------------
				// function: operator++
				// 	Increments the iterator position
				// parameters: none
				//--------------------------
				iterator& operator++();

				//--------------------------
				// function: operator++
				// 	Increments the iterator position
				// 	this is the prefix version.
				// parameters: none
				//--------------------------
				iterator& operator++(int);

				//--------------------------
				// function: operator==
				// 	Comparison operator.
				// parameters: const iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator==(const iterator& other) const;
				//--------------------------
				// function: operator!=
				// 	Oposite of comparison operator
				// parameters: const iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator!=(const iterator& other) const;

				//--------------------------
				// function: operator*
				// 	Returns reference to element
				// parameters: none
				//--------------------------
				T& operator*();

				//--------------------------
				// function: operator->
				// 	Returns pointer to element
				// parameters: none
				//--------------------------
				T* operator->();
		};

		class const_iterator {
			friend class Vector<T>;

			private:
				int position_;
				Vector<T> vector_;
				const_iterator(Vector& vec, int pos);
			public:
				//--------------------------
				// function: operator++
				// 	Increments the iterator position
				// parameters: none
				//--------------------------
				const_iterator& operator++();

				//--------------------------
				// function: operator++
				// 	Increments the iterator position
				// 	this is the prefix version.
				// parameters: none
				//--------------------------
				const_iterator& operator++(int);

				//--------------------------
				// function: operator==
				// 	Comparison operator for const_iterator
				// parameters: const const_iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator==(const const_iterator& other) const;

				//--------------------------
				// function: operator!=
				// 	Opposite of the comparison
				// 	operator for const_iterator
				// parameters: const const_iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator!=(const const_iterator& other) const;


				//--------------------------
				// function: operator*
				// 	Returns const reference to
				// 	the current element
				// parameters: none
				//--------------------------
				const T& operator*();

				//--------------------------
				// function: operator->
				// 	Returns const pointer to the
				// 	current element
				// parameters: none
				//--------------------------
				const T* operator->();
		};

		class reverse_iterator {
			friend class Vector<T>;

			private:
				int position_;
				Vector<T> vector_;
				reverse_iterator(Vector& vec, int pos);

			public:

				//--------------------------
				// function: operator++
				// 	Decrements the position of
				// 	the iterator since this is a
				// 	retverse iterator
				// parameters: none
				//--------------------------
				reverse_iterator& operator++();

				//--------------------------
				// function: operator++
				// 	Decrements the position of
				// 	the iterator since this is a
				// 	retverse iterator, prefix operator
				// parameters: none
				//--------------------------
				reverse_iterator& operator++(int);

				//--------------------------
				// function: operator==
				// 	Comparison operator for reverse_iterator
				// parameters: const reverse_iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator==(const reverse_iterator& other) const;

				//--------------------------
				// function: operator!=
				// 	Opposite of comparison operator
				// 	for reverse_iterator
				// parameters: const reverse_iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator!=(const reverse_iterator& other) const;

				//--------------------------
				// function: operator*
				// 	Returns reference to the
				// 	current element
				// parameters: none
				//--------------------------
				T& operator*();

				//--------------------------
				// function: operator->
				// 	Returns pointer to the
				// 	current element
				// parameters: none
				//--------------------------
				T* operator->();
		};

		class reverse_const_iterator {
			friend class Vector<T>;

			private:
				int position_;
				Vector<T> vector_;
				reverse_const_iterator(Vector& vec, int pos);

			public:

				//--------------------------
				// function: operator++
				// 	Decrements itreator pos
				// parameters: none
				//--------------------------
				reverse_const_iterator& operator++();

				//--------------------------
				// function: operator++
				// 	Decrements itreator pos, prefix
				// parameters: none
				//--------------------------
				reverse_const_iterator& operator++(int);

				//--------------------------
				// function: operator==
				// 	Compares two reverse_const_iterator
				// parameters: const reverse_const_iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator==(const reverse_const_iterator& other) const;

				//--------------------------
				// function: operator!=
				// 	Opposite of reverse_const_iterator comparator
				// parameters: const reverse_const_iterator&
				// 	rvalue of comparison
				//--------------------------
				bool operator!=(const reverse_const_iterator& other) const;

				//--------------------------
				// function: operator*
				// 	Returns const reference to
				// 	current iterator element
				// parameters: none
				//--------------------------
				const	T& operator*();

				//--------------------------
				// function: operator->
				//  Returns coint pointer to
				//  current iterator element
				// parameters: none
				//--------------------------
				const	T* operator->();
		};


		//--------------------------
		// function: begin
		// 	Returns new iterator to the
		// 	begining of the vector
		// parameters: none
		//--------------------------
		iterator begin();

		//--------------------------
		// function: end
		// 	Returns new iterator to the
		// 	end of the vector
		// parameters: none
		//--------------------------
		iterator end();

		//--------------------------
		// function: begin const
		// 	Returns const iterator to
		// 	the begining of the vector
		// parameters: none
		//--------------------------
		const_iterator begin() const;

		//--------------------------
		// function: end const
		// 	Returns const iterator to
		// 	the end of the vector
		// parameters: none
		//--------------------------
		const_iterator end() const;


		//--------------------------
		// function: rbegin
		// 	Returns reverse iterator to
		// 	the begining of the vector
		// parameters: none
		//--------------------------
		reverse_iterator rbegin();

		//--------------------------
		// function: rend
		// 	Returns reverse iterator to
		// 	the end of the vector
		// parameters: none
		//--------------------------
		reverse_iterator rend();

		//--------------------------
		// function: rbegin const
		// 	Returns const reverse iterator to
		// 	the begining of the vector
		// parameters: none
		//--------------------------
		reverse_const_iterator rbegin() const;

		//--------------------------
		// function: rend const
		// 	Returns const reverse iterator to
		// 	the end of the vector
		// parameters: none
		//--------------------------
		reverse_const_iterator rend() const;

		//--------------------------
		// function: front
		// 	Returns the first element
		// 	of the vector
		// parameters: none
		//--------------------------
		T& front();

		//--------------------------
		// function: front const
		// 	Returns const reference to
		// 	the first element	of the vector
		// parameters: none
		//--------------------------
		const T& front() const;


		//--------------------------
		// function: back
		// 	Returns the last element
		// 	of the vector
		// parameters: none
		//--------------------------
		T& back();


		//--------------------------
		// function: back const
		// 	Returns const reference to
		// 	the last element of the vector
		// parameters: none
		//--------------------------
		const T& back() const;

		//--------------------------
		// function: push_back
		//  Push new element to the back
		//  of the vector
		// parameters: const T& value
		// 	push
		//--------------------------
		void push_back(const T& val);

		//--------------------------
		// function: pop_back
		//  Delete the element at the back
		//  of the vector
		// parameters: none
		//--------------------------
		T pop_back();

		//--------------------------
		// function: insert
		//  Insert new element to the
		//  vector
		// parameters: iterator pos
		// 	position to insert the lement at
		//--------------------------
		void insert(iterator pos, const T& x);

		//--------------------------
		// function: erase
		//  Erase an element
		// parameters: iterator pos
		// 	position to delete the lement at
		//--------------------------
		void erase(iterator pos);

		//--------------------------
		// function: insert
		//  Delete a portion of the list.
		//  [first, last)
		// parameters: iterator pos
		// 	position at which to begin
		// iterator
		// 	position at wich to end
		//--------------------------
		void erase(iterator first, iterator last);

	private:
		void resize();
};

#endif
