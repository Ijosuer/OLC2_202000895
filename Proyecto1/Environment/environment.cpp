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
    bool flag = false;
    symbol sym (0,0,"",NULO,nullptr);
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.Tabla.find(id) == tmpEnv.Tabla.end())
        {
            if(tmpEnv.Anterior == nullptr)
            {
                break;
            }
            else
            {
                tmpEnv = *tmpEnv.Anterior;
            }
        }
        else
        {
            symbol tempSym (tmpEnv.Tabla[id].Line,
                            tmpEnv.Tabla[id].Col,
                            tmpEnv.Tabla[id].Id,
                            tmpEnv.Tabla[id].Tipo,
                            tmpEnv.Tabla[id].Value);
            sym = tempSym;
            flag = true;
            break;
        }

    }
    return sym;
}

void environment::ActualizarVariable(std::string id,environment *env, symbol *valor, ast *tree)
{
    bool flag =false;
    environment tmpEnv = *env;
    for(;;)
    {
        if(env->Tabla.find(id) == env->Tabla.end())
        {
            if(env->Anterior == nullptr)
            {
                break;
            }
            else
            {
                env = env->Anterior;
            }
        }
        else
        {
            env->Tabla[id].Value = valor->Value;
            flag = true;
            break;
        }
    }
    return;
    // env->Tabla[id].Value = valor->Value;
    // Tabla[id].Value = valor->Value;
}
