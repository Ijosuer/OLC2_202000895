#include "call_inst.hpp"
#include "Expression/map_struct_dec.hpp"
#include "Instruction/list_instruction.hpp"

call_inst::call_inst(int line, int col, std::string id, list_expression *explist)
{
    Line = line;
    Col = col;
    Id = id;
    ExpList = explist;
}

void call_inst::ejecutar(environment *env, ast *tree)
{
    //creamos entorno de funcion
    environment *FuncEnv = new environment(env, Id);
    //buscar la funcion
    func_symbol sym_func = env->GetFunc(Id, env, tree);
    //obtenemos parametros guardados
    map_struct_dec mapStrTemp;
    
    if (sym_func.ParamList != nullptr)
    {
        mapStrTemp = *(map_struct_dec*)sym_func.ParamList;
        
    }
    //obtenemos instrucciones guardados
    list_instruction instTemp = *(list_instruction*)sym_func.InstList;
    //validando si la llamada trae parametros
    // std::cout<<ExpList<<std::endl;
    if(ExpList != nullptr)
    {
        //Comparando cantidad de parametros
        map<std::string, TipoDato> mapTemp = mapStrTemp.ListDec;
        if(ExpList->ListExp.size() == mapTemp.size())
        {
            //comparando tipos de parametros
            int cont = 0;
            map<std::string, TipoDato>::iterator i;
            for(i = mapTemp.begin(); i != mapTemp.end(); ++i)
            {
                symbol sym = ExpList->ListExp[cont]->ejecutar(env, tree);
                if(sym.Tipo == i->second){
                    //se agrega la variable al entorno de la funcion
                    FuncEnv->SaveVariable(sym,i->first,tree);
                }
                else
                {
                    tree->ErrorOut += "Error: tipos de parámetros incompatibles";
                    return;
                }
                cont++;
            }
        }
        else
        {
            tree->ErrorOut += "Error: la cantidad de parámetros no es la correcta";
            return;
        }
    }
    //ejecutando instrucciones
    instTemp.ejecutar(FuncEnv, tree);
}

