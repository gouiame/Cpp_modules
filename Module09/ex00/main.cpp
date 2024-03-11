#include "BitcoinExchange.hpp"

int main (int ac, char **av) 
{
    if (ac != 2)
    {
        std::cerr << "Error : Check args" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;

    exchange.makeBitcoin(av[1]);
    return 0;
}