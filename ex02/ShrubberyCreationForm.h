#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#define TREE "Test tree" // ! Need to implement

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
  public:
    // Orthodox canonical form requirements
    ShrubberyCreationForm();
    ShrubberyCreationForm( const ShrubberyCreationForm& other );
    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
    ~ShrubberyCreationForm() override;

    // Main parameterized constructor
    ShrubberyCreationForm( std::string_view target );

    // Getter
    const std::string& getTarget() const;

    // Shrubbery-specific exception
    class CouldNotOpenFile : public std::exception {
      public:
        CouldNotOpenFile( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };

  protected:
    // Function to execute this specific form
    void specificExecute() const override;

  private:
    std::string mTarget;
};

#endif /* SHRUBBERYCREATIONFORM_H */
