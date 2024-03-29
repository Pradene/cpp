#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <aio.h>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <limits.h>
# include<cstdlib>

class Span {

public:
    Span(size_t size);
    Span(const Span &ref);
    ~Span();

    Span    &operator=(const Span &ref);

    void    print();

    void    addNumber(int n);
    void    addNumbers(std::vector<int> n);

    int     shortestSpan();
    int     longestSpan();

    const size_t            &getSize() const;
    const std::vector<int>  &getNumbers() const;

private:
    Span();

    size_t              _size;
    std::vector<int>    _numbers;

};

#endif