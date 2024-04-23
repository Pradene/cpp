#ifndef DATA_HPP
# define DATA_HPP

# include <cctype>
# include <cstdlib>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <map>
# include <algorithm>

# include <stdio.h>

class Data {

public:
    Data(const std::string &fileName);
    ~Data();

    void    exchangeRates(const std::string &file);    

private:
    Data();
    Data(const Data &rhs);
    Data    &operator=(const Data &rhs);

    bool    getKeyValue(const std::string &line, std::string &key, float &value, char sep);

    void    parseFile(const std::string &fileName);
    bool    checkDate(const std::string &date);
    
    std::map<std::string, float>    _rates;
};

#endif