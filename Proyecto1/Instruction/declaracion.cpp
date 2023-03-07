#include "declaracion.hpp"

declaracion::declaracion(int line, int col, TipoDato tipo, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Valor = valor;
}
void declaracion::ejecutar(environment *env, ast *tree)
{
    symbol sym = Valor->ejecutar(env, tree);
    if(Tipo == sym.Tipo)
    {
        env->SaveVariable(sym, Id, tree);
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
        //se reporta un error
        tree->ErrorOut += "Error: el tipo es incorrecto\n";
    }
}
