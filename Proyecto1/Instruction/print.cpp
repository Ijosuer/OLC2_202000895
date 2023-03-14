#include "print.hpp"

print::print(int line, int col, expression *valor)
{
    Line = line;
    Col = col;
    Valor = valor;
}

void print::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    sym = Valor->ejecutar(env, tree);
//    std::string* a = (std::string*)sym.Value;
//    std::cout<<a<<std::endl;
    switch (sym.Tipo) {
    case STRING:
        tree->ConsoleOut += *static_cast<std::string*>(sym.Value)+"\n";
        break;
    case INTEGER:
        tree->ConsoleOut += std::to_string(*static_cast<int*>(sym.Value))+ "\n";
        break;
    case BOOL:
        if(*static_cast<bool*>(sym.Value)){
            tree->ConsoleOut += "true\n";
        }
        else
        {
            tree->ConsoleOut += "false\n";
        }
        break;
    case FLOAT:
        tree->ConsoleOut+=std::to_string(*static_cast<float*>(sym.Value))+ "\n";
        break;
    default:
        break;
    }

}
