#include "Bureaucrat.hpp"
#include "Form.hpp"



int	main()
{
	try{
		Bureaucrat B("B", 7);
		Form F("F", 5, 1);
		std::cout << B << std::endl;
		std::cout << F << std::endl;
		B.signForm(F);
		F.beSigned(B);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}



// int main()
// {
// 	std::cout << "\033[1;33m--------------First Test---------------\033[0;m" << std::endl;
// 	try{
// 		Bureaucrat obj1("ibra", 3);
// 		Form obj2("omayr", 10, 4);

// 		// obj1.signForm(obj2);
// 		obj2.beSigned(obj1);
// 	}
// 	catch(std::exception &e){
// 		std::cout << e.what() << std::endl;
// 	}
// 	std::cout << "\033[1;33m--------------Second Test--------------\033[0;m" << std::endl;
// 	try{
// 		Bureaucrat obj1("ibra", 10);
// 		Form obj2("omayr", 55, 33);

// 		std::cout << obj1 << std::endl;
// 		std::cout << obj2 << std::endl;
// 		obj2.beSigned(obj1);
// 		obj1.signForm(obj2);
// 	}
// 	catch(std::exception &e){
// 		std::cout << e.what() << std::endl;
// 	}
// }
