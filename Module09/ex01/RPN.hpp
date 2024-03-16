#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int> myStack;
    public:
        RPN();
        RPN(const RPN & copy);
        RPN &operator=(const RPN & copy);
        ~RPN();

    void execute(std::string str);
    void pushNum(std::string &str);
    void doOperation(std::string &str);
};

#endif