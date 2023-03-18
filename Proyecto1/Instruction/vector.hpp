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
    vector(int,int, expression*, expression*, std::string);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // VECTOR_HPP
