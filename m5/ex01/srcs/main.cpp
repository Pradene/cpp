#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat  b1("Jake", 1);
        Bureaucrat  b2("Paul", 100);
        Bureaucrat  b3("Looser", 150);
        Form        f1("Impots St-Denis", 149, 80);
        Form        f2("Travaux JO", 100, 80);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << b3 << std::endl;

        b1.signForm(f1);
        b1.signForm(f1);
        b3.signForm(f1);
        b2.signForm(f2);
    
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
