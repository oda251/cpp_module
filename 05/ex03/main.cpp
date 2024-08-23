#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

__attribute__((destructor))
void    destructor(void)
{
	#ifdef LEAKS
	std::cout << "--- Destructor ---" << std::endl;
	system(LEAKS);
	#endif
}

int main(void) {
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
	return 0;
}
