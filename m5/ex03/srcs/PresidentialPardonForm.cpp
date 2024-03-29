#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
    AForm("SchrubberyCreationForm", 25, 5),
    _target("")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
    AForm("SchrubberyCreationForm", 25, 5),
    _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) :
    AForm("SchrubberyCreationForm", 25, 5)
{
    *this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
    if (this == &ref)
        return (*this);
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
