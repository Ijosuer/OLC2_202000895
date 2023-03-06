#include "primitive.hpp"

primitive::primitive(int line, int col, TipoDato tipo, std::string strval, int numval, float flotval, bool boolval){
    Line = line;
    Col = col;
    Tipo = tipo;
    strVal = strval;
    numVal = numval;
    floatVal = flotval;
    boolVal = boolval;
}

symbol primitive::ejecutar(environment *env, ast* tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    switch (Tipo) {
    case INTEGER:
        sym = symbol(Line,Col,"",Tipo,&numVal);
        break;
    case FLOAT:
        sym = symbol(Line,Col,"",Tipo,&floatVal);
        break;
    case STRING:
        sym = symbol(Line,Col,"",Tipo,&strVal);
        break;
    case BOOL:
        sym = symbol(Line,Col,"",Tipo,&boolVal);
        break;
    default:
        break;
    }
    //std::cout << "retornando: " + std::to_string(*static_cast<int*>(Value) )+ "\n";
    return sym;
}
