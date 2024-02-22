#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {    
        this->_target = copy._target;
        AForm::operator=(copy);    
    }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(this->getSigned() == false)
    {
        std::cout << "This form is not signed yet" << std::endl;
        return;
    }
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "ShrubberyCreationForm " << this->getName() << " has been executed" << std::endl;
    std::ofstream file(this->_target + "_shrubbery");
    file << "    ^    \n" << std::endl;
    file << "   ^^^   \n" << std::endl;
    file << "  ^^^^^  \n" << std::endl;
    file << " ^^^^^^^ \n" << std::endl;
    file << "^^^^^^^^^\n" << std::endl;
    file << "    |    \n" << std::endl;
    std::cout << "Tree has been created in " << this->_target << "_shrubbery" << std::endl;
    file.close();
}