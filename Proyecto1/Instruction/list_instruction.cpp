#include "list_instruction.hpp"
#include "Instruction/func_return.hpp"

list_instruction::list_instruction()
{
    this->ListInst = QVector<instruction*>();
}

void list_instruction::ejecutar(environment *env, ast *tree)
{
    for (int i = 0; i < this->ListInst.size(); i ++){
        this->ListInst[i]->ejecutar(env, tree);
        // Validacion de if return
        if(tree->ifReturn)
        {
            return;
        }
        // Validacion de return en funciones
        inst_return* retu = dynamic_cast<inst_return*>(ListInst[i]);
        if (retu)
        {
            return;
        }
    }

}

void list_instruction::newInst(instruction *inst)
{
    this->ListInst.push_back(inst);
}
