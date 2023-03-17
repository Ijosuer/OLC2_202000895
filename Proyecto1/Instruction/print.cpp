#include "print.hpp"

print::print(int line, int col, list_expression *valor)
{
    Line = line;
    Col = col;
    Valor = valor;
}

void print::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);

    // Iterar la cantidad de expresiones
    for (int var = 0; var < Valor->ListExp.size(); ++var) {
        sym = Valor->ListExp[var]->ejecutar(env, tree);

//    std::string* a = (std::string*)sym.Value;
    // std::cout<<"SIZE: "<<Valor->ListExp.size()<<std::endl;
    
        // Verificar el tipo de las expresiones
        switch (sym.Tipo) {
        case STRING:
            tree->ConsoleOut += *static_cast<std::string*>(sym.Value)+" ";
            break;
        case INTEGER:
            tree->ConsoleOut += std::to_string(*static_cast<int*>(sym.Value))+" ";
            break;
        case BOOL:
            if(*static_cast<bool*>(sym.Value)){
                tree->ConsoleOut += "true ";
            }
            else
            {
                tree->ConsoleOut += "false ";
            }
            break;
        case FLOAT:
            tree->ConsoleOut+=std::to_string(*static_cast<float*>(sym.Value))+ " ";
            break;
        default:
            break;
        }
    }
    tree->ConsoleOut+="\n";
}
