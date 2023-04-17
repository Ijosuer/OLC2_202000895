#ifndef MATRIZ_ACCESS_HPP
#define MATRIZ_ACCESS_HPP
#include "Interfaces/expression.hpp"

class matriz_access : public expression
{
public:
    int Line;
    int Col;
    expression *Array;
    expression *Index;
//    expression *Index2;
//    std::string Funcion;
    matriz_access(int,int, expression*,expression*);
    value ejecutar(environment *env, ast *tree, generator_code*) override;
};

#endif // MATRIZ_ACCESS_HPP
