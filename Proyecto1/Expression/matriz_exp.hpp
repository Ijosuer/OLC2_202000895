#ifndef MATRIZ_EXP_HPP
#define MATRIZ_EXP_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/expression.hpp"

class matriz_exp: public expression
{
public:
    int Line;
    int Col;
    expression* Index;
    TipoDato Tipo;
    list_expression *ExpList;
    QVector<symbol> ArrTemp;
    matriz_exp(int, int,expression*, TipoDato, list_expression*);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // MATRIZ_EXP_HPP
