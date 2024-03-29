#include <iostream>

#include "Serializer.hpp"


int main(void) {

    Data        *d = new Data;
    uintptr_t   ptr;

    d->_name = "Liam";
    d->_nick = "Pradene";
    d->_age = 22;

    std::cout << d->_name << std::endl;
    std::cout << d->_nick << std::endl;
    std::cout << d->_age << std::endl;

    ptr = Serializer::serialize(d);
    d = Serializer::deserialize(ptr);

    std::cout << d->_name << std::endl;
    std::cout << d->_nick << std::endl;
    std::cout << d->_age << std::endl;

    delete d;
    return (0);
}