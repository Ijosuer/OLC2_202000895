#ifndef ARRAY_ACCESS_HPP
#define ARRAY_ACCESS_HPP
#include "Interfaces/expression.hpp"

class array_access : public expression
{
public:
    int Line;
    int Col;
    expression *Array;
    expression *Index;

     std::string Funcion;
    array_access(int,int, expression*, expression*,std::string);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // ARRAY_ACCESS_HPP
