#pragma once
#include <stddef.h>

template <typename T>
class Array {
  private:
    T *_array;
    size_t _size;
  public:
    Array(void);
    Array(unsigned int n);
    Array(Array const &src);
    ~Array(void);
    Array &operator=(Array const &src);
    T& operator[](unsigned int i);

    size_t size(void) const;

    class OutOfRangeException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

#include "Array.tpp"