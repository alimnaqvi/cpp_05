#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>
#include <exception>

int main() {
    try {
        std::cout << "----------------------------------" << '\n';

        Bureaucrat marie{ "Marie", 10 };
        std::cout << marie << '\n';

        Bureaucrat robert{ "Robert", 55 };
        std::cout << robert << '\n';

        Bureaucrat david{ "David", 138 };
        std::cout << david << '\n';

        std::cout << "----------------------------------" << '\n';

        ShrubberyCreationForm shrubbery1{ "Garden" };
        std::cout << shrubbery1 << '\n';

        RobotomyRequestForm robotomy1{ "Megawatt" };
        std::cout << robotomy1 << '\n';

        PresidentialPardonForm presidential1{ "Don Vito Corleone" };
        std::cout << presidential1 << '\n';

        // Marie can sign all forms
        marie.signForm( shrubbery1 );
        marie.signForm( robotomy1 );
        marie.signForm( presidential1 );

        // Marie can execute shrubbery and robotomy forms
        marie.executeForm( shrubbery1 );
        marie.executeForm( robotomy1 );
        marie.executeForm( presidential1 );

        // Let's give Marie 5 promotions
        for ( int i{ 0 }; i < 5; ++i )
            marie.incrementGrade();
        std::cout << marie.getName() << " got 5 promotions and her grade is now " << marie.getGrade() << '\n';

        // Marie can now execute presidential pardon form
        marie.executeForm( presidential1 );

        std::cout << "----------------------------------" << '\n';

        ShrubberyCreationForm shrubbery2{ "Office" };
        std::cout << shrubbery2 << '\n';

        RobotomyRequestForm robotomy2{ "Thunderbite" };
        std::cout << robotomy2 << '\n';

        PresidentialPardonForm presidential2{ "Michael Corleone" };
        std::cout << presidential2 << '\n';

        // Robert signs
        robert.signForm( shrubbery2 );
        robert.signForm( robotomy2 );
        robert.signForm( presidential2 );

        // Robert executes
        robert.executeForm( shrubbery2 );
        robert.executeForm( robotomy2 );
        robert.executeForm( presidential2 );

        std::cout << "----------------------------------" << '\n';

        ShrubberyCreationForm shrubbery3{ "Home" };
        std::cout << shrubbery3 << '\n';

        RobotomyRequestForm robotomy3{ "Thresher" };
        std::cout << robotomy3 << '\n';

        PresidentialPardonForm presidential3{ "Sonny Corleone" };
        std::cout << presidential3 << '\n';

        // David signs
        david.signForm( shrubbery3 );
        david.signForm( robotomy3 );
        david.signForm( presidential3 );

        // David executes
        david.executeForm( shrubbery3 );
        david.executeForm( robotomy3 );
        david.executeForm( presidential3 );

        // David gets a promotion
        david.incrementGrade();
        std::cout << david.getName() << " got a promotion and his grade is now " << david.getGrade() << '\n';
        david.signForm( shrubbery3 );
        david.executeForm( shrubbery3 );

        std::cout << "----------------------------------" << '\n';
    } catch ( const std::exception& e ) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
    }

    return 0;
}
