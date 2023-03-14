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

void environment::SaveFunc(func_symbol funcSym, std::string id, ast *tree)
{
    if (TablaFunctions.find(id) == TablaFunctions.end())
    {
        std::cout << "guardando: "<<id;
        TablaFunctions[id] = funcSym;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Error: ya existe la funcion "+id;
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
            flag = true;
            sym = tempSym;
            break;
        }

    }
    return sym;
}

func_symbol environment::GetFunc(std::string id, environment *env, ast *tree)
{
    func_symbol sym_func;
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.TablaFunctions.find(id) == tmpEnv.TablaFunctions.end())
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
            sym_func = tmpEnv.TablaFunctions[id];
            break;
        }

    }
    return sym_func;
}

void environment::ActualizarVariable(std::string id,environment *env, symbol valor, ast *tree)
{
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
            env->Tabla[id] = valor;
            break;
        }
    }
    
    // env->Tabla[id].Value = valor->Value;
    // Tabla[id].Value = valor->Value;
}
