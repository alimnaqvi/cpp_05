#ifndef INTERN_H
#define INTERN_H

#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <string>
#include <exception>
#include <cctype> // for std::toupper

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
  public:
    // Orthodox canonical form
    Intern();
    Intern( const Intern& other );
    Intern& operator=( const Intern& other );
    ~Intern();

    // Main ability of intern
    AForm* makeForm( std::string formName, std::string_view targetName ) const;

    // Exception class
    class FormNotKnown : public std::exception {
      public:
        FormNotKnown( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };
  
  private:
    AForm* mKnownForms[3];
};

#endif /* INTERN_H */
