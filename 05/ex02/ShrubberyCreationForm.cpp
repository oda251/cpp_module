#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <dirent.h>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", SHRUBBERY_FORM_SIGNGRADE, SHRUBBERY_FORM_EXECGRADE),
	_target("default")
	{}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	AForm("ShrubberyCreationForm", SHRUBBERY_FORM_SIGNGRADE, SHRUBBERY_FORM_EXECGRADE),
	_target(target)
	{}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	AForm(src),
	_target(src._target)
	{}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget(void) const {
	return _target;
}
void ShrubberyCreationForm::setTarget(std::string const & target) {
	_target = target;
}

static std::string get_ascii_tree_of_working_directory(void) {
	DIR* dir = opendir(".");
	if (!dir)
	{
		std::cerr << "couldn't open directory."
	}
	dir = 
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::ofstream file;
	file.open(_target + "_shrubbery");
	std::string tree = get_ascii_tree_of_working_directory();
	file.close();
}
