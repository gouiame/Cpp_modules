#include "Base.hpp"

int main()
{
    Base *base = generate();

    std::cout << "     Using pointer" << std::endl;
    identify(base);
    std::cout << "     Using reference" << std::endl;
    identify(*base);

    delete base;
    return 0;
}