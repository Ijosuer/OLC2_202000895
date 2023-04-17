#ifndef FUNC_RETURN_HPP
#define FUNC_RETURN_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class inst_return : public instruction
{
public:
    int Line;
    int Col;
    expression *Exp;
    inst_return(int, int, expression*);
    void ejecutar(environment *env, ast *tree, generator_code*) override;
};

#endif //FUNC_RETURN_HPP
