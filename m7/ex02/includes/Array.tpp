#include "Array.hpp"

template <typename T>
Array<T>::Array() :
    _arr(NULL),
    _size(0)
{}

template <typename T>
Array<T>::Array(const size_t &size) :
    _arr(new T[size]()),
    _size(size)
{
    if (_arr == NULL)
        throw std::runtime_error("Cannot allocate array");
}

template <typename T>
Array<T>::Array(const Array &arr) {
    *this = arr;
}

template <typename T>
Array<T>::~Array() {
    if (_size > 0)
        delete[] _arr;
}

template <typename T>
Array<T>    &Array<T>::operator=(const Array<T> &arr) {
    if (this == &arr)
        return (*this);
    if (_size > 0)
        delete[] _arr;
    _size = arr.size();
    _arr = new T[_size]();
    if (_arr == NULL)
        throw std::runtime_error("Cannot allocate array");
    for (size_t i = 0; i < _size; ++i)
        _arr[i] = arr._arr[i];
    return (*this);
}

template <typename T>
T   &Array<T>::operator[](const size_t index) {
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_arr[index]);
}


template <typename T>
size_t  Array<T>::size() const { return (_size); };