#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        this->_target = copy.getTarget();
        AForm::operator=(copy);
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(this->getSigned() == false)
    {
        std::cout << "This form is not signed yet" << std::endl;
        return;
    }
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "robotomy " << this->getName() << " has been executed" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl; 
    else
        std::cout << this->getTarget() << " Robotomy failed" << std::endl;
}