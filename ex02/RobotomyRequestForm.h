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

  protected:
    // Function to execute this specific form
    void specificExecute() const override;

  private:
    std::string mTarget;
};

#endif /* ROBOTOMYREQUESTFORM_H */
