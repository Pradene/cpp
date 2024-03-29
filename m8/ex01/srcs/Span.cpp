#include "Span.hpp"

Span::Span() :
    _size(0),
    _numbers()
{}

Span::Span(size_t size) :
    _size(size),
    _numbers()
{
    if (_size < 0)
        throw std::runtime_error("Size has to be greater than or equal to 0");
}

Span::Span(const Span &ref) { *this = ref; }

Span::~Span() {}

Span    &Span::operator=(const Span &ref) {
    if (this == &ref)
        return (*this);
    _size = ref.getSize();
    for (size_t i = 0; i < _size; ++i)
        _numbers[i] = ref._numbers[i];
    return (*this);
}

const size_t            &Span::getSize() const { return (_size); }
const std::vector<int>  &Span::getNumbers() const { return (_numbers); }

void    Span::print()
{
    for (std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end(); ++it) {
        std::cout << (*it) << ((it + 1 !=_numbers.end()) ? ", " : "\n");
    }
}

void    Span::addNumber(int n) {
    if (_numbers.size() + 1 > _size)
        throw std::runtime_error("Error: couldn't add to Span, not enough room");
    _numbers.push_back(n);
    std::sort(_numbers.begin(), _numbers.end());
}

void    Span::addNumbers(std::vector<int> vec) {
    size_t  range;

    range = (_size - _numbers.size());
    if (range > vec.size())
        throw std::runtime_error("Error: couldn't add to Span, not enough room");
    _numbers.insert(_numbers.end(), vec.begin(), vec.end());
    std::sort(_numbers.begin(), _numbers.end());
}

int Span::shortestSpan() {
    int n = INT_MAX;
    
    if (_size <= 1)
        throw std::runtime_error("Not emough numbers");

    for (size_t i = 1; i < _numbers.size(); ++i) {
        if (n > _numbers[i] - _numbers[i - 1])
            n = _numbers[i] - _numbers[i - 1];
    }

    return (n);
}

int Span::longestSpan() {
    if (_size <= 1)
        throw std::runtime_error("Not emough numbers");
    
    return (_numbers.back() - _numbers.front());
}
