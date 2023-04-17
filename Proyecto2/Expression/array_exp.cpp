#include "array_exp.hpp"

array_exp::array_exp(int line, int col,TipoDato tipo , list_expression *explist)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    ExpList = explist;
}

value array_exp::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    value sym ("",false,NULO);
    return sym;
}
