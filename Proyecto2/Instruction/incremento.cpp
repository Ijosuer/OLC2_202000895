#include "incremento.hpp"

incremento::incremento(int line, int col, std::string id, std::string valor)
{
  this->Line = line;
  this->Col = col;
  this->Id = id;
  this->Operador = valor;
}

void incremento::ejecutar(environment *env, ast *tree, generator_code* gen){
     std::cout<<">Execute incremento"<<std::endl;
}
