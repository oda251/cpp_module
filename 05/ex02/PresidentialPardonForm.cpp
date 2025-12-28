#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("presidential pardon", _signGrade, _execGrade),
	_target("default")
	{}
PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	AForm("presidential pardon", _signGrade, _execGrade),
	_target(target)
	{}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	AForm(src),
	_target(src._target)
	{}
PresidentialPardonForm::~PresidentialPardonForm(void) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

const std::string& PresidentialPardonForm::getTarget(void) const {
	return _target;
}
void PresidentialPardonForm::setTarget(std::string const & target) {
	_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getSigned()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > _execGrade) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm *PresidentialPardonForm::newForm(std::string const & target) const {
	return new PresidentialPardonForm(target);
}
