#include "AForm.h"
#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>
#include <exception>

int main() {
    try {
        Bureaucrat A {"Jim", 1};
    
        ShrubberyCreationForm a {"home"};
        std::cout << a << '\n';
        std::cout << "Target: " << a.getTarget() << '\n';

        A.executeForm(a);

        A.signForm(a);

        A.executeForm(a);

    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
    }

    return 0;
}
