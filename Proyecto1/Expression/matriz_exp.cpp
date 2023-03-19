#include "matriz_exp.hpp"

matriz_exp::matriz_exp(int line, int col,expression* index, TipoDato tipo , list_expression *explist)
{
    Line = line;
    Col = col;
    Index = index;
    Tipo = tipo;
    ExpList = explist;
}

symbol matriz_exp::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol ind (Line,Col,"",NULO,nullptr);
    symbol tmp (Line,Col,"",NULO,nullptr);
    ind = Index->ejecutar(env, tree);
//    QVector<symbol> Arr = QVector<symbol>();
    symbol Arr[*static_cast<int*>(ind.Value)];
    int *a = static_cast<int*>(ind.Value);
    std::cout<<"size[]: "<<*static_cast<int*>(ind.Value)<<" >"<<ExpList->ListExp.size()<<std::endl;
    if (*a != ExpList->ListExp.size()) {
        tree->ErrorOut+="Error de cantidad en matriz\n";
        return sym;
    }else{

    map<std::string, TipoDato>::iterator i;
    for(int i=0; i < ExpList->ListExp.size(); ++i){
        tmp = ExpList->ListExp[i]->ejecutar(env,tree);
        if (tmp.Tipo == Tipo) {
            Arr[i] = ExpList->ListExp[i]->ejecutar(env,tree);
//            Arr.push_back(ExpList->ListExp[i]->ejecutar(env, tree));
        }else{
            tree->ErrorOut+="Error en los tipos del ARRAY";
            break;
        }
    }
    }
    sym = symbol(Line, Col, "", VECTOR, &Arr);
    return sym;
}
