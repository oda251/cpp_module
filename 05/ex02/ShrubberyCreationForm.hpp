#pragma once
#include "AForm.hpp"
#define SHRUBBERY_FORM_SIGNGRADE 145
#define SHRUBBERY_FORM_EXECGRADE 137

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & src);
		const std::string& getTarget(void) const;
		void setTarget(std::string const & target);

		void execute(Bureaucrat const & executor) const;
};
