//--------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XIb
// NUMBER: 15
// PROBLEM: #3
// FILE NAME: list.cc
// FILE PURPOSE: Contains all method implementations
//---------------------------------------------

#ifndef __LIST_HH__
#define __LIST_HH__

#include<iostream>
using namespace std;

template <class T>
class List{

	friend class iterator;
	friend class const_iterator;
	friend class reverse_iterator;
	friend class reverse_const_iterator;
	private:

		struct Node {
			T data_;
			Node* next_;
			Node* prev_;

			Node(T val)
				: data_(val),
					next_(0),
					prev_(0)
			{}
		};

		Node* head_;
		int size_;

	public:
		List(T val)
			: head_(new Node(val)),
				size_(0)
		{
			head_->prev_ = head_;
			head_->next_ = head_;
		}

		List(const List<T>& other)
			: size_(0),
				head_(new Node(0))
		{
			head_->next_ = head_->prev_ = head_;
			for(List<T>::const_iterator it = other.cbegin(); it != other.cend(); it++) {
				push_back(*it);
			}
		}

		~List() {
			while(!empty()) {
				pop_front();
			}
		}

		//--------------------------------------------
		// FUNCTION: push_back
		// Pushes an element at the back of the list
		// PARAMETERS:
		// const T& the data to push
		//----------------------------------------------
		void push_back(const T& val) {
			Node* new_elem = new Node(val);
			Node* temp = head_->prev_;

			temp->next_ = new_elem;
			new_elem->prev_ = temp;

			new_elem->next_ = head_;
			head_->prev_ = new_elem;
			size_++;
		}

		//--------------------------------------------
		// FUNCTION: pop_back
		// Pops one element from the back of the list
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		void pop_back() {
			Node* temp = head_->prev_;

			head_->prev_ = temp->prev_;
			temp->prev_->next_ = head_;

			delete temp;
			size_--;
		}

		//--------------------------------------------
		// FUNCTION: push_front
		// Pushes an element at the front of the list
		// PARAMETERS:
		// const T& the data to push
		//----------------------------------------------
		void push_front(const T& val) {
			Node* new_elem = new Node(val);
			Node* front = head_->next_;

			head_->next_ = new_elem;
			new_elem->prev_ = head_;

			new_elem->next_ = front;
			front->prev_=new_elem;

			size_++;
		}

		//--------------------------------------------
		// FUNCTION: pop_front
		// Pops one element from the front of the list
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		void pop_front() {
			Node* temp = head_->next_;

			head_->next_ = temp->next_;
			temp->next_->prev_ = head_;

			delete temp;
			size_--;
		}

		//--------------------------------------------
		// FUNCTION: front
		// Returns a reference to the data in the first
		// element in the list.
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		T& front() {
			return head_->next_->data_;
		}

		//--------------------------------------------
		// FUNCTION: back
		// Returns a reference to the data in the last
		// element in the list.
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		T& back() {
			return head_->prev_->data_;
		}

		//--------------------------------------------
		// FUNCTION:const back
		// Returns a const reference to the data in
		// the last element in the list.
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		const T& back() const {
			return head_->prev_->data_;
		}

		//--------------------------------------------
		// FUNCTION: size
		// Returns the size of the list
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		int size() const {
			return size_;
		}

		//--------------------------------------------
		// FUNCTION: empty
		// Returns true if the list is empty.
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		bool empty() const {
			return size_ == 0;
		}

		//--------------------------------------------
		// FUNCTION: clear
		// Deletes all elements in the list.
		// PARAMETERS:
		// 	none
		//----------------------------------------------
		void clear() {
			while(!empty()) {
				pop_back();
			}
		}

		//--------------------------------------------
		// FUNCTION:swap
		// Swaps the values of two lists.
		// PARAMETERS:
		// 	List& the list to copy from
		//----------------------------------------------
		void swap(List& other) {
			for(iterator it1 = begin(), it2 = other.begin();
					it1 != end() && it2 != other.end(); it1++, it2++) {
				T temp = *it1;
				*it1 = *it2;
				*it2 = *temp;
			}
		}

		//--------------------------------------------
		// FUNCTION: operator=
		// 	Assignment operator.
		// PARAMETERS:
		// 	List& the list to copy from
		//----------------------------------------------
		List& operator=(const List& other) {
			if(this != other) {
				size_ = other.size_;
				clear();
				for(List<T>::const_iterator it = other.cbegin(); it != other.cend(); it++) {
					push_back(*it);
				}
				return *this;
			}
		}

		class iterator {
			friend class List;
			private:
				Node* curr_;

				iterator(Node* curr)
					: curr_(curr)
				{}

			public:

				//--------------------------------------------
				// FUNCTION:operator++
				// Postfix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				iterator& operator++() {
					curr_ = curr_->next_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator++
				// Prefix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				iterator& operator++(int) {
					curr_ = curr_->next_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator==
				// Checks if two iterators are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator==(const iterator& other) const {
					return curr_ == other.curr_;
				}

				//--------------------------------------------
				// FUNCTION:operator!=
				// Checks if two iterators not are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator!=(const iterator& other) const {
					return !operator==(other);
				}

				//--------------------------------------------
				// FUNCTION:operator*
				// Get current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				T& operator*() {
					return curr_->data_;
				}

				//--------------------------------------------
				// FUNCTION:operator->
				// Get pointer to current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				T* operator->() {
					return &curr_->data_;
				}
		};

		class const_iterator {
			friend class List;
			private:
				Node* curr_;

				const_iterator(Node* curr)
					: curr_(curr)
				{}

			public:

				//--------------------------------------------
				// FUNCTION:operator++
				// Postfix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				const_iterator& operator++() {
					curr_ = curr_->next_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator++
				// Prefix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				const_iterator& operator++(int) {
					curr_ = curr_->next_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator==
				// Checks if two iterators are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator==(const const_iterator& other) const {
					return curr_ == other.curr_;
				}

				//--------------------------------------------
				// FUNCTION:operator!=
				// Checks if two iterators not are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator!=(const const_iterator& other) const {
					return !operator==(other);
				}

				//--------------------------------------------
				// FUNCTION:operator*
				// Get current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				const T& operator*() {
					return curr_->data_;
				}

				//--------------------------------------------
				// FUNCTION:operator->
				// Get pointer to current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				const T* operator->() {
					return &curr_->data_;
				}
		};

		class reverse_iterator {
			friend class List;
			private:
				Node* curr_;

				reverse_iterator(Node* curr)
					: curr_(curr)
				{}

			public:

				//--------------------------------------------
				// FUNCTION:operator++
				// Postfix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				reverse_iterator& operator++() {
					curr_ = curr_->prev_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator++
				// Prefix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				reverse_iterator& operator++(int) {
					curr_ = curr_->prev_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator==
				// Checks if two iterators are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator==(const reverse_iterator& other) const {
					return curr_ == other.curr_;
				}

				//--------------------------------------------
				// FUNCTION:operator!=
				// Checks if two iterators not are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator!=(const reverse_iterator& other) const {
					return !operator==(other);
				}

				//--------------------------------------------
				// FUNCTION:operator*
				// Get current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				T& operator*() {
					return curr_->data_;
				}

				//--------------------------------------------
				// FUNCTION:operator->
				// Get pointer to current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				T* operator->() {
					return &curr_->data_;
				}
		};

		class reverse_const_iterator {
			friend class List;
			private:
				Node* curr_;

				reverse_const_iterator(Node* curr)
					: curr_(curr)
				{}

			public:

				//--------------------------------------------
				// FUNCTION:operator++
				// Postfix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				reverse_const_iterator& operator++() {
					curr_ = curr_->prev_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator++
				// Prefix incrementation
				// PARAMETERS:
				// none
				//----------------------------------------------
				reverse_const_iterator& operator++(int) {
					curr_ = curr_->prev_;
					return *this;
				}

				//--------------------------------------------
				// FUNCTION:operator==
				// Checks if two iterators are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator==(const reverse_const_iterator& other) const {
					return curr_ == other.curr_;
				}

				//--------------------------------------------
				// FUNCTION:operator!=
				// Checks if two iterators not are equal
				// PARAMETERS:
				// const iterator& the iterator to compare to
				//----------------------------------------------
				bool operator!=(const reverse_const_iterator& other) const {
					return !operator==(other);
				}

				//--------------------------------------------
				// FUNCTION:operator*
				// Get current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				const T& operator*() {
					return curr_->data_;
				}

				//--------------------------------------------
				// FUNCTION:operator->
				// Get pointer to current node value
				// PARAMETERS:
				// none
				//----------------------------------------------
				const T* operator->() {
					return &curr_->data_;
				}
		};

		//--------------------------------------------
		// FUNCTION:begin
		// Return an iterator from the begining of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		iterator begin() {
			return iterator(head_->next_);
		}

		//--------------------------------------------
		// FUNCTION:end
		// Return an iterator from the end of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		iterator end() {
			return iterator(head_);
		}

		//--------------------------------------------
		// FUNCTION:cbegin
		// Return a const_iterator from the begining of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		const_iterator cbegin() const {
			return const_iterator(head_->next_);
		}

		//--------------------------------------------
		// FUNCTION:end
		// Return a const_iterator from the end of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		const_iterator cend() const {
			return const_iterator(head_);
		}

		//--------------------------------------------
		// FUNCTION:rbegin
		// Return a reverse_iterator from the begining of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		reverse_iterator rbegin() {
			return reverse_iterator(head_->prev_);
		}

		//--------------------------------------------
		// FUNCTION:rend
		// Return a reverse_iterator from the end of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		reverse_iterator rend() {
			return reverse_iterator(head_);
		}

		//--------------------------------------------
		// FUNCTION:cbegin
		// Return a reverse_const_iterator from the begining of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		reverse_const_iterator rcbegin() const {
			return reverse_const_iterator(head_);
		}

		//--------------------------------------------
		// FUNCTION:rend
		// Return a reverse_const_iterator from the end of the list
		// PARAMETERS:
		// none
		//----------------------------------------------
		reverse_const_iterator rcend() const {
			return reverse_const_iterator(head_->next_);
		}

		//--------------------------------------------
		// FUNCTION:insert
		// Inserts a new element in the list at a given
		// position
		// PARAMETERS:
		// 	iterator the position to insert at
		// 	const T& the value of the new element
		//----------------------------------------------
		iterator insert(iterator pos, const T& x) {
			Node* new_elem = new Node(x);
			for(iterator it = begin(); it != end(); it++) {
				if(it == pos) {
					new_elem->next_ = it.curr_->next_;
					it.curr_->next_->prev_ = new_elem;

					new_elem->prev_ = it.curr_->prev_;
					it.curr_->prev_->next_ = new_elem;
					size_++;
				}
			}
			return iterator(new_elem);
		}

		//--------------------------------------------
		// FUNCTION:erase
		// Erases a signle element at a given position
		// PARAMETERS:
		// 	iterator the position to delete at
		//----------------------------------------------
		iterator erase(iterator pos) {
			Node* temp;
			for(iterator it = begin(); it != end(); it++) {
				if(it == pos) {
					temp = it.curr_;
					Node* back = temp->prev_;

					back->next_ = temp->next_;
					temp->next_->prev_ = back;

					delete temp;
					size_--;
				}
			}
			return iterator(temp->next_);
		}

		//--------------------------------------------
		// FUNCTION:erase
		// Erases a range of elements
		// PARAMETERS:
		// 	iterator the position to start deleting from
		// 	iterator the position to stop deleting at
		//----------------------------------------------
		iterator erase(iterator begin, iterator end) {
			for(iterator it = begin; it != end; it++) {
				erase(it);
			}
		}
};

#endif

