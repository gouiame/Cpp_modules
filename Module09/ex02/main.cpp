#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    Pmerge obj;
    try{
        if (ac <= 1)
            throw std::runtime_error("Error: Bad Argument");
        obj.storeData(ac, av);
        obj.sortData();
    }
    catch(const std::exception &e){
        std::cout << e.what() << std::endl;
    }
}