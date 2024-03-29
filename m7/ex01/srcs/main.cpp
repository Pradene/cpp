#include "Iter.hpp"

int main(void) {
    int     arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    char    str[8] = "Bonjour";
    float   flt[8] = {9.2, 1, 2, 3, 4, 5, 6, 7};

    Iter(arr, 8, printElem);
    std::cout << std::endl;
    Iter(str, 8, printElem);
    std::cout << std::endl;
    Iter(flt, 8, printElem);
    std::cout << std::endl;

    return (0);
}