#include "Bureaucrat.hpp"
#include "Form.hpp"



int	main()
{
	try
	{
		Bureaucrat B("B", 4);
		Form F("F", 5, 1);
		std::cout << B << std::endl;
		std::cout << F << std::endl;
		B.signForm(F);
		std::cout << F << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
