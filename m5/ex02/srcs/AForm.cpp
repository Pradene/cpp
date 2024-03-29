#include "../includes/AForm.hpp"

AForm::AForm() : 
    _name("Unknown"),
    _signed(false),
    _gradeToSign(150),
    _gradeToExec(150)
{}

AForm::AForm(const AForm &ref) :
    _name(ref._name),
    _signed(ref._signed),
    _gradeToSign(ref._gradeToSign),
    _gradeToExec(ref._gradeToExec)
{}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) :
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

AForm::~AForm() {}

const std::string AForm::GradeTooLowException() { return ("Grade too Low"); }
const std::string AForm::GradeTooHighException() { return ("Grade too high"); }

const std::string   &AForm::getName() const { return (_name); }
const bool          &AForm::getStatus() const { return (_signed); }
const int           &AForm::getGradeToSign() const { return (_gradeToSign); }
const int           &AForm::getGradeToExec() const { return (_gradeToExec); }

void        AForm::beSigned(const Bureaucrat &ref)
{
    if (_signed == true)
        throw std::runtime_error("form is already signed");
    else if (_gradeToSign < ref.getGrade())
        throw std::runtime_error(GradeTooLowException());
    else
        _signed = true;
}

void        AForm::execute(const Bureaucrat &executor) const
{
    if (_signed == false)
        throw std::runtime_error("Form is not signed");
    else if (_gradeToExec < executor.getGrade())
        throw std::runtime_error(executor.GradeTooLowException());
}

AForm    &AForm::operator=(const AForm &ref)
{
    if (this == &ref)
        return (*this);
    _signed = ref._signed;
    return (*this);
}

std::ostream    &operator<<(std::ostream &os, const AForm &ref)
{
    os << "Form :" << std::endl \
    << "  name : " << ref.getName() << std::endl \
    << "  status : " << (ref.getStatus() ? "signed" : "not signed") << std::endl \
    << "  gradeToSign : " << ref.getGradeToSign() << std::endl \
    << "  gradeToSign : " << ref.getGradeToExec() << std::endl;
    return (os);
}
