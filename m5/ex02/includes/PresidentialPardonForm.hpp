#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &ref);
    ~PresidentialPardonForm();

    PresidentialPardonForm    &operator=(const PresidentialPardonForm &ref);

    void    execute(const Bureaucrat &executor) const;

private:
    const std::string   _target;
};

#endif