#include "AForm.h"

/* Orthodox canonical form requirements */

AForm::AForm() : mName{ "noName" }, mIsSigned{ false }, mGradeToSign{ 1 }, mGradeToExecute{ 1 } {}

AForm::AForm( const AForm& other )
    : mName{ other.mName }, mIsSigned{ other.mIsSigned }, mGradeToSign{ other.mGradeToSign },
      mGradeToExecute{ other.mGradeToExecute } {}

AForm& AForm::operator=( const AForm& other ) {
    if ( this != &other ) {
        this->mIsSigned = other.mIsSigned;
    }

    return *this;
}

AForm::~AForm() {}

/* Main parameterized constructor */

AForm::AForm( std::string_view initName, const int initGradeToSign, const int initGradeToExecute )
    : mName{ initName }, mIsSigned{ false }, mGradeToSign{ initGradeToSign }, mGradeToExecute{ initGradeToExecute } {
    if ( initGradeToSign < 1 || initGradeToExecute < 1 )
        throw GradeTooHighException{ "Grade (to sign or execute) cannot be higher than 1!" };
    else if ( initGradeToSign > 150 || initGradeToExecute > 150 )
        throw GradeTooLowException{ "Grade (to sign or execute) cannot be lower than 150!" };
}

/* Getters */

const std::string& AForm::getName() const {
    return mName;
}

bool AForm::isSigned() const {
    return mIsSigned;
}

int AForm::getGradeToSign() const {
    return mGradeToSign;
}

int AForm::getGradeToExecute() const {
    return mGradeToExecute;
}

/* Change form status (if bureaucrat’s grade is high enough) */

void AForm::beSigned( const Bureaucrat& bureaucrat ) {
    if ( mIsSigned )
        throw FormAlreadySigned{ "form is already signed!" };
    else if ( bureaucrat.getGrade() > mGradeToSign )
        throw GradeTooLowException{ "the bureacrat's grade is too low to sign this form!" };
    else
        mIsSigned = true;
}

/* Execute the form (if is signed and bureaucrat’s grade is high enough) */

void AForm::execute( Bureaucrat const& executor ) const {
    if ( !mIsSigned )
        throw FormMustBeSigned{ "form must be signed in order to be executed!" };
    else if ( executor.getGrade() > mGradeToExecute )
        throw GradeTooLowException{ "the bureacrat's grade is too low to execute this form!" };
    else
        specificExecute();
}

/* Grade too high exception constructor and `what` member */

AForm::GradeTooHighException::GradeTooHighException( std::string_view error ) : mError{ error } {}

const char* AForm::GradeTooHighException::what() const noexcept {
    return mError.c_str();
}

/* Grade too low exception constructor and `what` member */

AForm::GradeTooLowException::GradeTooLowException( std::string_view error ) : mError{ error } {}

const char* AForm::GradeTooLowException::what() const noexcept {
    return mError.c_str();
}

/* Form already signed exception constructor and `what` member */

AForm::FormAlreadySigned::FormAlreadySigned( std::string_view error ) : mError{ error } {}

const char* AForm::FormAlreadySigned::what() const noexcept {
    return mError.c_str();
}

/* Form must be signed exception constructor and `what` member */

AForm::FormMustBeSigned::FormMustBeSigned( std::string_view error ) : mError{ error } {}

const char* AForm::FormMustBeSigned::what() const noexcept {
    return mError.c_str();
}

/* Insertion operator overload */

std::ostream& operator<<( std::ostream& out, const AForm& form ) {
    out << "Form name: " << form.getName() << ", Is signed: " << std::boolalpha << form.isSigned()
        << ", Minimum grade to sign: " << form.getGradeToSign()
        << ", Minimum grade to execute: " << form.getGradeToExecute() << '.';

    return out;
}
