#include "environment.hpp"

environment::environment(environment *back, std::string id)
{   
    Anterior = back;
    Id = id;
}

void environment::SaveVariable(symbol sym, std::string id, ast *tree)
{
    if (Tabla.find(id) == Tabla.end())
    {
        std::cout<<"guarda"<<std::endl;
        Tabla[id] = sym;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Ya existe la variable "+id;
    }
}

symbol environment::GetVariable(std::string id, environment *env, ast *tree)
{
    symbol sym (0,0,"",NULO,nullptr);
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.Tabla.find(id) == tmpEnv.Tabla.end())
        {
            std::cout<<"Entra aca"<<std::endl;
            if(tmpEnv.Anterior == nullptr)
            {
            std::cout<<"Entra aca en break"<<std::endl;
                break;
            }
            else
            {
                tmpEnv = *tmpEnv.Anterior;
            }
        }
        else
        {
            std::cout<<"nel aca"<<std::endl;
            symbol tempSym (tmpEnv.Tabla[id].Line,
                            tmpEnv.Tabla[id].Col,
                            tmpEnv.Tabla[id].Id,
                            tmpEnv.Tabla[id].Tipo,
                            tmpEnv.Tabla[id].Value);
            sym = tempSym;
            break;
        }

    }

    return sym;
}

void environment::ActualizarVariable(std::string id, symbol valor, ast *tree)
{
    Tabla[id].Value = valor.Value;
}
