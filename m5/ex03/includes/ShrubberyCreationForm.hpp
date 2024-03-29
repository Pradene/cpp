#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &ref);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm    &operator=(const ShrubberyCreationForm &ref);

    void    execute(const Bureaucrat &executor) const;

private:
    const std::string   _target;
};

#endif