#include "Intern.h"

/* Orthodox canonical form requirement */
Intern::Intern() {}

Intern::Intern( const Intern& other ) {
    // Nothing to copy initialize with since there are no data members
}

Intern& Intern::operator=( const Intern& other ) {
    // Nothing to copy since there are no data members
    return *this;
}

Intern::~Intern() {}

/* Main ability of intern */

AForm* Intern::makeForm( std::string_view formName, std::string_view targetName ) const {
    //
}
