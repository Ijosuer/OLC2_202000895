#include "asignacion.hpp"

asignacion::asignacion(int line, int col, std::string id, expression *valor)
{
  Line = line;
  Col = col;
  Id = id;
  Valor = valor;
}

void asignacion::ejecutar(environment *env, ast *tree)
{

    symbol sym = Valor->ejecutar(env, tree);//Opera el valor a asignar
    symbol temp = env->GetVariable(Id, tree);//Devuelve un simbolo

    std::cout<<temp.Tipo<<" "<<*static_cast<int*>(temp.Value)<<std::endl;
    std::cout<<*static_cast<int*>(sym.Value)<<std::endl;
    if(sym.Tipo == temp.Tipo)
    {
        env->ActualizarVariable(Id,sym,tree);
    }
    else
    {
        tree->ErrorOut+="No es posible actualizar la variable: "+Id;
    }
}
