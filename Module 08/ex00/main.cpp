#include "easyfind.hpp"

int main()
{
    try
    {
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        easyfind(lst, 2);
        easyfind(lst, 4);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}