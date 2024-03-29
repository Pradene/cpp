#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
    srand(time(NULL));

    Bureaucrat  b1("Jake", 70);
    ShrubberyCreationForm   f1("home");
    PresidentialPardonForm  f2("Zack");

    b1.executeForm(f1);
    b1.signForm(f1);
    b1.signForm(f1);
    b1.executeForm(f1);

    std::cout << std::endl;

    b1.executeForm(f2);
    b1.signForm(f2);
    b1.executeForm(f2);

    return (0);
}
