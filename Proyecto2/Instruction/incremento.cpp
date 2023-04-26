#include "incremento.hpp"

incremento::incremento(int line, int col, std::string id, std::string valor)
{
  this->Line = line;
  this->Col = col;
  this->Id = id;
  this->Operador = valor;
}

void incremento::ejecutar(environment *env, ast *tree, generator_code* gen){
    gen->AddComment("Asignación");
    if (Operador == "++") {
        //buscando variable en entorno
        symbol sym = env->GetVariable(Id,env, tree);
        std::string tmp = gen->newTemp();
        //Traer del stack la variable
        gen->AddGetStack(tmp,std::to_string(sym.Posicion));
        // Aumentar
        gen->AddExpression(tmp,tmp,"1","+");
        //asignando valor
        gen->AddSetStack(std::to_string(sym.Posicion), tmp);
        gen->AddBr();
    }else{
        //buscando variable en entorno
        symbol sym = env->GetVariable(Id,env, tree);
        std::string tmp = gen->newTemp();
        //Traer del stack la variable
        gen->AddGetStack(tmp,std::to_string(sym.Posicion));
        // Decremento
        gen->AddExpression(tmp,tmp,"1","-");
        //asignando valor
        gen->AddSetStack(std::to_string(sym.Posicion), tmp);
        gen->AddBr();
    }
}
