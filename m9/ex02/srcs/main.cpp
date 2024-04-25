#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

void    printVec(std::vector<size_t> &vec) {
    for (std::vector<size_t>::iterator it = vec.begin(); it != vec.end(); ++it)
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

std::vector<size_t> pairsSort(std::vector<size_t> &vec) {
    for (std::vector<size_t>::iterator it = vec.begin(); it != vec.end(); it += 2) {
        if (*(it) < *(it + 1))
            std::swap(*(it), *(it + 1));
    }

    return (vec);
}

std::vector<size_t> merge(std::vector<size_t> &v1, std::vector<size_t> &v2) {

    std::vector<size_t> v;
    size_t  i = 0;
    size_t  k = 0;

    while (i < v1.size() && k < v2.size()) {
        if (v1[i] < v2[k]) {
            v.push_back(v1[i++]);
            v.push_back(v1[i++]);

        } else {
            v.push_back(v2[k++]);
            v.push_back(v2[k++]);
        }
    }

    while (i < v1.size())
        v.push_back(v1[i++]);

    while (k < v2.size())
        v.push_back(v2[k++]);

    return (v);
}

std::vector<size_t> mergeSort(std::vector<size_t> &vec) {

    if (vec.size() <= 2) return (vec);

    int mid = vec.size() / 2;
    if (mid % 2) ++mid;

    std::vector<size_t>::iterator   it = vec.begin();
    std::advance(it, mid);

    std::vector<size_t> v1(vec.begin(), it);
    std::vector<size_t> v2(it, vec.end());

    v1 = mergeSort(v1);
    v2 = mergeSort(v2);

    return (merge(v1, v2));
}

size_t  jacobstahl(size_t index) {
    size_t  jacob = 0;

    size_t  v1 = 0;
    size_t  v2 = 1;
    for (size_t i = 0; i < index; ++i) {
        jacob = v1 * 2 + v2;
        
        v1 = v2;
        v2 = jacob;
    }

    return (jacob);
}

std::vector<size_t> insertionSort(std::vector<size_t> &vec) {
    std::vector<size_t>::iterator  insertPos;
    std::vector<size_t>::iterator  end = vec.begin();
    size_t  jacob = 0;
    size_t  value = 0;
    size_t  index = 0;

    std::swap(*(vec.begin()), *(vec.begin() + 1));

    for (size_t i = 0; 1; ++i) {
        jacob = jacobstahl(i);
        if (jacob > vec.size() / 2) break ;

        index = 2 * (jacob + 1);
        end = vec.begin();
        std::advance(end, index);

        for (size_t k = jacobstahl(i + 1), it = 2 * k + 1; \
            k < vec.size() / 2 && k > jacob; \
            --k, --it) {

            value = vec[it];
            insertPos = std::upper_bound(vec.begin(), end, value);
            vec.erase(vec.begin() + it);
            vec.insert(insertPos, value);
            
            end = vec.begin();
            std::advance(end, ++index);
        }
    }

    index = std::distance(vec.begin(), end);
    for (size_t it = index + 1; it < vec.size(); ++it) {
        value = vec[it];
        insertPos = std::upper_bound(vec.begin(), end, value);

        vec.erase(vec.begin() + it);
        vec.insert(insertPos, value);

        end = vec.begin();
        std::advance(end, ++index);

        it += 1;
    }

    return (vec);
}

void    fordJohnson(std::vector<size_t> &vec) {
    int odd = 0;

    if (vec.size() % 2) {
        odd = vec.back();
        vec.pop_back();
    }

    vec = pairsSort(vec);
    vec = mergeSort(vec);
    vec = insertionSort(vec);

    if (odd != 0) {
        std::vector<size_t>::iterator  it;
        it = std::lower_bound(vec.begin(), vec.end(), odd);
        vec.insert(it, odd);
    }
}

int main(int ac, const char **av) {
    try {
        if (ac < 3)
            throw std::runtime_error("./PMerge [numbers...]");

        std::vector<size_t>    vec;
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
        fordJohnson(vec);
        gettimeofday(&end, NULL);

        printVec(vec);

        size_t duration = ((end.tv_sec - start.tv_sec) * 1000000) + end.tv_usec - start.tv_usec;
        std:: cout << "Time to sort: " << duration << "ms\n";

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}