#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
    AForm("ShrubberyCreationForm", 145, 137),
    _target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
    AForm("ShrubberyCreationForm", 145, 137),
    _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) :
    AForm("ShrubberyCreationForm", 145, 137)
{
    *this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
    if (this == &ref)
        return (*this);
    return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::ofstream output((_target + "_shrubbery").c_str());
    output << std::endl;
    output.close();
}
