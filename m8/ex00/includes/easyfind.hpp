#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <sstream>
# include <iostream>

# include <algorithm>
# include <vector>
# include <deque>

template <typename T>
typename T::iterator    easyfind(const T &container, int n);

# include "easyfind.tpp"

#endif