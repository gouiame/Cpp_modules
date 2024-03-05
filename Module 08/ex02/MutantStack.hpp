#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() : std::stack<T, Container >() {}
        MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) {}
        ~MutantStack() {}
        MutantStack &operator=(const MutantStack &copy)
        {
            if (this != &copy)
                std::stack<T, Container>::operator=(copy);
            return *this;
        }

        typedef typename Container::iterator iterator;
        iterator begin() { return this->c.begin();}
        iterator end() { return this->c.end();}

        typedef typename Container::const_iterator const_iterator;
        const_iterator begin() const { return this->c.begin();}
        const_iterator end() const { return this->c.end();}
};

#endif