#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    printElem(const T &t) {
    std::cout << t << " ";
}

template <typename T>
void    Iter(T *array, size_t size, void (*func)(const T &)) {
    for (size_t i = 0; i < size; ++i) {
        func(array[i]);
    }
}

#endif