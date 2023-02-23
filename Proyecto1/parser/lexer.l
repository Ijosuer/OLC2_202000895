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

"+"     return Parser::symbol_type( token::suma, loc );
"-"     return Parser::symbol_type( token::menos, loc );
"*"     return Parser::symbol_type( token::mult, loc );
"/"     return Parser::symbol_type( token::div, loc );

    /* defincion clásica / para caracteres especiales */
";"     return Parser::symbol_type( token_type(';'), loc );
"="     return Parser::symbol_type( token_type('='), loc );


"("     return Parser::symbol_type( token::tk_PARA, loc );
")"     return Parser::symbol_type( token::tk_PARC, loc );
"{"     return Parser::symbol_type( token::tk_LLAVA, loc );
"}"     return Parser::symbol_type( token::tk_LLAVC, loc );


    /* TOKENS  */
"printf"    return Parser::symbol_type( token::PRINTF, loc );
"void"    return Parser::symbol_type( token::tk_void, loc );
"main"    return Parser::symbol_type( token::rmain, loc );
    /* datos prim  */
"int"    return Parser::symbol_type( token::tk_int, loc );
"string"    return Parser::symbol_type( token::tk_string, loc );
"float"    return Parser::symbol_type( token::tk_float, loc );
"bool"    return Parser::symbol_type( token::tk_bool, loc );

{ID}  return Parser::make_id(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_CADENA (yytext, loc);

.   {std::cerr<<loc <<": "<<"error token no esperado"<<  std::endl; }




%%
