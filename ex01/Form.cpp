#include "Form.h"

/* Orthodox canonical form requirements */

Form::Form() : mName{ "noName" }, mIsSigned{ false }, mGradeToSign{ 1 }, mGradeToExecute{ 1 } {}

Form::Form( const Form& other )
    : mName{ other.mName }, mIsSigned{ other.mIsSigned }, mGradeToSign{ other.mGradeToSign },
      mGradeToExecute{ other.mGradeToExecute } {}

Form& Form::operator=( const Form& other ) {
    if ( this != &other ) {
        this->mIsSigned = other.mIsSigned;
    }

    return *this;
}

Form::~Form() {}

/* Main parameterized constructor */

Form::Form( std::string_view initName, const int initGradeToSign, const int initGradeToExecute )
    : mName{ initName }, mIsSigned{ false }, mGradeToSign{ initGradeToSign }, mGradeToExecute{ initGradeToExecute } {
    if ( initGradeToSign < 1 || initGradeToExecute < 1 )
        throw GradeTooHighException{ "Grade (to sign or execute) cannot be higher than 1!" };
    else if ( initGradeToSign > 150 || initGradeToExecute > 150 )
        throw GradeTooLowException{ "Grade (to sign or execute) cannot be lower than 150!" };
}

/* Getters */

const std::string& Form::getName() const {
    return mName;
}

bool Form::isSigned() const {
    return mIsSigned;
}

int Form::getGradeToSign() const {
    return mGradeToSign;
}

int Form::getGradeToExecute() const {
    return mGradeToExecute;
}

/* Change form status (if bureaucrat’s grade is high enough) */

void Form::beSigned( const Bureaucrat& bureaucrat ) {
    if ( bureaucrat.getGrade() <= mGradeToSign )
        mIsSigned = true;
    else
        throw GradeTooLowException{ "the bureacrat's grade is too low to sign this form!" };
}

/* Grade too high exception constructor and `what` member */

Form::GradeTooHighException::GradeTooHighException( std::string_view error ) : mError{ error } {}

const char* Form::GradeTooHighException::what() const noexcept {
    return mError.c_str();
}

/* Grade too low exception constructor and `what` member */

Form::GradeTooLowException::GradeTooLowException( std::string_view error ) : mError{ error } {}

const char* Form::GradeTooLowException::what() const noexcept {
    return mError.c_str();
}

/* Insertion operator overload */

std::ostream& operator<<( std::ostream& out, const Form& form ) {
    out << "Form name: " << form.getName()
        << ", Is signed: " << std::boolalpha << form.isSigned()
        << ", Minimum grade to sign: " << form.getGradeToSign()
        << ", Minimum grade to execute: " << form.getGradeToExecute() << '.';

    return out;
}
