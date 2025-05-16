#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>

class Bureaucrat;

class AForm {
  public:
    // Orthodox canonical form requirements
    AForm();
    AForm( const AForm& other );
    AForm& operator=( const AForm& other );
    virtual ~AForm();

    // Parameterized constructor
    AForm( std::string_view initName, std::string_view initType, const int initGradeToSign,
           const int initGradeToExecute );

    // Getters
    const std::string& getName() const;
    const std::string& getType() const;
    bool               isSigned() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;

    // Change form status (if bureaucrat’s grade is high enough)
    void beSigned( const Bureaucrat& bureaucrat );

    // Execute the form (if is signed and bureaucrat’s grade is high enough)
    void execute( Bureaucrat const& executor ) const;

    // Return a clone of self
    virtual AForm* makeCopy() const = 0;

    // Return a copy of self with specified target
    virtual AForm* makeCopy( std::string_view targetName ) const = 0;

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

    class FormAlreadySigned : public std::exception {
      public:
        FormAlreadySigned( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };

    class FormMustBeSigned : public std::exception {
      public:
        FormMustBeSigned( std::string_view error );
        const char* what() const noexcept override;

      private:
        const std::string mError{};
    };

  protected:
    // Pure virtual function that is defined by each derived form
    virtual void specificExecute() const = 0;

  private:
    const std::string mName;
    const std::string mType;
    bool              mIsSigned;
    const int         mGradeToSign;
    const int         mGradeToExecute;
};

std::ostream& operator<<( std::ostream& out, const AForm& form );

#endif /* AFORM_H */
