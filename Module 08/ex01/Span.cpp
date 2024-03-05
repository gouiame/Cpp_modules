#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span::~Span(){}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        N = copy.N;
        vec = copy.vec;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (vec.size() < N)
        vec.push_back(n);
    else
        throw std::out_of_range("The vector is full");
}

int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw std::out_of_range("The vector is too small or empty");
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 2; i < tmp.size(); i++)
    {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (vec.size() < 2)
        throw std::out_of_range("The vector is too small or empty");
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void    Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (vec.size() + std::distance(begin, end) > N)
        throw std::out_of_range("Not enough space in the vector"); 
    vec.insert(vec.end(), begin, end);
}