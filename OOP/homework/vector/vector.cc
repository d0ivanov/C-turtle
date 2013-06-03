//--------------------------------------------
// NAME: Dobromir Ivanov
// CLASS: XIb
// NUMBER: 15
// PROBLEM: #2
// FILE NAME: vector.cc
// FILE PURPOSE: contains all class and method
// 	definitions
//---------------------------------------------

#include "vector.hh"
#include <cstddef>

template<class T>
Vector<T>::Vector(int capacity)
	: capacity_(capacity),
		size_(0),
		buffer_(new T[capacity])
{}

template<class T>
Vector<T>::Vector(const Vector& other)
	: capacity_(other.capacity_),
		size_(other.size_),
		buffer_(new T[capacity_])
{
	for(int i = 0; i < size_; i++) {
		buffer_[i] = other[i];
	}
}

template<class T>
Vector<T>::~Vector()
{
	delete [] buffer_;
}


template<class T>
int Vector<T>::size() const {
	return size_;
}

template<class T>
bool Vector<T>::empty() const {
	return size_ == 0;
}

template<class T>
void Vector<T>::clear() {
	delete [] buffer_;
	size_ = 0;
	buffer_ = new T[capacity_];
}

template<class T>
int Vector<T>::capacity() const {
	return capacity_;
}

template<class T>
T& Vector<T>::operator[](size_t index) {
	return buffer_[index];
}

template<class T>
const T& Vector<T>::operator[](size_t index) const {
	return buffer_[index];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
	if(this != &other) {
		delete [] buffer_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		buffer_ = new T[capacity_];
		for(int i = 0; i < size_; i++) {
			buffer_[i] = other[i];
		}
	}
	return *this;
}

template<class T>
Vector<T>::iterator::iterator(Vector& vec, int pos)
	: vector_(vec),
		position_(pos)
{}

template<class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++() {
	position_++;
	return *this;
}

template<class T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++(int) {
	position_++;
	return *this;
}

template<class T>
bool Vector<T>::iterator::operator==(const iterator& other) const {
	return position_ == other.position_;
}

template<class T>
bool Vector<T>::iterator::operator!=(const iterator& other) const {
	return !operator==(other);
}

template<class T>
T& Vector<T>::iterator::operator*() {
	return vector_[position_];
}

template<class T>
T* Vector<T>::iterator::operator->() {
	return &buffer_[position_];
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin() {
	return iterator(*this, 0);
}

template<class T>
typename Vector<T>::iterator Vector<T>::end() {
	return iterator(*this, size_);
}

//const iterator
template<class T>
Vector<T>::const_iterator::const_iterator(Vector& vec, int pos)
	: vector_(vec),
		position_(pos)
{}

template<class T>
typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator++() {
	position_++;
	return *this;
}

template<class T>
typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator++(int) {
	position_++;
	return *this;
}

template<class T>
bool Vector<T>::const_iterator::operator==(const const_iterator& other) const {
	return position_ == other.position_;
}

template<class T>
bool Vector<T>::const_iterator::operator!=(const const_iterator& other) const {
	return !operator==(other);
}

template<class T>
const T& Vector<T>::const_iterator::operator*() {
	return vector_[position_];
}

template<class T>
const T* Vector<T>::const_iterator::operator->() {
	return &vector_[position_];
}

template<class T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
	return const_iterator(*this, 0);
}

template<class T>
typename Vector<T>::const_iterator Vector<T>::end() const {
	return const_iterator(*this, size_);
}

//reverse iterator
template<class T>
Vector<T>::reverse_iterator::reverse_iterator(Vector& vec, int pos)
	: vector_(vec),
		position_(pos)
{}

template<class T>
typename Vector<T>::reverse_iterator& Vector<T>::reverse_iterator::operator++() {
	position_--;
	return *this;
}

template<class T>
typename Vector<T>::reverse_iterator& Vector<T>::reverse_iterator::operator++(int) {
	position_--;
	return *this;
}

template<class T>
bool Vector<T>::reverse_iterator::operator==(const reverse_iterator& other) const {
	return position_ == other.position_;
}

template<class T>
bool Vector<T>::reverse_iterator::operator!=(const reverse_iterator& other) const {
	return !operator==(other);
}

template<class T>
T& Vector<T>::reverse_iterator::operator*() {
	return vector_[position_];
}

template<class T>
T* Vector<T>::reverse_iterator::operator->() {
	return &vector_[position_];
}

template<class T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin() {
	return reverse_iterator(*this, (size_-1));
}

template<class T>
typename Vector<T>::reverse_iterator Vector<T>::rend() {
	return reverse_iterator(*this, -1);
}

//reverse const iterator
template<class T>
Vector<T>::reverse_const_iterator::reverse_const_iterator(Vector& vec, int pos)
	: vector_(vec),
		position_(pos)
{}

template<class T>
typename Vector<T>::reverse_const_iterator& Vector<T>::reverse_const_iterator::operator++() {
	position_--;
	return *this;
}

template<class T>
typename Vector<T>::reverse_const_iterator& Vector<T>::reverse_const_iterator::operator++(int) {
	position_--;
	return *this;
}

template<class T>
bool Vector<T>::reverse_const_iterator::operator==(const reverse_const_iterator& other) const {
	return position_ == other.position_;
}

template<class T>
bool Vector<T>::reverse_const_iterator::operator!=(const reverse_const_iterator& other) const {
	return !operator==(other);
}

template<class T>
const T& Vector<T>::reverse_const_iterator::operator*() {
	return vector_[position_];
}

template<class T>
const T* Vector<T>::reverse_const_iterator::operator->() {
	return &vector_[position_];
}

template<class T>
typename Vector<T>::reverse_const_iterator Vector<T>::rbegin() const {
	return reverse_const_iterator(*this, size_-1);
}

template<class T>
typename Vector<T>::reverse_const_iterator Vector<T>::rend() const {
	return reverse_const_iterator(*this, -1);
}

template<class T>
T& Vector<T>::front() {
	return buffer_[0];
}

template<class T>
const T& Vector<T>::front() const {
	return buffer_[0];
}

template<class T>
T& Vector<T>::back() {
	return buffer_[size_-1];
}

template<class T>
const T& Vector<T>::back() const {
	return buffer_[size_-1];
}

template<class T>
void Vector<T>::push_back(const T& val) {
	if(capacity_ < size_ + 1)
		resize();
	buffer_[size_++] = val;
}

template<class T>
T Vector<T>::pop_back() {
	return buffer_[size_--];
}

template<class T>
void Vector<T>::insert(iterator pos, const T& x) {
	if(capacity_ < size_ + 1)
		resize();
	T* temp = new T[capacity_];
	++size_;
	for(int i = 0; i < size_; i++) {
		if(i < pos.position_)
			temp[i] = buffer_[i];
		if(i == pos.position_)
			temp[i] = x;
		if(i > pos.position_)
			temp[i] = buffer_[i-1];
	}
	delete [] buffer_;
	buffer_ = temp;
}

template<class T>
void Vector<T>::erase(iterator pos) {
	T* temp = new T[capacity_];
	for (int i = 0; i < size_; i++) {
		if(i < pos.position_)
			temp[i] = buffer_[i];
		if(i >= pos.position_)
			temp[i] = buffer_[i+1];
	}
	delete [] buffer_;
	size_--;
	buffer_ = temp;
}

template <class T>
void Vector<T>::erase(Vector::iterator first, Vector::iterator last) {
	for(Vector<T>::iterator it = first; it != last; it++) {
		erase(it);
	}
}

template <class T>
void Vector<T>::resize() {
  T* temp = buffer_;
  buffer_ = new T [++capacity_];
  for(int  i = 0; i < size_; i++) {
    buffer_[i] = temp[i];
  }
  delete [] temp;
}
