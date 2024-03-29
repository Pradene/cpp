#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <iterator>

template < typename T = int, class container=std::deque<T> >
class MutantStack : public std::stack<T> {

public:
    MutantStack();
    MutantStack(const MutantStack &ms);
    MutantStack &operator=(const MutantStack &ms);
    ~MutantStack();

    typedef typename container::iterator iterator;

    iterator begin();
    iterator end();

private:

};

# include "MutantStack.tpp"

#endif
