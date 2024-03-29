#include "RPN.hpp"




//----- METHODS -----//

void    RPN::handleOperand(const std::string &token) {
    if (_stack.size() < 2)
        throw std::runtime_error("Error: Bad input.");

    int n2 = _stack.top();
    _stack.pop();
    int n1 = _stack.top();
    _stack.pop();
    
    if (token == "+") {
        _stack.push(n1 + n2);
    } else if (token == "-") {
        _stack.push(n1 - n2);
    } else if (token == "*") {
        _stack.push(n1 * n2);
    } else if (token == "/") {
        if (n2 != 0) {
            _stack.push(n1 / n2);
        } else {
            throw std::runtime_error("Error: Division by zero.");
        }
    } else {
        throw std::runtime_error("Error: Invalid operator " + token);
    }
}




//----- RPN -----//

RPN::RPN() {}
RPN::RPN(const RPN &rhs) { *this = rhs; }
RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
    if (this == &rhs)
        return (*this);
    return (*this);
}

RPN::RPN(const std::string &s) {
    std::istringstream  iss(s);
    std::string         token;
    
    while (iss >> token) {
        if (token.size() != 1) {
            throw std::runtime_error("Error: Bad input.");

        } else if (isdigit(token[0])) {
            int num;
            
            std::istringstream(token) >> num;
            _stack.push(num);

        } else {
            handleOperand(token);
        }
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Error: Bad input.");

    std::cout << _stack.top() << std::endl;
    _stack.pop();
}
