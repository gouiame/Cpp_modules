#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vec;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span &operator=(const Span &copy);

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif