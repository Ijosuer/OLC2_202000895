#ifndef AST_HPP
#define AST_HPP
#include <string>

class ast
{
public:
    std::string ConsoleOut;
    std::string ErrorOut;
    std::string GraphOut;
    bool EliFlag;
    bool ifReturn;
    ast();
};

#endif // AST_HPP
