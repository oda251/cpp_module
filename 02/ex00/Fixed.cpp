#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = src.getRawBits();
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = src.getRawBits();
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
