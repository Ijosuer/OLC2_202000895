#ifndef DECLARACION_HPP
#define DECLARACION_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"
#include <cmath>
    
class declaracion : public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    expression *Valor;
    expression *Index;

    declaracion(int line, int col, TipoDato tipo, std::string Id, expression *valor, expression*);
    void ejecutar(environment *env, ast *tree) override;
    std::string getvalor(symbol);
};

#endif // DECLARACION_HPP
