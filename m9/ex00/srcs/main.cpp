#include "Data.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Error: ./RPN file" << std::endl;
        return (1);
    }
    
    try {
        Data    data("data.csv");
        data.exchangeRates(av[1]);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}