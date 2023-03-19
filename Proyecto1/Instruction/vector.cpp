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

void vector::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symInd (Line,Col,"",NULO,nullptr);
    symbol symArr = Array->ejecutar(env, tree);
    if(Index != nullptr)symInd = Index->ejecutar(env, tree);

    if(Funcion == "push_back") {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        Arr->append(symInd);
    }
    else if (Funcion == "push_front") {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        Arr->prepend(symInd);
    }
    else if (Funcion == "remove") {
        QVector<symbol> *Arr = (QVector<symbol>*)symArr.Value;
        int *val = (int *)symInd.Value;
        if (*val > Arr->size()-1) {
            tree->ErrorOut+="Error: index out of range";
        }else{

            Arr->removeAt(*val);
        }
    }
    else if (Funcion == "asignar") {
        sym = Valor->ejecutar(env, tree);
        QVector<symbol> *vec = (QVector<symbol>*)symArr.Value;
//        int *val = (int *)symInd.Value;
//        void * a = new void*;
        for (auto it = vec->begin(); it != vec->end(); ++it) {
            if (std::distance(vec->begin(), it) == *static_cast<int*>(symInd.Value)) {
                reinterpret_cast<int*>((*it).Value)[0] = *static_cast<int*>(sym.Value);
                break;
            }
        }
    }
}
