#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {}
Intern::Intern(Intern const &src) {
  *this = src;
}
Intern::~Intern(void) {}
Intern & Intern::operator=(Intern const &src) {
  return *this;
}

const AForm *Intern::_plainForms[3] = {
  new ShrubberyCreationForm(),
  new PresidentialPardonForm(),
  new RobotomyRequestForm()
};

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
  for (int i = 0; i < 3; i++) {
    if (formName == _plainForms[i]->getName()) {
      std::cout << "Intern creates " << formName << std::endl;
      return _plainForms[i]->newForm(target);
    }
  }
  throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
  return "Form not found";
}

void Intern::cleanUp(void) {
  for (int i = 0; i < 3; i++) {
    delete _plainForms[i];
  }
}

