#include "func_while.hpp"

func_while::func_while(int line, int col, expression *condition, instruction *block)
{
  Line = line;
  Col = col;
  Condition = condition;
  Block = block;
}

void func_while::ejecutar(environment *env, ast *tree)
{
  symbol sym = Condition->ejecutar(env,tree);
    if (sym.Tipo == BOOL)
    {
      int cont = 0;
      while (true && cont < 1000)
      {
        // Crear entorno de WHILE
        environment *new_env = new environment(env, "WHILE") ;
        bool *val = (bool*)sym.Value;
        // Si se cumple la condicion
        if(*val)
        {
          Block->ejecutar(new_env,tree);
        }
        else
        {
          delete new_env;
          break;
        }
        cont+=1;
        // Volver a ejecutar condicion en el entorno anterior
        sym = Condition->ejecutar(env,tree);
      }
    }
    else
    {
      tree->ErrorOut+= "Error: Tipo incorrecto para WHILE";
    }
    
}
