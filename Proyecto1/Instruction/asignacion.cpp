#include "asignacion.hpp"

asignacion::asignacion(int line, int col, std::string id, expression *valor , expression *val2)
{
  this->Line = line;
  this->Col = col;
  this->Id = id;
  this->Valor = valor; 
  this->Valor2 = val2;
}

std::string getvalor(symbol sym)
{
    if (sym.Tipo == INTEGER)
    {
        return std::to_string(*static_cast<int*>(sym.Value));
    }
    else if (sym.Tipo == BOOL)
    {
        return std::to_string(*static_cast<bool*>(sym.Value));
    }
    else if (sym.Tipo == FLOAT)
    {
        return std::to_string(*static_cast<float*>(sym.Value));
    }
    else
    {
        return*static_cast<std::string*>(sym.Value);
    }

}
void asignacion::ejecutar(environment *env, ast *tree)
{
    symbol sym (0,0,"",NULO,nullptr);
    sym = this->Valor->ejecutar(env, tree); //Opera el valor a asignar
    symbol temp (0,0,"",NULO,nullptr);
    temp = env->GetVariable(Id,env, tree); //Devuelve un simbolo

    symbol vec_sym (0,0,"",NULO,nullptr);
    if(Valor2 != nullptr)vec_sym = this->Valor2->ejecutar(env,tree);
    // std::cout<<"EL tipo de la variable es: "<<temp.Tipo<<" "<<"Valor actual es: "<<*static_cast<int*>(temp.Value)<<std::endl;
    // std::cout<<"El valor a asignar es: "<<*static_cast<int*>(sym.Value)<<std::endl;
    if (vec_sym.Tipo == INTEGER)
    {
        env->ActualizarVariable(Id,env,vec_sym,tree);
        return;
    }
    
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
        std::string nameNodo = "instruccion_"+std::to_string(this->Line)+"_"+std::to_string(this->Col)+"_";
        std::string val = getvalor(sym);
        tree->idNodos.push_back(nameNodo);
        tree->GraphOut+=nameNodo+"[label=\"<Instruccion> Asignacion\"];\n";
        tree->GraphOut+=nameNodo+"1[label=\"<Id>\\n"+(this->Id)+"\"];\n";
        tree->GraphOut+=nameNodo+"2[label=\"<Valor>\\n"+(val)+"\"];\n";
        tree->GraphOut+=nameNodo+"->"+nameNodo+"1;\n";
        tree->GraphOut+=nameNodo+"->"+nameNodo+"2;\n";
    }
    else
    {
        tree->ErrorOut+="Error: Tipo no valido para asignar a: "+Id;
    }
}
