#pragma once
#include <stdexcept>
#include "Array.hpp"

template<typename T>
Array<T>::Array() :
  arr_(NULL),
  size_(0) {}

template<typename T>
Array<T>::Array(unsigned int n) :
  arr_(new T[n]),
  size_(n) {}

template<typename T>
Array<T>::Array(const Array<T>& src) {
  *this = src;
}

template<typename T>
Array<T>::~Array() {
  delete[] arr_;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
  if (this == &src)
    return ;
  if (arr_)
    delete[] arr_;
  arr_ = new T[src.size_];
  size_ = src.size_;
  for (unsigned int i = 0; i < size_; i++) {
    arr_[i] = src.arr_[i];
  }
}

template<typename T>
T& Array<T>::operator[](unsigned int idx) {
  if (idx >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return arr_[idx];
}

template<typename T>
const T& Array<T>::operator[](unsigned int idx) const {
  if (idx >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return arr_[idx];
}

template<typename T>
unsigned int Array<T>::size(void) const {
  return size_;
}
