#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include <limits>
# include <cmath>

class ScalarConverter
{
public:
    static void convert(const std::string &arg);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &sc);
    ScalarConverter &operator=(const ScalarConverter &sc);
    ~ScalarConverter();
};

#endif