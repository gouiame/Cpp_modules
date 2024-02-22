#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &copy)
{   
    (void)copy;
    return (*this);
}

AForm *createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    formFunction forms[3] = {&createShrubbery, &createRobotomy, &createPresidential};

    int i = 0;
    while (i < 3)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i](target);
        }
        i++;
    }
    std::cout << "Form " << formName << " not found" << std::endl;
    return NULL;
}