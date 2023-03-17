#ifndef INCREMENTO_HPP
#define INCREMENTO_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class incremento : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    std::string Operador;

    incremento(int line, int col, std::string Id, std::string operador);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // INCREMENTO_HPP
