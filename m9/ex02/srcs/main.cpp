#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

int stringToInt(std::string arg) {
    int num;
    std::stringstream   ss(arg);
        
    ss >> num;
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Bad input");
    
    return (num);
}

void    printVec(std::vector<size_t> &vec) {
    for (std::vector<size_t>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *(it) << " ";
    std::cout << "\n";
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
    size_t  rs = 0;
    size_t  v1 = 0;
    size_t  v2 = 1;
    
    for (size_t i = 0; i < index; ++i) {
        rs = v1 * 2 + v2;

        v1 = v2;
        v2 = rs;
    }

    return (rs);
}

std::vector<size_t> insertionSort(std::vector<size_t> &vec) {

    std::vector<size_t>::iterator ps;
    std::vector<size_t>::iterator end;
    std::vector<size_t> XS;
    std::vector<size_t> S;
    size_t  inserted = 0;
    size_t  index = 0;
    size_t  min = 0;

    for (std::vector<size_t>::iterator it = vec.begin(); it != vec.end(); ++it) {
        S.push_back(*(it));
        XS.push_back(*(++it));
    }

    for (size_t i = 1; 1; ++i) {
        min = index;
        index = jacobstahl(i);
        if (index > XS.size())
            break ;
        
        for (size_t k = index; k != min; ) {
            end = S.begin() + k + inserted;
            ps = std::upper_bound(S.begin(), end - 1, XS[--k]);
            
            S.insert(ps, XS[k]);
            ++inserted;
        }
    }

    for (size_t i = min; i < XS.size(); ++i) {        
        end = S.begin() + i + inserted;
        ps = std::upper_bound(S.begin(), end - 1, XS[i]);
        
        S.insert(ps, XS[i]);
        ++inserted;
    }

    return (S);
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