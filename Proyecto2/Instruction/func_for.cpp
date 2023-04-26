#include "func_for.hpp"

func_for::func_for(int line, int col,instruction *sent1, expression *condition,instruction *sent2, instruction *block)
{
  Line = line;
  Col = col;
  Sentencia1 = sent1;
  Condition = condition;
  Sentencia2 = sent2;
  Block = block;
}

void func_for::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    gen->AddComment("Ejecutando FOR");
    value val;
//    Ejecutar Sentencia1 (declaracion)
    Sentencia1->ejecutar(env,tree,gen);
//    Generar etiquieta de retorno
    std::string RetLvl = gen->newLabel();
    gen->AddLabel(RetLvl);
//    Ejecutando Expresion
    val = Condition->ejecutar(env, tree, gen);

//    Etiquetas break y continue (falta implementar)
//    Agregar etiquetas  true
    for (int var = 0; var < val.TrueLvl.size(); ++var) {
        gen->AddLabel(val.TrueLvl[var]);
    }
//    Ejecutar instrucciones
    Block->ejecutar(env, tree, gen);
//    Ejecutar Sentencia2 (asignacion)
    Sentencia2->ejecutar(env, tree, gen);
//    Regresar a evaluar
    gen->AddGoto(RetLvl);
//    Agregar etiquetas  False
    for (int var = 0; var < val.FalseLvl.size(); ++var) {
        gen->AddLabel(val.FalseLvl[var]);
    }
}
