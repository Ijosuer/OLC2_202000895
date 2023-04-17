#include "vector.hpp"

vector::vector(int line, int col, expression *array, expression *index, std::string func, expression *valor)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
    Funcion = func;
    Valor = valor;
}

void vector::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    std::cout<<">Execute vector"<<std::endl;
}
