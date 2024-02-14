#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string	_name;
    bool				_sign;
    const int			grade_sign;
    const int			grade_execute;
public:
    Form();
    Form(std::string name, int signGrade, int executeGrad);
    Form(const Form &copy);
    ~Form();
    Form &operator=(const Form &copy);

    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
        public:
                const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
                const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif