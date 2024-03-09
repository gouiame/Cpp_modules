#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _bitcoinValues;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        ~BitcoinExchange();
        void    outputBitcoinValues(std::string fileName);
};

std::vector<std::string> splitString(std::string str, char delimiter);
std::string skipSpaces(std::string str);

double myStod(std::string str);


#endif // BITCOINEXCHANGE_HPP