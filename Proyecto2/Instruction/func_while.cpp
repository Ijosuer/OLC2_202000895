#include "func_while.hpp"

func_while::func_while(int line, int col, expression *condition, instruction *block)
{
  Line = line;
  Col = col;
  Condition = condition;
  Block = block;
}

void func_while::ejecutar(environment *env, ast *tree, generator_code* gen)
{
    gen->AddComment("Ejecutando While");
    value condicion;
    //Generar etiqueta de retorno
    std::string RetLvl = gen->newLabel();
    gen->AddLabel(RetLvl);
    //Ejecutando expresion
    condicion = Condition->ejecutar(env,tree,gen);
    //Agregar etiquetas de break y return (falta implementar xd)
    //Agregar etiquetas true
    for (int var = 0; var < condicion.TrueLvl.size(); ++var) {
        gen->AddLabel(condicion.TrueLvl[var]);
    }
    // Ejecutar instrucciones
    Block->ejecutar(env, tree, gen );
    // Regresar a evular
    gen->AddGoto(RetLvl);
    //Agregar etiquetas false
    for (int var = 0; var < condicion.FalseLvl.size(); ++var) {
        gen->AddLabel(condicion.FalseLvl[var]);
    }

}
