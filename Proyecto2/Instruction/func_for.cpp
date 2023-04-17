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

void func_for::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    std::cout<<">Execute for"<<std::endl;
    
}
