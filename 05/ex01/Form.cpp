#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}
Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {}
Form::~Form(void) {}
Form &Form::operator=(const Form &src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

const std::string& Form::getName(void) const {
	return _name;
}
bool Form::getSigned(void) const {
	return _signed;
}
int Form::getSignGrade(void) const {
	return _signGrade;
}
int Form::getExecGrade(void) const {
	return _execGrade;
}
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	if (_signed)
		throw Form::FormAlreadySignedException();
	_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw() {
	return "Grade is too high";
}
const char *Form::GradeTooLowException::what(void) const throw() {
	return "Grade is too low";
}
const char *Form::FormAlreadySignedException::what(void) const throw() {
	return "Form is already signed";
}
