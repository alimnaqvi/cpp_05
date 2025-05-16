#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>
#include <string>
#include <exception>
#include <random>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
  public:
    // Orthodox canonical form requirements
    RobotomyRequestForm();
    RobotomyRequestForm( const RobotomyRequestForm& other );
    RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
    ~RobotomyRequestForm() override;

    // Main parameterized constructor
    RobotomyRequestForm( std::string_view target );

    // Getter
    const std::string& getTarget() const;

    // Return a clone of self
    AForm* makeCopy() const override;

    // Return copy of self with specified target
    AForm* makeCopy( std::string_view targetName ) const override;

  protected:
    // Function to execute this specific form
    void specificExecute() const override;

  private:
    std::string mTarget;
};

std::ostream& operator<<( std::ostream& out, const RobotomyRequestForm& form );

#endif /* ROBOTOMYREQUESTFORM_H */
