#include <iostream>

char    *toUpperCase(char *s)
{
    int i;

    i = -1;
    while (s && s[++i])
        s[i] = toupper(s[i]);
    return (s);
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        i = 0;
        while (++i < argc)
            std::cout << toUpperCase(argv[i]);
        std::cout << std::endl;
    }
    return (0);
}
