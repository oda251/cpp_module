#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(0) {
  *this = src;
}

template <typename T>
Array<T>::~Array(void) {
  delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src) {
  if (this != &src) {
    delete[] _array;
    _array = new T[src._size];
    for (size_t i = 0; i < src._size; i++) {
      _array[i] = src._array[i];
    }
    _size = src._size;
  }
  return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
  if (i >= _size) {
    throw OutOfRangeException();
  }
  return _array[i];
}

template <typename T>
size_t Array<T>::size(void) const {
  return _size;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
  return "Array index out of range";
}
