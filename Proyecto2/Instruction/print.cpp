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
   if(result.TipoExpresion == INTEGER){

        gen->AddComment("----Print Numero----");
        gen->AddPrintf("d", "(int)"+ result.Value);
        gen->AddPrintf("c", "10");
        gen->AddBr();
       }
   else if(result.TipoExpresion == STRING){
        gen->AddComment("----Print STRING----");
        //llamar a generar printstring
        gen->GeneratePrintString();
        //agregar codigo en el main
        std::string NewTemp1 = gen->newTemp();
        std::string NewTemp2 = gen->newTemp();
        int size = env->Size;
        gen->AddComment("new temporal en pos vacia");
        gen->AddExpression(NewTemp1, "P", std::to_string(size), "+");
        gen->AddComment("se deja espacio de retorno");
        gen->AddExpression(NewTemp1, NewTemp1, "1", "+");
        gen->AddComment("se coloca string en parametro que se manda");
        gen->AddSetStack("(int)"+ NewTemp1, result.Value);
        gen->AddComment("cambio de entorno simulado");
        gen->AddExpression("P", "P", std::to_string(size), "+");
        gen->AddComment("Llamada");
        gen->AddCall("olc3d_printString");
        gen->AddComment("obtener retorno");
        gen->AddGetStack(NewTemp2, "(int)P");
        gen->AddComment("regreso del entorno");
        gen->AddExpression("P", "P", std::to_string(size), "-");
        gen->AddComment("salto de linea");
        gen->AddPrintf("c", "10");
        gen->AddBr();
    }
    else if(result.TipoExpresion == BOOL){
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
    }
}





