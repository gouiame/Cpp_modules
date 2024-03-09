#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    std::string line;
    std::string key;
    double value;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            iss >> key >> value;
            _bitcoinValues[key] = value;
        }
        file.close();
    }
    else {
        throw std::runtime_error("File not found");
    }
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
    _bitcoinValues = other._bitcoinValues;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void    BitcoinExchange::outputBitcoinValues(std::string fileName) {
    std::ofstream file(fileName);
    std::string line;
    if (!file.is_open())
        throw std::runtime_error("File not found");
    std::getline(file, line);
    if (line != "date | value") {
        throw std::runtime_error("Invalid file format");
    }
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        double value;
        iss >> date >> value;
        if (_bitcoinValues.find(date) != _bitcoinValues.end()) {
            file << date << " | " << value << " | " << _bitcoinValues[date] << std::endl;
        }
    }
}

std::vector<std::string> splitString(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

std::string skipSpaces()
