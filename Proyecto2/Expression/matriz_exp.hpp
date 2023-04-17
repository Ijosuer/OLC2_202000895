#ifndef MATRIZ_EXP_HPP
#define MATRIZ_EXP_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/expression.hpp"

class matriz_exp: public expression
{
public:
    int Line;
    int Col;
//    expression* Index;
//    expression* Index2;
//    TipoDato Tipo;
    list_expression *ExpList;
    std::string Matriz;
    QVector<symbol> ArrTemp;
//    QVector<QVector<symbol>> Arr2Temp;
//    matriz_exp(int, int,expression*,expression*, TipoDato, list_expression*, std::string);
        matriz_exp(int, int, list_expression*);
    value ejecutar(environment *env, ast *tree,generator_code*) override;
};

#endif // MATRIZ_EXP_HPP
