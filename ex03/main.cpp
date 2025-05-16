#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"
#include <iostream>
#include <exception>

int main() {
    AForm* shrubbery    = nullptr;
    AForm* robotomy     = nullptr;
    AForm* presidential = nullptr;
    AForm* abcdef       = nullptr;

    try {
        Intern randomIntern1;
        Intern randomIntern2;
        Intern randomIntern3;

        shrubbery = randomIntern1.makeForm( "shrubbery creation", "Park" );
        std::cout << *shrubbery << '\n';

        robotomy = randomIntern2.makeForm( "robotomy request", "Blastus" );
        std::cout << *robotomy << '\n';

        presidential = randomIntern3.makeForm( "presidential pardon", "Julius Caesar" );
        std::cout << *presidential << '\n';

        abcdef = randomIntern1.makeForm( "something something", "someone" );

        std::cout << "This and below won't be reached because the previous line will throw an exception." << '\n';
        delete abcdef;
        abcdef = randomIntern2.makeForm( "abcdef", "hello" );
        delete abcdef;
        abcdef = randomIntern3.makeForm( "hdkjfhkd", "garbage" );

    } catch ( const std::exception& e ) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
    }

    delete shrubbery;
    delete robotomy;
    delete presidential;
    delete abcdef;

    return 0;
}
