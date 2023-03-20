#include "declaracion.hpp"
//#include "qdebug.h"

declaracion::declaracion(int line, int col, TipoDato tipo, std::string id, expression *valor, expression* val)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Valor = valor;
    Index = val;
}
void declaracion::ejecutar(environment *env, ast *tree)
{
    symbol sym = Valor->ejecutar(env, tree);
    if(Tipo == sym.Tipo)
    {
        if(sym.Tipo == STRING){
            std::string * a = new std::string;
            *a = *static_cast<std::string*>(sym.Value);
            sym.Value = a;
        }
        else if(sym.Tipo == FLOAT){
            float * a = new float;
            *a = *static_cast<float*>(sym.Value);
            sym.Value = a;
        }
        else if(sym.Tipo == BOOL){
            bool * a = new bool;
            *a = *static_cast<bool*>(sym.Value);
            sym.Value = a;
        }
        env->SaveVariable(sym, Id, tree);
    }
    else if (sym.Tipo == VECTOR) {
        symbol indice = Index->ejecutar(env, tree);
        std::cout<<"indice: "<<*static_cast<int*>(indice.Value)<<std::endl;
        QVector<symbol> *Arr = (QVector<symbol>*)sym.Value;
        std::cout<<"Filas "<< Arr->size()<<std::endl;
        if (*static_cast<int*>(indice.Value) == Arr->size()) {
            env->SaveVariable(sym, Id, tree);
        }else {
            tree->ErrorOut+="Error valor de indice";
        }
    }
                                                            //    else if(Tipo == INTEGER && sym.Tipo == FLOAT)
                                                            //    {
                                                            //        float *var = static_cast<float*>(sym.Value);

                                                            //        int i = trunc(*var);

                                                            //        std::cout<<i<<std::endl;
                                                            //        sym.Value = static_cast<void*>(&i);
                                                            //        std::cout << "El valor del puntero genérico es: " <<static_cast<int*>(sym.Value) << std::endl;
                                                            //        env->SaveVariable(sym, Id, tree);
                                                            //    }
    else
    {
        std::cout<<"Tipo: "<<Tipo<<std::endl;
        std::cout<<"Sym.tipo: "<<sym.Tipo<<std::endl;
        //se reporta un error
        tree->ErrorOut += "Error: el tipo es incorrecto\n";
    }
    std::string nameNodo = "instrucccion_"+std::to_string(this->Line)+"_"+std::to_string(this->Col)+"_";
//    std::string val = getvalor(sym);
//    tree->GraphOut+=nameNodo+"[label=\"<Instruccion> Declaracion\"];\n";
//    tree->GraphOut+=nameNodo+"1[label=\"<Tipo>\\n"+std::to_string(this->Tipo)+"\"];\n";
//    tree->GraphOut+=nameNodo+"2[label=\"<Nombre>\\n"+(this->Id)+"\"];\n";
//    tree->GraphOut+=nameNodo+"3[label=\"<Valor>\\n"+(val)+"\"];\n";
//    tree->GraphOut+=nameNodo+"->"+nameNodo+"1;\n";
//    tree->GraphOut+=nameNodo+"->"+nameNodo+"2;\n";
//    tree->GraphOut+=nameNodo+"->"+nameNodo+"3;\n";
}
std::string
declaracion::getvalor(symbol sym)
{
    if (sym.Tipo == INTEGER)
    {
        return std::to_string(*static_cast<int*>(sym.Value));
    }
    else
    {
        return*static_cast<std::string*>(sym.Value);
    }

}
