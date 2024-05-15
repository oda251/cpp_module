#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		// ex02
		Fixed(const int value);
		Fixed(const float value);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &src);

#endif
