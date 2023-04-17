#ifndef FUNC_FOR_HPP
#define FUNC_FOR_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_for : public instruction
{
public:
    int Line;
    int Col;
    instruction *Sentencia1;
    instruction *Sentencia2;
    expression *Condition;
    instruction *Block;

    func_for(int line, int col,instruction *sent1, expression *condition,instruction *sent2, instruction *block);
    void ejecutar(environment *env, ast *tree, generator_code*) override;
};

#endif // FUNC_FOR_HPP
