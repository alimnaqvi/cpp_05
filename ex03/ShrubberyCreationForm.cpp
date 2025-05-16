#include "ShrubberyCreationForm.h"

/* Orthodox canonical form requirements */

ShrubberyCreationForm::ShrubberyCreationForm() : ShrubberyCreationForm( "defaultTarget" ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
    : AForm( other ), mTarget{ other.mTarget } {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
    if ( this != &other ) {
        AForm::operator=( other );
        mTarget = other.mTarget;
    }

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Main parameterized constructor */

ShrubberyCreationForm::ShrubberyCreationForm( std::string_view target )
    : AForm{ "Shrubbery Creation Form", "shrubbery creation", 145, 137 }, mTarget{ target } {}

/* Getter */

const std::string& ShrubberyCreationForm::getTarget() const {
    return mTarget;
}

/* Return a clone of self */

AForm* ShrubberyCreationForm::makeCopy() const {
    return new ShrubberyCreationForm{ mTarget };
}

/* Return copy of self with specified target */

AForm* ShrubberyCreationForm::makeCopy( std::string_view targetName ) const {
    return new ShrubberyCreationForm{ targetName };
}

/* Helper non-member function */

void drawTree( std::ofstream& outfileStream ) {
    int         heightWithoutTrunk{ 15 };
    int         trunkHeight{ 5 };
    std::string leef{ "*" };
    std::string trunk{ "▓" };

    for ( int i = 0; i < heightWithoutTrunk; ++i ) {
        for ( int j = heightWithoutTrunk - i; j > 0; --j )
            outfileStream << " ";

        for ( int j = 0; j < i; ++j )
            outfileStream << leef;

        for ( int j = 0; j < i; ++j )
            outfileStream << leef;

        outfileStream << '\n';
    }

    for ( int i = 0; i < trunkHeight; ++i ) {
        for ( int j = 0; j < heightWithoutTrunk - 1; ++j )
            outfileStream << " ";
        outfileStream << trunk << '\n';
    }
}

/* Execute this specific form’s action on target */

void ShrubberyCreationForm::specificExecute() const {
    std::string outfileName{ mTarget + "_shrubbery" };

    std::ofstream outfileStream{ outfileName };
    if ( !outfileStream )
        throw CouldNotOpenFile{ outfileName + " could not be opened for writing." };

    for ( int i = 0; i < 5; ++i ) {
        drawTree( outfileStream );
        outfileStream << "\n\n";
    }

    outfileStream.close();
}

/* Could not open file exception constructor and `what` member */

ShrubberyCreationForm::CouldNotOpenFile::CouldNotOpenFile( std::string_view error ) : mError{ error } {}

const char* ShrubberyCreationForm::CouldNotOpenFile::what() const noexcept {
    return mError.c_str();
}

/* Insertion operator overload */

std::ostream& operator<<( std::ostream& out, const ShrubberyCreationForm& form ) {
    out << "Form name: " << form.getName() << ", Is signed: " << std::boolalpha << form.isSigned()
        << ", Minimum grade to sign: " << form.getGradeToSign()
        << ", Minimum grade to execute: " << form.getGradeToExecute() << ", Target: " << form.getTarget() << '.';

    return out;
}
