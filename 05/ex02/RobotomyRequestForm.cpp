#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", _signGrade, _execGrade),
	_target("default")
	{}
RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	AForm("RobotomyRequestForm", _signGrade, _execGrade),
	_target(target)
	{}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	AForm(src),
	_target(src._target)
	{}
RobotomyRequestForm::~RobotomyRequestForm(void) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

const std::string& RobotomyRequestForm::getTarget(void) const {
	return _target;
}
void RobotomyRequestForm::setTarget(std::string const & target) {
	_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSigned()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > _execGrade) {
		throw GradeTooLowException();
	}
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
