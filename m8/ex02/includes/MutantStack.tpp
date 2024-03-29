#include "MutantStack.hpp"

template < typename T, class container>
MutantStack<T, container>::MutantStack() :
    std::stack<T, container>()
{}

template < typename T, class container>
MutantStack<T, container>::~MutantStack() {}

template < typename T, class container>
MutantStack<T, container>::MutantStack(const MutantStack &ms) { *this = ms; }

template < typename T, class container>
MutantStack<T, container>  &MutantStack<T, container>::operator=(const MutantStack &ms) {
    if (this == &ms)
        return (*this);
    return (*this);
}

template < typename T, class container>
typename MutantStack<T, container>::iterator    MutantStack<T, container>::begin() {
    return (typename MutantStack<T, container>::iterator(std::stack<T, container>::c.begin()));
}


template < typename T, class container>
typename MutantStack<T, container>::iterator    MutantStack<T, container>::end() {
    return (typename MutantStack<T, container>::iterator(std::stack<T, container>::c.end()));
}
