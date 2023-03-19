#ifndef MATRIZ_ACCESS_HPP
#define MATRIZ_ACCESS_HPP
#include "Interfaces/expression.hpp"

class matriz_access : public expression
{
public:
    int Line;
    int Col;
    expression *Array;
    expression *Index1;
    expression *Index2;
    std::string Funcion;
    matriz_access(int,int, expression*,expression*, expression*, std::string);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // MATRIZ_ACCESS_HPP
