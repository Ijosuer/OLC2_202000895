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
        std::cout << "guardando: "<<id<<std::endl;
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
    
}

void environment::aument(std::string id,environment *env, std::string operador, ast *tree)
{
    environment tmpEnv = *env;
    symbol sym (0,0,"",NULO,nullptr);
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
            sym = env->Tabla[id];
            if (operador == "++") {
                if (sym.Tipo == INTEGER) {
                    int *a = new int;
                    int result =*static_cast<int*>(sym.Value)+1;
                    sym.Value = static_cast<int*>(&result);
                    *a = *static_cast<int*>(sym.Value);
                    sym.Value = a;
                    env->Tabla[id]= sym;
                }
            }else{
                tree->ErrorOut+="Error en el aumento";
            }
            break;
        }
    }
    
}
