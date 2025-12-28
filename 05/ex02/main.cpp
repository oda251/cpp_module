#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
	Bureaucrat boss = Bureaucrat("Boss", 1);
	Bureaucrat underling = Bureaucrat("Underling", 150);

	ShrubberyCreationForm shrubbery = ShrubberyCreationForm("shrubbery");
	PresidentialPardonForm president = PresidentialPardonForm("president");
	RobotomyRequestForm robotomy = RobotomyRequestForm("robotomy");

	std::cout << "--- test by underling ---" << std::endl;
	std::cout << underling << std::endl;
	underling.executeForm(shrubbery);
	underling.executeForm(president);
	underling.executeForm(robotomy);
	underling.signForm(shrubbery);
	underling.signForm(president);
	underling.signForm(robotomy);
	underling.executeForm(shrubbery);
	underling.executeForm(president);
	underling.executeForm(robotomy);

	std::cout << "--- test by boss ---" << std::endl;
	std::cout << boss << std::endl;
	boss.executeForm(shrubbery);
	boss.executeForm(president);
	boss.executeForm(robotomy);
	boss.signForm(shrubbery);
	boss.signForm(president);
	boss.signForm(robotomy);
	boss.executeForm(shrubbery);
	boss.executeForm(president);
	boss.executeForm(robotomy);

	return 0;
}
