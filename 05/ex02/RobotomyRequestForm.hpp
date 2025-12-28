#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		static const int _signGrade = 72;
		static const int _execGrade = 45;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(RobotomyRequestForm const & src);

		const std::string& getTarget(void) const;
		void setTarget(std::string const & target);

		void execute(Bureaucrat const & executor) const;
		AForm *newForm(std::string const & target) const;
};
