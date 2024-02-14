#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string	_name;
    bool				_sign;
    const int			grade_sign;
    const int			grade_execute;

public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    AForm(const AForm &aForm);
    virtual ~AForm();
    AForm &operator=(const AForm &aForm);

    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif