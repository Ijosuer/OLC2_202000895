#include "asignacion.hpp"

asignacion::asignacion(int line, int col, std::string id, expression *valor , expression *val2)
{
  this->Line = line;
  this->Col = col;
  this->Id = id;
  this->Valor = valor;
  this->Valor2 = val2;
}

void asignacion::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    std::cout<<">Execute asignacion"<<std::endl;
    value sym = this->Valor->ejecutar(env,tree,gen);
    std::string tmp = gen->newTemp();
    std::string tmp2 = gen->newTemp();
    gen->Code+="\t" + tmp + " = heap[(int)" + tmp2 + "];\n";
    gen->AddPrintf("f",tmp);
    gen->AddPrintf("c","10");

}
