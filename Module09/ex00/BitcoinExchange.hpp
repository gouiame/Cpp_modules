
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange 
{
    private:
        std::map<std::string, std::string> _bitcoinValues;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        ~BitcoinExchange();

        void makeBitcoin(char *filename);
        void displayBitcoinValues(std::string &date, std::string &value);
};




#endif