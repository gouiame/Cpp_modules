#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &Input)
{
    if (this != &Input)
    {
        this->v = Input.v;
        this->d = Input.d;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

int checkValue(char *str)
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

void PmergeMe::storeData(int ac, char **av)
{
    int nb;
    for (int i = 1; i < ac; i++)
    {
        nb = checkValue(av[i]);
        v.push_back(nb);
    }
}

// group the elements of container into pairs of elements and if the number of elements id odd, the last element will be inpaired we will call a stuggler

void PmergeMe::divideData()
{
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> stuggler;

    for (int i = 0; i < v.size(); i++)
    {
        if (v.size() % 2 == 0)
        {
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
            i++;
        }
        else
        {
            if (i == v.size() - 1)
                stuggler.push_back(v[i]);
            else
                pairs.push_back(std::make_pair(v[i], v[i + 1]));
            i++;
        }
    }
}


// void PmergeMe::determineLarger()
// {
//     std::vector<int> larger;
//     for (int i = 0; i < pairs.size(); i++)
//     {
//         if (pairs[i].first > pairs[i].second)
//             larger.push_back(pairs[i].first);
//         else
//             larger.push_back(pairs[i].second);
//     }
}