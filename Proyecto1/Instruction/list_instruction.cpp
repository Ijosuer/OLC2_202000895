#include "list_instruction.hpp"

list_instruction::list_instruction()
{
    this->ListInst = QVector<instruction*>();
}

void list_instruction::ejecutar(environment *env, ast *tree)
{
    for (int i = 0; i < this->ListInst.size(); i ++){
        this->ListInst[i]->ejecutar(env, tree);
        if(tree->ifReturn)
        {
            return;
        }
    }
}

void list_instruction::newInst(instruction *inst)
{
    this->ListInst.push_back(inst);
}
