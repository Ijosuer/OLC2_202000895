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

}

/* enlace con la función del retorno de simbolos */
%code { yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO id CADENA DECIMAL suma menos mult div PRINTF tk_void tk_int tk_string tk_float tk_bool tk_PARA tk_PARC rmain tk_LLAVA tk_LLAVC
%token <std::string> tk_true tk_false tk_igualq tk_diferenteq tk_mayor_igual tk_menor_igual tk_CORCHA tk_CORCHC
%token <std::string> tk_menorq tk_mayorq tk_and tk_or tk_not res_IF res_ELSE res_WHILE res_FOR res_BREAK res_CONTINUE res_RETURN res_pushB res_pushF 
%token <std::string> res_get res_remove res_size res_struct res_mean res_median res_mode res_atoi res_atof res_iota res_VECTOR mas_mas menos_menos
%token ';' '=' ',' '.'  


/* precedencia de operadores */
%left tk_or
%left tk_and
%right tk_not
%left tk_menorq tk_mayorq tk_menor_igual tk_igualq tk_diferenteq

%left suma menos
%left mult div

/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
%type<expression*> PRIMITIVE
%type<expression*> EXP
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

/* printer */
%printer { yyoutput << $$; } <*>;

/* inicio de la grámatica */
%%

%start START;

START : MAIN
    {
      ctx.Main = $1;
        ctx.Salida = "!Ejecución realizada con éxito!";
      $$ = $1;
    }
;

// PRUEBA : LIST_INST;

MAIN : tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
{
    $$ = new func_main(0, 0, $1, $6);
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
            | FUNC  {$$=$1;}
            | WHILE  {$$=$1;}
            | FOR  {$$=$1;}
            | IF  {$$=$1;}
            | error ';'{}
;

DECLARAR: TYPES id  {std::cout<<"Declarando "<<$2<<std::endl; }
        | TYPES id '=' EXP {std::cout<<"Declarando con valor a "<<$2<<std::endl;
                            $$ = new declaracion(0,0,$1,$2,$4);}
;

ASIGNAR:  id '=' EXP {std::cout<<"Asignando valor a "<<$1<<std::endl; $$ = new asignacion(0,0,$1,$3);}
        | id tk_LLAVA  EXP tk_LLAVC '=' tk_LLAVA  EXP tk_LLAVC {std::cout<<"Asignando valor vector a: "<<$1<<std::endl;} 

;

// IF
IF  : res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELIF_LIST ELSE {$$ = new func_if(0,0,$3,$6,$8,$9);}
    | res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELSE {$$ = new func_if(0,0,$3,$6,nullptr,$8);}
;

ELIF_LIST: ELIF_LIST ELIF { $1->newInst($2); $$=$1; }
         | ELIF           { $$=new list_instruction(); $$->newInst($1); }
;

ELIF: res_ELSE res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
        {
            $$ = new func_if(0,0,$4,$7, nullptr, nullptr);
        }
;

ELSE: res_ELSE tk_LLAVA LIST_INST tk_LLAVC { $$=$3; }
    | %empty {}
;

// While
WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC {std::cout<<"While "<<std::endl;}
;
        
// For
FOR:  res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC {std::cout<<"FOR "<<std::endl;}
;

// Break - Continue
BREAK: res_BREAK {std::cout<<"Break"<<std::endl;}
;
CONT: res_CONTINUE {std::cout<<"continue"<<std::endl;}
;

// Vector
VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC {std::cout<<"VECTOR con valores "<<std::endl;}
      | res_VECTOR tk_menorq TYPES tk_mayorq id {std::cout<<"VECTOR empty "<<std::endl;}
      | id '.' res_pushB tk_PARA EXP tk_PARC {std::cout<<"VECTOR.pushB "<<std::endl;}
      | id '.' res_pushF tk_PARA EXP tk_PARC {std::cout<<"VECTOR.pushF "<<std::endl;}
      | id '.' res_get tk_PARA EXP tk_PARC {std::cout<<"VECTOR.get "<<std::endl;}
      | id '.' res_remove tk_PARA EXP tk_PARC {std::cout<<"VECTOR.remove "<<std::endl;}
      | id '.' res_size tk_PARA  tk_PARC {std::cout<<"VECTOR.size "<<std::endl;}
;

PRINT : PRINTF tk_PARA EXP tk_PARC { $$ = new print(0,0,$3); }
;

INCREMENTO: id mas_mas  {std::cout<<"masmas "<<std::endl;}
            | id menos_menos {std::cout<<"menosmenos "<<std::endl;}
;

FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC {std::cout<<"funcion: "<<$2<<std::endl;}
    | TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC {std::cout<<"funcion: "<<$2<<std::endl;}
;

LLAMADAF: id tk_PARA LISTAEXP tk_PARC {std::cout<<"Llamando funcion: "<<$1<<std::endl;}
;

RETORNO: res_RETURN EXP {std::cout<<"returno de : "<<$2<<std::endl;}
;

TYPES :tk_int { $$ = INTEGER; }
    | tk_string { $$ = STRING; }
    | tk_float { $$ = FLOAT; }
    | tk_bool { $$ = BOOL; }
    // |tk_void { $$ = "void"; }
;

LISTAEXP: LISTAEXP ',' EXP 
        |   EXP
;

LISTPARAM: LISTPARAM ','  TYPES id
         | TYPES id
;

EXP : EXP suma EXP { $$ = new operation(0, 0, $1, $3, "+"); }
    | EXP menos EXP { $$ = new operation(0, 0, $1, $3, "-"); }
    | EXP mult EXP { $$ = new operation(0, 0, $1, $3, "*"); }
    | EXP div EXP { $$ = new operation(0, 0, $1, $3, "/"); }
    | EXP tk_menor_igual EXP { $$ = new operation(0, 0, $1, $3, "<="); }
    | EXP tk_menorq EXP { $$ = new operation(0, 0, $1, $3, "<"); }
    | EXP tk_mayor_igual EXP { $$ = new operation(0, 0, $1, $3, ">="); }
    | EXP tk_mayorq EXP { $$ = new operation(0, 0, $1, $3, ">"); }
    | EXP tk_igualq EXP { $$ = new operation(0, 0, $1, $3, "=="); }
    | EXP tk_diferenteq EXP { $$ = new operation(0, 0, $1, $3, "!="); }
    | EXP tk_and EXP { $$ = new operation(0, 0, $1, $3, "&&"); }
    | EXP tk_or EXP { $$ = new operation(0, 0, $1, $3, "||"); }
    | EXP tk_not EXP { $$ = new operation(0, 0, $1, $3, "!"); }
    | tk_PARA EXP tk_PARC { $$ = $2; }
    | PRIMITIVE { $$ = $1; }
;

PRIMITIVE : NUMERO {  int num = stoi($1); $$ = new primitive(0,0,INTEGER, "",num,0.0,false); }
        | CADENA
        {
            std::string str1 = $1.erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            $$ = new primitive(0,0,STRING,str2,0,0.0, false);
        }
        | id   {$$ = new access(0,0,$1);}
        | DECIMAL   {float num = stof($1); $$ = new primitive(0,0,FLOAT, "",0,num,false);}
        | tk_true   { $$ = new primitive(0,0,BOOL,"",0,0.0,true); }
        | tk_false  { $$ = new primitive(0,0,BOOL,"",0,0.0,false); }
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

