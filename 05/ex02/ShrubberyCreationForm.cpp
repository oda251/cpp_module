#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <dirent.h>
#define CROSS " ├─"
#define CORNER " └─"
#define VERTICAL " │ "
#define SPACE "   "

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

static std::string get_ascii_tree(std::ofstream out, DIR* dir, std::string prefix, bool is_last) {
	struct dirent* entry;
	while ((entry = readdir(dir))) {
		if (entry->d_type == DT_DIR) {
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
				continue;
			}
			out << prefix << (is_last ? CORNER : CROSS) << entry->d_name << "\n";
			get_ascii_tree(out, dir, prefix + (is_last ? SPACE : VERTICAL), false);
		} else {
			out << prefix << (is_last ? CORNER : CROSS) << entry->d_name << "\n";
		}
	}
	return tree;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::ofstream out;
	out.open(_target + "_shrubbery");
	DIR* dir = opendir(".");
	if (!dir) {
		std::cerr << "couldn't open directory."
		throw std::exception();
	}
	out << ".\n";
	get_ascii_tree_of_working_directory(dir, "", true);
	file.close();
}
