#include "PresidentialPardonForm.h"

/* Orthodox canonical form requirements */

PresidentialPardonForm::PresidentialPardonForm()
    : AForm{ "Presidential Pardon Form", 25, 5 }, mTarget{ "defaultTarget" } {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
    : AForm{ other.getName(), other.getGradeToSign(), other.getGradeToExecute() }, mTarget{ other.mTarget } {}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
    if ( this != &other ) {
        AForm::operator=( other );
        mTarget = other.mTarget;
    }

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/* Main parameterized constructor */

PresidentialPardonForm::PresidentialPardonForm( std::string_view target )
    : AForm{ "Presidential Pardon Form", 25, 5 }, mTarget{ target } {}

/* Getter */

const std::string& PresidentialPardonForm::getTarget() const {
    return mTarget;
}

/* Execute this specific form’s action on target */

void PresidentialPardonForm::specificExecute() const {
    std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox." << '\n';
}

/* Insertion operator overload */

std::ostream& operator<<( std::ostream& out, const PresidentialPardonForm& form ) {
    out << "Form name: " << form.getName()
        << ", Is signed: " << std::boolalpha << form.isSigned()
        << ", Minimum grade to sign: " << form.getGradeToSign()
        << ", Minimum grade to execute: " << form.getGradeToExecute()
        << ", Target: " << form.getTarget() << '.';

    return out;
}
