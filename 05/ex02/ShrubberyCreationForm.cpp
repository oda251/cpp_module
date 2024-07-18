#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#define CROSS " ├─"
#define CORNER " └─"
#define VERTICAL " │ "
#define SPACE "   "

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", _signGrade, _execGrade),
	_target("default")
	{}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	AForm("ShrubberyCreationForm", _signGrade, _execGrade),
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

static void get_ascii_tree(std::string path, std::ofstream& out, DIR* dir, std::string prefix) {
	struct dirent* entry;
	struct dirent* next;
	entry = readdir(dir);
	next = readdir(dir);
	while (entry) {
		if (entry->d_type == DT_DIR) {
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
				goto label;
			}
			out << prefix << (next ? CROSS : CORNER) << entry->d_name << "\n";
			std::string sub_path = path + "/" + entry->d_name;
			DIR* subdir = opendir(sub_path.c_str());
			get_ascii_tree(sub_path, out, subdir, prefix + (next ? VERTICAL : SPACE));
		} else {
			out << prefix << (next ? CROSS : CORNER) << entry->d_name << "\n";
		}
		label:
		entry = next;
		if (next) {
			next = readdir(dir);
		}
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSigned()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > _execGrade) {
		throw GradeTooLowException();
	}
	std::ofstream out;
	out.open(_target + "_shrubbery");
	if (!out.is_open()) {
		std::cerr << "couldn't open file." << std::endl;
		throw std::exception();
	}
	char path[1024];
	if (!getcwd(path, sizeof(path))) {
		std::cerr << "couldn't get current working directory." << std::endl;
		throw std::exception();
	}
	DIR* dir = opendir(path);
	if (!dir) {
		std::cerr << "couldn't open directory." << std::endl;
		throw std::exception();
	}
	out << path << "\n";
	get_ascii_tree(path, out, dir, "");
	out.close();
}
