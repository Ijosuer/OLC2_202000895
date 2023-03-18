#include "array_access.hpp"

array_access::array_access(int line, int col, expression *array, expression *index, std::string func)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
    Funcion = func;
}

symbol array_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symInd (Line,Col,"",NULO,nullptr);
    symbol symArr = Array->ejecutar(env, tree);
    if(Index != nullptr)symInd = Index->ejecutar(env, tree);

    if(Funcion == "size"){
      std::cout<<"> entra en SIZE!\n";
      QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
//      std::cout<<Arr->size()<<std::endl;
      int *val = (int *)Arr->size();
      sym = symbol(Line,Col,"",INTEGER,&val);
      int *a = new int;
      *a = *static_cast<int*>(sym.Value);
      sym.Value = a;
    }
    else if (Funcion == "push_back") {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        Arr->append(symInd);
        return sym;
    }
    else if (Funcion == "push_front") {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        Arr->prepend(symInd);
        return sym;
    }
    //validando tipo array
    if(symArr.Tipo == VECTOR && symInd.Tipo == INTEGER)
    {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        QVector<symbol> result = *Arr;
        int *val = (int *)symInd.Value;
        sym = result[*val];
    }

    return sym;
}
