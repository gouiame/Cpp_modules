#include "Form.hpp"

Form::Form() : _name("Default"), _sign(false), grade_sign(150), grade_execute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrad) : _name(name), grade_sign(signGrade), grade_execute(executeGrad)
{
    if (signGrade < 1 || executeGrad < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || executeGrad > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _sign(copy._sign), grade_sign(copy.grade_sign), grade_execute(copy.grade_execute)
{
    *this = copy;
}

Form::~Form()
{
    std::cout << "Form " << this->_name << " destructor called" << std::endl;
}

Form &Form::operator=(const Form &copy) {
    if (this != &copy)
        this->_sign = copy.getSigned();
    return (*this);
}

std::string Form::getName() const {
    return (this->_name);
}

bool Form::getSigned() const {
    return (this->_sign);
}

int Form::getGradeToSign() const {
    return (this->grade_sign);
}

int Form::getGradeToExecute() const {
    return (this->grade_execute);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->grade_sign)
        throw Form::GradeTooLowException();
    this->_sign = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return (out);
}