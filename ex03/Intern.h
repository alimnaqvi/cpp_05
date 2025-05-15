#ifndef INTERN_H
#define INTERN_H

#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <string>

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
    AForm* makeForm( std::string_view formName, std::string_view targetName );
};

#endif /* INTERN_H */
