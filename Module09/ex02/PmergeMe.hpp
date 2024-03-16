#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <chrono>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        int strugglerVector;
        std::vector<int> v;
        std::vector<std::pair<int, int> > pairs;
        std::vector<int> mainChain;
        std::vector<int> pend;
        std::vector<int> jacob;   
        
        int strugglerDeque;
        std::deque<int> d;
        std::deque<std::pair<int, int> > pairsDeque;
        std::deque<int> mainChainDeque;
        std::deque<int> pendDeque;
        std::deque<int> jacobDeque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator = (const PmergeMe &Input);
        ~PmergeMe();
        void storeDataVector(int ac, char **av);
        void divideDataVector();
        void separatePairs();
        void generateJacobVector(int len);
        void sortDataVector();
        std::vector<int> getVector();

        void storeDataDeque(int ac, char **av);
        void divideDataDeque();
        void separatePairsDeque();
        void generateJacobDeque(int len);
        void sortDataDeque();
        std::deque<int> getDeque();
    };

#endif