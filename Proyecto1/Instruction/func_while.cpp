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
        bool *val = (bool*)sym.Value;
        std::cout<<"Valor: "<<*val<<std::endl;
        environment *new_env = new environment(env, "WHILE") ;
        // Si se cumple la condicion
        if(*val)
        {
          // Crear entorno de IF
          Block->ejecutar(new_env,tree);
        }
        else
        {
          std::cout<<"hace break"<<std::endl;
          break;
        }
        std::cout<<"cont++"<<std::endl;
        cont+=1;
          sym = Condition->ejecutar(new_env,tree);
      }
    }
    else
    {
      tree->ErrorOut+= "Error: Tipo incorrecto para WHILE";
    }
    
}