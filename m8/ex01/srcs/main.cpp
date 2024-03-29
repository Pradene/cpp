#include "Span.hpp"

#define TEST 4
#define N 16
#define MAX 1024


//-----TEST -----//

void    testAddNumbers() {
    Span                s(N);
    std::vector<int>    vec;
    int                 num;

    try {

        for (size_t i = 0; i < N; ++i) {
            num = rand() % MAX;
            vec.push_back(num);
        }

        s.addNumbers(vec);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    s.print();
    std::cout << "longestSpan: " << s.shortestSpan() << std::endl;
    std::cout << "shortestSpan: " << s.longestSpan() << std::endl;
    std::cout << std::endl;
}

void    testAddNumber() {
    Span    s(N);
    int     num;

    try {

        for (size_t i = 0; i < N; ++i) {
            num = rand() % MAX;
            s.addNumber(num);
        }

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    s.print();
    std::cout << "longestSpan: " << s.shortestSpan() << std::endl;
    std::cout << "shortestSpan: " << s.longestSpan() << std::endl;
    std::cout << std::endl;
}


//----- MAIN -----//

int main(void) {
    std::srand(time(NULL));

    for (size_t i = 0; i < TEST; ++i)
        testAddNumbers();
    
    testAddNumber();

    return (0);
}