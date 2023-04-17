#include "matriz.hpp"

matriz::matriz(int line, int col, expression *array, expression *index1,expression *index2,expression *index3, std::string func, expression *valor)
{
    Line = line;
    Col = col;
    Matriz = array;
    Index1 = index1;
    Index2 = index2;
    Index3 = index3;
    Funcion = func;
    Valor = valor;
}

void matriz::ejecutar(environment *env, ast *tree,generator_code* gen){}
