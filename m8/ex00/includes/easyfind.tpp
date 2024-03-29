#include "easyfind.hpp"

template<typename T>
std::string to_string(const T &value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
typename T::iterator    easyfind(T &container, int n) {
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::runtime_error(to_string(n) + " not found");
    return (it);
}
