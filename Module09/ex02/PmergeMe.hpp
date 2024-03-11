#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int> v;
        std::deque<int> d;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator = (const PmergeMe &Input);
        ~PmergeMe();
        void storeData(int ac, char **av);
        void divideData();
        void determineData();
        void mergeData();
        void displayData();
        int checkValue(char *str);
};

#endif