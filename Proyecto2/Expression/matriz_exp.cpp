#include "matriz_exp.hpp"

matriz_exp::matriz_exp(int line, int col , list_expression *explist)
{
    Line = line;
    Col = col;
//    Index = index;
//    Index2 = index2;
//    Tipo = tipo;
    ExpList = explist;
//    Matriz = matriz;
}

value matriz_exp::ejecutar(environment *env, ast *tree,generator_code* gen)
{
   value sym ("",false,NULO);
    return sym;

}
