#include "../includes/ScalarConverter.hpp"

bool    isFloatPseudoLiteral(const std::string &param)
{
    return (param == "nanf" \
    || param == "-inff" \
    || param == "+inff");
}

bool    isDoublePseudoLiteral(const std::string &param)
{
    return (param == "nan" \
    || param == "-inf" \
    || param == "+inf");
}

bool    isPseudoLiteral(const std::string &param)
{
    return (isDoublePseudoLiteral(param) \
    || isFloatPseudoLiteral(param));
}

bool    isPrint(int n)
{
    return (n >= ' ' && n <= '~');
}

bool    isDigit(int n)
{
    return (n >= '0' && n <= '9');
}

bool    isChar(const std::string &literal)
{
    return (literal.size() == 1 && isPrint(literal[0]) && !isDigit(literal[0]));
}

bool    isInt(const std::string &literal)
{
    size_t  i;

    i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        ++i;
    for ((void)i; i < literal.length(); ++i) {
        if (!isDigit(literal[i]))
            return (false);
    }
    return (true);
}

bool    isFloat(const std::string &literal)
{
    size_t  i;
    bool    end;

    i = 0;
    end = false;
    if (literal[0] == '-' || literal[0] == '+')
        ++i;
    for ((void)i; i < literal.length(); ++i) {
        if ((literal[i] == '.' || literal[i] == 'f') && ++i)
            break ;
        if (!isDigit(literal[i]))
            return (false);
    }
    for ((void)i; i < literal.length(); ++i) {
        if (end)
            return (false);
        if (literal[i] == 'f')
            end = true;
        else if (!isDigit(literal[i]))
            return (false);
    }
    return (true);
}

bool    isDouble(const std::string &literal)
{
    size_t  i;

    i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        ++i;
    for ((void)i; i < literal.length(); ++i) {
        if (literal[i] == '.' && ++i)
            break ;
        if (!isDigit(literal[i]))
            return (false);
    }
    for ((void)i; i < literal.length(); ++i) {
        if (!isDigit(literal[i]))
            return (false);
    }
    return (true);
}



//



void    impossibleConversion()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void    convertInt(int n)
{
    std::cout << "char: ";
    if (isPrint(n))
        std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
    else if (n >= 0 && n <= 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "Impossible" << std::endl;

    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void    convertFloat(float f)
{
    std::cout << "char: ";
    if (isPrint(static_cast<int>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else if (f >= 0 && f <= 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "Impossible" << std::endl;

    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void    convertDouble(double d)
{
    std::cout << "char: ";
    if (isPrint(static_cast<int>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= 0 && d <= 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "Impossible" << std::endl;

    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    ScalarConverter::convert(const std::string &literal)
{
	std::string         toChar = "";
	int                 toInt = 0;
	float               toFloat = 0.0f;
	double              toDouble = 0.0;
    std::istringstream  iss(literal);

    std::cout << std::fixed << std::setprecision(8);

	if (isChar(literal)) {
		std::cout << "char: " << "'" << literal[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
	
    } else if (isInt(literal)) {
        iss >> toInt;
        if (iss.fail())
            return (impossibleConversion());
        convertInt(toInt);
    
    } else if (isFloat(literal)) {
        iss >> toFloat;
        if (iss.fail())
            return (impossibleConversion());
        convertFloat(toFloat);
    
    } else if (isDouble(literal)) {
        iss >> toDouble;
        if (iss.fail())
            return (impossibleConversion());
        convertDouble(toDouble);
    
    } else if (isPseudoLiteral(literal)) {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        if (isDoublePseudoLiteral(literal)) {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        } else {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << std::string(literal.substr(0, literal.length() - 1)) << std::endl;
        }
    } else {
        impossibleConversion();
    }
}



//



ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &sc) { *this = sc; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) {
    if (this == &sc)
        return (*this);
    return (*this);
}