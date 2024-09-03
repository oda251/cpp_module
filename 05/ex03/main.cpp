#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		delete rrf;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		delete rrf;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("nonexistent form", "Bender");
		delete rrf;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	Intern::cleanUp();
	return 0;
}
