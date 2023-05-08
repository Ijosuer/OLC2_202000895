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
        gen->AddComment("HOLA ESTOY HACIENDO UNA SUMA");

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
                gen->AddComment("Concatenando STRING + NUMERO");
                std::string tmp = gen->newTemp();
                gen->AddAssign(tmp,"H");
                gen->AddComment("Parte STRING");
                std::string labelRepetir = gen->newLabel();
                std::string labelSalir = gen->newLabel();
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
            return val;
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
    else if(Operator == "%")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.TipoExpresion][op2.TipoExpresion];
        if(Dominante == INTEGER)
        {
            gen->AddComment("Agregar validacion division cero");
            gen->AddExpression(newTemp,op1.Value,op2.Value,"% ");
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
    else if (Operator == "iota") {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        if (op1.TipoExpresion == INTEGER)
        {  
                std::string tmp = gen->newTemp();
            gen->AddAssign(tmp, "H");
            gen->AddSetHeap("(int)H",op1.Value);
            gen->AddExpression("H","H","1","+");
            //indica que es un int
            gen->AddSetHeap("(int)H","-2");
            gen->AddExpression("H","H","1","+");
            //indica el fin de la cadenas
            gen->AddSetHeap("(int)H","-1");
            gen->AddExpression("H","H","1","+");
            value val(tmp, true, STRING);
            return val;
        }
        else if (op1.TipoExpresion == FLOAT)
        {
            std::string tmp = gen->newTemp();
            gen->AddAssign(tmp, "H");
            gen->AddSetHeap("(int)H",op1.Value);
            gen->AddExpression("H","H","1","+");

            gen->AddSetHeap("(int)H","-3");
            gen->AddExpression("H","H","1","+");

            gen->AddSetHeap("(int)H","-1");
            gen->AddExpression("H","H","1","+");
            value val(tmp, true, STRING);
            return val;
        }
        else if(op1.TipoExpresion == BOOL){
//            std::cout<<"ENTRA EN EXP BOOL   \n"<<op1.Value<<std::endl;
            std::string labelTrue = gen->newLabel();
            std::string labelFalse = gen->newLabel();
            std::string labelSalir = gen->newLabel();
            std::string tmp = gen->newTemp();
            gen->AddIf(op1.Value,"1","==",labelTrue);
            gen->AddGoto(labelFalse);

            //TRUE
            gen->AddLabel(labelTrue);
            gen->AddAssign(tmp,"H");
            //concatenar true
            gen->AddComment("t");
            gen->AddSetHeap("(int)H","116" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("r");
            gen->AddSetHeap("(int)H","114" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("u");
            gen->AddSetHeap("(int)H","117" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("e");
            gen->AddSetHeap("(int)H","101" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddSetHeap("(int)H","-1" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddGoto(labelSalir);
            //FALSE
            gen->AddLabel(labelFalse);
            gen->AddAssign(tmp,"H");
            gen->AddComment("f");
            gen->AddSetHeap("(int)H","102" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("a");
            gen->AddSetHeap("(int)H","97" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("l");
            gen->AddSetHeap("(int)H","108" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("s");
            gen->AddSetHeap("(int)H","115" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddComment("e");
            gen->AddSetHeap("(int)H","101" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddSetHeap("(int)H","-1" );
            gen->AddExpression("H", "H", "1", "+");
            gen->AddGoto(labelSalir);
            gen->AddLabel(labelSalir);
            value val(tmp, true, STRING);
            return val;
        }
    }
    else if (Operator == "atoi") {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        gen->AddComment("----ATOI---");
        std::string t2 = gen->newTemp();
        std::string t3 = gen->newTemp();
        std::string t4 = gen->newTemp();
        std::string tpeso = gen->newTemp();

        std::string L1 = gen->newLabel();
        std::string L2 = gen->newLabel();
        std::string L3 = gen->newLabel(); 
        std::string L4 = gen->newLabel();
        std::string L5 = gen->newLabel();

        //Encontrar la ultima posicion del string y asignarsela al temporal que va a iterar
        //Pos del heap donde empieza el valor String
        gen->AddAssign(tpeso, "1");
        gen->AddAssign(t2, op1.Value);
        gen->AddAssign(t3, "0");
        gen->AddLabel(L4);
        gen->AddAssign(t4, "heap[(int)"+t2+"]");
        gen->AddIf(t4, "-1","==",L1);
        gen->AddComment("Validando solo caracteres numericos");
        gen->AddIf(t4,"48","<",L5);
        gen->AddIf(t4,"57",">",L5);

        gen->AddGoto(L2);
        gen->AddLabel(L1);

        gen->AddGoto(L3);
        gen->AddLabel(L2);
        gen->AddAssign(t3,t2);
        gen->AddExpression(t2, t2,"1","+");
        gen->AddGoto(L4);
        gen->AddLabel(L3);
        //AQUI TENGO EN t3 la ultima posicion de la cadena (Ej. 510 t3= 2, pos 2 del heap es la ultima pos de la cadena)
        std::string t5 = gen->newTemp();
        std::string t6 = gen->newTemp();
        std::string L6 = gen->newLabel();
        std::string L7 = gen->newLabel();
        std::string tresultado = gen->newTemp();
        std::string LSalir = gen->newLabel();

        gen->AddAssign(t5,t3);
        std::string LRec = gen->newLabel();
        //Aqui iria la etiqueta
        gen->AddLabel(LRec);
        gen->AddAssign(t6,"heap[(int)"+t5+"]");
        gen->AddIf(t6,"-2","==", L6);
        gen->AddIf(t6,"-3","==", L5);
        gen->AddIf(t6,"-1","==", LSalir);
        gen->AddIf(t5,"-1","==",LSalir);
        gen->AddGoto(L7);

        //es -2 es un int
        gen->AddLabel(L6);
        gen->AddExpression(t5,t5,"1","-");
        gen->AddAssign(tresultado, "heap[(int)"+t5+"]");
        gen->AddGoto(LSalir);

        //es una cadena de caracteres
        gen->AddLabel(L7);
        std::string tmpComparar = gen->newTemp();
        std::string L8 = gen->newLabel();
        std::string L9 = gen->newLabel();
        gen->AddAssign(tmpComparar,"heap[(int)" + t5 +"]");
        gen->AddIf(tpeso, "1","==", L8);
        gen->AddGoto(L9);
        gen->AddLabel(L8);
        //primer digito de la derecha  
        std::string tmpOperar = gen->newTemp();
        gen->AddExpression(tmpComparar, tmpComparar,"48","-");
        gen->AddExpression(tmpOperar,tmpComparar,"1","*");
        gen->AddExpression(tresultado,tresultado,tmpOperar,"+");
        gen->AddExpression(t5,t5,"1","-");
        gen->AddExpression(tpeso,tpeso,"10","*");
        gen->AddGoto(LRec);

        // restar 48 para obtener digito
        gen->AddLabel(L9);
        std::string tmpOperar2 = gen->newTemp();
        gen->AddExpression(tmpComparar, tmpComparar,"48","-");
        gen->AddExpression(tmpOperar2,tmpComparar,tpeso,"*");
        gen->AddExpression(tresultado,tresultado,tmpOperar2,"+");
        gen->AddExpression(t5,t5,"1","-");
        gen->AddExpression(tpeso,tpeso,"10","*");
        gen->AddGoto(LRec);

        //ERROR
        gen->AddLabel(L5);
        gen->AddComment("No se puede convertir la cadena a INT"); 
        gen->AddPrintf("c", "78");
        gen->AddPrintf("c", "111");
        gen->AddPrintf("c", "32");
        gen->AddPrintf("c", "115");
        gen->AddPrintf("c", "101");
        gen->AddPrintf("c", "32");
        gen->AddPrintf("c", "112");
        gen->AddPrintf("c", "117");
        gen->AddPrintf("c", "101");
        gen->AddPrintf("c", "100");
        gen->AddPrintf("c", "101");
        gen->AddPrintf("c", "32");
        gen->AddPrintf("c", "99");
        gen->AddPrintf("c", "111");
        gen->AddPrintf("c", "110");
        gen->AddPrintf("c", "118");
        gen->AddPrintf("c", "101");
        gen->AddPrintf("c", "114");
        gen->AddPrintf("c", "116");
        gen->AddPrintf("c", "105");
        gen->AddPrintf("c", "114");
        gen->AddPrintf("c", "32");
        gen->AddPrintf("c", "97");
        gen->AddPrintf("c", "32");
        gen->AddPrintf("c", "73");
        gen->AddPrintf("c", "78");
        gen->AddPrintf("c", "84");
        gen->AddGoto(LSalir);
        gen->AddLabel(LSalir);

        val = value(tresultado, true, INTEGER);
        return val;

    }
    return val;
}
