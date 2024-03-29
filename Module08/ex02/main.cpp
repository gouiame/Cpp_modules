#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "     testing with list" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.pop_back();
    std::cout << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    std::list<int>::iterator itl = l.begin();
    std::list<int>::iterator itel = l.end();
    ++itl;
    --itl;
    while (itl != itel)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }
    std::cout<< "     testing with vector" << std::endl;
    std::vector<int> v;
    v.push_back(5);
    v.push_back(17);
    std::cout << v.back() << std::endl;
    v.pop_back();
    std::cout << v.size() << std::endl;
    v.push_back(3);
    v.push_back(5);
    v.push_back(737);
    v.push_back(0);
    std::vector<int>::iterator itv = v.begin();
    std::vector<int>::iterator itev = v.end();
    ++itv;
    --itv;
    while (itv != itev)
    {
        std::cout << *itv << std::endl;
        ++itv;
    }
    return 0;
}