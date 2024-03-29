#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class AForm;

# include "AForm.hpp"

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string name, const int grade);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat();

    Bureaucrat  &operator=(const Bureaucrat &ref);

    std::string GradeTooLowException() const;
    std::string GradeTooHighException() const;

    const std::string   &getName() const;
    const int           &getGrade() const;

    void        incrementGrade();
    void        decrementGrade();

    void        signForm(AForm &ref) const;
    void        executeForm(const AForm &form) const;

private:
    const std::string   _name;
    int                 _grade;
};

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &ref);

#endif