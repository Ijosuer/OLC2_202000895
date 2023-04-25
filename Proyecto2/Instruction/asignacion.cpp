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
    gen->AddComment("Asignación");
    //buscando variable en entorno
    symbol sym = env->GetVariable(Id,env, tree);
    //ejecutando valor
    value val = Valor->ejecutar(env, tree, gen);
    //asignando valor
    gen->AddSetStack(std::to_string(sym.Posicion), val.Value);
    gen->AddBr();


}
