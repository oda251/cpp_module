#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = src._fixedPointValue;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

// ex01
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
	if (std::numeric_limits<int>::max() >> _fractionalBits < value
		|| std::numeric_limits<int>::min() >> _fractionalBits > value)
		std::cerr << "\tOverflow" << std::endl;
}
Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBits))){
	std::cout << "Float constructor called" << std::endl;
	float max = static_cast<float>(std::numeric_limits<int>::max() >> _fractionalBits);
	float min = static_cast<float>(std::numeric_limits<int>::min() >> _fractionalBits);
	if (max < value || min > value)
		std::cerr << "\tOverflow" << std::endl;
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