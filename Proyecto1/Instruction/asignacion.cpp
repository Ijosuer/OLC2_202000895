#include "asignacion.hpp"

asignacion::asignacion(int line, int col, std::string id, expression *valor)
{
  this->Line = line;
  this->Col = col;
  this->Id = id;
  this->Valor = valor; 
}

void asignacion::ejecutar(environment *env, ast *tree)
{
    symbol sym (0,0,"",NULO,nullptr);
    sym = this->Valor->ejecutar(env, tree); //Opera el valor a asignar
    symbol temp (0,0,"",NULO,nullptr);
    temp = env->GetVariable(Id,env, tree); //Devuelve un simbolo

    // std::cout<<"EL tipo de la variable es: "<<temp.Tipo<<" "<<"Valor actual es: "<<*static_cast<int*>(temp.Value)<<std::endl;
    // std::cout<<"El valor a asignar es: "<<*static_cast<int*>(sym.Value)<<std::endl;
    if(sym.Tipo == temp.Tipo)
    {
        if (sym.Tipo == INTEGER)
        {
            int *a = new int;
            *a = *static_cast<int*>(sym.Value);
            sym.Value = a;
        }
        else if (sym.Tipo == STRING)
        {
            std::string *a = new std::string;
            *a = *static_cast<std::string*>(sym.Value);
            sym.Value = a;
        }
        else if (sym.Tipo == FLOAT)
        {
            float *a = new float;
            *a = *static_cast<float*>(sym.Value);
            sym.Value = a;
        }
        else if (sym.Tipo == BOOL)
        {
            bool *a = new bool;
            *a = *static_cast<bool*>(sym.Value);
            sym.Value = a;
        }
        
        // env->Tabla[Id] = sym;
        env->ActualizarVariable(this->Id,env,sym,tree);
    }
    else
    {
        tree->ErrorOut+="Error: Tipo no valido para asignar a: "+Id;
    }
}
