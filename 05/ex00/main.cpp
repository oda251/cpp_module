#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	Bureaucrat bob = Bureaucrat("Bob", 1);
	std::cout << bob << std::endl;
	try
	{
		std::cout << "-- Bob Incrementing grade ---" << std::endl;
		bob.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "-- Intend to Create Jim, grade is 0 ---" << std::endl;
		Bureaucrat jim = Bureaucrat("Jim", 0);
		std::cout << jim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
