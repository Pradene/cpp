#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
    AForm("RobotomyRequestForm", 72, 45),
    _target("")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
    AForm("RobotomyRequestForm", 72, 45),
    _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) :
    AForm("RobotomyRequestForm", 72, 45)
{
    *this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm    &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
    if (this == &ref)
        return (*this);
    return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    if (rand() % 2)
        std::cout << _target << " has been successfully robotomized" << std::endl;
    else
        std::cout << _target << " hasn't been robotomized" << std::endl;
}
