#pragma once
#include <stddef.h>

template <typename T>
void iter(T *array, size_t length, void (*func)(T&));