#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}
AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {}
AForm::~AForm(void) {}
AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		_signed = src._signed;
	return *this;
}

const std::string& AForm::getName(void) const {
	return _name;
}
bool AForm::getSigned(void) const {
	return _signed;
}
int AForm::getSignGrade(void) const {
	return _signGrade;
}
int AForm::getExecGrade(void) const {
	return _execGrade;
}
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (_signed)
		throw AForm::FormAlreadySignedException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what(void) const throw() {
	return "Grade is too high";
}
const char *AForm::GradeTooLowException::what(void) const throw() {
	return "Grade is too low";
}
const char *AForm::FormAlreadySignedException::what(void) const throw() {
	return "AForm is already signed";
}
const char *AForm::FormNotSignedException::what(void) const throw() {
	return "AForm is not signed";
}