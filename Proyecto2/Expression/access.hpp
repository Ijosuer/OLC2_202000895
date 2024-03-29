#ifndef ACCESS_HPP
#define ACCESS_HPP
#include "Interfaces/expression.hpp"

class access : public expression
{
public:
    int Line;
    int Col;
    std::string Id;
    access(int line, int col, std::string id);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // ACCESS_HPP
