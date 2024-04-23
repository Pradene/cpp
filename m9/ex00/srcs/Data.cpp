#include "Data.hpp"




//----- UTILS -----//

std::string to_string(const int &n) {
    std::stringstream   ss;
    std::string         str = ss.str();

    ss << n;
    str = ss.str();
    return (str);
}

int to_int(const std::string &str) {
    std::istringstream  iss(str);
    int                 n;

    if (!(iss >> n))
        throw std::runtime_error("Error: impossible conversion");
    return (n);
}




bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool isValidDate(int year, int month, int day) {

    if (month < 1 || month > 12)
        return (false);

    if (day < 1)
        return (false);

    switch (month) {
        case 2:
            if (isLeapYear(year))
                return (day <= 29);
            else
                return (day <= 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return (day <= 30);
        default:
            return (day <= 31);
    }
}




std::string ltrim(std::string str) {
    std::string::size_type pos = str.find_first_not_of(" \t\n\r");
    if (pos != std::string::npos)
        str.erase(0, pos);
    else
        str.clear();
    return (str);
}

std::string rtrim(std::string str) {
    std::string::size_type pos = str.find_last_not_of(" \t\n\r");
    if (pos != std::string::npos)
        str.erase(pos + 1);
    else
        str.clear();
    return (str);
}

std::string trim(std::string str) {
    return (ltrim(rtrim(str)));
}




//----- DATA -----//

Data::Data()
{}

Data::Data(const std::string &fileName) {
    parseFile(fileName);
}

Data::Data(const Data &rhs) {
    *this = rhs;
}

Data    &Data::operator=(const Data &rhs) {
    if (this == &rhs) 
        return (*this);
    return (*this);
}

Data::~Data()
{}




//----- METHODS -----//

bool    Data::checkDate(const std::string &date) {
    int year;
    int month;
    int day;

    if ( date.length() != 10 \
    || !std::isdigit(date[0]) || !std::isdigit(date[1]) \
    || !std::isdigit(date[2]) || !std::isdigit(date[3]) \
    || date[4] != '-' \
    || !std::isdigit(date[5]) || !std::isdigit(date[6]) \
    || date[7] != '-' \
    || !std::isdigit(date[8]) || !std::isdigit(date[9]))
        return (0);
    
    year = to_int(date.substr(0, 4));
    month = to_int(date.substr(5, 7));
    day = to_int(date.substr(8, date.length()));

    return (isValidDate(year, month, day));
}

bool    Data::getKeyValue(const std::string &line, std::string &key, float &value, char sep) {
    char    *end;
    size_t  pos;

    pos = line.find(sep);
    if (pos == std::string::npos)
        return (true);

    key = trim(line.substr(0, pos));
    value = std::strtof(trim(line.substr(pos + 1, line.size())).c_str(), &end);

    return (!checkDate(key) || *end != '\0');
}

void    Data::parseFile(const std::string &fileName) {
    std::ifstream   file(fileName.c_str());
    std::string     line;
    std::string     key;
    float           value;
    int             lineNumber = 0;

    if (!file.is_open())
        throw std::runtime_error("Error: cannot open " + fileName);
    
    if (!std::getline(file, line))
        throw std::runtime_error("Error: cannot read " + fileName);
    line.erase();
    ++lineNumber;

    while (std::getline(file, line)) {
        ++lineNumber;
        
        if (getKeyValue(line, key, value, ','))
            throw std::runtime_error("Error: wrong format at line " + to_string(lineNumber));

        _rates.insert(std::make_pair(key, value));

        line.erase();
    }
    return ;
}

void    Data::exchangeRates(const std::string &fileName) {
    std::ifstream   file(fileName.c_str());
    std::string     line;
    std::string     key;
    float           value;
    int             lineNumber = 0;


    if (!file.is_open())
        throw std::runtime_error("Error: cannot open " + fileName);
    
    if (!std::getline(file, line))
        throw std::runtime_error("Error: cannot read " + fileName);
    ++lineNumber;
    line.erase();

    while (std::getline(file, line)) {
        value = -1;
        ++lineNumber;

        if (getKeyValue(line, key, value, '|')) {
            std::cerr << "Error: format isn't valid" << std::endl;
            continue ;
        }

        if (value < 0 || value > 1000) {
            std::cerr << "Error: value isn't valid" << std::endl;
            continue ;
        }

        std::map<std::string, float>::iterator it = _rates.lower_bound(key);

        if (it == _rates.begin()) {
            std::cerr << "Error: no value found before " << key << std::endl;
            continue ;
        } else {
            --it;
        }

        if (it == _rates.end()) {
            std::cerr << "Error: no date before " << key << " found" << std::endl;
            continue ;
        }

        std::cout << key << " => " << value << " => " << (it)->second * value << std::endl;

        line.erase();
        key.erase();
    }
    return ;
}
