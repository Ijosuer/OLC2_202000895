#include "asignacion.hpp"

asignacion::asignacion(int line, int col, std::string id, expression *valor , expression *val2)
{
  this->Line = line;
  this->Col = col;
  this->Id = id;
  this->Valor = valor; 
  this->Valor2 = val2;
}

std::string getvalor(symbol sym)
{
    if (sym.Tipo == INTEGER)
    {
        return std::to_string(*static_cast<int*>(sym.Value));
    }
    else if (sym.Tipo == BOOL)
    {
        return std::to_string(*static_cast<bool*>(sym.Value));
    }
    else if (sym.Tipo == FLOAT)
    {
        return std::to_string(*static_cast<float*>(sym.Value));
    }
    else
    {
        return*static_cast<std::string*>(sym.Value);
    }

}
void asignacion::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    std::cout<<">Execute asignacion"<<std::endl;

}
