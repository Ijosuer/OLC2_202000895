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
//    bool flagm;
    QVector<symbol> ListReturn;
    QVector<symbol> TablaReporte;
    QVector<std::string> TablaReporteEntorno;
    QVector<std::string> idNodos;
    ast();
};

#endif // AST_HPP
