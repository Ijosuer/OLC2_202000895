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

void func_if::ejecutar(environment *env, ast *tree)
{
    symbol sym = Condition->ejecutar(env,tree);
    if (sym.Tipo == BOOL)
    {
    // // Crear entorno de IF
    // environment *ifenv = new environment(env, "IF") ;
        bool *val = (bool *)sym.Value;
        // Si se cumple el if
        if (*val)
        {
            // Crear entorno de IF
            environment *ifenv = new environment(env, "IF") ;
            /* ejecutar el primer bloque  */
            Block->ejecutar(ifenv,tree);
            // Puede ser un else if por lo que hay que validar
            if (tree->EliFlag)
            {
                tree->EliFlag = false;
                tree->ifReturn = true;
            }
            return;
        }
        // Si no se cumple y existe un elif
        if(ElseIfBlock!=nullptr)
        {
            // Crear entorno de IF
            environment *ifenv = new environment(env, "IF") ;
            // Flag de elif
            tree->EliFlag = true;
            tree->ifReturn = false;
            ElseIfBlock->ejecutar(ifenv,tree);
            // Validar el return
            if(tree->ifReturn)return;
        }
        // Si aun no se cumple y hay ELSE
        if (ElseBlock != nullptr)
        {
            // Crear entorno de IF
            environment *ifenv = new environment(env, "IF") ;
            ElseBlock->ejecutar(ifenv,tree);
        }
        
        
    }else
    {
        /* reportar ERROR */
        tree->ErrorOut+="Error: tipo incorreco para IF\n";
    }
}