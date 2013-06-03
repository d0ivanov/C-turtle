#include <iostream>
using namespace std;


class ListError{};

class List {
	friend class iterator;
	struct Elem {
		int data_;
		Elem* next_;
		Elem* prev_;

		Elem(int data)
		: data_(data),
		  next_(0),
		  prev_(0)
		{}
	};

	Elem* head_;
public:
	List()
	: head_(new Elem(0))
	{
		head_->next_=head_;
		head_->prev_=head_;
	}

	~List() {
		while(!empty()) {
			pop_front();
		}

		delete head_;
	}


	bool empty() const {
		return head_->next_==head_;
	}

	void push_back(int val) {
		Elem* newElem=new Elem(val);
		Elem* back=head_->prev_;

		back->next_=newElem;
		newElem->prev_=back;

		newElem->next_=head_;
		head_->prev_=newElem;
	}

	void push_front(int val) {
		Elem* newElem=new Elem(val);
		Elem* front=head_->next_;

		head_->next_=newElem;
		newElem->prev_=head_;

		newElem->next_=front;
		front->prev_=newElem;
	}

	int back() const {
		return head_->prev_->data_;
	}

	int front() const {
		return head_->next_->data_;
	}

	void pop_back() {
		if(empty()) {
			throw ListError();
		} else {
			Elem* back=head_->prev_;
			Elem* newBack=back->prev_;

			newBack->next_=head_;
			head_->prev_=newBack;

			delete back;
		}
	}

	void pop_front() {
		if(empty()) {
			throw ListError();
		} else {
			Elem* front=head_->next_;
			Elem* newFront=front->next_;

			head_->next_=newFront;
			newFront->prev_=head_;

			delete front;
		}
	}

	class iterator {
		friend class List;

		Elem* current_;

		iterator(Elem* elem)
		: current_(elem)
		{}

	public:
		iterator& operator++() {
			current_ = current_->next_;
			return *this;
		}

		iterator& operator++(int) {

		}

		int& operator*() {
			return current_->data_;
		}

		bool operator==(const iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const iterator& other) const {
			return !operator==(other);
		}
	};

	iterator begin() {
		return iterator(head_->next_);
	}

	iterator end() {
		return iterator(head_);
	}

	class const_iterator {
	friend class List;

	Elem* current_;

	const_iterator(Elem* elem)
	: current_(elem)
	{}



	public:
		const_iterator& operator++() {
			current_ = current_->next_;
			return *this;
		}

		const_iterator& operator++(int) {

		}

		const int& operator*() {
			return current_->data_;
		}

		bool operator==(const const_iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const const_iterator& other) const {
			return !operator==(other);
		}
	};

	const_iterator begin() const {
		return const_iterator(head_->next_);
	}

	const_iterator end() const{
		return const_iterator(head_);
	}

	List(const List& other)
	: head_(new Elem(0))
	{
		head_->next_ = head_->prev_ = head_;

		for(List::const_iterator it=other.begin();it!=other.end();++it) {
				push_back(*it);
		}

	}

	void clear() {
		while(!empty()) {
			pop_back();
		}
	}

	List& operator=(const List& other) {
		if(this != &other) {
			clear();
			for(List::const_iterator it=other.begin(); it!=other.end(); ++it) {
				push_back(*it);
			}
			return *this;
		}

	}

	void insert(iterator it, int val) {
		for(List::iterator iter=it;; ++iter) {
			if(iter == it) {
				(*iter) = val;
				break;
			}
		}
	}

	void erase(iterator it) {
		for(List::iterator iter = it;; ++iter) {
			if(iter == it) {
				Elem* temp = new Elem(0);
				temp->next_ = *this->next_;

				iter->next_ = iter->prev_;
				iter->prev_ = temp->next_;
				delete temp;
			}
		}
	}
};
int main() {

	List l;
	cout << "l.empty()=" << l.empty() << endl;
	l.push_front(1);
	l.push_front(2);
	cout << "l.empty()=" << l.empty() << endl;
	cout << "l.back() =" << l.back() << endl;
	cout << "l.front()=" << l.front() << endl;
	l.pop_front();
	cout << "l.back() =" << l.back() << endl;
	cout << "l.front()=" << l.front() << endl;

	l.push_back(34);
	l.push_back(35);

	for(List::iterator it=l.begin();it!=l.end();++it) {
		cout << (*it) << endl;
	}

	List l1 = l;

	for(List::iterator it=l1.begin();it!=l1.end();++it) {
		cout << (*it) << endl;
	}

	l.push_back(42);

	List l3;
	l3 = l;
	for(List::iterator it=l3.begin();it!=l3.end();++it) {
		cout << (*it) << endl;
	}

	l3 = l3;
	cout << "l3 >>>>>>>>>>>>>>>>>>>>>>" << endl;
	for(List::iterator it=l3.begin();it!=l3.end();++it) {
		cout << (*it) << endl;
	}
	cout << "l3 >>>>>>>>>>>>>>>>>>>>>>" << endl;

	l3.insert(l3.begin(),5);
	cout << "l3 >>>>>>>>>>>---->>>>>>" << endl;
	for(List::iterator it=l3.begin();it!=l3.end();++it) {
		cout << (*it) << endl;
	}
	cout << "l3 >>>>>>>>>>-->>>>>>>" << endl;


	return 0;
}
