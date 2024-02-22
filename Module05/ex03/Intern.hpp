#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern &operator=(const Intern &copy);

    AForm *makeForm(std::string name, std::string target);
};

typedef AForm *(*formFunction)(std::string target);

#endif
