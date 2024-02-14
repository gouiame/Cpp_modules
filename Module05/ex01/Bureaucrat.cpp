#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout<< "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout<< "Bureaucrat "<<this->_name << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g) : _name(n), _grade(g) {
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (g > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name) {
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        this->_grade = copy.getGrade();
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}

void    Bureaucrat::signForm(Form &form)
{
    if (form.getSigned())
        std::cout << this->_name << " couldn't sign " << form.getName() << " because it's already signed" << std::endl;
    else if (form.getGradeToSign() < this->_grade)
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->_name << " couldn't sign " << form.getName() << " because bureaucrat grade is too low" << std::endl;
    form.beSigned(*this);
}