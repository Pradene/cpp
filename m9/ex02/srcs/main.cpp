#include "PMerge.hpp"

int main(int ac, const char **av) {
    if (ac < 3) {
        std::cerr << "Error: ./PMerge numbers..." << std::endl;
        return (1);
    }

    PMerge(&av[1]);
    
    return (0);
}