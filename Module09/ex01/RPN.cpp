#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &coppy) : myStack(coppy.myStack) {}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        this->myStack = copy.myStack;
    return *this;
}

RPN::~RPN(){}

bool isValid(std::string &str)
{
    int len = str.length();
    if (str.empty())
        return false;
    for (int i = 0; i < len ; i++)
    {
        if (isdigit(str[i]) == true)
            continue;
        else if (str[i] == ' ' || str[i] == '+' || str[i] == '-'
                    || str[i] == '*' || str[i] == '/')
            continue;
        else
            return false;
    }
    return true;
}

void RPN::pushNum(std::string &str)
{
    std::istringstream ss(str);
    int num;
    ss >> num;
    this->myStack.push(num);
}

void RPN::doOperation(std::string &str)
{
    int a;
    int b;

    if (this->myStack.size() < 2)
    {
        std::cerr << "Error : Invalid input !" << std::endl;
        exit(1);
    }
    else
    {
        b = this->myStack.top();
        this->myStack.pop();
        a = this->myStack.top();
        this->myStack.pop();
        if (str == "+")
            this->myStack.push(a + b);
        else if (str == "-")
            this->myStack.push(a - b);
        else if (str == "*")
            this->myStack.push(a * b);
        else if (str == "/")
        {
            if (b == 0)
            {
                std::cerr << "Error : Division by zero!" << std::endl;
                exit(1);
            }
            this->myStack.push(a / b);
        }
    }
}

void RPN::execute(std::string str)
{
    std::stringstream ss(str);
    std::string token;

    if (isValid(str) == false)
    {
        std::cerr << "Error : Invalid input !" << std::endl;
        exit(1);
    }
    while(ss >> token)
    {
        if(token.length() == 1 && isdigit(token[0]) == true)
            pushNum(token);
        else if (token == "+"|| token == "-" || token == "*" || token == "/")
            doOperation(token);
        else
        {
            std::cerr << "Error : Invalid input !" << std::endl;
            exit(1);
        }
    }
    if (myStack.size() != 1)
    {
        std::cerr << "Error : Invalid input !" << std::endl;
        exit(1);
    }
    std::cout << myStack.top() << std::endl;
}