#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): strugglerVector(-1){}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &Input)
{
    if (this != &Input)
    {
        *this = Input;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

int checkValue(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
        {
            std::cerr << "Error: Invalid input" << std::endl;
            exit(1);
        }
        i++;
    }
    return (atoi(str.c_str()));
}

void PmergeMe::storeDataVector(int ac, char **av)
{
    int nb = 0;
    for (int i = 1; i < ac; i++)
    {
        nb = checkValue(av[i]);
        v.push_back(nb);
    }
}

void PmergeMe::divideDataVector()
{
        for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        {
            if (it + 1 != v.end())
            {
                pairs.push_back(std::make_pair(*it, *(it + 1)));
                ++it;
            }
            else
            {
                strugglerVector = *it;
            }
        }    
    std::vector<std::pair<int, int> >::iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
    std::sort(pairs.begin(), pairs.end());
}

void PmergeMe::separatePairs()
{
    std::vector<std::pair<int, int> >::iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it)
    {
        mainChain.push_back(it->first);
        pend.push_back(it->second);
    }

    if (!pend.empty())
    {
        mainChain.insert(mainChain.begin(), pend.front());
    }
}

void PmergeMe::generateJacobVector(int len)
{
	int jn_1 = 1;
	int jn_2 = 0;
	for (int i = 0; i < len; i++)
	{
		jacob.push_back(jn_1 + (2 * jn_2));
		jn_1 = jn_1 + (2 * jn_2);
		jn_2 = jacob[i];
	}
}

void PmergeMe::sortDataVector()
{
    generateJacobVector(pend.size() + 1);

    unsigned long start = jacob[0];
    unsigned long end = jacob[1];
    unsigned long len = mainChain.size() + pend.size() - 1;
    for (unsigned long i = 1; i < jacob.size(); i++)
    {
        start = jacob[i - 1];
        end = jacob[i];

        while (start < end)
        {
            if (mainChain.size() >= len)
                break;
            if (end > pend.size())
                end = pend.size();
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[end - 1]);
                mainChain.insert(it, pend[end - 1]);
            end--;
        }

        if (mainChain.size() >= len)
            break;
    }
    if ( strugglerVector != -1)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), strugglerVector);
        mainChain.insert(it, strugglerVector);
    }
} 

std::vector<int> PmergeMe::getVector()
{
    return mainChain;
}
/****************************************************/

void PmergeMe::storeDataDeque(int ac, char **av)
{
    int nb = 0;
    for (int i = 1; i < ac; i++)
    {
        nb = checkValue(av[i]);
        d.push_back(nb);
    }
}

void PmergeMe::divideDataDeque()
{
        for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
        {
            if (it + 1 != d.end())
            {
                pairsDeque.push_back(std::make_pair(*it, *(it + 1)));
                ++it;
            }
            else
            {
                strugglerDeque = *it;
            }
        }    
    std::deque<std::pair<int, int> >::iterator it;
    for (it = pairsDeque.begin(); it != pairsDeque.end(); ++it)
    {
        if (it->first < it->second)
            std::swap(it->first, it->second);
    }
    std::sort(pairsDeque.begin(), pairsDeque.end());
}

void PmergeMe::separatePairsDeque()
{
    std::deque<std::pair<int, int> >::iterator it;
    for (it = pairsDeque.begin(); it != pairsDeque.end(); ++it)
    {
        mainChainDeque.push_back(it->first);
        pendDeque.push_back(it->second);
    }

    if (!pendDeque.empty())
    {
        mainChainDeque.insert(mainChainDeque.begin(), pendDeque.front());
    }
}

void PmergeMe::generateJacobDeque(int len)
{
    int jn_1 = 1;
    int jn_2 = 0;
    for (int i = 0; i < len; i++)
    {
        jacobDeque.push_back(jn_1 + (2 * jn_2));
        jn_1 = jn_1 + (2 * jn_2);
        jn_2 = jacobDeque[i];
    }
}

void PmergeMe::sortDataDeque()
{
    generateJacobDeque(pendDeque.size() + 1);

    unsigned long start = jacobDeque[0];
    unsigned long end = jacobDeque[1];
    unsigned long len = mainChainDeque.size() + pendDeque.size() - 1;
    unsigned long i = 1;
    for (; i < jacobDeque.size(); i++)
    {
        start = jacobDeque[i - 1];
        end = jacobDeque[i];

        while (start < end)
        {
            if (mainChainDeque.size() >= len)
                break;
            if (end > pendDeque.size())
                end = pendDeque.size();

            std::deque<int>::iterator it = std::lower_bound(mainChainDeque.begin(), mainChainDeque.end(), pendDeque[end - 1]);

            mainChainDeque.insert(it, pendDeque[end - 1]);
            end--;
        }

        if (mainChainDeque.size() >= len)
            break;
    }
    if ( strugglerDeque != -1)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChainDeque.begin(), mainChainDeque.end(), strugglerDeque);
        mainChainDeque.insert(it, strugglerDeque);
    }
}

std::deque<int> PmergeMe::getDeque()
{
    return mainChainDeque;
}