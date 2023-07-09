#ifndef HARL
#define HARL

#include <iostream>
#include <string>

class Harl
{
public:
    Harl(std::string);
    void    complain();

private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

    int     _filter;
};

#endif