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
    std::cout<<">Execute declaracion"<<std::endl;
    gen->AddExpression("H", "H", "1", "+");
    value sym = Valor->ejecutar(env, tree,gen );
    gen->AddSetHeap("(int)H",sym.Value);

//    gen->AddPrintf("f",sym.Value);
//    gen->AddPrintf("c","10");


}
