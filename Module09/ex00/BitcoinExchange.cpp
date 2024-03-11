#include "BitcoinExchange.hpp"
#include <iostream>


BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    std::string line;
    size_t length;

    std::string date;
    std::string exchange_rate;
    
    if (file.is_open())
    {
        std::getline(file, line);
        while (std::getline(file, line))
        {
            length = line.length();
            date = line.substr(0, 10);
            exchange_rate = line.substr(11, length - 11);
            
            _bitcoinValues[date] = exchange_rate;
        }
        file.close();
    }
    else 
    {
        std::cerr << "Eroor : file not found" << std::endl;
        exit(1);
    }
    // std::map<std::string, std::string>::iterator it = _bitcoinValues.begin();
    // for(it = _bitcoinValues.begin(); it != _bitcoinValues.end(); it++)
    // {
    //     std::cout << it->first << " " << it->second << "   ----"<< std::endl;
    // }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    _bitcoinValues = other._bitcoinValues;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void checkFile(std::ifstream &file)
{
    std::string line;
    if (file.is_open() == false)
    {
        std::cerr << "Error : file not found" << std::endl;
        exit(1);
    }
    std::getline(file, line);
    if (file.eof() == true)
    {
        std::cerr << "Error : file is empty" << std::endl;
        exit(1);
    }
    if (line != "date | value")
    {
        std::cerr << "Error : bad file format" << std::endl;
        exit(1);
    }
}

bool checkInput(std::string &date, std::string &value, std::string &line)
{
    size_t pos;

    pos = line.find('|');
    if (pos == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    date = line.substr(0, pos - 1);
    value = line.substr(pos + 2, line.length() - pos - 2);
    return true;
}

int strtoi(std::string str)
{
    std::istringstream iss(str);
    int val;

    iss >> val;
    return val;
}

std::string itostr(int &val)
{
    std::ostringstream iss;
    iss << val;

    return iss.str();
}

bool checkDate(int &yearInt, int &monthInt, int &dayInt)
{
    if (yearInt < 2009 || yearInt > 2022)
        return false;
    if (monthInt < 1 || monthInt > 12)
        return false;
    if (dayInt < 1 || dayInt > 31)
        return false;
    if ( (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return false;
    if (monthInt == 2)
    {
        if ((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0)
        {
            if (dayInt > 29)
                return false;
        }
        else
        {
            if (dayInt > 28)
                return false;
        }
    }
    return true;
}

bool dateValide(std::string &date)
{

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        return false;
    int yearInt = strtoi(year);
    int monthInt = strtoi(month);
    int dayInt = strtoi(day);
    if (checkDate(yearInt, monthInt, dayInt) == false)
        return false;
    return true;
}

bool valueValide(std::string &value)
{
    size_t j = 0;
    size_t length = value.length();
    int point = 0;

    if (value[0] == '-' || value[0] == '+')
        j++;
    for (size_t i = j ; i < length; i++)
    {
        if (value[i] == '.')
        {
            if (point == 1)
                return false;
            point = 1;
        }
        else if (value[i] < '0' || value[i] > '9')
            return false;
    }
    return true;
}

bool checkValue(std::string &value)
{
    std::istringstream iss(value);
    double val;

    iss >> val;
    if (val < 0)
    {
        std::cout << "Error : not a positive number." << std::endl;
        return false;
    }
    if (val > 1000)
    {
        std::cout << "Error : too large a number." << std::endl;
        return false;
    }
    return true;
}

std::string checkPreviousDate(std::string &date)
{
    int year = strtoi(date.substr(0, 4));
    int month = strtoi(date.substr(5, 2));
    int day = strtoi(date.substr(8, 2));

    day = day - 1;
    if (day == 0)
    {
        month = month - 1;
        if (month == 0)
        {
            month = 12;
            year = year - 1;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11)
            day = 30;
        else if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                day = 29;
            else
                day = 28;
        }
        else
            day = 31;
    }
    std::string yearStr = itostr(year);
    std::string monthStr = itostr(month);
    std::string dayStr = itostr(day);
    if (monthStr.length() == 1)
        monthStr = "0" + monthStr;
    if (dayStr.length() == 1)
        dayStr = "0" + dayStr;
    return yearStr + "-" + monthStr + "-" + dayStr;
}

double strToDouble(std::string str)
{
    std::istringstream iss(str);
    double val;

    iss >> val;
    return val;
}

void BitcoinExchange::displayBitcoinValues(std::string &date, std::string &value)
{
    std::map<std::string, std::string>::iterator it;

    std::string date_csv = date;
    std::string temp;

    while(1)
    {
        it = _bitcoinValues.find(date_csv);
        if (it != _bitcoinValues.end())
            break;
        temp = checkPreviousDate(date_csv);
        date_csv = temp;
    }
    double exchange_rate = strToDouble(it->second);
    double exchange_value = strToDouble(value);
    std::cout << date << " => " << value << " = " << exchange_value * exchange_rate << std::endl;
}

void BitcoinExchange::makeBitcoin(char *filename)
{
    std::ifstream file(filename);
    std::string line;
    std::string date;
    std::string value;

    checkFile(file);
    while (std::getline(file, line))
    {
        if (checkInput(date, value, line) == false)
            continue;
        if (dateValide(date) == false)
        {
            std::cout << "Error : invalide date => " << date << std::endl;
            continue;
        }
        if (valueValide(value) == false)
        {
            std::cout << "Error : invalide value => " << value << std::endl;
            continue;
        }
        if (checkValue(value) == false)
            continue;
        displayBitcoinValues(date, value);
    }
}