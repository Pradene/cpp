#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
    _name("Undefined"),
    _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, const int grade) :
    _name(name),
    _grade(grade)
{
    if (_grade < 1)
        throw std::runtime_error(this->GradeTooHighException());
    else if (_grade > 150)
        throw std::runtime_error(this->GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) { *this = ref; }
Bureaucrat::~Bureaucrat() {}

const std::string   &Bureaucrat::getName() const { return (_name); }
const int           &Bureaucrat::getGrade() const { return (_grade); }

const std::string Bureaucrat::GradeTooLowException() const
{
    return ("Grade too low");
}

const std::string Bureaucrat::GradeTooHighException() const
{
    return ("Grade too high");
}

void    Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw std::runtime_error(this->GradeTooHighException());
    _grade -= 1;
}

void    Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw std::runtime_error(this->GradeTooLowException());
    _grade += 1;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &ref)
{
    if (this == &ref)
        return (*this);
    _grade = ref._grade;
    return (*this);
}

std::ostream    &operator<<(std::ostream& os, const Bureaucrat& ref)
{
    os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
    return (os);
}
