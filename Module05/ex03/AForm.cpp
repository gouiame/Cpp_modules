#include "AForm.hpp"

AForm::AForm() : _name("Default"), _sign(false), grade_sign(150), grade_execute(150){}

AForm::AForm(std::string name, int signGrade, int executeGrad) : _name(name), grade_sign(signGrade), grade_execute(executeGrad)
{
    if (signGrade < 1 || executeGrad < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrad > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _sign(copy._sign), grade_sign(copy.grade_sign), grade_execute(copy.grade_execute)
{
    *this = copy;
}

AForm::~AForm(){}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
        this->_sign = copy.getSigned();
    return (*this);
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getSigned() const
{
    return (this->_sign);
}

int AForm::getGradeToSign() const
{
    return (this->grade_sign);
}

int AForm::getGradeToExecute() const
{
    return (this->grade_execute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->grade_sign)
        throw AForm::GradeTooLowException();
    this->_sign = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return (" Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return (" Grade too low");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return (out);
}