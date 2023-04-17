#include "func_while.hpp"

func_while::func_while(int line, int col, expression *condition, instruction *block)
{
  Line = line;
  Col = col;
  Condition = condition;
  Block = block;
}

void func_while::ejecutar(environment *env, ast *tree, generator_code* gen)
{
   std::cout<<">Execute WHILE"<<std::endl;
    
}
