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

    asignacion(int line, int col, std::string Id, expression *valor);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // ASIGNACION_HPP
