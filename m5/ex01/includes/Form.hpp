#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

# include "Bureaucrat.hpp"

class Form
{
public:
    Form();
    Form(const Form &ref);
    Form(const std::string name, const int gradeToSign, const int gradeToExec);
    ~Form();

    Form    &operator=(const Form &ref);

    const std::string GradeTooLowException();
    const std::string GradeTooHighException();

    const std::string   &getName() const;
    const bool          &getStatus() const;
    const int           &getGradeToSign() const;
    const int           &getGradeToExec() const;

    void        beSigned(const Bureaucrat &ref);

private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExec;
};

std::ostream    &operator<<(std::ostream &os, const Form &ref);

#endif