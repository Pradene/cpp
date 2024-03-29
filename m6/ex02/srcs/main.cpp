#include "Base.hpp"

Base    *generate(void)
{
    int n = std::rand() % 3;
    switch (n)
    {
        case 0:
            return (new A);
            break ;
        case 1:
            return (new B);
            break ;
        case 2:
            return (new C);
            break ;
        default:
            break ;
    }
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "unknown" << std::endl;
    }
}

void identify(Base &p)
{
    try {
        A a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;

    } catch (const std::exception &e) {
        try {
            B b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;

        } catch (const std::exception &e) {
            try {
                C c = dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;

            } catch (const std::exception &e) {
                std::cerr << "Unknown Type" << std::endl;
            }
        }
    }
}

int main(void)
{
    std::srand(std::time(NULL));

    Base    *a;
    Base    *b;
    Base    *c;

    a = generate();
    b = generate();
    c = generate();

    identify(a);
    identify(b);
    identify(c);

    std::cout << "-" << std::endl;

    identify(*a);
    identify(*b);
    identify(*c);

    delete a;
    delete b;
    delete c;

    return (0);
}