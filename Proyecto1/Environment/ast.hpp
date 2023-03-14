#ifndef AST_HPP
#define AST_HPP
#include <string>
#include <Environment/symbol.hpp>
#include <QVector>

class ast
{
public:
    std::string ConsoleOut;
    std::string ErrorOut;
    std::string GraphOut;
    bool EliFlag;
    bool ifReturn;
    QVector<symbol> ListReturn;
    ast();
};

#endif // AST_HPP
