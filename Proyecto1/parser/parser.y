/* comando   bison --verbose -o parser.cpp  parser.y */

/* Se requiere una versión minima de Bison */
%require  "3.0.4"
/* Se usa el skeleton más recienta para c++ */
%skeleton "lalr1.cc"

/* indica que se deben de crear archivos de cabeceras (.h)*/
%defines

/* indica el namespace que contiene al parser */
%define api.prefix{yy}

/* indica la clase que envuelve al parser */
%define api.parser.class {Parser}

/* indica que se generaran clases de tipo locations que leerá el lexer*/
%locations

/* indica que se deben crear contructores y funciones tipo make_TOKEN para cada token */
%define api.token.constructor

/* indica que se utilizará la notacion $1 -> $$ de los no terminales */
%define api.value.type variant

/* indica que el analizador mostrara un trace cuando haya un error*/
%define parse.trace

/* indica que el analizador mostrará los errores de forma descriptiva */
%define parse.error verbose

%code requires
{
    /* cabeceras iniciales */
    #include <iostream>
    #include <string>
    #include <vector>
    #include "../parserctx.hpp"

    /* expresiones */
    #include "../Expression/primitive.hpp"
    #include "../Expression/access.hpp"
    #include "../Expression/operation.hpp"
    #include "../Expression/call_exp.hpp"
    #include "../Expression/map_struct_dec.hpp"
    #include "../Expression/list_expression.hpp"
    #include "../Expression/array_exp.hpp"
    #include "../Expression/array_access.hpp"

    #include "../Environment/type.h"
    #include "../Interfaces/expression.hpp"

    /* instrucciones */
    #include "../Interfaces/instruction.hpp"
    #include "../Instruction/print.hpp"
    #include "../Instruction/declaracion.hpp"
    #include "../Instruction/asignacion.hpp"
    #include "../Instruction/list_instruction.hpp"
    #include "../Instruction/func_main.hpp"
    #include "../Instruction/func_if.hpp"
    #include "../Instruction/func_while.hpp"
    #include "../Instruction/function.hpp"
    #include "../Instruction/func_return.hpp"
    #include "../Instruction/call_inst.hpp"
    #include "../Instruction/func_for.hpp"
    #include "../Instruction/incremento.hpp"

}

/* enlace con la función del retorno de simbolos */
%code { yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO id CADENA DECIMAL suma menos mult div modulo PRINTF tk_void tk_int tk_string tk_float tk_bool tk_PARA tk_PARC rmain tk_LLAVA tk_LLAVC
%token <std::string> tk_true tk_false tk_igualq tk_diferenteq tk_mayor_igual tk_menor_igual tk_CORCHA tk_CORCHC
%token <std::string> tk_menorq tk_mayorq tk_and tk_or tk_not res_IF res_ELSE res_WHILE res_FOR res_BREAK res_CONTINUE res_RETURN res_pushB res_pushF 
%token <std::string> res_get res_remove res_size res_struct res_mean res_median res_mode res_atoi res_atof res_iota res_VECTOR mas_mas menos_menos
%token ';' '=' ',' '.'  


/* precedencia de operadores */
%left tk_or
%left tk_and
%right tk_not
%left tk_diferenteq tk_igualq
%left tk_menorq tk_mayorq tk_menor_igual 
%left suma menos
%left mult div modulo
/* %left tk_PARA tk_PARC */

/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
%type<expression*> PRIMITIVE
%type<expression*> EXP
%type<expression*> CALL_EXP;
%type<func_main*> START
%type<list_instruction*> LIST_INST
%type<func_main*> MAIN
%type<instruction*> INSTRUCTION
%type<instruction*> PRINT
%type<instruction*> DECLARAR
%type<instruction*> ASIGNAR
%type<instruction*> IF
%type<instruction*> ELIF
%type<list_instruction*> ELSE
%type<list_instruction*> ELIF_LIST
%type<list_instruction*> LIST_FUNC
%type<instruction*> WHILE
%type<instruction*> BREAK
%type<instruction*> CONT
%type<instruction*> FOR
%type<instruction*> INCREMENTO
%type<instruction*> VECTOR
%type<instruction*> FUNC
%type<instruction*> LLAMADAF
%type<instruction*> RETORNO
%type<TipoDato> TYPES
%type<map_struct_dec*> LISTPARAM
%type<list_expression*> LISTAEXP


/* printer */
%printer { yyoutput << $$; } <*>;

/* inicio de la grámatica */
%%

%start START;

START : MAIN
    {
      ctx.Main = $1;
      ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
      $$ = $1;
    }
    | LIST_FUNC MAIN
    {
        ctx.Main = $2;
        ctx.Functions = $1;
        ctx.Salida = "!Ejecución realizada con éxito!";
        $$ = $2;
    }
;
LIST_FUNC: LIST_FUNC FUNC
            {
                $1->newInst($2);
                $$=$1;
            }
         | FUNC
         {
            $$= new list_instruction();
            $$->newInst($1);
         }

;
// PRUEBA : LIST_INST;

MAIN : tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
{
    $$ = new func_main(@1.begin.line,@1.begin.column, $1, $6);
    
}
;

LIST_INST : LIST_INST INSTRUCTION
        {
            $1->newInst($2);
            $$ = $1;
        }
        | INSTRUCTION
        {
            $$ = new list_instruction();
            $$->newInst($1);
        }
;

INSTRUCTION : PRINT ';' { $$ = $1; }
            | DECLARAR ';' {$$=$1;}
            | ASIGNAR ';' {$$=$1;}
            | VECTOR ';' {$$=$1;}
            | BREAK ';' {$$=$1;}
            | CONT ';' {$$=$1;}
            | RETORNO ';'  {$$=$1;}
            | INCREMENTO ';' {$$=$1;}
            | LLAMADAF ';' {$$=$1;}
            // | FUNC  {$$=$1;}
            | WHILE  {$$=$1;}
            | FOR  {$$=$1;}
            | IF  {$$=$1;}
            | error ';'{}
;

DECLARAR: TYPES id  {std::cout<<"Declarando "<<$2<<std::endl; 
                            $$ = new declaracion(@1.begin.line,@1.begin.column,$1,$2,new primitive(@1.begin.line,@1.begin.column,$1,"",0,0.0,0));
                    }
        | TYPES id '=' EXP {std::cout<<"Declarando con valor a "<<$2<<std::endl;
                            $$ = new declaracion(@1.begin.line,@1.begin.column,$1,$2,$4);
                            }
;

ASIGNAR:  id '=' EXP {std::cout<<"Asignando valor a "<<$1<<std::endl; $$ = new asignacion(@1.begin.line,@1.begin.column,$1,$3);}
        | id tk_LLAVA  EXP tk_LLAVC '=' tk_LLAVA  EXP tk_LLAVC {std::cout<<"Asignando valor vector a: "<<$1<<std::endl;} 

;

// IF
IF  : res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELIF_LIST ELSE {$$ = new func_if(@1.begin.line,@1.begin.column,$3,$6,$8,$9);}
    | res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELSE {$$ = new func_if(@1.begin.line,@1.begin.column,$3,$6,nullptr,$8);}
;

ELIF_LIST: ELIF_LIST ELIF { $1->newInst($2); $$=$1; }
         | ELIF           { $$=new list_instruction(); $$->newInst($1); }
;

ELIF: res_ELSE res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
        {
            $$ = new func_if(@1.begin.line,@1.begin.column,$4,$7, nullptr, nullptr);
        }
;

ELSE: res_ELSE tk_LLAVA LIST_INST tk_LLAVC { $$=$3; }
    | %empty {}
;

// While
WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC {$$ = new func_while(@1.begin.line,@1.begin.column,$3,$6);}
;
        
// For
FOR:  res_FOR tk_PARA DECLARAR ';' EXP ';' ASIGNAR tk_PARC tk_LLAVA LIST_INST tk_LLAVC {$$ = new func_for(@1.begin.line,@1.begin.column,$3,$5,$7,$10);}
    | res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC {$$ = new func_for(@1.begin.line,@1.begin.column,$3,$5,$7,$10);}
;

// Break - Continue
BREAK: res_BREAK {std::cout<<"Break"<<std::endl;}
;
CONT: res_CONTINUE {std::cout<<"continue"<<std::endl;}
;

// Vector
VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_LLAVA LISTAEXP tk_LLAVC {$$ = new declaracion(0,0,$3,$5,new array_exp(0,0,$3,$8));}
      | res_VECTOR tk_menorq TYPES tk_mayorq id {std::cout<<"VECTOR empty "<<std::endl;}
      | id '.' res_get tk_PARA EXP tk_PARC {std::cout<<"VECTOR.get "<<std::endl;}
      | id '.' res_remove tk_PARA EXP tk_PARC {std::cout<<"VECTOR.remove "<<std::endl;}
;
PRINT : PRINTF tk_PARA LISTAEXP tk_PARC { $$ = new print(@1.begin.line,@1.begin.column,$3); }
;

INCREMENTO: id mas_mas  {$$ = new incremento(0,0,$1,"++");}
            | id menos_menos {$$ = new incremento(0,0,$1,"--");
                             }
;

FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC {$$=new function(@1.begin.line,@1.begin.column,$1,$2,$4,$7);}
    | TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC {$$=new function(@1.begin.line,@1.begin.column,$1,$2,nullptr,$6);}
;

CALL_EXP : id tk_PARA LISTAEXP tk_PARC { $$ = new call_exp(@1.begin.line,@1.begin.column,$1,$3); }
       | id tk_PARA tk_PARC { $$ = new call_exp(@1.begin.line,@1.begin.column,$1,nullptr); }
;

LLAMADAF: id tk_PARA LISTAEXP tk_PARC {$$= new call_inst(@1.begin.line,@1.begin.column,$1,$3);}
        | id tk_PARA tk_PARC {$$= new call_inst(@1.begin.line,@1.begin.column,$1,nullptr);}
;

RETORNO: res_RETURN EXP {$$= new inst_return(@1.begin.line,@1.begin.column,$2);}
        |  res_RETURN {$$= new inst_return(@1.begin.line,@1.begin.column,nullptr);}
;

TYPES :tk_int { $$ = INTEGER; }
    | tk_string { $$ = STRING; }
    | tk_float { $$ = FLOAT; }
    | tk_bool { $$ = BOOL; }
    |tk_void { $$ = NULO; }
;
LISTAEXP: LISTAEXP ',' EXP 
       {
            $1->newExp($3);
            $$ = $1;
        }
        | EXP 
        {
            $$ = new list_expression();
            $$->newExp($1);
        }
;

LISTPARAM: LISTPARAM ','  TYPES id
        {
            $1->newMap($4,$3);
            $$=$1;
        }
         | TYPES id
        {
            $$ = new map_struct_dec();
            $$->newMap($2,$1);
        }
;

EXP : EXP suma EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "+");}
    | EXP menos EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "-"); }
    | EXP mult EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "*"); }
    | EXP div EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "/"); }
    | EXP modulo EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "%"); }
    | tk_PARA EXP tk_PARC { $$ = $2; }
    | EXP tk_menor_igual EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "<="); }
    | EXP tk_menorq EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "<"); }
    | EXP tk_mayor_igual EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, ">="); }
    | EXP tk_mayorq EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, ">"); }
    | EXP tk_igualq EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "=="); }
    | EXP tk_diferenteq EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "!="); }
    | EXP tk_and EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "&&"); }
    | EXP tk_or EXP { $$ = new operation(@1.begin.line,@1.begin.column, $1, $3, "||"); }
    | res_atof tk_PARA EXP tk_PARC {$$ = new operation(@1.begin.line,@1.begin.column, $3, $3, "atof");}
    | res_atoi tk_PARA EXP tk_PARC {$$ = new operation(@1.begin.line,@1.begin.column, $3, $3, "atoi");}
    | res_iota tk_PARA EXP tk_PARC {$$ = new operation(@1.begin.line,@1.begin.column, $3, $3, "iota");}
    | tk_not EXP { $$ = new operation(@1.begin.line,@1.begin.column, $2, $2, "!"); }
    | tk_LLAVA LISTAEXP tk_LLAVC { $$ = new array_exp(0,0,NULO,$2); }
    | id '.' res_size tk_PARA  tk_PARC {std::cout<<"VECTOR.size "<<std::endl; $$ = new array_access(0,0,new access(0,0,$1),nullptr,"size");}
    | id '.' res_pushF tk_PARA EXP tk_PARC {$$ = new array_access(0,0,new access(0,0,$1),$5,"push_front");}
    | id '.' res_pushB tk_PARA EXP tk_PARC {$$ = new array_access(0,0,new access(0,0,$1),$5,"push_back");}
    | id tk_CORCHA EXP tk_CORCHC {$$ = new array_access(0,0,new access(0,0,$1),$3,"");}
    | PRIMITIVE { $$ = $1;}
    | CALL_EXP
    // | CALL_EXP suma CALL_EXP
;

PRIMITIVE : NUMERO {  int num = stoi($1); $$ = new primitive(@1.begin.line,@1.begin.column,INTEGER, "",num,0.0,false);}
        | CADENA
        {
            std::string str1 = $1.erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            $$ = new primitive(@1.begin.line,@1.begin.column,STRING,str2,0,0.0, false);
        }
        | id   {$$ = new access(@1.begin.line,@1.begin.column,$1);}
        | DECIMAL   {float num = stof($1); $$ = new primitive(@1.begin.line,@1.begin.column,FLOAT, "",0,num,false);}
        | tk_true   { $$ = new primitive(@1.begin.line,@1.begin.column,BOOL,"",0,0.0,true); }
        | tk_false  { $$ = new primitive(@1.begin.line,@1.begin.column,BOOL,"",0,0.0,false); }
        | res_mean tk_PARA id tk_PARC {std::cout<<"Media de: "<<$3<<std::endl;}
        | res_median tk_PARA id tk_PARC {std::cout<<"Mediana de: "<<$3<<std::endl;}
        | res_mode tk_PARA id tk_PARC {std::cout<<"Moda de: "<<$3<<std::endl;}
;

%%

/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

