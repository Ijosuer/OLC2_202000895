#include "matriz_access.hpp"

matriz_access::matriz_access(int line, int col, expression *array, expression *index1)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index1;
//    Index2 = index2;
//    Funcion = func;
}

value matriz_access::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    value sym ("",false,NULO);
    return sym;
}
