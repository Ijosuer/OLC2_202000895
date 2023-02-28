/* se convierte con: flex --verbose lexer.l*/
/* opcciones para encapsulamiento */
/*%option outfile="lexer.cpp" */
/* %option header-file="lexer.hpp"*/

/*%option debug*/
%option reentrant noyywrap nounput batch noinput

%{
    #include <iostream>
 // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);
    // defincion de caracter EOF
    #define yyterminate() return Parser::make_END(loc)
    //se incrusta el parser
    #include "parser.hpp"


    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;
/// código adicinoal aquí

%}



/* ============== INICIO DE SCANNER ==========  */

/* TODO tokens */
DIGITO [0-9]
LETRAS [a-zA-ZñÑ]
NUMERO {DIGITO}+
ID  (["_"]+|{LETRAS})({DIGITO}|{LETRAS}|"_")*
DECIMAL ({NUMERO})"."({NUMERO})
%%

%{
// inicia la lectura
    loc.step();
%}


"//"[^\n]*\n            ; /* comentarios de una linea */

"/*""/"*([^*/]|[^*]"/"|"*"[^/])*"*"*"*/"; /* comentarios de multi linea */

[ \t\v\r\n\f]             ; /* caracteres en blanco */
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales
    */

"++"     return Parser::symbol_type( token::mas_mas, loc );
"--"     return Parser::symbol_type( token::menos_menos, loc );
"+"     return Parser::symbol_type( token::suma, loc );
"-"     return Parser::symbol_type( token::menos, loc );
"*"     return Parser::symbol_type( token::mult, loc );
"/"     return Parser::symbol_type( token::div, loc );

    /* defincion clásica / para caracteres especiales */
";"     return Parser::symbol_type( token_type(';'), loc );
"="     return Parser::symbol_type( token_type('='), loc );
","     return Parser::symbol_type( token_type(','), loc );
"."     return Parser::symbol_type( token_type('.'), loc );


"("     return Parser::symbol_type( token::tk_PARA, loc );
")"     return Parser::symbol_type( token::tk_PARC, loc );
"{"     return Parser::symbol_type( token::tk_LLAVA, loc );
"}"     return Parser::symbol_type( token::tk_LLAVC, loc );
"["     return Parser::symbol_type( token::tk_CORCHA, loc );
"]"     return Parser::symbol_type( token::tk_CORCHC, loc );

    /* operaciones de comparacion */
"=="     return Parser::symbol_type( token_type::tk_igualq, loc );
"!="     return Parser::symbol_type( token::tk_diferenteq, loc );
">="     return Parser::symbol_type( token::tk_mayor_igual, loc );
"<="     return Parser::symbol_type( token::tk_menor_igual, loc );
"<"     return Parser::symbol_type( token::tk_menorq, loc );
">"     return Parser::symbol_type( token::tk_mayorq, loc );

    /* operadores logicos */
"&&"     return Parser::symbol_type( token::tk_and, loc );
"||"     return Parser::symbol_type( token::tk_or, loc );
"!"     return Parser::symbol_type( token::tk_not, loc );

            /* Sentencias de control de flujo */
"if"    return Parser::symbol_type( token::res_IF, loc );
"else"    return Parser::symbol_type( token::res_ELSE, loc );

"while"    return Parser::symbol_type( token::res_WHILE, loc );
"for"    return Parser::symbol_type( token::res_FOR, loc );
"break"    return Parser::symbol_type( token::res_BREAK, loc );
"continue"    return Parser::symbol_type( token::res_CONTINUE, loc );
"return"    return Parser::symbol_type( token::res_RETURN, loc );

            /* Estructuras de datos */
"vector"    return Parser::symbol_type( token::res_VECTOR, loc );
"push_back"    return Parser::symbol_type( token::res_pushB, loc );
"push_front"    return Parser::symbol_type( token::res_pushF, loc );
"get"    return Parser::symbol_type( token::res_get, loc );
"remove"    return Parser::symbol_type( token::res_remove, loc );
"size"    return Parser::symbol_type( token::res_size, loc );

            /* Structs */
"struct"    return Parser::symbol_type( token::res_struct, loc );

            /* Funciones */
"mean"    return Parser::symbol_type( token::res_mean, loc );
"median"    return Parser::symbol_type( token::res_median, loc );
"mode"    return Parser::symbol_type( token::res_mode, loc );
"atoi"    return Parser::symbol_type( token::res_atoi, loc );
"atof"    return Parser::symbol_type( token::res_atof, loc );
"iota"    return Parser::symbol_type( token::res_iota, loc );


    /* TOKENS  */
"printf"    return Parser::symbol_type( token::PRINTF, loc );
"void"    return Parser::symbol_type( token::tk_void, loc );
"main"    return Parser::symbol_type( token::rmain, loc );
    /* datos prim  */
"int"    return Parser::symbol_type( token::tk_int, loc );
"string"    return Parser::symbol_type( token::tk_string, loc );
"float"    return Parser::symbol_type( token::tk_float, loc );
"bool"    return Parser::symbol_type( token::tk_bool, loc );
"true"    return Parser::symbol_type( token::tk_true, loc );
"false"    return Parser::symbol_type( token::tk_false, loc );

{ID}  return Parser::make_id(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
{DECIMAL} return Parser::make_DECIMAL(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_CADENA (yytext, loc);

.   {std::cerr<<loc <<": "<<"error token no esperado"<<  std::endl; }




%%
