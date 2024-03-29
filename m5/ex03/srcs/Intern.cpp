#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &ref) { *this = ref; }
Intern::~Intern() {}

Intern  &Intern::operator=(const Intern &ref)
{
    static_cast<void>(ref);
    return (*this);
}

AForm   *makeShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm   *makeRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm   *makePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
    typedef AForm   *(*func)(std::string target);
    std::string     names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    func            array[3] = {&makeRobotomyRequestForm, &makePresidentialPardonForm, &makeShrubberyCreationForm};

    for (int i = 0; i < 3; ++i)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (array[i](target));
        }
    }
    std::cout << "Intern can't create " << name << " form" << std::endl;
    return (NULL);
}
