#include "declaracion.hpp"

declaracion::declaracion(int line, int col, TipoDato tipo, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Valor = valor;
}
void declaracion::ejecutar(environment *env, ast *tree, generator_code *gen)
{
//    std::cout<<">Execute declaracion"<<std::endl;
    symbol newVar;
    value sym = Valor->ejecutar(env, tree,gen );
    gen->AddComment("Declarando variable");
    newVar = env->SaveVariable(Id,Tipo,tree);
    if (sym.TipoExpresion == BOOL) {
        //No es temporal (valor booleano)
        std::string newLabel = gen->newLabel();
        //Agregar los trueLavel
        for (int var = 0; var < sym.TrueLvl.size(); ++var) {
            gen->AddLabel(sym.TrueLvl[var]);
        }
        gen->AddSetStack(std::to_string(newVar.Posicion),"1");
        gen->AddGoto(newLabel);
        //Agregar los falseLavel
        for (int var = 0; var < sym.FalseLvl.size(); ++var) {
            gen->AddLabel(sym.FalseLvl[var]);
        }
        gen->AddSetStack(std::to_string(newVar.Posicion),"0");
        gen->AddGoto(newLabel);
        gen->AddLabel(newLabel);

    }else {
        //Si es un temporal (num,string,float,etc)
        gen->AddSetStack(std::to_string(newVar.Posicion),sym.Value);
    }
    gen->AddBr();


}
