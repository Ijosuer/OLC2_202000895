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

    std::cout<<"SIZE: "<<Valor->ListExp.size()<<std::endl;
    // Iterar la cantidad de expresiones
    for (int var = 0; var < Valor->ListExp.size(); ++var) {
        sym = Valor->ListExp[var]->ejecutar(env, tree);

//    std::string* a = (std::string*)sym.Value;
    
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
        case VECTOR:
            QVector<symbol> *Arr = (QVector<symbol>*)sym.Value;
            QVector<symbol> result = *Arr;
            tree->ConsoleOut += ArrayToString(result);
            break;
        }
    }
    tree->ConsoleOut+="\n";
}
std::string print::ArrayToString(QVector<symbol> Array)
{
    std::string strBuffer = "[";
    int contIndex = 0;
    for(int i=0; i < Array.size(); ++i){
        contIndex++;
        if(Array[i].Tipo == VECTOR)
        {
            if(contIndex < Array.size())
            {
                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value)) + ",";
            }
            else
            {
                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value));
            }

        }
        else
        {
            if(Array[i].Tipo == STRING)
            {
                if(contIndex < Array.size())
                {
                    strBuffer += *static_cast<std::string*>(Array[i].Value) + ",";
                }
                else
                {
                    strBuffer += *static_cast<std::string*>(Array[i].Value);
                }

            }
            else if(Array[i].Tipo == INTEGER)
            {
                if(contIndex < Array.size())
                {
                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value)) + ",";
                }
                else
                {
                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value));
                }

            }
            else if(Array[i].Tipo == BOOL)
            {
                if(contIndex < Array.size())
                {
                    if(*static_cast<bool*>(Array[i].Value))
                    {
                        strBuffer += "true,";
                    }
                    else
                    {
                        strBuffer += "false,";
                    }
                }
                else
                {
                    if(*static_cast<bool*>(Array[i].Value))
                    {
                        strBuffer += "true";
                    }
                    else
                    {
                        strBuffer += "false";
                    }
                }

            }
        }
    }
    strBuffer += "]\n";
    return strBuffer;
}
