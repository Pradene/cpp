#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

# include "Bureaucrat.hpp"

class AForm
{
public:
    AForm();
    AForm(const AForm &ref);
    AForm(const std::string name, const int gradeToSign, const int gradeToExec);
    virtual ~AForm() = 0;

    AForm    &operator=(const AForm &ref);

    const std::string GradeTooLowException();
    const std::string GradeTooHighException();

    const std::string   &getName() const;
    const bool          &getStatus() const;
    const int           &getGradeToSign() const;
    const int           &getGradeToExec() const;

    void            beSigned(const Bureaucrat &ref);
    virtual void    execute(const Bureaucrat &executor) const = 0;

private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExec;
};

std::ostream    &operator<<(std::ostream &os, const AForm &ref);

#endif