#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange(av[1]);
    exchange.outputBitcoinValues("BTC");
    return 0;
}