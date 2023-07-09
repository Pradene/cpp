#include "sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Please run the program with ./Sed [filename] [s1] [s2]" << std::endl;    
        return (1);
    }

    (void)sed(argv[1], argv[2], argv[3]);
    return (0);
}