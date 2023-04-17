#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class matriz : public instruction
{
public:
    int Line;
    int Col;
    expression *Matriz;
    expression *Index1;
    expression *Index2;
    expression *Index3;
    std::string Funcion;
    expression *Valor;
    matriz(int,int, expression*, expression*, expression*, expression*, std::string, expression*);
    void ejecutar(environment *env, ast *tree, generator_code*) override;
};

#endif // MATRIZ_HPP
