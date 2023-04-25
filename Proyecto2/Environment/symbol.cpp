#include "symbol.hpp"
symbol::symbol()
{

}

symbol::symbol(int line, int col, std::string id, TipoDato tipo, int posi){
    Line = line;
    Col = col;
    Id = id;
    Tipo = tipo;
    Posicion = posi;
}
