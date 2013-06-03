#include <iostream>

using namespace std;

template <class T>
class List {

	private:
		struct Node {
			T val_;
			Node* next_;
			Node* prev_;

			Node(T val)
				: val_(val),
					next_(0),
					prev_(0)
			{}
		};

		Node* head_;
		int size_;
	public:

		List()
			: size_(0),
				head_(new Node(0))
		{
			head_->next_ = head_->prev_ = head_;
		}

		List(const List<T>& other)
			: size_(other.size_),
				head_(new Node(0))
		{
			head_->next_ = head_->prev_ = head_;
			Node* it = other.head_->next_;
			while(it != other.head_) {
				push_front(it->val_);
				it = it->next_;
			}
		}

		~List() {
			while(!empty()) {
				pop_front();
			}
		}

		bool empty() const {
			return size_ == 0;
		}

		List operator=(const List<T>& other) {
			if(this != other) {
				size_ = other.size_;
				head_ = new Node(0);

				head_->next_ = head_->prev_ = head_;
				Node* it = other.head_->next_;
				while(it != other.head_) {
					push_front(it->val_);
					it = it->next_;
				}
			}
			return this;
		}

		void push_front(T val) {
			Node* temp = head_->next_;

			Node* new_val = new Node(val);

			head_->next_ = new_val;
			new_val->prev_ = head_;

			new_val->next_ = temp;
			size_++;
		}

		T pop_front() {
			Node* temp = head_->next_;

			head_->next_ = temp->next_;
			temp->next_->prev_ = head_;
			size_--;
			T val = temp->val_;
			return val;
		}

		void print() {
			Node* it = head_->next_;

			while(it != head_) {
				cout << it->val_ << endl;
				it = it->next_;
			}
		}
};


int main() {
	List<int> l;
	for(int i = 0; i < 10; i++) {
		l.push_front(i);
	}
	l.print();
	List<int> l2(l);

	cout << "LIST 2!" << endl;
	l2.print();

	List<int> l3 = l2;
	cout << "LIST 3!" << endl;
	l3.print();

	return 0;
}
