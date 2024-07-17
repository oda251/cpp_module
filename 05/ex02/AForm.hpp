#pragma once
#include <string>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		AForm(void);
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &src);
		virtual ~AForm(void);
		AForm &operator=(const AForm &src);
		const std::string& getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
