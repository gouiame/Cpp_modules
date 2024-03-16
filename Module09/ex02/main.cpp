#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cerr << "Error: Bad Argument" << std::endl;
        return 1;
    }
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        int nb;
        iss >> nb;
        if (iss.fail() == true)
        {
            std::cerr << "Error: Invalid input" << std::endl;
            return 1;
        }
    }
    PmergeMe obj;
    size_t size = ac - 1;

    std::clock_t startVector = std::clock();
    obj.storeDataVector(ac, av);
    obj.divideDataVector();
    obj.separatePairs();
    obj.sortDataVector();
    std::clock_t endVector = std::clock();
    double vectorTime = (double)(endVector - startVector)/CLOCKS_PER_SEC * 1e6;
    

    std::clock_t startDeque = std::clock();
    obj.storeDataDeque(ac, av);
    obj.divideDataDeque();
    obj.separatePairsDeque();
    obj.sortDataDeque();
    std::clock_t endDeque = std::clock();
    double dequeTime = (double)(endDeque - startDeque)/CLOCKS_PER_SEC * 1e6;

    std::cout << "Before: ";
    for (int i = 1; i < ac; i++)
    {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    std::vector<int> v = obj.getVector();
    std::deque<int> d = obj.getDeque();
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << dequeTime << " us" << std::endl;
}
