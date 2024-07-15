#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
	Bureaucrat boss = Bureaucrat("Boss", 1);
	Bureaucrat underling = Bureaucrat("Underling", 150);
	std::cout << boss << std::endl;
	std::cout << underling << std::endl;

	Form form = Form("Form", 100, 100);
	std::cout << "--- sign Form, signLevel is 100 ---" << std::endl;
	try
	{
		underling.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		boss.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--- sign Form again ---" << std::endl;
	try
	{
		boss.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
