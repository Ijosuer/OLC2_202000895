#include "print.hpp"

print::print(int line, int col, expression *valor)
{
    this->Line = line;
    this->Col = col;
    this->Valor = valor;
}

void print::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value result = Valor->ejecutar(env, tree, gen);
    switch (result.TipoExpresion) {
    case INTEGER:
        gen->AddPrintf("d", "(int)"+ result.Value);
        gen->AddPrintf("c", "10");
        gen->AddBr();
        break;
    case STRING:
        //llamar a generar printstring
        gen->GeneratePrintString();
        //agregar codigo en el main
        break;
    case BOOL:
        std::string newLabel = gen->newLabel();
        //add true labels
        for(int i=0; i < result.TrueLvl.size(); i++)
        {
            gen->AddLabel(result.TrueLvl[i]);
        }
        gen->AddPrintf("c", "(char)116");
        gen->AddPrintf("c", "(char)114");
        gen->AddPrintf("c", "(char)117");
        gen->AddPrintf("c", "(char)101");
        gen->AddGoto(newLabel);
        //add false labels
        for(int j=0; j < result.FalseLvl.size(); j++)
        {
            gen->AddLabel(result.FalseLvl[j]);
        }
        gen->AddPrintf("c", "(char)102");
        gen->AddPrintf("c", "(char)97");
        gen->AddPrintf("c", "(char)108");
        gen->AddPrintf("c", "(char)115");
        gen->AddPrintf("c", "(char)101");
        gen->AddLabel(newLabel);
        gen->AddPrintf("c", "10");
        gen->AddBr();
        break;
    }
}





