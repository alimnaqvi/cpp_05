#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>

class Form {
  public:
    // Orthodox canonical form requirements
    Form();
    Form( const Form& other );
    Form& operator=( const Form& other );
    ~Form();

    // Parameterized constructor
    Form( std::string_view initName, const int initGradeToSign, const int initGradeToExecute );

    // Getters
    const std::string& getName() const;
    bool               isSigned() const;
    const int          getGradeToSign() const;
    const int          getGradeToExecute() const;

    // Change form status (if bureaucrat’s grade is high enough)
    void beSigned( const Bureaucrat& bureaucrat );

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
    bool              mIsSigned;
    const int         mGradeToSign;
    const int         mGradeToExecute;
};

std::ostream& operator<<( std::ostream& out, const Form& form );

#endif /* FORM_H */
