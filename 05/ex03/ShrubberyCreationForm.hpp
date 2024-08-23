#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		static const int _signGrade = 145;
		static const int _execGrade = 137;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & src);
		const std::string& getTarget(void) const;
		void setTarget(std::string const & target);

		void execute(Bureaucrat const & executor) const;
		AForm *newForm(std::string const & target) const;

		class GetCwdFailureException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FileOpeningFailureException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
