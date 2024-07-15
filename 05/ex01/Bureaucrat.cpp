#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}
Bureaucrat::~Bureaucrat(void) {}

std::string const& Bureaucrat::getName(void) const {
	return _name;
}
int Bureaucrat::getGrade(void) const {
	return _grade;
}
void Bureaucrat::incrementGrade(void) {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade(void) {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade is too high";
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

// ex01
bool Bureaucrat::signForm(Form& form) const {
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
		return true;
	}
	catch (std::exception &e)
	{
		std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return false;
	}
}
