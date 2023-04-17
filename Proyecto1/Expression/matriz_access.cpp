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

symbol matriz_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symInd (Line,Col,"",NULO,nullptr);
//    symbol symInd2 (Line,Col,"",NULO,nullptr);
    symbol symArr = Array->ejecutar(env, tree);

//    if(Index1 != nullptr)symInd = Index1->ejecutar(env, tree);
//    if(Index2 != nullptr)symInd2 = Index2->ejecutar(env, tree);
    std::cout<<"ACCES"<<std::endl;
    //validando tipo array
    if(symArr.Tipo == VECTOR && symInd.Tipo == INTEGER)
    {
        QVector<symbol> *tmp = (QVector<symbol>*)symArr.Value;
        QVector<symbol> result = *tmp;
        int *val = (int *)symInd.Value;
        std::cout<<*val;
        sym = result[*val];
    }
    return sym;
}
