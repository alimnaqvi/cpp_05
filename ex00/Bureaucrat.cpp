#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : mName{ "noName" }, mGrade{ 150 } {}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : mName{ other.mName }, mGrade{ other.mGrade } {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
    if ( this != &other )
        this->mGrade = other.mGrade;

    return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat( std::string_view initName, int grade ) : mName{ initName } {
    if ( grade < 1 )
        throw GradeTooHighException{ "Grade cannot be higher than 1!" };
    else if ( grade > 150 )
        throw GradeTooLowException{ "Grade cannot be lower than 150!" };

    mGrade = grade;
}

const std::string& Bureaucrat::getName() const {
    return mName;
}

int Bureaucrat::getGrade() const {
    return mGrade;
}

void Bureaucrat::incrementGrade() {
    if ( mGrade == 1 )
        throw GradeTooHighException{ "Grade cannot be higher than 1!" };

    --mGrade;
}

void Bureaucrat::decrementGrade() {
    if ( mGrade == 150 )
        throw GradeTooLowException{ "Grade cannot be lower than 150!" };

    ++mGrade;
}

/* Grade too high exception constructor and `what` member: */

Bureaucrat::GradeTooHighException::GradeTooHighException( std::string_view error ) : mError{ error } {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return mError.c_str();
}

/* Grade too low exception constructor and `what` member: */

Bureaucrat::GradeTooLowException::GradeTooLowException( std::string_view error ) : mError{ error } {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return mError.c_str();
}

/* Insertion operator overload: */

std::ostream& operator<<( std::ostream& out, const Bureaucrat& bureaucrat ) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.';

    return out;
}
