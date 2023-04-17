#include "declaracion.hpp"

declaracion::declaracion(int line, int col, TipoDato tipo, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Valor = valor;
}
void declaracion::ejecutar(environment *env, ast *tree, generator_code *gen)
{
     std::cout<<">Execute declaracion"<<std::endl;
}
