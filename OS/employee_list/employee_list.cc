#include <iostream>
#include <string>

using namespace std;

class ListError {};

class Employee {
  private:
    string firstName_;
    string middleName_;
    string lastName_;
    unsigned int age_;
    float salary_;
  public:

    Employee() {  }

    Employee(string firstName, string middleName, string lastName, unsigned int age, float salary)
    : firstName_(firstName),
      middleName_(middleName),
      lastName_(lastName),
      age_(age),
      salary_(salary)
    {}


    string getFirstName() const {
      return firstName_;
    }

    void setFirstName(string firstName) {
      firstName_ = firstName;
    }

    string getMiddleName() const {
      return middleName_;
    }

    void setMiddleName(string middleName) {
      middleName_ = middleName;
    }

    string getLastName() const {
      return lastName_;
    }

    void setLastName(string lastName) {
      lastName_ = lastName;
    }

    unsigned int getAge() const {
      return age_;
    }

    void setAge(unsigned int age) {
      age_ = age;
    }

    float getSalary() const {
      return salary_;
    }

    void setSalary(float salary) {
      salary_ = salary;
    }
};

ostream& operator<<(ostream& out, const Employee* empl) {
  out << "Employee: " << empl->getFirstName() << " " << empl->getMiddleName() << " " << empl->getLastName() << endl;
  out << "  age : " << empl->getAge() << endl << "  salary : " << empl->getSalary() << endl;
  return out;
}

class EmployeeList {
  friend class iterator;
  private:
    struct Elem {
      Employee* data_;
      Elem* next_;
      Elem* prev_;

      Elem(Employee* data)
      : data_(data)
      {}

      Elem(){}
    };

    Elem* head_;

  public:
    EmployeeList()
    : head_(new Elem)
    {
      head_->next_ = head_;
      head_->prev_ = head_;
    }

    bool empty() const {
      return head_->next_ == head_;
    }

    void push_back(Employee* empl) {
      Elem* newElem = new Elem(empl);
      Elem* back = head_->prev_;

      back->next_ = newElem;
      newElem->prev_ = back;

      newElem->next_ = head_;
      head_->prev_ = newElem;
    }

    void push_front(Employee* empl) {
      Elem* newElem = new Elem(empl);
      Elem* front = head_->next_;

      head_->next_ = newElem;
      newElem->prev_ = head_;

      newElem->next_ = front;
      front->prev_ = newElem;
    }

    Employee* back() const {
      return head_->prev_->data_;
    }

    Employee* front() const {
      return head_->next_->data_;
    }

    void pop_back() {
      if(empty()) {
        throw ListError();
      }
      Elem* back = head_->prev_;
      Elem* newBack = back->prev_;

      head_->prev_ = newBack;
      newBack->next_ = head_;

      delete back;
    }

    void pop_front() {
      if(empty()) {
        throw ListError();
      }
      Elem* front = head_->next_;
      Elem* newFront = front->next_;

      head_->next_ = newFront;
      newFront->prev_ = head_;

      delete front;
    }

  public:
    class iterator {
      friend class EmployeeList;
      private:

        Elem* current_;

        iterator(Elem* elem)
        : current_(elem)
        {}
      public:

      iterator& operator++() {
        current_ = current_->next_;
        return *this;
      }

      Employee* operator*() {
        return current_->data_;
      }

      bool operator==(const iterator& other) {
        return current_ == other.current_;
      }

      bool operator!=(const iterator& other) {
        return !operator==(other);
      }

    };

  public:
    iterator begin() {
      return iterator(head_->next_);
    }

    iterator end() {
      return iterator(head_->prev_);
    }

    Employee* get(iterator& it) {
      for(EmployeeList::iterator iter = it;; ++it) {
        if(iter == it) {
          return iter.current_->data_;
        }
      }
    }

    void clear() {
      while(!empty()) {
        pop_back();
      }
    }

    void insert(iterator it, Employee* empl) {
      for(EmployeeList::iterator iter = it;; ++iter) {
        if(iter == it) {
          Elem* currentElem = it.current_;
          Elem* prevElem = it.current_->prev_;
          Elem* newElem = new Elem(empl);

          prevElem->next_ = newElem;
          newElem->prev_ = prevElem;

          newElem->next_ = currentElem;
          currentElem->prev_ = newElem;

          break;
        }
      }
    }

    void erase(iterator it) {
      for(EmployeeList::iterator iter = it;; ++iter) {
        if(iter == it) {
          Elem* temp = new Elem();
          temp->next_ = head_->next_;

          iter.current_->next_ = iter.current_->prev_;
          iter.current_->prev_ = temp->next_;
          delete temp;
          break;
        }
      }
    }

    Employee* findRichest() {
      Employee* empl = front();
      for(EmployeeList::iterator it = begin(); it!=end(); ++it) {

      }

      return empl;
    }

    Employee* findOldest() {

    }

    Employee* findPoorest() {

    }

    Employee* findYoungest() {

    }

    void dump() {
      for(EmployeeList::iterator it = begin(); it != end(); ++it) {
        cout << it.current_->data_;
      }
    }
};

int main() {

  return 0;
}
