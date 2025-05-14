#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "AForm.h"
#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
  public:
    // Orthodox canonical form
    Bureaucrat();
    Bureaucrat( const Bureaucrat& other );
    Bureaucrat& operator=( const Bureaucrat& other );
    ~Bureaucrat();

    // String and grade constructor
    Bureaucrat( std::string_view initName, int grade );

    // Getters
    const std::string& getName() const;
    int                getGrade() const;

    // Increment and decrement the private grade member
    void incrementGrade();
    void decrementGrade();

    // (Attempt to) sign a form
    void signForm( AForm& form ) const;

    // (Attempt to) execute a form
    void executeForm( AForm const& form ) const;

    // Exception classes
    class GradeTooHighException : public std::exception {
      public:
        GradeTooHighException( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };

    class GradeTooLowException : public std::exception {
      public:
        GradeTooLowException( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };

  private:
    const std::string mName;
    int               mGrade;
};

std::ostream& operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif /* BUREAUCRAT_H */
