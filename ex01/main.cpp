#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>
#include <exception>

int main() {
    try {
        std::cout << "----------------------------------" << '\n';

        Bureaucrat marie{ "Marie", 10 };
        std::cout << marie << '\n';

        Bureaucrat robert{ "Robert", 55 };
        std::cout << robert << '\n';

        Bureaucrat david{ "David", 133 };
        std::cout << david << '\n';

        std::cout << "----------------------------------" << '\n';

        Form A1{ "A1", 15, 5 };
        std::cout << A1 << '\n';

        Form A2{ "A2", 55, 38 };
        std::cout << A2 << '\n';

        Form A3{ "A3", 132, 99 };
        std::cout << A3 << '\n';

        // Marie can sign all forms
        marie.signForm( A1 );
        marie.signForm( A2 );
        marie.signForm( A3 );

        std::cout << "----------------------------------" << '\n';

        Form A1copy{ "A1copy", 15, 5 };
        std::cout << A1copy << '\n';

        Form A2copy{ "A2copy", 55, 38 };
        std::cout << A2copy << '\n';

        Form A3copy{ "A3copy", 132, 99 };
        std::cout << A3copy << '\n';

        // Robert can sign A2 and A3
        robert.signForm( A1copy );
        robert.signForm( A2copy );
        robert.signForm( A3copy );

        std::cout << "----------------------------------" << '\n';

        Form A1copy2{ "A1copy2", 15, 5 };
        std::cout << A1copy2 << '\n';

        Form A2copy2{ "A2copy2", 55, 38 };
        std::cout << A2copy2 << '\n';

        Form A3copy2{ "A3copy2", 132, 99 };
        std::cout << A3copy2 << '\n';

        // David can sign none
        david.signForm( A1copy2 );
        david.signForm( A2copy2 );
        david.signForm( A3copy2 );

        // David gets a promotion; now he can sign A3
        david.incrementGrade();
        std::cout << david.getName() << " got a promotion and his grade is now " << david.getGrade() << '\n';
        david.signForm( A3copy2 );

        std::cout << "----------------------------------" << '\n';

    } catch ( const std::exception& e ) {
        std::cout << "An exception occurred: " << e.what() << '\n';
    }

    return 0;
}
