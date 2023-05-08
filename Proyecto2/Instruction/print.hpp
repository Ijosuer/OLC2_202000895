#ifndef PRINT_HPP
#define PRINT_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/instruction.hpp"

class print : public instruction
{
public:
    int Line;
    int Col;
    list_expression *Valor;

    print(int line, int col, list_expression *valor);
    void ejecutar(environment *env, ast *tree, generator_code*) override;
    std::string ArrayToString(QVector<symbol> Array);
};

#endif // PRINT_HPP
