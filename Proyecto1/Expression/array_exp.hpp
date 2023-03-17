#ifndef ARRAY_EXP_HPP
#define ARRAY_EXP_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/expression.hpp"

class array_exp: public expression
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    list_expression *ExpList;
    QVector<symbol> ArrTemp;
    array_exp(int, int, TipoDato, list_expression*);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // ARRAY_EXP_HPP
