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
    #include "../Expression/operation.hpp"
    #include "../Environment/type.h"
    #include "../Interfaces/expression.hpp"

    /* instrucciones */
    #include "../Interfaces/instruction.hpp"
    #include "../Instruction/print.hpp"
    #include "../Instruction/list_instruction.hpp"
    #include "../Instruction/func_main.hpp"

}

/* enlace con la función del retorno de simbolos */
%code { yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO id CADENA suma menos mult div PRINTF tk_void tk_int tk_string tk_float tk_bool tk_PARA tk_PARC rmain tk_LLAVA tk_LLAVC
%token ';' '='

/* precedencia de operadores */
%left suma menos
%left mult div

/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
%type<expression*> PRIMITIVE;
%type<expression*> EXP;
%type<func_main*> START;
%type<list_instruction*> LIST_INST;
%type<func_main*> MAIN;
%type<instruction*> INSTRUCTION;
%type<instruction*> PRINT;
%type<instruction*> DECLARAR;
%type<std::string> TYPES;

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

//PRUEBA : DECLARAR;


//START : MAIN
MAIN : TYPES rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
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
            | DECLARAR {$$=$1;}
;

DECLARAR: TYPES id '=' EXP ';' {std::cout<<"Declarando "<<$2<<std::endl;}
;

PRINT : PRINTF tk_PARA EXP tk_PARC { $$ = new print(0,0,$3); }
;

TYPES : tk_void { $$ = "void"; }
    | tk_int { $$ = "int"; }
    | tk_string { $$ = "string"; }
    | tk_float { $$ = "float"; }
    | tk_bool { $$ = "bool"; }
;

EXP : EXP suma EXP { $$ = new operation(0, 0, $1, $3, "+"); }
    | EXP menos EXP { $$ = new operation(0, 0, $1, $3, "-"); }
    | EXP mult EXP { $$ = new operation(0, 0, $1, $3, "*"); }
    | EXP div EXP { $$ = new operation(0, 0, $1, $3, "/"); }
    | tk_PARA EXP tk_PARC { $$ = $2; }
    | PRIMITIVE { $$ = $1; }
;

PRIMITIVE : NUMERO { $$ = new primitive(0,0,INTEGER, "", std::stod($1)); }
        | CADENA
        {
            std::string cadenita = $1.erase(0,1);
            $$ = new primitive(0,0,STRING, cadenita.erase(cadenita.length()-1,1), 0);
        }
;

%%

/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

