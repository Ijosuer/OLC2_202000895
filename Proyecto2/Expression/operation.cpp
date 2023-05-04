    #include "operation.hpp"

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    Line = line;
    Col = col;
    Op_izq = op_izq;
    Op_der = op_der;
    Operator = operador;
}

value operation::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val ("",false,NULO);

    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    TipoDato Matrz[5][5] = {
        {INTEGER, FLOAT, STRING, INTEGER, NULO},
        {FLOAT, FLOAT, STRING, FLOAT, NULO},
        {STRING, STRING, STRING, STRING, NULO},
        {INTEGER, FLOAT, STRING, BOOL, NULO},
        {NULO, NULO, NULO, NULO, NULO}
    };
    std::string newTemp = gen->newTemp();
    if(Operator == "+")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else if (Dominante == STRING ) {
            if (op1.TipoExpresion==INTEGER || op1.TipoExpresion == FLOAT) {
                gen->AddComment("Concat Int+Str");
                gen->AddComment("Parte NUMERO");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                if(op1.IsTemp){
                   std::string tmpNumero = gen->newTemp();
                   gen->AddAssign(tmpNumero, op1.Value);
                   gen->AddSetHeap("(int)H",tmpNumero);
                   gen->AddExpression("H", "H", "1", "+");
                   if(op1.TipoExpresion == INTEGER){
                       gen->AddComment("se agrega -2 para definir entero");
                       gen->AddSetHeap("(int)H","-2");
                   }else if(op1.TipoExpresion == FLOAT){
                       gen->AddSetHeap("(int)H","-3");
                   }
                   gen->AddExpression("H", "H", "1", "+");

               }else{
                   //es un valor
                   gen->AddSetHeap("(int)H",op1.Value);
                   gen->AddExpression("H", "H", "1", "+");
                   if(op1.TipoExpresion == INTEGER){
                       gen->AddSetHeap("(int)H","-2");
                   }else if(op1.TipoExpresion == FLOAT){
                       gen->AddSetHeap("(int)H","-3");
                   }//INDICA QUE ES VALOR ENTERO
                   gen->AddExpression("H", "H", "1", "+");
               }
               gen->AddComment("Parte STRING");
               std::string labelRepetir = gen->newLabel();
               std::string labelSalir = gen->newLabel();
               //Op2 es str
               //Tmp del str
               std::string tmpInicio = gen->newTemp();
               gen->AddAssign(tmpInicio, op2.Value);
               gen->AddLabel(labelRepetir);
               std::string tmpIterar = gen->newTemp();
               gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
               std::string labelTrue = gen->newLabel();
               gen->AddIf(tmpIterar,"-1","!=",labelTrue);
               gen->AddGoto(labelSalir);
               gen->AddLabel(labelTrue);
               gen->AddSetHeap("(int)H", tmpIterar);
               gen->AddExpression("H", "H", "1", "+");
               gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
               gen->AddGoto(labelRepetir);
               //encuentra en el heap -1
               gen->AddLabel(labelSalir);
               gen->AddSetHeap("(int)H", "-1");
               gen->AddExpression("H", "H", "1", "+");
               gen->AddBr();
               //string retorna el temporal creado al inicio
               val = value(tmp, true, STRING);
               return val;
            }
            else if (op2.TipoExpresion==INTEGER || op2.TipoExpresion == FLOAT) {
                //string + float = string ==============================================================
                gen->AddComment("Concatenando STRING + NUMERO");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                gen->AddComment("Parte STRING");
                std::string labelRepetir = gen->newLabel();
                std::string labelSalir = gen->newLabel();
                //EL SEGUNDO OPERANDO TIENE QUE SER STRING
                //Temporal del string
                std::string tmpInicio = gen->newTemp();
                gen->AddAssign(tmpInicio, op1.Value);
                gen->AddLabel(labelRepetir);
                std::string tmpIterar = gen->newTemp();
                gen->AddAssign(tmpIterar, "heap[(int)"+tmpInicio+"]");
                std::string labelTrue = gen->newLabel();
                gen->AddIf(tmpIterar,"-1","!=",labelTrue);
                gen->AddGoto(labelSalir);
                gen->AddLabel(labelTrue);
                gen->AddSetHeap("(int)H", tmpIterar);
                gen->AddExpression("H", "H", "1", "+");
                gen->AddExpression(tmpInicio, tmpInicio, "1", "+");
                gen->AddGoto(labelRepetir);
                //encuentra en el heap -1
                gen->AddLabel(labelSalir);

               // gen->AddExpression("H", "H", "1", "+");

                //Agregar el numero al heap seguido de -2 para indicarle que es un numero y no un ascii
                gen->AddComment("Parte NUMERO");
                if(op2.IsTemp){
                    std::string tmpNumero = gen->newTemp();
                    gen->AddAssign(tmpNumero, op2.Value);
                    gen->AddSetHeap("(int)H",tmpNumero);
                    gen->AddExpression("H", "H", "1", "+");
                    if(op2.TipoExpresion == INTEGER){
                        gen->AddSetHeap("(int)H","-2");
                    }else if(op2.TipoExpresion == FLOAT){
                        gen->AddSetHeap("(int)H","-3");
                    }
                    gen->AddExpression("H", "H", "1", "+");
                }else{
                    //es un valor
                    gen->AddSetHeap("(int)H",op2.Value);
                    gen->AddExpression("H", "H", "1", "+");
                    if(op2.TipoExpresion == INTEGER){
                        gen->AddSetHeap("(int)H","-2");
                    }else if(op2.TipoExpresion == FLOAT){
                        gen->AddSetHeap("(int)H","-3");
                    }//INDICA QUE ES VALOR ENTERO
                    gen->AddExpression("H", "H", "1", "+");
                }
                gen->AddSetHeap("(int)H", "-1");
                gen->AddExpression("H", "H", "1", "+");
                //string retorna el temporal creado al inicio
                val = value(tmp, true, STRING);
                return val;
            }

            else{

            //String + String
            value val = gen->GenerateConcatString(op1,op2);
//            gen->AddComment("Llamar funcion para concatenar str");
//            gen->Code.append("olc3d_ConcatString(); \n");
            }
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para suma";
        }
    }
    else if(Operator == "-")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"-");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para resta";
        }
    }
    else if(Operator == "*")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"*");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para multiplicación";
        }
    }
    else if(Operator == "/")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            gen->AddComment("Agregar validacion division cero");
            gen->AddExpression(newTemp,op1.Value,op2.Value,"/");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para división";
        }
    }
    else if(Operator == "<")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "<", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == ">")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, ">", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == ">=")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, ">=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "<=")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "<=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "==")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "==", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "!=")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "!=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLvl.append(trueLabel);
            val.FalseLvl.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion relacional";
        }
    }
    else if(Operator == "&&")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        //se agregan etiquetas verdaderas de op1
        for(int i=0; i < op1.TrueLvl.size(); i++)
        {
            gen->AddLabel(op1.TrueLvl[i]);
        }
        value op2 = Op_der->ejecutar(env, tree, gen);

        val = value("", false, BOOL);

        val.TrueLvl += op2.TrueLvl;
        val.FalseLvl += op1.FalseLvl;
        val.FalseLvl += op2.FalseLvl;

        return val;
    }
    else if(Operator == "||")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        //se agregan etiquetas falsas de op1
        for(int i=0; i < op1.FalseLvl.size(); i++)
        {
            gen->AddLabel(op1.FalseLvl[i]);
        }
        value op2 = Op_der->ejecutar(env, tree, gen);

        val = value("", false, BOOL);

        val.TrueLvl += op1.TrueLvl;
        val.TrueLvl += op2.TrueLvl;
        val.FalseLvl += op2.FalseLvl;
        return val;
    }
    else if(Operator == "!")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        if(op1.TipoExpresion == BOOL)
        {
            val = value("", false, BOOL);
            val.TrueLvl += op1.FalseLvl;
            val.FalseLvl += op1.TrueLvl;
            return val;
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para operacion lógica";
        }
    }
    return val;
}
