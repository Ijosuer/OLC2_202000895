#ifndef DECLARACION_HPP
#define DECLARACION_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"
    
class declaracion : public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    expression *Valor;

    declaracion(int line, int col, TipoDato tipo, std::string Id, expression *valor);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // DECLARACION_HPP
