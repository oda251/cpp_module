#include <iostream>
#include <string>
#include <cstdlib>
#include "Fixed.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main( void ) {
	Fixed			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "--- pdf-example test ---" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "--- x=8.765f, y=0.5f ---" << std::endl;
	Fixed x(8.765f);
	Fixed y(0.5f);
	std::cout << "--- x ---" << std::endl;
	std::cout << x << std::endl;
	std::cout << "--- y ---" << std::endl;
	std::cout << y << std::endl;
	
	std::cout << "--- x > y ---" << std::endl;
	std::cout << (x > y) << std::endl;
	std::cout << "--- x < y ---" << std::endl;
	std::cout << (x < y) << std::endl;
	std::cout << "--- x >= y ---" << std::endl;
	std::cout << (x >= y) << std::endl;
	std::cout << "--- x <= y ---" << std::endl;
	std::cout << (x <= y) << std::endl;
	std::cout << "--- x == y ---" << std::endl;
	std::cout << (x == y) << std::endl;
	std::cout << "--- x != y ---" << std::endl;
	std::cout << (x != y) << std::endl;
	std::cout << "--- x + y ---" << std::endl;
	std::cout << (x + y) << std::endl;
	std::cout << "--- x - y ---" << std::endl;
	std::cout << (x - y) << std::endl;
	std::cout << "--- x * y ---" << std::endl;
	std::cout << (x * y) << std::endl;
	std::cout << "--- x / y ---" << std::endl;
	std::cout << (x / y) << std::endl;
	std::cout << "--- x++ ---" << std::endl;
	std::cout << x++ << std::endl;
	std::cout << "--- ++x ---" << std::endl;
	std::cout << ++x << std::endl;
	std::cout << "--- x-- ---" << std::endl;
	std::cout << x-- << std::endl;
	std::cout << "--- --x ---" << std::endl;
	std::cout << --x << std::endl;
	std::cout << "--- min(x, y) ---" << std::endl;
	std::cout << Fixed::min(x, y) << std::endl;
	std::cout << "--- max(x, y) ---" << std::endl;
	std::cout << Fixed::max(x, y) << std::endl;

	return 0;
}