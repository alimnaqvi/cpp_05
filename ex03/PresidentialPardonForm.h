#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>
#include <string>

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm {
  public:
    // Orthodox canonical form requirements
    PresidentialPardonForm();
    PresidentialPardonForm( const PresidentialPardonForm& other );
    PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
    ~PresidentialPardonForm() override;

    // Main parameterized constructor
    PresidentialPardonForm( std::string_view target );

    // Getter
    const std::string& getTarget() const;

  protected:
    // Function to execute this specific form
    void specificExecute() const override;

  private:
    std::string mTarget;
};

std::ostream& operator<<( std::ostream& out, const PresidentialPardonForm& form );

#endif /* PRESIDENTIALPARDONFORM_H */
