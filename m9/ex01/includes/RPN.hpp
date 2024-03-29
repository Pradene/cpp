#ifndef RPN_HPP
# define RPN_HPP

# include <cctype>
# include <string>
# include <iostream>
# include <sstream>
# include <exception>
# include <stack>

class RPN {

public:
    RPN(const std::string &s);
    RPN(const RPN &rhs);
    RPN& operator=(const RPN &rhs);
    ~RPN();

private:
    RPN();
    void    handleOperand(const std::string &token);

    std::stack<int> _stack;
};

#endif // RPN_HPP