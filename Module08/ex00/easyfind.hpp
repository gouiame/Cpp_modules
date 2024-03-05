#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>

template <typename T>
void easyfind(T& container, int value)
{
    if (container.empty())
        throw std::out_of_range("Container is empty");
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::out_of_range("Value not found");
    else
        std::cout << "Value " << value << " found" << std::endl;
}

#endif