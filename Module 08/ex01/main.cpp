#include "Span.hpp"

int main()
{
    std::cout << "     First test" << std::endl;
    Span sp = Span(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "      Second test" << std::endl;
    
    Span sp2(6);
    std::vector<int> v;

    try
    {
        sp2.addNumber(5);
        sp2.addNumber(3);
        sp2.addNumber(15);
        v.push_back(1);
        v.push_back(2);
        v.push_back(6);
        // v.push_back(4);

        sp2.addRange(v.begin(), v.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}