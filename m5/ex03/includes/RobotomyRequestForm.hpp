#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <stdlib.h>
# include <time.h>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &ref);
    ~RobotomyRequestForm();

    RobotomyRequestForm    &operator=(const RobotomyRequestForm &ref);

    void    execute(const Bureaucrat &executor) const;

private:
    const std::string   _target;
};

#endif