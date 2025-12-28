#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>

Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {}
Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits))) {}
Fixed::Fixed(const Fixed &src) : _fixedPointValue(src._fixedPointValue) {}
Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &src) {
	_fixedPointValue = src._fixedPointValue;
	return *this;
}

int Fixed::getRawBits(void) const {
	return _fixedPointValue;
}
void Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}
float Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, Fixed const &src) {
	os << src.toFloat();
	return os;
}

//ex02
bool Fixed::operator>(const Fixed &src) const {
	return _fixedPointValue > src._fixedPointValue;
}
bool Fixed::operator<(const Fixed &src) const {
	return _fixedPointValue < src._fixedPointValue;
}
bool Fixed::operator>=(const Fixed &src) const {
	return _fixedPointValue >= src._fixedPointValue;
}
bool Fixed::operator<=(const Fixed &src) const {
	return _fixedPointValue <= src._fixedPointValue;
}
bool Fixed::operator==(const Fixed &src) const {
	return _fixedPointValue == src._fixedPointValue;
}
bool Fixed::operator!=(const Fixed &src) const {
	return _fixedPointValue != src._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &src) const {
	Fixed res;
	res._fixedPointValue = _fixedPointValue + src._fixedPointValue;
	return res;
}
Fixed Fixed::operator-(const Fixed &src) const {
	Fixed res;
	res._fixedPointValue = _fixedPointValue - src._fixedPointValue;
	return res;
}
Fixed Fixed::operator*(const Fixed &src) const {
	Fixed res;
	res._fixedPointValue = (static_cast<long long>(_fixedPointValue) * src._fixedPointValue) >> _fractionalBits;
	return res;
}
Fixed Fixed::operator/(const Fixed &src) const {
	Fixed res;
	res._fixedPointValue = (static_cast<long long>(_fixedPointValue) << _fractionalBits) / src._fixedPointValue;
	return res;
}

Fixed &Fixed::operator++() {
	_fixedPointValue++;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	_fixedPointValue++;
	return tmp;
}
Fixed &Fixed::operator--() {
	_fixedPointValue--;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	_fixedPointValue--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return a < b ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return a > b ? a : b;
}
