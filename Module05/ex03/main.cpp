#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern In;
    std::string input;
    AForm *form;

    while(1)
    {
        std::cout <<"Enter a form name: ";
        if (!std::getline(std::cin, input))
            return 0;
        if (input.empty())
            continue ;
        form = In.makeForm(input, "target");
        
        if (form != NULL)
        {
            delete form;
        }
    }
}