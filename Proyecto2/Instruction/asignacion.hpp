#ifndef ASIGNACION_HPP
#define ASIGNACION_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class asignacion : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Valor;
    expression *Valor2;

    asignacion(int line, int col, std::string Id, expression *valor, expression *valor2);
    void ejecutar(environment *env, ast *tree, generator_code* gen) override;
};

#endif // ASIGNACION_HPP
