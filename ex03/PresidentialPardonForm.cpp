#include "PresidentialPardonForm.h"

/* Orthodox canonical form requirements */

PresidentialPardonForm::PresidentialPardonForm() : PresidentialPardonForm( "defaultTarget" ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
    : AForm( other ), mTarget{ other.mTarget } {}

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
    : AForm{ "Presidential Pardon Form", "presidential pardon", 25, 5 }, mTarget{ target } {}

/* Getter */

const std::string& PresidentialPardonForm::getTarget() const {
    return mTarget;
}

/* Return a clone of self */

AForm* PresidentialPardonForm::makeCopy() const {
    return new PresidentialPardonForm{ mTarget };
}

/* Return copy of self with specified target */

AForm* PresidentialPardonForm::makeCopy( std::string_view targetName ) const {
    return new PresidentialPardonForm{ targetName };
}

/* Execute this specific form’s action on target */

void PresidentialPardonForm::specificExecute() const {
    std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox." << '\n';
}

/* Insertion operator overload */

std::ostream& operator<<( std::ostream& out, const PresidentialPardonForm& form ) {
    out << "Form name: " << form.getName() << ", Is signed: " << std::boolalpha << form.isSigned()
        << ", Minimum grade to sign: " << form.getGradeToSign()
        << ", Minimum grade to execute: " << form.getGradeToExecute() << ", Target: " << form.getTarget() << '.';

    return out;
}
