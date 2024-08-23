#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		static const int _signGrade = 25;
		static const int _execGrade = 5;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(PresidentialPardonForm const & src);
		const std::string& getTarget(void) const;
		void setTarget(std::string const & target);

		void execute(Bureaucrat const & executor) const;
		AForm *newForm(std::string const & target) const;
};
