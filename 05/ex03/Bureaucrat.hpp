#pragma once
#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();
		std::string const& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		// ex01
		bool signForm(AForm& AForm) const;

		// ex02
		bool executeForm(AForm const &AForm) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);