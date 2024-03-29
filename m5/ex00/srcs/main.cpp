#include "../includes/Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat  b("Kev", 150);
        std::cout << b << std::endl;
        b.incrementGrade();
        b.incrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;


    } catch (const std::exception &e) {
        std::cerr << "Couln't create Bureaucrat because : " << e.what() << std::endl;

    }



    try {
        Bureaucrat  b("Paul", 0);
        std::cout << b << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Couln't create Bureaucrat because : " << e.what() << std::endl;
        
    }



    try {
        Bureaucrat  b("Jake", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Couln't increment Bureaucrat grade because : " << e.what() << std::endl;
        
    }

    return (0);
}
