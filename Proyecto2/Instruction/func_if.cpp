#include "func_if.hpp"

func_if::func_if(int line, int col, expression *condition, instruction *block, instruction *elseifblock, instruction *elseblock)
{
    Line = line;
    Col = col;
    Condition = condition;
    Block = block;
    ElseIfBlock = elseifblock;
    ElseBlock = elseblock;

}

void func_if::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    gen->AddComment("Ejecutando IF");
    value val = Condition->ejecutar(env, tree, gen);
    std::string RetLvl = gen->newLabel();
//    Agregar etiqutas true
    for (int i = 0; i < val.TrueLvl.size(); ++i) {
        gen->AddLabel(val.TrueLvl[i]);
    }
    Block->ejecutar(env , tree, gen);
//    std::cout<<"val: "<<gen->flag<<"\n";
    if(gen->flag != true){
        gen->AddGoto(RetLvl);
    }else{
//        std::cout<<RetLvl<<std::endl;
        gen->AddGoto(gen->auxLvl);
    }
//    Agregar etiqutas false
    for (int i = 0; i < val.FalseLvl.size(); ++i) {
        gen->AddLabel(val.FalseLvl[i]);
    }
    if (ElseIfBlock != nullptr) {
//        std::cout<<RetLvl<<std::endl;
        if (gen->flag == true) {
            gen->flag = false;
            ElseIfBlock->ejecutar(env, tree, gen);
        }else{
            gen->auxLvl = RetLvl;
//            gen->flag = true;
            ElseIfBlock->ejecutar(env, tree, gen);
        }
    }
//    gen->AddGoto(RetLvl);
    if (ElseBlock != nullptr) {
        ElseBlock->ejecutar(env, tree, gen);
        gen->flag= false;
    }
    gen->AddLabel(RetLvl);
}
