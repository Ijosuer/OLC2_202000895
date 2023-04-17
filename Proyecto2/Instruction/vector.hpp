#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class vector : public instruction
{
public:
    int Line;
    int Col;
    expression *Array;
    expression *Index;
    std::string Funcion;
    expression *Valor;
    vector(int,int, expression*, expression*, std::string, expression*);
    void ejecutar(environment *env, ast *tree, generator_code* gen) override;
};

#endif // VECTOR_HPP
