#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{

	try
	{

		Bureaucrat B("B", 45);
		RobotomyRequestForm F("target");
		// ShrubberyCreationForm F("target");
		// // PresidentialPardonForm F("target");

		B.signForm(F);
		B.executeForm(F);
	}
	catch(const std::exception& e)
	{

		std::cout  << e.what() << std::endl;
	}
	
}
