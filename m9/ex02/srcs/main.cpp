#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

void    printVec(std::vector<int> &vec) {
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *(it) << " ";
    std::cout << "\n";
}

int stringToInt(std::string arg) {
    int num;
    std::stringstream   ss(arg);
        
    ss >> num;
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Bad input");
    
    return (num);
}

void    sortPairs(std::vector<int> &vec) {
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2) {
        if (*(it) < *(it + 1))
            std::swap(*(it), *(it + 1));
    }
}

// NEED TO OPTIMIZE
void    sortEachPairs(std::vector<int> &vec) {
    for (std::vector<int>::iterator first = vec.begin(); first + 2 != vec.end(); first += 2) {
        for (std::vector<int>::iterator last = first + 2; last != vec.end(); last += 2) {
            if (*(first) > *(last))
                std::swap_ranges(first, first + 2, last);
        }
    }
}

void    sortVector(std::vector<int> &vec) {
    std::vector<int>::iterator  it = vec.begin();
    std::vector<int>::iterator  end;

    for (size_t i = 1; i < vec.size(); i += 2) {
        end = vec.begin() + i;
        it = std::lower_bound(vec.begin(), end - 1, *(end));
        vec.insert(it, *(end));
        vec.erase(++end);
    }
}

void    PMerge(std::vector<int> &vec) {
    int odd = 0;

    if (vec.size() % 2) {
        odd = vec.back();
        vec.pop_back();
    }

    sortPairs(vec);
    sortEachPairs(vec);
    sortVector(vec);

    if (odd != 0) {
        std::vector<int>::iterator  it;
        it = std::lower_bound(vec.begin(), vec.end(), odd);
        vec.insert(it, odd);
    }
}

int main(int ac, const char **av) {
    try {
        if (ac < 3)
            throw std::runtime_error("./PMerge [numbers...]");

        std::vector<int>    vec;
        int n = 0;

        for (size_t i = 1; av[i] != NULL; ++i) {
            n = stringToInt(av[i]);
            if (n <= 0)
                throw std::runtime_error("Integer <= 0");
            vec.push_back(n);
        }

        struct timeval  start;
        struct timeval  end;

        gettimeofday(&start, NULL);
        PMerge(vec);
        gettimeofday(&end, NULL);

        printVec(vec);

        size_t duration = ((end.tv_sec - start.tv_sec) * 1000000) + end.tv_usec - start.tv_usec;
        std:: cout << "Time to sort: " << duration << "ms\n";

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}