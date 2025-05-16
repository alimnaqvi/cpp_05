#include "Intern.h"

/* Orthodox canonical form requirement */
Intern::Intern() {
    mKnownForms[0] = new ShrubberyCreationForm;
    mKnownForms[1] = new RobotomyRequestForm;
    mKnownForms[2] = new PresidentialPardonForm;
}

Intern::Intern( const Intern& other ) {
    for ( int i{ 0 }; i < 3; ++i ) {
        // For deep copy: clone the other's known forms (check for NULL before dereferencing)
        if ( other.mKnownForms[i] )
            mKnownForms[i] = other.mKnownForms[i]->makeCopy();
        else
            mKnownForms[i] = other.mKnownForms[i];
    }
}

Intern& Intern::operator=( const Intern& other ) {
    if ( this != &other ) {
        for ( int i{ 0 }; i < 3; ++i ) {
            // delete own known forms first
            delete mKnownForms[i];
            mKnownForms[i] = nullptr;
            // For deep copy: clone the other's known forms (check for NULL before dereferencing)
            if ( other.mKnownForms[i] )
                mKnownForms[i] = other.mKnownForms[i]->makeCopy();
            else
                mKnownForms[i] = other.mKnownForms[i];
        }
    }

    return *this;
}

Intern::~Intern() {
    for ( int i{ 0 }; i < 3; ++i ) {
        delete mKnownForms[i];
    }
}

/* Main ability of intern */

AForm* Intern::makeForm( std::string formName, std::string_view targetName ) const {
    // Convert formName to lowercase to make it case insensitive
    for ( char& c : formName )
        c = std::tolower( c );

    for ( int i{ 0 }; i < 3; ++i ) {
        if ( formName == mKnownForms[i]->getType() ) {
            std::cout << "Intern creates " << mKnownForms[i]->getName() << '\n';
            return mKnownForms[i]->makeCopy( targetName );
        }
    }

    throw FormNotKnown( "Intern does not know how to create " + formName );

    return nullptr;
}

/* Form not known exception constructor and `what` member */

Intern::FormNotKnown::FormNotKnown( std::string_view error ) : mError{ error } {}

const char* Intern::FormNotKnown::what() const noexcept {
    return mError.c_str();
}
