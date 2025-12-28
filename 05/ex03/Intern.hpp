#pragma once

#include <string>
#include "AForm.hpp"

class Intern {
  private:
    static const AForm* _plainForms[3];
  public:
    Intern(void);
    Intern(Intern const &src);
    ~Intern(void);
    Intern & operator=(Intern const &src);

    AForm* makeForm(std::string const &formName, std::string const &target);
    class FormNotFoundException : public std::exception {
      public:
        const char* what() const throw();
    };
    static void cleanUp(void);
};
