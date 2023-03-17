#include "operation.hpp"

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    this->Line = line;
    this->Col = col;
    this->Op_izq = op_izq;
    this->Op_der = op_der;
    this->Operator = operador;
}

symbol operation::ejecutar(environment *env, ast *tree)
{
    symbol sym = *new symbol(Line,Col,"",NULO,nullptr);
    symbol op1 = this->Op_izq->ejecutar(env, tree);
    symbol op2 = this->Op_der->ejecutar(env, tree);

    ?


    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    TipoDato Matrz[5][5] = {
        {INTEGER, FLOAT, STRING, INTEGER, NULO},
        {FLOAT, FLOAT, STRING, FLOAT, NULO},
        {STRING, STRING, STRING, STRING, NULO},
        {INTEGER, FLOAT, STRING, INTEGER, NULO},
        {NULO, NULO, NULO, NULO, NULO}
    };

    TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
//    std::cout<<"valor: "<<Matrz[3][3]<<std::endl;

    if(Operator == "+")
    {
        if(Dominante == INTEGER)
        {
            if(op1.Tipo == BOOL || op2.Tipo == BOOL)
            {
//            std::cout<<"val1:"<<*static_cast<int*>(op1.Value)<<" Val2:"<<*static_cast<int*>(op2.Value)<<std::endl;
            int result = *static_cast<bool*>(op1.Value) + *static_cast<bool*>(op2.Value);
            sym = symbol(Line,Col,"",Dominante,&result);
            }
            else
            {
//            std::cout<<"val1:"<<*static_cast<int*>(op1.Value)<<" Val2:"<<*static_cast<int*>(op2.Value)<<std::endl;
            int result=   *static_cast<int*>(op1.Value) + *static_cast<int*>(op2.Value);
            sym = symbol(Line,Col,"",Dominante,&result);
            int *a = new int;
            *a = *static_cast<int*>(sym.Value);
            sym.Value = a;
            }
        }
        else if(Dominante == STRING)
        {
            if(op1.Tipo == BOOL)
            {
                bool b = *static_cast<bool*>(op1.Value);
                std::string s = (b)? "true" : "false";
                std::string d = *static_cast<std::string*>(op2.Value);
                // std::cout<<"val1:"<<s<<std::endl;
                std::string result = s+d;
                 sym = symbol(Line,Col,"",Dominante,&result);
            }
            else if(op2.Tipo == BOOL)
            {
                bool b = *static_cast<bool*>(op2.Value);
                std::string s = (b)? "true" : "false";
                std::string d = *static_cast<std::string*>(op1.Value);
            //    std::cout<<"val2:"<<s<<std::endl;
                std::string result = d+s;
                // std::cout<<"res:"<<result<<std::endl;
                sym = symbol(Line,Col,"",Dominante,&result);
            }
            else if(op1.Tipo == INTEGER)
            {
                int d = *static_cast<int*>(op1.Value);
                std::string val1 = std::to_string(d);
                std::string *val2 = (std::string *)op2.Value;
                std::string result = val1 + *val2;
                sym = symbol(Line,Col,"",Dominante,&result);
                std::string *a = new std::string;
                *a = *static_cast<std::string*>(sym.Value);
                sym.Value = a;
            }
            else if(op2.Tipo == INTEGER)
            {
                int d = *static_cast<int*>(op2.Value);
                std::cout<<d<<std::endl;
                std::string val2 = std::to_string(d);
                std::string *val1 = (std::string *)op1.Value;
                std::string result =*val1+ val2 ;
                sym = symbol(Line,Col,"",Dominante,&result);
                std::string *a = new std::string;
                *a = *static_cast<std::string*>(sym.Value);
                sym.Value = a;
            }
            else
            {
//                std::cout<<op1.Value<<std::endl;
//                std::cout<<op2.Value<<std::endl;
                std::string *val1 = (std::string *)op1.Value;
                std::string *val2 = (std::string *)op2.Value;
                std::string result = val1->append(*val2);
                sym = symbol(Line,Col,"",op1.Tipo,&result);
                std::string *a = new std::string;
                *a = *static_cast<std::string*>(sym.Value);
                sym.Value = a;
            }
        }
        else if(Dominante == FLOAT)
        {
            if(op1.Tipo == FLOAT && op2.Tipo == FLOAT)
            {
                float result = *static_cast<float*>(op1.Value) + *static_cast<float*>(op2.Value);
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }else if(op1.Tipo == FLOAT && op2.Tipo == INTEGER)
            {
                int temp1 = *static_cast<int*>(op2.Value);
                float result = *static_cast<float*>(op1.Value) + temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }else if(op2.Tipo == FLOAT && op1.Tipo == INTEGER)
            {
                int temp1 = *static_cast<int*>(op1.Value);
                float result = *static_cast<float*>(op2.Value) + temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
            else if(op1.Tipo == FLOAT && op2.Tipo == BOOL)
            {
                int temp1 = *static_cast<bool*>(op2.Value);
                float result = *static_cast<float*>(op1.Value) + temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
            else if(op1.Tipo == BOOL && op2.Tipo == FLOAT)
            {
                int temp1 = *static_cast<bool*>(op1.Value);
                float result = *static_cast<float*>(op2.Value) + temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para suma";
        }
    }
    else if(Operator == "-")
    {
        if(Dominante == INTEGER)
        {
            if(op1.Tipo == BOOL || op2.Tipo == BOOL)
            {
                int result = *static_cast<bool*>(op1.Value) - *static_cast<bool*>(op2.Value);
                sym = symbol(Line,Col,"",Dominante,&result);
            }
            else{
                int *val1 = (int *)op1.Value;
                int *val2 = (int *)op2.Value;
                int result = *val1 - *val2;
                sym = symbol(Line,Col,"",Dominante,&result);
                int *a = new int;
                *a = *static_cast<int*>(sym.Value);
                sym.Value = a;
            }
        }
        else if(Dominante == FLOAT)
        {
            if(op1.Tipo == FLOAT && op2.Tipo == FLOAT)
            {
                float result = *static_cast<float*>(op1.Value) - *static_cast<float*>(op2.Value);
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }else if(op1.Tipo == FLOAT && op2.Tipo == INTEGER)
            {
                int temp1 = *static_cast<int*>(op2.Value);
                float result = *static_cast<float*>(op1.Value) - temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }else if(op2.Tipo == FLOAT && op1.Tipo == INTEGER)
            {
                int temp1 = *static_cast<int*>(op1.Value);
                float result = *static_cast<float*>(op2.Value) - temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
            else if(op1.Tipo == FLOAT && op2.Tipo == BOOL)
            {
                int temp1 = *static_cast<bool*>(op2.Value);
                float result = *static_cast<float*>(op1.Value) - temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
            else if(op1.Tipo == BOOL && op2.Tipo == FLOAT)
            {
                int temp1 = *static_cast<bool*>(op1.Value);
                float result = *static_cast<float*>(op2.Value) - temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para resta";
        }
    }
    else if(Operator == "*")
    {
        if(Dominante == INTEGER)
        {
            if(op1.Tipo == BOOL || op2.Tipo == BOOL)
            {
            int result = *static_cast<bool*>(op1.Value) * *static_cast<bool*>(op2.Value);
            sym = symbol(Line,Col,"",Dominante,&result);
            }
            else{

            // int *val1 = (int *)op1.Value;
            // int *val2 = (int *)op2.Value;
            int *a = new int;
            int result = *static_cast<int*>(op1.Value) * *static_cast<int*>(op2.Value);
            sym = symbol(Line,Col,"",Dominante,&result);
            *a = *static_cast<int*>(sym.Value);
            sym.Value = a;

            // return sym;
            }
        }
        else if(Dominante == FLOAT)
        {
            if(op1.Tipo == FLOAT && op2.Tipo == FLOAT)
            {
                float result = *static_cast<float*>(op1.Value) * *static_cast<float*>(op2.Value);
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }else if(op1.Tipo == FLOAT && op2.Tipo == INTEGER)
            {
                int temp1 = *static_cast<int*>(op2.Value);
                float result = *static_cast<float*>(op1.Value) * temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }else if(op2.Tipo == FLOAT && op1.Tipo == INTEGER)
            {
                int temp1 = *static_cast<int*>(op1.Value);
                float result = *static_cast<float*>(op2.Value) * temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
            else if(op1.Tipo == FLOAT && op2.Tipo == BOOL)
            {
                int temp1 = *static_cast<bool*>(op2.Value);
                float result = *static_cast<float*>(op1.Value) * temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
            else if(op1.Tipo == BOOL && op2.Tipo == FLOAT)
            {
                int temp1 = *static_cast<bool*>(op1.Value);
                float result = *static_cast<float*>(op2.Value) * temp1;
                sym = symbol(Line,Col,"",Dominante,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
           
        }
    }
    else if(Operator == "/")
    {
        if(Dominante == INTEGER)
        {
            if(op1.Tipo == BOOL || op2.Tipo == BOOL)
            {
                bool *val1 = (bool *)op1.Value;
                bool *val2 = (bool *)op2.Value;
                if(*val2 != 0)
                {
                    int result = *val1 / *val2;
                    sym = symbol(Line,Col,"",Dominante,&result);
                }
                else
                {
                    //se reporta un error
                    tree->ErrorOut += "Error: no se puede dividir cero";
                }
            }
            else{
                int *val1 = (int *)op1.Value;
                int *val2 = (int *)op2.Value;
                int *a = new int;
                if(*val2 != 0)
                {
                    int result = *val1 / *val2;
                    sym = symbol(Line,Col,"",Dominante,&result);
                    *a = *static_cast<int*>(sym.Value);
                    sym.Value = a;
                }
                else
                {
                    //se reporta un error
                    tree->ErrorOut += "Error: no se puede dividir cero";
                }
            }
        }
        else if(Dominante == FLOAT)
        {
            if(op1.Tipo == FLOAT && op2.Tipo == FLOAT)
            {
                if(*static_cast<float*>(op2.Value) != 0)
                {
                    float result = *static_cast<float*>(op1.Value) / *static_cast<float*>(op2.Value);
                    sym = symbol(Line,Col,"",Dominante,&result);
                    float *a = new float;
                    *a = *static_cast<float*>(sym.Value);
                    sym.Value = a;
                }
                else
                {
                    //se reporta un error
                    tree->ErrorOut += "Error: no se puede dividir cero";
                }
            }else if(op1.Tipo == FLOAT && op2.Tipo == INTEGER)
            {
                if(*static_cast<int*>(op2.Value) != 0)
                {
                    int temp1 = *static_cast<int*>(op2.Value);
                    float result = *static_cast<float*>(op1.Value) / temp1;
                    sym = symbol(Line,Col,"",Dominante,&result);
                    float *a = new float;
                    *a = *static_cast<float*>(sym.Value);
                    sym.Value = a;
                }else{
                    tree->ErrorOut+="Error: no se puede dividir por cero";
                }
            }else if(op2.Tipo == FLOAT && op1.Tipo == INTEGER)
            {
                if(*static_cast<float*>(op2.Value) != 0)
                {
                    int temp1 = *static_cast<int*>(op1.Value);
                    float result = *static_cast<float*>(op2.Value) / temp1;
                    sym = symbol(Line,Col,"",Dominante,&result);
                    float *a = new float;
                    *a = *static_cast<float*>(sym.Value);
                    sym.Value = a;
                }else{
                    tree->ErrorOut+="Error: no se puede dividir por cero";
                }
            }
            else if(op1.Tipo == FLOAT && op2.Tipo == BOOL)
            {
                if(*static_cast<bool*>(op2.Value) != 0)
                {
                    int temp1 = *static_cast<bool*>(op2.Value);
                    float result = *static_cast<float*>(op1.Value) / temp1;
                    sym = symbol(Line,Col,"",Dominante,&result);
                    float *a = new float;
                    *a = *static_cast<float*>(sym.Value);
                    sym.Value = a;
                }else{
                    tree->ErrorOut+="Error: no se puede dividir por cero";
                }
            }
            else if(op1.Tipo == BOOL && op2.Tipo == FLOAT)
            {
                if(*static_cast<float*>(op2.Value) != 0)
                {
                    if (*static_cast<bool*>(op1.Value)<= 0)
                    {
                        std::cout<<"ENTRA"<<std::endl;
                        float result = 0.0;
                        sym = symbol(Line,Col,"",Dominante,&result);
                        float *a = new float;
                        *a = *static_cast<float*>(sym.Value);
                        sym.Value = a;
                    }else{
                        int temp1 = *static_cast<bool*>(op1.Value);
                        float result = *static_cast<float*>(op2.Value) / temp1;
                        sym = symbol(Line,Col,"",Dominante,&result);
                    }
                }else{
                    tree->ErrorOut+="Error: no se puede dividir por cero";
                }
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para división";
        }
    }
    else if(Operator == "%")
    {
        if(Dominante == INTEGER)
        {
            if(op1.Tipo == BOOL || op2.Tipo == BOOL)
            {
                bool val1 = (bool*)op1.Value;
                bool val2 = (bool*)op2.Value;
                int result = val1 % val2;
                sym = symbol(Line,Col,"",Dominante,&result);
                int *a = new int;
                *a = *static_cast<int*>(sym.Value);
                sym.Value = a;
            }
            else
            {
                int *val1 = (int *)op1.Value;
                int *val2 = (int *)op2.Value;
                int *a = new int;
                if(*val2 != 0)
                {
                    int result = *val1 % *val2;
                    sym = symbol(Line,Col,"",Dominante,&result);
                    *a = *static_cast<int*>(sym.Value);
                    sym.Value = a;
                }
                else
                {
                    tree->ErrorOut+="Error: No se puede hacer MOD por 0";
                }
            }
        }else{
            tree->ErrorOut+=("Error: tipo incorrecto para modulo");

        }
    }
    else if(Operator == "<")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 < *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para menor q";
            std::cout<<Dominante<<std::endl;
        }
    }
    else if(Operator == ">")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 > *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para mayor q";
        }
    }
    else if(Operator == "<=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 <= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para menor o igual q";
        }
    }
    else if(Operator == ">=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 >= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para mayor o igual q";
        }
    }
    else if(Operator == "!=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para diferente q";
        }
    }
    else if(Operator == "==")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para igual q";
        }
    }
    else if (Operator == "&&")
    {
        if(op1.Tipo == BOOL && op2.Tipo == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 && *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
            bool *a = new bool;
            *a = *static_cast<bool*>(sym.Value);
            sym.Value = a;
        }
        else
        {
            tree->ErrorOut+="Error: tipo incorrecto en exp logica";
        }
    }
    else if (Operator == "||")
    {
        if(op1.Tipo == BOOL && op2.Tipo == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 || *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
            bool *a = new bool;
            *a = *static_cast<bool*>(sym.Value);
            sym.Value = a;
        }
        else
        {
            tree->ErrorOut+="Error: tipo incorrecto en exp logica";
        }
    }
    else if (Operator == "!")
    {
        if(op2.Tipo == BOOL)
        {
            // bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = !*val2;
            sym = symbol(Line,Col,"",BOOL,&result);
            bool *a = new bool;
            *a = *static_cast<bool*>(sym.Value);
            sym.Value = a;
        }
        else
        {
            tree->ErrorOut+="Error: tipo incorrecto en exp logica";
        }
    }
    else if (Operator == "atoi")
    {
        if(op2.Tipo == STRING)
        {
            // bool *val1 = (bool *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            try {
                int result = std::stoi(*val2);
                sym = symbol(Line,Col,"",INTEGER,&result);
                int *a = new int;
                *a = *static_cast<int*>(sym.Value);
                sym.Value = a;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: la cadena no representa un número válido." << std::endl;
            }
        }
        else
        {
            tree->ErrorOut+="Error [atoi]: tipo incorrecto en atoi";
        }
    }
    else if (Operator == "atof")
    {
        if(op2.Tipo == STRING)
        {
            // bool *val1 = (bool *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            try {
                float result = std::stof(*val2);
                sym = symbol(Line,Col,"",FLOAT,&result);
                float *a = new float;
                *a = *static_cast<float*>(sym.Value);
                sym.Value = a;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error [atof]: la cadena no representa un número válido." << std::endl;
            }
        }
        else
        {
            tree->ErrorOut+="Error [atof]: tipo incorrecto en atof";
        }
    }
    else if (Operator == "iota")
    {
        if(op2.Tipo == INTEGER)
        {
            try {
                int *val2 = (int*)op2.Value;
                std::string result = std::to_string(*val2);
                sym = symbol(Line,Col,"",STRING,&result);
                std::string *a = new std::string;
                *a = *static_cast<std::string*>(sym.Value);
                sym.Value = a;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error [atoi]: El número no es válido." << std::endl;
            }
        }
        else if(op2.Tipo == FLOAT)
        {
            try {
                float *val2 = (float*)op2.Value;
                std::string result = std::to_string(*val2);
                sym = symbol(Line,Col,"",STRING,&result);
                std::string *a = new std::string;
                *a = *static_cast<std::string*>(sym.Value);
                sym.Value = a;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error [atoi]: El número no es válido." << std::endl;
            }
        }
        else if(op2.Tipo == BOOL)
        {
            bool *val2 = (bool*)op2.Value;
            std::string result = "";
            try {
                if (*val2 == false) {
                    result = "false";
                }else{
                    result = "true";
                }
                sym = symbol(Line,Col,"",STRING,&result);
                std::string *a = new std::string;
                *a = *static_cast<std::string*>(sym.Value);
                sym.Value = a;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error [atoi]: El número no es válido." << std::endl;
            }
        }
        else
        {
            tree->ErrorOut+="Error [atoi]: tipo incorrecto en atof";
        }
    }
    return sym;
}
