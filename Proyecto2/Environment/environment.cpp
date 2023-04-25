#include "environment.hpp"

environment::environment(environment *back, std::string id)
{   
    Anterior = back;
    Id = id;
    Size = 0;
}

void environment::SaveVariable(std::string id, TipoDato tipo ,ast *tree)
{
    if (Tabla.find(id) == Tabla.end())
    {   
        symbol sym(0,0,id,tipo,Size);
        Tabla[id] = sym;
        Size += 1;
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
//        std::cout << "guardando: "<<id<<std::endl;
        TablaFunctions[id] = funcSym;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Error: ya existe la funcion "+id;
    }
}

void environment::SaveStruct(map<std::string, TipoDato> tabla, std::string id, ast *tree)
{
        std::cout << "guardando: "<<id<<std::endl;
    if (TablaStructs.find(id) == TablaStructs.end())
    {
        TablaStructs[id] = tabla;
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Ya existe el struct "+id;
    }
}

symbol environment::GetVariable(std::string id, environment *env, ast *tree)
{
    symbol sym = *new symbol;
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
                            tmpEnv.Tabla[id].Posicion);
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

map<std::string, TipoDato> environment::GetStruct(std::string id, environment *env, ast *tree)
{
    map<std::string, TipoDato> sym_struct;
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.TablaStructs.find(id) == tmpEnv.TablaStructs.end())
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
            sym_struct = tmpEnv.TablaStructs[id];
            break;
        }

    }
    return sym_struct;
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
    
}
