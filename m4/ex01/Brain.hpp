#ifndef BRAIN
#define BRAIN

#include <iostream>
#include <string>

class Brain
{
public:
    Brain();
    Brain(const Brain &b);
    ~Brain();

    Brain   &operator=(const Brain &b);

private:
    std::string _ideas[100];

};

#endif