#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
    srand(time(NULL));
    Bureaucrat  boss("boss", 1);
    Intern      i;

    AForm *f1 = i.makeForm("robotomy request", "Paul");
    AForm *f2 = i.makeForm("request", "Paul");

    boss.executeForm(*f1);
    boss.signForm(*f1);
    boss.executeForm(*f1);
    boss.executeForm(*f1);
    boss.executeForm(*f1);
    boss.executeForm(*f1);
    delete f1;
    delete f2;

    return (0);
}
