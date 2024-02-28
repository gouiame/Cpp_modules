#include "Scalar.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool ft_isValid(std::string const &input, eType type)
{
    if (type == INT)
    {
        std::istringstream input_stream(input);
        int nb;
        input_stream >> nb;
        if (input_stream.fail() == true)
        {
            std::cout << "Error: Conversion failed." << std::endl;
            return true;
        }
    }
    if (type == FLOAT)
    {
        int len = input.length();
        std::string str = input.substr(0, len - 1);
        std::istringstream input_stream(str);
        float nb;
        input_stream >> nb;
        if (input_stream.fail() == true)
        {
            std::cout << "Error: Conversion failed." << std::endl;
            return true;
        }
    }
    if (type == DOUBLE)
    {
        std::istringstream input_stream(input);
        double nb;
        input_stream >> nb;
        if (input_stream.fail() == true)
        {
            std::cout << "Error: Conversion failed." << std::endl;
            return true;
        }
    }
    return false;
}

static bool ft_isChar(std::string const &input)
{
    if (input.length() == 1 && !isdigit(input[0]) && (input[0] >= 0 && input[0] <= 127))
        return true;
    return false;
}

static bool ft_isInt(std::string const &input)
{
    if (input.length() == 1 && isdigit(input[0]))
        return true;
    if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+'))
    {
        for (size_t i = 1; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
                return false;
        }
        return true;
    }
    return false;
}

static bool ft_isFloat(std::string const &input)
{
    int dot_count = 0;
    int f_count = 0;
    size_t len = input.length();
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;
    if (input[len - 1] != 'f')
        return false;
    if (input.length() == 1 && input[0] == 'f')
        return false;
    if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+'))
    {
        for (size_t i = 1; i < len - 1; i++)
        {
            if (!isdigit(input[i]) && input[i] != '.')
                return false;
            if (input[i] == '.')
                dot_count++;
            if (input[i] == 'f')
                f_count++;
            if (dot_count > 1 || f_count > 1)
                return false;
        }
        return true;
    }
    return false;
}

static bool ft_isDouble(std::string const &input)
{
    int dot_count = 0;

    if (input == "-inf" || input == "+inf" || input == "nan")
        return true;
    if (input.length() == 1)
        return false;
    if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+'))
    {
        for (size_t i = 1; i < input.length(); i++)
        {
            if (!isdigit(input[i]) && input[i] != '.')
                return false;
            if (input[i] == '.')
                dot_count++;
            if (dot_count > 1)
                return false;
        }
        return true;
    }
    return false;
}

static eType ft_getType(std::string const &input)
{
    if (ft_isChar(input) == true)
        return CHAR;
    if (ft_isInt(input) == true)
        return INT;
    if (ft_isFloat(input) == true)
        return FLOAT;
    if (ft_isDouble(input) == true)
        return DOUBLE;
    return INVALID;
}

static void ft_convertChar(std::string const &input)
{
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void ft_convertInt(std::string const &input)
{
    if (ft_isValid(input, INT) == true)
        return ;
    int nb;
    std::istringstream input_stream(input);
    input_stream >> nb;

    if (isprint(nb) == true)
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << static_cast<float>(nb) << ".0f" <<std::endl;
    std::cout << "double: " <<  static_cast<double>(nb) << ".0" <<std::endl;
}

static void ft_convertFloat(std::string const &input)
{
    if (ft_isValid(input, FLOAT) == true)
        return ;
    int len = input.length();
    if (input == "-inff" || input == "+inff" || input == "nanf")
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, len - 1) << std::endl;
        return;
    }
    
    char array[len + 1];
    for (int i = 0; i < len; i++)
        array[i] = input[i];
    array[len] = '\0';
    float nb = std::strtof(array, NULL);
    if (isprint(nb) == true)
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nb) << std::endl;
    if (nb == static_cast<int>(nb))
        std::cout << "float: " << nb << ".0f" << std::endl;
    else
        std::cout << "float: " << nb << "f" << std::endl;
    if (nb == static_cast<int>(nb))
        std::cout << "double: " << static_cast<double>(nb) << ".0" <<std::endl;
    else
        std::cout << "double: " << static_cast<double>(nb) <<std::endl;
}

static void ft_convertDouble(std::string const &input)
{
    if (ft_isValid(input, DOUBLE) == true)
        return ;

    int len = input.length();
    if(input == "-inf" || input == "+inf" || input == "nan")
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    }
    char array[len + 1];
    for (int i = 0; i < len; i++)
        array[i] = input[i];
    array[len] = '\0';
    double nb = std::strtod(array, NULL);
    if (isprint(nb) == true)
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nb) << std::endl;
    if (nb == static_cast<int>(nb))
        std::cout << "float: " << nb << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(nb) << "f" <<std::endl;
    if (nb == static_cast<int>(nb))
        std::cout << "double: " << nb << ".0" <<std::endl;
    else
        std::cout << "doule: " << nb << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
    switch(ft_getType(input))
    {
        
        case CHAR:
            ft_convertChar(input);
            break;
        case INT:
            ft_convertInt(input);
            break;
        case FLOAT:
            ft_convertFloat(input);
            break;
        case DOUBLE:
            ft_convertDouble(input);
            break;
        default:
            std::cout << "Error: Invalid input" << std::endl;
            break;
    }
}