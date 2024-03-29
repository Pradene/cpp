#include "../includes/Form.hpp"

Form::Form() : 
    _name("Unknown"),
    _signed(false),
    _gradeToSign(150),
    _gradeToExec(150)
{}

Form::Form(const Form &ref) :
    _name(ref._name),
    _signed(ref._signed),
    _gradeToSign(ref._gradeToSign),
    _gradeToExec(ref._gradeToExec)
{}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) :
    _name(name),
    _signed(false),
    _gradeToSign(gradeToSign),
    _gradeToExec(gradeToExec)
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw std::runtime_error(GradeTooHighException());
    else if (_gradeToSign > 150 || _gradeToExec > 150)
        throw std::runtime_error(GradeTooLowException());
}

Form::~Form() {}

const std::string Form::GradeTooLowException() { return ("Grade too Low"); }
const std::string Form::GradeTooHighException() { return ("Grade too high"); }

const std::string   &Form::getName() const { return (_name); }
const bool          &Form::getStatus() const { return (_signed); }
const int           &Form::getGradeToSign() const { return (_gradeToSign); }
const int           &Form::getGradeToExec() const { return (_gradeToExec); }

void        Form::beSigned(const Bureaucrat &ref)
{
    if (_gradeToSign < ref.getGrade())
        throw std::runtime_error(GradeTooLowException());
    else if (_signed == true)
        throw std::runtime_error("form already signed");
    else
        _signed = true;
}

Form    &Form::operator=(const Form &ref)
{
    if (this == &ref)
        return (*this);
    _signed = ref._signed;
    return (*this);
}

std::ostream    &operator<<(std::ostream &os, const Form &ref)
{
    os << "Form :" << std::endl \
    << "  name : " << ref.getName() << std::endl \
    << "  status : " << (ref.getStatus() ? "signed" : "not signed") << std::endl \
    << "  gradeToSign : " << ref.getGradeToSign() << std::endl \
    << "  gradeToSign : " << ref.getGradeToExec() << std::endl;
    return (os);
}
