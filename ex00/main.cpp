#include "Bureaucrat.h"
#include <iostream>
#include <exception>

int main() {
    try {
        Bureaucrat A;
        std::cout << A << '\n';

        Bureaucrat B{ "B", 25 };
        std::cout << B << '\n';

        Bureaucrat const Bcopy{ B };
        std::cout << Bcopy << '\n';

        const Bureaucrat C{ "C", 200 };
        std::cout << C << '\n';

        std::cout << "This will not execute because the above will throw an exception." << '\n';
    } catch ( const std::exception& e ) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
    }

    std::cout << "----------------------------------------" << '\n';

    Bureaucrat* a{ nullptr };
    Bureaucrat* c{ nullptr };
    try {
        a = new Bureaucrat{ "a", 1 };
        std::cout << *a << '\n';

        Bureaucrat b{ "b", 110 };
        b = *a;
        std::cout << b << '\n';

        c = new Bureaucrat{ "c", -1 };
        // Below will not execute because above will throw an exception
        std::cout << *c << '\n';

        Bureaucrat d{ "d", 1000 };
        std::cout << d << '\n';

    } catch ( const Bureaucrat::GradeTooHighException& e ) {
        std::cerr << "A GradeTooHighException exception occurred: " << e.what() << '\n';
    } catch ( const Bureaucrat::GradeTooLowException& e ) {
        std::cerr << "A GradeTooLowException exception occurred: " << e.what() << '\n';
    } catch ( const std::exception& e ) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
    }
    delete a;
    delete c;

    std::cout << "----------------------------------------" << '\n';

    try {
        Bureaucrat marie{ "Marie", 2 };
        std::cout << marie << '\n';

        marie.incrementGrade();
        std::cout << marie.getName() << "'s grade after promotion: " << marie.getGrade() << '\n';

        marie.incrementGrade();
        // Below will not execute because above will throw an exception
        std::cout << marie.getName() << "'s grade after second promotion: " << marie.getGrade() << '\n';

    } catch ( const std::exception& e ) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
    }

    std::cout << "----------------------------------------" << '\n';

    try {
        Bureaucrat robert{ "Robert", 149 };
        std::cout << robert << '\n';

        robert.decrementGrade();
        std::cout << robert.getName() << "'s grade after demotion: " << robert.getGrade() << '\n';

        robert.decrementGrade();
        // Below will not execute because above will throw an exception
        std::cout << robert.getName() << "'s grade after second demotion: " << robert.getGrade() << '\n';

    } catch ( const std::exception& e ) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
    }

    return 0;
}
