#include "matriz_access.hpp"

matriz_access::matriz_access(int line, int col, expression *array, expression *index1,expression *index2, std::string func)
{
    Line = line;
    Col = col;
    Array = array;
    Index1 = index1;
    Index2 = index2;
    Funcion = func;
}

symbol matriz_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symInd (Line,Col,"",NULO,nullptr);
    symbol symArr = Array->ejecutar(env, tree);
    if(Index1 != nullptr)symInd = Index1->ejecutar(env, tree);
    if(Index2 != nullptr)symInd = Index2->ejecutar(env, tree);
    //validando tipo array
    if(symArr.Tipo == VECTOR && symInd.Tipo == INTEGER)
    {
        symbol Arr[1];
        sym =  Arr[0];
    }

    return sym;
}
