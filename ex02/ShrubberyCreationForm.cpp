#include "ShrubberyCreationForm.h"

/* Orthodox canonical form requirements */

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm{ "Shrubbery Creation Form", 145, 137 }, mTarget{ "defaultTarget" } {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
    : AForm{ other.getName(), other.getGradeToSign(), other.getGradeToExecute() }, mTarget{ other.mTarget } {}

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
    : AForm{ "Shrubbery Creation Form", 145, 137 }, mTarget{ target } {}

/* Getter */

const std::string& ShrubberyCreationForm::getTarget() const {
    return mTarget;
}

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
