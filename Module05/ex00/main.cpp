#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat  b("B", 10);
        std::cout << b;
        b.incrementGrade();
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
        std::cout << "If you see this, it means that the exception was not thrown" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}