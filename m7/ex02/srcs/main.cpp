#include "Array.hpp"

int main(void) {
    Array<int>  arr1(10);
    Array<int>  arr2(10);

    for (size_t i = 0; i < arr1.size(); ++i) {
        arr1[i] = i * 2;
        arr2[i] = i * 4;
        std::cout << "arr1[" << i << "]: " << arr1[i] << " | ";
        std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }

    arr2 = arr1;
    std::cout << std::endl << std::endl;

    for (size_t i = 0; i < arr1.size(); ++i) {
        std::cout << "arr1[" << i << "]: " << arr1[i] << " | ";
        std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }

    std::cout << std::endl << std::endl;
    try {
        arr1[12] = 3;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    return (0);
}