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

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}