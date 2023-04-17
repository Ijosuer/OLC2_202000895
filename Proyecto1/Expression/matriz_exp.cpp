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

symbol matriz_exp::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol tmp (Line,Col,"",NULO,nullptr);
    QVector<symbol> Arr = QVector<symbol>();

    map<std::string, TipoDato>::iterator i;
    for(int i=0; i < ExpList->ListExp.size(); ++i){
        tmp = ExpList->ListExp[i]->ejecutar(env,tree);
        if (tmp.Tipo == INTEGER || tmp.Tipo == VECTOR || tmp.Tipo == STRING || tmp.Tipo == BOOL || tmp.Tipo == FLOAT) {

            Arr.push_back(ExpList->ListExp[i]->ejecutar(env, tree));
        }else{
            tree->ErrorOut+="Error en los tipos de la matriz";
            break;
        }
    }
    std::cout<<"EXP\n";
    this->ArrTemp = Arr;
    sym = symbol(Line, Col, "", VECTOR, &ArrTemp);
    return sym;

}
