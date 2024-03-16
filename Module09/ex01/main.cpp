#include "RPN.hpp"


int main (int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Error : Check args!" << std::endl;
		return 1;
	}
	RPN rpn;
	
	std::string str(av[1]);
	rpn.execute(str);
}