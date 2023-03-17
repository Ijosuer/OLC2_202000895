#include "func_for.hpp"

func_for::func_for(int line, int col,instruction *sent1, expression *condition,instruction *sent2, instruction *block)
{
  Line = line;
  Col = col;
  Sentencia1 = sent1;
  Condition = condition;
  Sentencia2 = sent2;
  Block = block;
}

void func_for::ejecutar(environment *env, ast *tree)
{
    environment *new_env = new environment(env, "FOR") ;
    Sentencia1->ejecutar(new_env,tree); //Ejecutando declaracion
    symbol sym = Condition->ejecutar(new_env,tree);
    Sentencia2->ejecutar(new_env,tree); //Ejecutando asignacion 
    if (sym.Tipo == BOOL)
    {
      int cont =0;
        std::cout<<"entra a ejecutar"<<std::endl;
      while (true && cont < 1000)
      {
        // Crear entorno de FOR
        environment *env_for = new environment(new_env, "FOR") ;
        bool *val = (bool*)sym.Value;
        // Si se cumple la condicion
        if(*val)
        {
          Block->ejecutar(env_for,tree);
        }
        else
        {
          break;
        }
        // Volver a ejecutar condicion en el entorno anterior
        Sentencia2->ejecutar(env_for,tree);
        sym = Condition->ejecutar(new_env,tree);
        cont+=1;
      }
    }
    else
    {
      tree->ErrorOut+= "Error: Tipo incorrecto para FOR";
    }
    
}
