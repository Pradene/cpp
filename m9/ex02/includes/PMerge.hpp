#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <deque>
# include <vector>
# include <string>
# include <sstream>
# include <iostream>
# include <algorithm>

# include <ctime>


void    swap(int &n1, int &n2);
int     clamp(const int value, const int lower, const int upper);
size_t  jacobsthal(size_t n);
void    print(std::vector<int> &vec);
std::vector<int>   parseData(const char **args);

void    PMerge(const char **av);

#endif // PMERGE_HPP