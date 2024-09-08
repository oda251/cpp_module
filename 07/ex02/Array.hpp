#pragma once

template<typename T>
class Array {
  private:
    T *arr_;
    unsigned int size_;

  public:
    Array();
    Array(unsigned int len);
    Array(const Array &src);
    ~Array();
    Array& operator=(const Array &src);
    T& operator[](unsigned int idx);
    const T& operator[](unsigned int idx) const;
    unsigned int size(void) const;
};

#include "Array.tpp"
