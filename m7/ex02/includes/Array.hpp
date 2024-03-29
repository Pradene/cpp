#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T = int>
class Array {

public:
    Array();
    Array(const size_t &size);
    Array(const Array &arr);
    ~Array();

    T       &operator[](const size_t index);
    Array   &operator=(const Array &arr);

    size_t  size() const;


private:
    T       *_arr;
    size_t  _size;

};

# include "Array.tpp"

#endif