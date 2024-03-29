#include "easyfind.hpp"

#define N 16
#define MAX 32

template <typename T>
void    test(T &container)
{
    int n;
    
    for (int i = 0; i < N; ++i) {
        n = rand() % MAX;
        try {
            typename T::iterator    it = easyfind(container, n);
            std::cout << n << " found at position " << it - container.begin() << std::endl; 
        
        } catch (const std::exception &e) {
            // std::cerr << e.what() << std::endl;
        }
    }
}

int main(void) {
    std::srand(time(NULL));

    std::vector<int>    v;
    std::deque<int>     d;

    for (size_t i = 0; i < N; ++i) {
        int n = std::rand() % MAX;
        v.push_back(n);
        d.push_back(n);

        
        std::cout << n << ((i < N - 1) ? ", " : "\n");
    }

    

    std::cout << std::endl << std::endl;
    std::cout << "Vector:" << std::endl;
    test(v);

    std::cout << std::endl << std::endl;
    std::cout << "Deque:" << std::endl;
    test(d);

    return (0);
}