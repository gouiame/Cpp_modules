#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &copy);
        ScalarConverter &operator=(ScalarConverter const &copy);
        ~ScalarConverter();

    public:
        static void convert(std::string const &input);
};

enum eType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID,
};

#endif