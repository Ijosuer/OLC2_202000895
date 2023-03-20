// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 76 "parser.y"
 yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); 

#line 49 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 141 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class OCL2Calc::ParserCtx & ctx_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      ctx (ctx_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.YY_MOVE_OR_COPY< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.YY_MOVE_OR_COPY< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.YY_MOVE_OR_COPY< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_DECLARAR: // DECLARAR
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELIF: // ELIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONT: // CONT
      case symbol_kind::S_VECTOR: // VECTOR
      case symbol_kind::S_MATRIZ: // MATRIZ
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INCREMENTO: // INCREMENTO
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_LLAMADAF: // LLAMADAF
      case symbol_kind::S_RETORNO: // RETORNO
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.YY_MOVE_OR_COPY< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
        value.YY_MOVE_OR_COPY< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_id: // id
      case symbol_kind::S_CADENA: // CADENA
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_suma: // suma
      case symbol_kind::S_menos: // menos
      case symbol_kind::S_mult: // mult
      case symbol_kind::S_div: // div
      case symbol_kind::S_modulo: // modulo
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_tk_void: // tk_void
      case symbol_kind::S_tk_int: // tk_int
      case symbol_kind::S_tk_string: // tk_string
      case symbol_kind::S_tk_float: // tk_float
      case symbol_kind::S_tk_bool: // tk_bool
      case symbol_kind::S_tk_PARA: // tk_PARA
      case symbol_kind::S_tk_PARC: // tk_PARC
      case symbol_kind::S_rmain: // rmain
      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
      case symbol_kind::S_tk_true: // tk_true
      case symbol_kind::S_tk_false: // tk_false
      case symbol_kind::S_tk_igualq: // tk_igualq
      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
      case symbol_kind::S_tk_menorq: // tk_menorq
      case symbol_kind::S_tk_mayorq: // tk_mayorq
      case symbol_kind::S_tk_and: // tk_and
      case symbol_kind::S_tk_or: // tk_or
      case symbol_kind::S_tk_not: // tk_not
      case symbol_kind::S_res_IF: // res_IF
      case symbol_kind::S_res_ELSE: // res_ELSE
      case symbol_kind::S_res_WHILE: // res_WHILE
      case symbol_kind::S_res_FOR: // res_FOR
      case symbol_kind::S_res_BREAK: // res_BREAK
      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
      case symbol_kind::S_res_RETURN: // res_RETURN
      case symbol_kind::S_res_pushB: // res_pushB
      case symbol_kind::S_res_pushF: // res_pushF
      case symbol_kind::S_res_get: // res_get
      case symbol_kind::S_res_remove: // res_remove
      case symbol_kind::S_res_size: // res_size
      case symbol_kind::S_res_struct: // res_struct
      case symbol_kind::S_res_mean: // res_mean
      case symbol_kind::S_res_median: // res_median
      case symbol_kind::S_res_mode: // res_mode
      case symbol_kind::S_res_atoi: // res_atoi
      case symbol_kind::S_res_atof: // res_atof
      case symbol_kind::S_res_iota: // res_iota
      case symbol_kind::S_res_VECTOR: // res_VECTOR
      case symbol_kind::S_mas_mas: // mas_mas
      case symbol_kind::S_menos_menos: // menos_menos
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.move< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_DECLARAR: // DECLARAR
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELIF: // ELIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONT: // CONT
      case symbol_kind::S_VECTOR: // VECTOR
      case symbol_kind::S_MATRIZ: // MATRIZ
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INCREMENTO: // INCREMENTO
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_LLAMADAF: // LLAMADAF
      case symbol_kind::S_RETORNO: // RETORNO
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.move< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
        value.move< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_id: // id
      case symbol_kind::S_CADENA: // CADENA
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_suma: // suma
      case symbol_kind::S_menos: // menos
      case symbol_kind::S_mult: // mult
      case symbol_kind::S_div: // div
      case symbol_kind::S_modulo: // modulo
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_tk_void: // tk_void
      case symbol_kind::S_tk_int: // tk_int
      case symbol_kind::S_tk_string: // tk_string
      case symbol_kind::S_tk_float: // tk_float
      case symbol_kind::S_tk_bool: // tk_bool
      case symbol_kind::S_tk_PARA: // tk_PARA
      case symbol_kind::S_tk_PARC: // tk_PARC
      case symbol_kind::S_rmain: // rmain
      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
      case symbol_kind::S_tk_true: // tk_true
      case symbol_kind::S_tk_false: // tk_false
      case symbol_kind::S_tk_igualq: // tk_igualq
      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
      case symbol_kind::S_tk_menorq: // tk_menorq
      case symbol_kind::S_tk_mayorq: // tk_mayorq
      case symbol_kind::S_tk_and: // tk_and
      case symbol_kind::S_tk_or: // tk_or
      case symbol_kind::S_tk_not: // tk_not
      case symbol_kind::S_res_IF: // res_IF
      case symbol_kind::S_res_ELSE: // res_ELSE
      case symbol_kind::S_res_WHILE: // res_WHILE
      case symbol_kind::S_res_FOR: // res_FOR
      case symbol_kind::S_res_BREAK: // res_BREAK
      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
      case symbol_kind::S_res_RETURN: // res_RETURN
      case symbol_kind::S_res_pushB: // res_pushB
      case symbol_kind::S_res_pushF: // res_pushF
      case symbol_kind::S_res_get: // res_get
      case symbol_kind::S_res_remove: // res_remove
      case symbol_kind::S_res_size: // res_size
      case symbol_kind::S_res_struct: // res_struct
      case symbol_kind::S_res_mean: // res_mean
      case symbol_kind::S_res_median: // res_median
      case symbol_kind::S_res_mode: // res_mode
      case symbol_kind::S_res_atoi: // res_atoi
      case symbol_kind::S_res_atof: // res_atof
      case symbol_kind::S_res_iota: // res_iota
      case symbol_kind::S_res_VECTOR: // res_VECTOR
      case symbol_kind::S_mas_mas: // mas_mas
      case symbol_kind::S_menos_menos: // menos_menos
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.copy< TipoDato > (that.value);
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.copy< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.copy< func_main* > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_DECLARAR: // DECLARAR
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELIF: // ELIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONT: // CONT
      case symbol_kind::S_VECTOR: // VECTOR
      case symbol_kind::S_MATRIZ: // MATRIZ
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INCREMENTO: // INCREMENTO
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_LLAMADAF: // LLAMADAF
      case symbol_kind::S_RETORNO: // RETORNO
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.copy< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (that.value);
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
        value.copy< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_id: // id
      case symbol_kind::S_CADENA: // CADENA
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_suma: // suma
      case symbol_kind::S_menos: // menos
      case symbol_kind::S_mult: // mult
      case symbol_kind::S_div: // div
      case symbol_kind::S_modulo: // modulo
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_tk_void: // tk_void
      case symbol_kind::S_tk_int: // tk_int
      case symbol_kind::S_tk_string: // tk_string
      case symbol_kind::S_tk_float: // tk_float
      case symbol_kind::S_tk_bool: // tk_bool
      case symbol_kind::S_tk_PARA: // tk_PARA
      case symbol_kind::S_tk_PARC: // tk_PARC
      case symbol_kind::S_rmain: // rmain
      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
      case symbol_kind::S_tk_true: // tk_true
      case symbol_kind::S_tk_false: // tk_false
      case symbol_kind::S_tk_igualq: // tk_igualq
      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
      case symbol_kind::S_tk_menorq: // tk_menorq
      case symbol_kind::S_tk_mayorq: // tk_mayorq
      case symbol_kind::S_tk_and: // tk_and
      case symbol_kind::S_tk_or: // tk_or
      case symbol_kind::S_tk_not: // tk_not
      case symbol_kind::S_res_IF: // res_IF
      case symbol_kind::S_res_ELSE: // res_ELSE
      case symbol_kind::S_res_WHILE: // res_WHILE
      case symbol_kind::S_res_FOR: // res_FOR
      case symbol_kind::S_res_BREAK: // res_BREAK
      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
      case symbol_kind::S_res_RETURN: // res_RETURN
      case symbol_kind::S_res_pushB: // res_pushB
      case symbol_kind::S_res_pushF: // res_pushF
      case symbol_kind::S_res_get: // res_get
      case symbol_kind::S_res_remove: // res_remove
      case symbol_kind::S_res_size: // res_size
      case symbol_kind::S_res_struct: // res_struct
      case symbol_kind::S_res_mean: // res_mean
      case symbol_kind::S_res_median: // res_median
      case symbol_kind::S_res_mode: // res_mode
      case symbol_kind::S_res_atoi: // res_atoi
      case symbol_kind::S_res_atof: // res_atof
      case symbol_kind::S_res_iota: // res_iota
      case symbol_kind::S_res_VECTOR: // res_VECTOR
      case symbol_kind::S_mas_mas: // mas_mas
      case symbol_kind::S_menos_menos: // menos_menos
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (that.value);
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.move< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_DECLARAR: // DECLARAR
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELIF: // ELIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONT: // CONT
      case symbol_kind::S_VECTOR: // VECTOR
      case symbol_kind::S_MATRIZ: // MATRIZ
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INCREMENTO: // INCREMENTO
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_LLAMADAF: // LLAMADAF
      case symbol_kind::S_RETORNO: // RETORNO
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.move< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (that.value);
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
        value.move< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_id: // id
      case symbol_kind::S_CADENA: // CADENA
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_suma: // suma
      case symbol_kind::S_menos: // menos
      case symbol_kind::S_mult: // mult
      case symbol_kind::S_div: // div
      case symbol_kind::S_modulo: // modulo
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_tk_void: // tk_void
      case symbol_kind::S_tk_int: // tk_int
      case symbol_kind::S_tk_string: // tk_string
      case symbol_kind::S_tk_float: // tk_float
      case symbol_kind::S_tk_bool: // tk_bool
      case symbol_kind::S_tk_PARA: // tk_PARA
      case symbol_kind::S_tk_PARC: // tk_PARC
      case symbol_kind::S_rmain: // rmain
      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
      case symbol_kind::S_tk_true: // tk_true
      case symbol_kind::S_tk_false: // tk_false
      case symbol_kind::S_tk_igualq: // tk_igualq
      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
      case symbol_kind::S_tk_menorq: // tk_menorq
      case symbol_kind::S_tk_mayorq: // tk_mayorq
      case symbol_kind::S_tk_and: // tk_and
      case symbol_kind::S_tk_or: // tk_or
      case symbol_kind::S_tk_not: // tk_not
      case symbol_kind::S_res_IF: // res_IF
      case symbol_kind::S_res_ELSE: // res_ELSE
      case symbol_kind::S_res_WHILE: // res_WHILE
      case symbol_kind::S_res_FOR: // res_FOR
      case symbol_kind::S_res_BREAK: // res_BREAK
      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
      case symbol_kind::S_res_RETURN: // res_RETURN
      case symbol_kind::S_res_pushB: // res_pushB
      case symbol_kind::S_res_pushF: // res_pushF
      case symbol_kind::S_res_get: // res_get
      case symbol_kind::S_res_remove: // res_remove
      case symbol_kind::S_res_size: // res_size
      case symbol_kind::S_res_struct: // res_struct
      case symbol_kind::S_res_mean: // res_mean
      case symbol_kind::S_res_median: // res_median
      case symbol_kind::S_res_mode: // res_mode
      case symbol_kind::S_res_atoi: // res_atoi
      case symbol_kind::S_res_atof: // res_atof
      case symbol_kind::S_res_iota: // res_iota
      case symbol_kind::S_res_VECTOR: // res_VECTOR
      case symbol_kind::S_mas_mas: // mas_mas
      case symbol_kind::S_menos_menos: // menos_menos
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_NUMERO: // NUMERO
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 726 "parser.cpp"
        break;

      case symbol_kind::S_id: // id
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 732 "parser.cpp"
        break;

      case symbol_kind::S_CADENA: // CADENA
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 738 "parser.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 744 "parser.cpp"
        break;

      case symbol_kind::S_suma: // suma
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 750 "parser.cpp"
        break;

      case symbol_kind::S_menos: // menos
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 756 "parser.cpp"
        break;

      case symbol_kind::S_mult: // mult
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 762 "parser.cpp"
        break;

      case symbol_kind::S_div: // div
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 768 "parser.cpp"
        break;

      case symbol_kind::S_modulo: // modulo
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 774 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 780 "parser.cpp"
        break;

      case symbol_kind::S_tk_void: // tk_void
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 786 "parser.cpp"
        break;

      case symbol_kind::S_tk_int: // tk_int
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 792 "parser.cpp"
        break;

      case symbol_kind::S_tk_string: // tk_string
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 798 "parser.cpp"
        break;

      case symbol_kind::S_tk_float: // tk_float
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 804 "parser.cpp"
        break;

      case symbol_kind::S_tk_bool: // tk_bool
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 810 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARA: // tk_PARA
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 816 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARC: // tk_PARC
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 822 "parser.cpp"
        break;

      case symbol_kind::S_rmain: // rmain
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 828 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 834 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 840 "parser.cpp"
        break;

      case symbol_kind::S_tk_true: // tk_true
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 846 "parser.cpp"
        break;

      case symbol_kind::S_tk_false: // tk_false
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 852 "parser.cpp"
        break;

      case symbol_kind::S_tk_igualq: // tk_igualq
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 858 "parser.cpp"
        break;

      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 864 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 870 "parser.cpp"
        break;

      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 876 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 882 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 888 "parser.cpp"
        break;

      case symbol_kind::S_tk_menorq: // tk_menorq
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 894 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayorq: // tk_mayorq
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 900 "parser.cpp"
        break;

      case symbol_kind::S_tk_and: // tk_and
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 906 "parser.cpp"
        break;

      case symbol_kind::S_tk_or: // tk_or
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 912 "parser.cpp"
        break;

      case symbol_kind::S_tk_not: // tk_not
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 918 "parser.cpp"
        break;

      case symbol_kind::S_res_IF: // res_IF
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 924 "parser.cpp"
        break;

      case symbol_kind::S_res_ELSE: // res_ELSE
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 930 "parser.cpp"
        break;

      case symbol_kind::S_res_WHILE: // res_WHILE
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 936 "parser.cpp"
        break;

      case symbol_kind::S_res_FOR: // res_FOR
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 942 "parser.cpp"
        break;

      case symbol_kind::S_res_BREAK: // res_BREAK
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 948 "parser.cpp"
        break;

      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 954 "parser.cpp"
        break;

      case symbol_kind::S_res_RETURN: // res_RETURN
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 960 "parser.cpp"
        break;

      case symbol_kind::S_res_pushB: // res_pushB
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 966 "parser.cpp"
        break;

      case symbol_kind::S_res_pushF: // res_pushF
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 972 "parser.cpp"
        break;

      case symbol_kind::S_res_get: // res_get
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 978 "parser.cpp"
        break;

      case symbol_kind::S_res_remove: // res_remove
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 984 "parser.cpp"
        break;

      case symbol_kind::S_res_size: // res_size
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 990 "parser.cpp"
        break;

      case symbol_kind::S_res_struct: // res_struct
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 996 "parser.cpp"
        break;

      case symbol_kind::S_res_mean: // res_mean
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1002 "parser.cpp"
        break;

      case symbol_kind::S_res_median: // res_median
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1008 "parser.cpp"
        break;

      case symbol_kind::S_res_mode: // res_mode
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1014 "parser.cpp"
        break;

      case symbol_kind::S_res_atoi: // res_atoi
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1020 "parser.cpp"
        break;

      case symbol_kind::S_res_atof: // res_atof
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1026 "parser.cpp"
        break;

      case symbol_kind::S_res_iota: // res_iota
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1032 "parser.cpp"
        break;

      case symbol_kind::S_res_VECTOR: // res_VECTOR
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1038 "parser.cpp"
        break;

      case symbol_kind::S_mas_mas: // mas_mas
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1044 "parser.cpp"
        break;

      case symbol_kind::S_menos_menos: // menos_menos
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1050 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1056 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1062 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1068 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1074 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1080 "parser.cpp"
        break;

      case symbol_kind::S_DECLARAR: // DECLARAR
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1086 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1092 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1098 "parser.cpp"
        break;

      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1104 "parser.cpp"
        break;

      case symbol_kind::S_ELIF: // ELIF
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1110 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1116 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1122 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1128 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1134 "parser.cpp"
        break;

      case symbol_kind::S_CONT: // CONT
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1140 "parser.cpp"
        break;

      case symbol_kind::S_VECTOR: // VECTOR
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1146 "parser.cpp"
        break;

      case symbol_kind::S_MATRIZ: // MATRIZ
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1152 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1158 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENTO: // INCREMENTO
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1164 "parser.cpp"
        break;

      case symbol_kind::S_FUNC: // FUNC
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1170 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1176 "parser.cpp"
        break;

      case symbol_kind::S_LLAMADAF: // LLAMADAF
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1182 "parser.cpp"
        break;

      case symbol_kind::S_RETORNO: // RETORNO
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1188 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1194 "parser.cpp"
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1200 "parser.cpp"
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1206 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1212 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1218 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 139 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1224 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, loc, ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TYPES: // TYPES
        yylhs.value.emplace< TipoDato > ();
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        yylhs.value.emplace< expression* > ();
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        yylhs.value.emplace< func_main* > ();
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_DECLARAR: // DECLARAR
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELIF: // ELIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONT: // CONT
      case symbol_kind::S_VECTOR: // VECTOR
      case symbol_kind::S_MATRIZ: // MATRIZ
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_INCREMENTO: // INCREMENTO
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_LLAMADAF: // LLAMADAF
      case symbol_kind::S_RETORNO: // RETORNO
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        yylhs.value.emplace< list_expression* > ();
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< list_instruction* > ();
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
        yylhs.value.emplace< map_struct_dec* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_id: // id
      case symbol_kind::S_CADENA: // CADENA
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_suma: // suma
      case symbol_kind::S_menos: // menos
      case symbol_kind::S_mult: // mult
      case symbol_kind::S_div: // div
      case symbol_kind::S_modulo: // modulo
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_tk_void: // tk_void
      case symbol_kind::S_tk_int: // tk_int
      case symbol_kind::S_tk_string: // tk_string
      case symbol_kind::S_tk_float: // tk_float
      case symbol_kind::S_tk_bool: // tk_bool
      case symbol_kind::S_tk_PARA: // tk_PARA
      case symbol_kind::S_tk_PARC: // tk_PARC
      case symbol_kind::S_rmain: // rmain
      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
      case symbol_kind::S_tk_true: // tk_true
      case symbol_kind::S_tk_false: // tk_false
      case symbol_kind::S_tk_igualq: // tk_igualq
      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
      case symbol_kind::S_tk_menorq: // tk_menorq
      case symbol_kind::S_tk_mayorq: // tk_mayorq
      case symbol_kind::S_tk_and: // tk_and
      case symbol_kind::S_tk_or: // tk_or
      case symbol_kind::S_tk_not: // tk_not
      case symbol_kind::S_res_IF: // res_IF
      case symbol_kind::S_res_ELSE: // res_ELSE
      case symbol_kind::S_res_WHILE: // res_WHILE
      case symbol_kind::S_res_FOR: // res_FOR
      case symbol_kind::S_res_BREAK: // res_BREAK
      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
      case symbol_kind::S_res_RETURN: // res_RETURN
      case symbol_kind::S_res_pushB: // res_pushB
      case symbol_kind::S_res_pushF: // res_pushF
      case symbol_kind::S_res_get: // res_get
      case symbol_kind::S_res_remove: // res_remove
      case symbol_kind::S_res_size: // res_size
      case symbol_kind::S_res_struct: // res_struct
      case symbol_kind::S_res_mean: // res_mean
      case symbol_kind::S_res_median: // res_median
      case symbol_kind::S_res_mode: // res_mode
      case symbol_kind::S_res_atoi: // res_atoi
      case symbol_kind::S_res_atof: // res_atof
      case symbol_kind::S_res_iota: // res_iota
      case symbol_kind::S_res_VECTOR: // res_VECTOR
      case symbol_kind::S_mas_mas: // mas_mas
      case symbol_kind::S_menos_menos: // menos_menos
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // START: MAIN
#line 147 "parser.y"
    {
      ctx.Main = yystack_[0].value.as < func_main* > ();
      ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
      yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1590 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 154 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1601 "parser.cpp"
    break;

  case 4: // LIST_FUNC: LIST_FUNC FUNC
#line 162 "parser.y"
            {
                yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > ();
            }
#line 1610 "parser.cpp"
    break;

  case 5: // LIST_FUNC: FUNC
#line 167 "parser.y"
         {
            yylhs.value.as < list_instruction* > ()= new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
         }
#line 1619 "parser.cpp"
    break;

  case 6: // MAIN: tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 176 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(yystack_[6].location.begin.line,yystack_[6].location.begin.column, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
    
}
#line 1628 "parser.cpp"
    break;

  case 7: // LIST_INST: LIST_INST INSTRUCTION
#line 183 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1637 "parser.cpp"
    break;

  case 8: // LIST_INST: INSTRUCTION
#line 188 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1646 "parser.cpp"
    break;

  case 9: // INSTRUCTION: PRINT ';'
#line 194 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1652 "parser.cpp"
    break;

  case 10: // INSTRUCTION: DECLARAR ';'
#line 195 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1658 "parser.cpp"
    break;

  case 11: // INSTRUCTION: ASIGNAR ';'
#line 196 "parser.y"
                          {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1664 "parser.cpp"
    break;

  case 12: // INSTRUCTION: VECTOR ';'
#line 197 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1670 "parser.cpp"
    break;

  case 13: // INSTRUCTION: MATRIZ ';'
#line 198 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1676 "parser.cpp"
    break;

  case 14: // INSTRUCTION: BREAK ';'
#line 199 "parser.y"
                        {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1682 "parser.cpp"
    break;

  case 15: // INSTRUCTION: CONT ';'
#line 200 "parser.y"
                       {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1688 "parser.cpp"
    break;

  case 16: // INSTRUCTION: RETORNO ';'
#line 201 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1694 "parser.cpp"
    break;

  case 17: // INSTRUCTION: INCREMENTO ';'
#line 202 "parser.y"
                             {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1700 "parser.cpp"
    break;

  case 18: // INSTRUCTION: LLAMADAF ';'
#line 203 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1706 "parser.cpp"
    break;

  case 19: // INSTRUCTION: WHILE
#line 205 "parser.y"
                     {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1712 "parser.cpp"
    break;

  case 20: // INSTRUCTION: FOR
#line 206 "parser.y"
                   {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1718 "parser.cpp"
    break;

  case 21: // INSTRUCTION: IF
#line 207 "parser.y"
                  {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1724 "parser.cpp"
    break;

  case 22: // INSTRUCTION: error ';'
#line 208 "parser.y"
                       {}
#line 1730 "parser.cpp"
    break;

  case 23: // DECLARAR: TYPES id
#line 211 "parser.y"
                    {std::cout<<"Declarando "<<yystack_[0].value.as < std::string > ()<<std::endl; 
                            yylhs.value.as < instruction* > () = new declaracion(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),new primitive(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),"",0,0.0,0));
                    }
#line 1738 "parser.cpp"
    break;

  case 24: // DECLARAR: TYPES id '=' EXP
#line 214 "parser.y"
                           {std::cout<<"Declarando con valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;
                            yylhs.value.as < instruction* > () = new declaracion(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());
                            }
#line 1746 "parser.cpp"
    break;

  case 25: // ASIGNAR: id '=' EXP
#line 218 "parser.y"
                     {yylhs.value.as < instruction* > () = new asignacion(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > (), nullptr);}
#line 1752 "parser.cpp"
    break;

  case 26: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELIF_LIST ELSE
#line 223 "parser.y"
                                                                            {yylhs.value.as < instruction* > () = new func_if(yystack_[8].location.begin.line,yystack_[8].location.begin.column,yystack_[6].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());}
#line 1758 "parser.cpp"
    break;

  case 27: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELSE
#line 224 "parser.y"
                                                                  {yylhs.value.as < instruction* > () = new func_if(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[5].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());}
#line 1764 "parser.cpp"
    break;

  case 28: // ELIF_LIST: ELIF_LIST ELIF
#line 227 "parser.y"
                          { yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1770 "parser.cpp"
    break;

  case 29: // ELIF_LIST: ELIF
#line 228 "parser.y"
                          { yylhs.value.as < list_instruction* > ()=new list_instruction(); yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); }
#line 1776 "parser.cpp"
    break;

  case 30: // ELIF: res_ELSE res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 232 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1784 "parser.cpp"
    break;

  case 31: // ELSE: res_ELSE tk_LLAVA LIST_INST tk_LLAVC
#line 237 "parser.y"
                                           { yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1790 "parser.cpp"
    break;

  case 32: // ELSE: %empty
#line 238 "parser.y"
             {}
#line 1796 "parser.cpp"
    break;

  case 33: // WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 242 "parser.y"
                                                                 {yylhs.value.as < instruction* > () = new func_while(yystack_[6].location.begin.line,yystack_[6].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1802 "parser.cpp"
    break;

  case 34: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' ASIGNAR tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 246 "parser.y"
                                                                                       {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line,yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < instruction* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1808 "parser.cpp"
    break;

  case 35: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 247 "parser.y"
                                                                                          {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line,yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < instruction* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1814 "parser.cpp"
    break;

  case 36: // BREAK: res_BREAK
#line 251 "parser.y"
                 {std::cout<<"Break"<<std::endl;}
#line 1820 "parser.cpp"
    break;

  case 37: // CONT: res_CONTINUE
#line 253 "parser.y"
                   {std::cout<<"continue"<<std::endl;}
#line 1826 "parser.cpp"
    break;

  case 38: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 257 "parser.y"
                                                                                 {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[6].value.as < TipoDato > (),yystack_[4].value.as < std::string > (),new array_exp(0,0,yystack_[6].value.as < TipoDato > (),yystack_[1].value.as < list_expression* > ()));}
#line 1832 "parser.cpp"
    break;

  case 39: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id
#line 258 "parser.y"
                                                {std::cout<<"VECTOR empty "<<std::endl;}
#line 1838 "parser.cpp"
    break;

  case 40: // VECTOR: id '.' res_pushF tk_PARA EXP tk_PARC
#line 259 "parser.y"
                                             {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"push_front",nullptr);}
#line 1844 "parser.cpp"
    break;

  case 41: // VECTOR: id '.' res_pushB tk_PARA EXP tk_PARC
#line 260 "parser.y"
                                             {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"push_back",nullptr);}
#line 1850 "parser.cpp"
    break;

  case 42: // VECTOR: id '.' res_remove tk_PARA EXP tk_PARC
#line 261 "parser.y"
                                              {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"remove",nullptr);}
#line 1856 "parser.cpp"
    break;

  case 43: // VECTOR: id tk_CORCHA EXP tk_CORCHC '=' id tk_CORCHA EXP tk_CORCHC
#line 263 "parser.y"
        {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[8].value.as < std::string > ()),yystack_[6].value.as < expression* > (),"asignar",new array_access(0,0,new access(0,0,yystack_[3].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"get"));}
#line 1862 "parser.cpp"
    break;

  case 44: // VECTOR: id tk_CORCHA EXP tk_CORCHC '=' EXP
#line 264 "parser.y"
                                            {std::cout<<"[][]"<<std::endl; yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[3].value.as < expression* > (),"asignar",yystack_[0].value.as < expression* > ());}
#line 1868 "parser.cpp"
    break;

  case 45: // MATRIZ: TYPES id tk_CORCHA EXP tk_CORCHC '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 267 "parser.y"
                                                                          {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[8].value.as < TipoDato > (),yystack_[7].value.as < std::string > (),new matriz_exp(0,0,yystack_[1].value.as < list_expression* > ()));}
#line 1874 "parser.cpp"
    break;

  case 46: // MATRIZ: TYPES id tk_CORCHA EXP tk_CORCHC tk_CORCHA EXP tk_CORCHC '=' EXP
#line 269 "parser.y"
                                                {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[9].value.as < TipoDato > (),yystack_[8].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1880 "parser.cpp"
    break;

  case 47: // PRINT: PRINTF tk_PARA LISTAEXP tk_PARC
#line 273 "parser.y"
                                        { yylhs.value.as < instruction* > () = new print(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 1886 "parser.cpp"
    break;

  case 48: // INCREMENTO: id mas_mas
#line 276 "parser.y"
                        {yylhs.value.as < instruction* > () = new incremento(0,0,yystack_[1].value.as < std::string > (),"++");}
#line 1892 "parser.cpp"
    break;

  case 49: // INCREMENTO: id menos_menos
#line 277 "parser.y"
                             {yylhs.value.as < instruction* > () = new incremento(0,0,yystack_[1].value.as < std::string > (),"--");}
#line 1898 "parser.cpp"
    break;

  case 50: // FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 280 "parser.y"
                                                                     {yylhs.value.as < instruction* > ()=new function(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1904 "parser.cpp"
    break;

  case 51: // FUNC: TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 281 "parser.y"
                                                           {yylhs.value.as < instruction* > ()=new function(yystack_[6].location.begin.line,yystack_[6].location.begin.column,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());}
#line 1910 "parser.cpp"
    break;

  case 52: // CALL_EXP: id tk_PARA LISTAEXP tk_PARC
#line 284 "parser.y"
                                       { yylhs.value.as < expression* > () = new call_exp(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 1916 "parser.cpp"
    break;

  case 53: // CALL_EXP: id tk_PARA tk_PARC
#line 285 "parser.y"
                            { yylhs.value.as < expression* > () = new call_exp(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),nullptr); }
#line 1922 "parser.cpp"
    break;

  case 54: // LLAMADAF: id tk_PARA LISTAEXP tk_PARC
#line 288 "parser.y"
                                      {yylhs.value.as < instruction* > ()= new call_inst(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());}
#line 1928 "parser.cpp"
    break;

  case 55: // LLAMADAF: id tk_PARA tk_PARC
#line 289 "parser.y"
                             {yylhs.value.as < instruction* > ()= new call_inst(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),nullptr);}
#line 1934 "parser.cpp"
    break;

  case 56: // RETORNO: res_RETURN EXP
#line 292 "parser.y"
                        {yylhs.value.as < instruction* > ()= new inst_return(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[0].value.as < expression* > ());}
#line 1940 "parser.cpp"
    break;

  case 57: // RETORNO: res_RETURN
#line 293 "parser.y"
                      {yylhs.value.as < instruction* > ()= new inst_return(yystack_[0].location.begin.line,yystack_[0].location.begin.column,nullptr);}
#line 1946 "parser.cpp"
    break;

  case 58: // TYPES: tk_int
#line 316 "parser.y"
              { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1952 "parser.cpp"
    break;

  case 59: // TYPES: tk_string
#line 317 "parser.y"
                { yylhs.value.as < TipoDato > () = STRING; }
#line 1958 "parser.cpp"
    break;

  case 60: // TYPES: tk_float
#line 318 "parser.y"
               { yylhs.value.as < TipoDato > () = FLOAT; }
#line 1964 "parser.cpp"
    break;

  case 61: // TYPES: tk_bool
#line 319 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1970 "parser.cpp"
    break;

  case 62: // TYPES: tk_void
#line 320 "parser.y"
             { yylhs.value.as < TipoDato > () = NULO; }
#line 1976 "parser.cpp"
    break;

  case 63: // LISTAEXP: LISTAEXP ',' EXP
#line 323 "parser.y"
       {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1985 "parser.cpp"
    break;

  case 64: // LISTAEXP: EXP
#line 328 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1994 "parser.cpp"
    break;

  case 65: // LISTPARAM: LISTPARAM ',' TYPES id
#line 335 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > ()=yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2003 "parser.cpp"
    break;

  case 66: // LISTPARAM: TYPES id
#line 340 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
        }
#line 2012 "parser.cpp"
    break;

  case 67: // EXP: EXP suma EXP
#line 346 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+");}
#line 2018 "parser.cpp"
    break;

  case 68: // EXP: EXP menos EXP
#line 347 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 2024 "parser.cpp"
    break;

  case 69: // EXP: EXP mult EXP
#line 348 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 2030 "parser.cpp"
    break;

  case 70: // EXP: EXP div EXP
#line 349 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 2036 "parser.cpp"
    break;

  case 71: // EXP: EXP modulo EXP
#line 350 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 2042 "parser.cpp"
    break;

  case 72: // EXP: tk_PARA EXP tk_PARC
#line 351 "parser.y"
                          { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2048 "parser.cpp"
    break;

  case 73: // EXP: EXP tk_menor_igual EXP
#line 352 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 2054 "parser.cpp"
    break;

  case 74: // EXP: EXP tk_menorq EXP
#line 353 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 2060 "parser.cpp"
    break;

  case 75: // EXP: EXP tk_mayor_igual EXP
#line 354 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 2066 "parser.cpp"
    break;

  case 76: // EXP: EXP tk_mayorq EXP
#line 355 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 2072 "parser.cpp"
    break;

  case 77: // EXP: EXP tk_igualq EXP
#line 356 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 2078 "parser.cpp"
    break;

  case 78: // EXP: EXP tk_diferenteq EXP
#line 357 "parser.y"
                            { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 2084 "parser.cpp"
    break;

  case 79: // EXP: EXP tk_and EXP
#line 358 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 2090 "parser.cpp"
    break;

  case 80: // EXP: EXP tk_or EXP
#line 359 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 2096 "parser.cpp"
    break;

  case 81: // EXP: res_atof tk_PARA EXP tk_PARC
#line 360 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "atof");}
#line 2102 "parser.cpp"
    break;

  case 82: // EXP: res_atoi tk_PARA EXP tk_PARC
#line 361 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "atoi");}
#line 2108 "parser.cpp"
    break;

  case 83: // EXP: res_iota tk_PARA EXP tk_PARC
#line 362 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "iota");}
#line 2114 "parser.cpp"
    break;

  case 84: // EXP: tk_not EXP
#line 363 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line,yystack_[1].location.begin.column, yystack_[0].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"); }
#line 2120 "parser.cpp"
    break;

  case 85: // EXP: tk_LLAVA LISTAEXP tk_LLAVC
#line 364 "parser.y"
                                 { yylhs.value.as < expression* > () = new matriz_exp(0,0,yystack_[1].value.as < list_expression* > ()); }
#line 2126 "parser.cpp"
    break;

  case 86: // EXP: id '.' res_size tk_PARA tk_PARC
#line 366 "parser.y"
                                       {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[4].value.as < std::string > ()),nullptr,"size");}
#line 2132 "parser.cpp"
    break;

  case 87: // EXP: id '.' res_get tk_PARA EXP tk_PARC
#line 367 "parser.y"
                                         {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"get");}
#line 2138 "parser.cpp"
    break;

  case 88: // EXP: PRIMITIVE
#line 370 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2144 "parser.cpp"
    break;

  case 89: // EXP: CALL_EXP
#line 371 "parser.y"
      { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2150 "parser.cpp"
    break;

  case 90: // PRIMITIVE: NUMERO
#line 376 "parser.y"
                   {  int num = stoi(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,INTEGER, "",num,0.0,false);}
#line 2156 "parser.cpp"
    break;

  case 91: // PRIMITIVE: CADENA
#line 378 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,STRING,str2,0,0.0, false);
        }
#line 2166 "parser.cpp"
    break;

  case 92: // PRIMITIVE: id
#line 383 "parser.y"
               {yylhs.value.as < expression* > () = new access(yystack_[0].location.begin.line,yystack_[0].location.begin.column,yystack_[0].value.as < std::string > ());}
#line 2172 "parser.cpp"
    break;

  case 93: // PRIMITIVE: DECIMAL
#line 384 "parser.y"
                    {float num = stof(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,FLOAT, "",0,num,false);}
#line 2178 "parser.cpp"
    break;

  case 94: // PRIMITIVE: tk_true
#line 385 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,BOOL,"",0,0.0,true); }
#line 2184 "parser.cpp"
    break;

  case 95: // PRIMITIVE: tk_false
#line 386 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,BOOL,"",0,0.0,false); }
#line 2190 "parser.cpp"
    break;

  case 96: // PRIMITIVE: res_mean tk_PARA id tk_PARC
#line 387 "parser.y"
                                      {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr,"mean");}
#line 2196 "parser.cpp"
    break;

  case 97: // PRIMITIVE: res_median tk_PARA id tk_PARC
#line 388 "parser.y"
                                        {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr,"median");}
#line 2202 "parser.cpp"
    break;

  case 98: // PRIMITIVE: res_mode tk_PARA id tk_PARC
#line 389 "parser.y"
                                      {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr,"moda");}
#line 2208 "parser.cpp"
    break;

  case 99: // PRIMITIVE: LIST_ARR
#line 390 "parser.y"
                   {yylhs.value.as < expression* > ()=yystack_[0].value.as < expression* > ();}
#line 2214 "parser.cpp"
    break;

  case 100: // LIST_ARR: LIST_ARR tk_CORCHA EXP tk_CORCHC
#line 393 "parser.y"
                                            { yylhs.value.as < expression* > () = new array_access(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > (),""); }
#line 2220 "parser.cpp"
    break;

  case 101: // LIST_ARR: id
#line 395 "parser.y"
             {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ()); }
#line 2226 "parser.cpp"
    break;


#line 2230 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -58;

  const signed char Parser::yytable_ninf_ = -102;

  const short
  Parser::yypact_[] =
  {
      78,   -10,   -58,   -58,   -58,   -58,     5,    78,   -58,   -58,
       0,     3,   -58,   -58,   -58,    12,    20,    71,    29,   -58,
      51,    58,   -11,   442,   442,   -58,    53,   123,    39,    14,
      15,    80,    81,    99,   -58,   -58,   526,    45,    41,   -58,
      69,    70,   -58,   -58,   -58,    83,    85,    86,    91,    92,
      94,   101,   102,   125,   141,   442,   157,   -58,   467,   526,
     -58,   -58,   526,   -18,   526,   526,   526,   123,   -58,   -15,
     -58,   -58,   526,   526,   -58,   -58,   526,   147,   148,   154,
     155,   158,   160,   -58,   960,   -58,   161,   123,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
      -7,   -58,   225,   -58,   -58,    -1,   960,   177,   960,   171,
     173,   175,     1,   606,   634,   139,   191,   489,   -32,   662,
     -16,   970,   194,   195,   196,   526,   526,   526,   526,   526,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     526,   526,   169,   526,   526,   -58,   -58,   526,   159,   526,
     526,   526,   -58,   185,   192,   526,   165,   -58,     4,   199,
     201,   -58,   -58,   208,   209,   217,   690,   718,   746,   137,
     137,   216,   216,   216,   619,   619,   960,   124,   124,   124,
     970,   223,   759,   240,   787,   960,   960,   548,   797,   825,
     853,   442,   442,   578,   -58,   526,   226,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   187,     7,     6,   960,   -58,   -58,
     -58,   256,   287,   248,   881,   -58,   224,   526,   229,   526,
     222,   -58,    64,   243,   255,   -58,   526,   894,   526,   922,
      -9,   222,   -58,   -58,   254,   258,     8,   218,    18,   -58,
     442,   263,   -58,   -58,   442,   442,   -58,   526,   -58,   318,
     526,   349,   380,   960,   -58,   932,   -58,   -58,   261,   442,
     411,   -58
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    62,    58,    59,    60,    61,     0,     0,     2,     5,
       0,     0,     1,     3,     4,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    57,     0,     0,     8,
       0,     0,    21,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
      48,    49,     0,     0,     0,     0,     0,     0,    90,    92,
      91,    93,     0,     0,    94,    95,     0,     0,     0,     0,
       0,     0,     0,    89,    56,    88,    99,     0,     6,     7,
      10,    11,    14,    15,    12,    13,     9,    17,    18,    16,
      23,    51,     0,    65,    55,     0,    64,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    54,     0,     0,     0,
       0,     0,    47,     0,     0,     0,    23,    53,     0,     0,
       0,    72,    85,     0,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,    77,    78,    75,    73,    74,    76,
      79,    80,     0,     0,     0,    24,    63,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,    96,    97,    98,
      82,    81,    83,   100,    39,     0,    92,    44,    41,    40,
      42,     0,     0,     0,     0,    86,     0,     0,     0,     0,
      32,    33,     0,     0,     0,    87,     0,     0,     0,     0,
       0,    32,    29,    27,     0,     0,     0,     0,     0,    43,
       0,     0,    28,    26,     0,     0,    38,     0,    45,     0,
       0,     0,     0,    46,    31,     0,    34,    35,     0,     0,
       0,    30
  };

  const short
  Parser::yypgoto_[] =
  {
     -58,   -58,   -58,   269,   -24,   -37,   219,    72,   -58,   -58,
      52,    56,   -58,   -58,   -58,   -58,   -58,   -58,   -58,    76,
     277,   -58,   -58,   -58,     2,   -57,   -58,   -25,   -58,   -58
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     6,     7,     8,    38,    39,    40,    41,    42,   231,
     232,   233,    43,    44,    45,    46,    47,    48,    49,    50,
       9,    83,    51,    52,    53,   105,    22,   106,    85,    86
  };

  const short
  Parser::yytable_[] =
  {
      54,    89,    10,   117,    15,    12,   162,   112,    26,    10,
      11,    84,   240,   159,  -101,   160,   120,    89,   146,    21,
     152,    16,   143,   194,   117,   109,   110,   241,   111,    56,
      17,   102,    58,    64,   107,   219,   217,   108,   246,    18,
     113,   114,    28,    59,   147,    29,   118,   119,   248,    27,
      23,   121,   144,    30,    19,     2,     3,     4,     5,   147,
     158,   147,    25,    88,   147,    89,   218,   118,   147,   116,
      60,    61,    24,    62,    55,    63,    87,    31,   147,    32,
      33,    34,    35,    36,    19,     2,     3,     4,     5,   142,
      20,     1,     2,     3,     4,     5,    37,    57,    65,    66,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    67,   184,   185,
      60,    61,   186,    62,   188,   189,   190,    90,    91,   100,
     193,   128,   129,   130,   131,   132,    19,     2,     3,     4,
       5,    92,    28,    93,    94,    29,   130,   131,   132,    95,
      96,   135,    97,    30,    19,     2,     3,     4,     5,    98,
      99,   103,   207,   101,   135,   122,   123,   211,   212,   236,
     214,   238,   124,   125,    89,    89,   126,    31,   127,    32,
      33,    34,    35,    36,   128,   129,   130,   131,   132,   149,
     141,   150,   227,   151,   229,   156,    37,   155,   163,   164,
     165,   183,   133,   134,   135,   136,   191,   148,   137,   138,
     139,   140,    89,   192,    89,    89,   249,   195,   187,   196,
     251,   252,   253,    89,   144,   255,    28,   197,   198,    29,
     128,   129,   130,   131,   132,   260,   199,    30,    19,     2,
       3,     4,     5,   135,   204,   215,   216,   145,   133,   134,
     135,   136,   222,   226,   137,   138,   139,    28,   228,   230,
      29,    31,   234,    32,    33,    34,    35,    36,    30,    19,
       2,     3,     4,     5,   235,   244,    13,   247,   220,   245,
      37,   250,   259,   242,    14,   223,   115,   243,    28,   224,
       0,    29,    31,     0,    32,    33,    34,    35,    36,    30,
      19,     2,     3,     4,     5,     0,     0,     0,     0,   221,
       0,    37,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,    29,    31,     0,    32,    33,    34,    35,    36,
      30,    19,     2,     3,     4,     5,     0,     0,     0,     0,
     254,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,    29,    31,     0,    32,    33,    34,    35,
      36,    30,    19,     2,     3,     4,     5,     0,     0,     0,
       0,   256,     0,    37,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    29,    31,     0,    32,    33,    34,
      35,    36,    30,    19,     2,     3,     4,     5,     0,     0,
       0,     0,   257,     0,    37,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,    29,    31,     0,    32,    33,
      34,    35,    36,    30,    19,     2,     3,     4,     5,     0,
       0,     0,     0,   261,     0,    37,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,    29,    31,     0,    32,
      33,    34,    35,    36,    30,    19,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
      68,    69,    70,    71,     0,     0,     0,     0,    31,     0,
      32,    33,    34,    35,    36,    72,   104,     0,    73,     0,
      74,    75,    68,    69,    70,    71,     0,    37,     0,     0,
       0,     0,    76,     0,     0,     0,     0,    72,   157,     0,
      73,     0,    74,    75,     0,     0,    77,    78,    79,    80,
      81,    82,     0,     0,    76,     0,     0,     0,     0,    68,
      69,    70,    71,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    72,     0,     0,    73,     0,    74,
      75,    68,   206,    70,    71,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    72,     0,     0,    73,
       0,    74,    75,     0,     0,    77,    78,    79,    80,    81,
      82,     0,     0,    76,     0,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,   133,   134,   135,   136,     0,     0,   137,
     138,   139,   140,   128,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,   153,   128,   129,   130,   131,
     132,   133,   134,   135,   136,     0,   213,   137,   138,   139,
     140,   128,   129,   130,   131,   132,   135,   136,     0,     0,
     137,   138,     0,   154,     0,     0,     0,     0,     0,   133,
     134,   135,   136,     0,     0,   137,   138,   139,   140,   128,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,   133,   134,   135,
     136,     0,     0,   137,   138,   139,   140,   128,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,     0,     0,   133,   134,   135,   136,     0,
       0,   137,   138,   139,   140,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,   201,     0,     0,
       0,     0,     0,   133,   134,   135,   136,     0,     0,   137,
     138,   139,   140,   128,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,   202,   128,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,   137,   138,   139,
     140,     0,     0,     0,   133,   134,   135,   136,     0,   203,
     137,   138,   139,   140,   128,   129,   130,   131,   132,     0,
       0,     0,     0,     0,   128,   129,   130,   131,   132,     0,
       0,     0,   133,   134,   135,   136,   208,   205,   137,   138,
     139,   140,   133,   134,   135,   136,     0,     0,   137,   138,
     139,   140,   128,   129,   130,   131,   132,     0,     0,     0,
       0,     0,     0,     0,   209,     0,     0,     0,     0,     0,
     133,   134,   135,   136,     0,     0,   137,   138,   139,   140,
     128,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,     0,     0,   133,   134,
     135,   136,     0,     0,   137,   138,   139,   140,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,     0,     0,
     225,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,   137,   138,   139,   140,     0,     0,     0,   133,
     134,   135,   136,     0,   237,   137,   138,   139,   140,   128,
     129,   130,   131,   132,     0,     0,     0,     0,     0,   128,
     129,   130,   131,   132,     0,     0,     0,   133,   134,   135,
     136,   258,   239,   137,   138,   139,   140,   133,   134,   135,
     136,     0,     0,   137,   138,   139,   140,   128,   129,   130,
     131,   132,     0,     0,     0,     0,     0,   128,   129,   130,
     131,   132,     0,     0,     0,   133,   134,   135,   136,     0,
       0,   137,   138,   139,   140,   133,   134,   135,   136,     0,
       0,   137,   138
  };

  const short
  Parser::yycheck_[] =
  {
      24,    38,     0,    18,     4,     0,    22,    64,    19,     7,
      20,    36,    21,    45,    29,    47,    73,    54,    19,    17,
      19,    18,    29,    19,    18,    43,    44,    36,    46,    27,
      18,    55,    18,    18,    59,    29,    29,    62,    30,    19,
      65,    66,     1,    29,    60,     4,    61,    72,    30,    60,
      21,    76,    59,    12,    13,    14,    15,    16,    17,    60,
     117,    60,     4,    22,    60,   102,    59,    61,    60,    67,
      56,    57,    21,    59,    21,    61,    31,    36,    60,    38,
      39,    40,    41,    42,    13,    14,    15,    16,    17,    87,
      19,    13,    14,    15,    16,    17,    55,    58,    18,    18,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    18,   143,   144,
      56,    57,   147,    59,   149,   150,   151,    58,    58,     4,
     155,     7,     8,     9,    10,    11,    13,    14,    15,    16,
      17,    58,     1,    58,    58,     4,     9,    10,    11,    58,
      58,    27,    58,    12,    13,    14,    15,    16,    17,    58,
      58,     4,   187,    22,    27,    18,    18,   191,   192,   226,
     195,   228,    18,    18,   211,   212,    18,    36,    18,    38,
      39,    40,    41,    42,     7,     8,     9,    10,    11,    18,
      29,    18,   217,    18,   219,     4,    55,    58,     4,     4,
       4,    32,    25,    26,    27,    28,    21,    30,    31,    32,
      33,    34,   249,    21,   251,   252,   240,    18,    59,    18,
     244,   245,   247,   260,    59,   250,     1,    19,    19,     4,
       7,     8,     9,    10,    11,   259,    19,    12,    13,    14,
      15,    16,    17,    27,     4,    19,    59,    22,    25,    26,
      27,    28,     4,    29,    31,    32,    33,     1,    29,    37,
       4,    36,    19,    38,    39,    40,    41,    42,    12,    13,
      14,    15,    16,    17,    19,    21,     7,    59,    22,    21,
      55,    18,    21,   231,     7,   213,    67,   231,     1,   213,
      -1,     4,    36,    -1,    38,    39,    40,    41,    42,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,     4,    36,    -1,    38,    39,    40,    41,    42,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,     4,    36,    -1,    38,    39,    40,    41,
      42,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,     4,    36,    -1,    38,    39,    40,
      41,    42,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,     4,    36,    -1,    38,    39,
      40,    41,    42,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,     4,    36,    -1,    38,
      39,    40,    41,    42,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    18,    19,    -1,    21,    -1,
      23,    24,     3,     4,     5,     6,    -1,    55,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    18,    19,    -1,
      21,    -1,    23,    24,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    -1,    35,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    18,    -1,    -1,    21,    -1,    23,
      24,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      -1,    23,    24,    -1,    -1,    49,    50,    51,    52,    53,
      54,    -1,    -1,    35,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,     7,     8,     9,    10,
      11,    25,    26,    27,    28,    -1,    58,    31,    32,    33,
      34,     7,     8,     9,    10,    11,    27,    28,    -1,    -1,
      31,    32,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,     7,     8,     9,    10,
      11,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    25,    26,    27,    28,    19,    30,    31,    32,
      33,    34,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,     7,     8,     9,    10,    11,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    25,    26,    27,
      28,    19,    30,    31,    32,    33,    34,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    25,    26,    27,    28,    -1,
      -1,    31,    32
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    14,    15,    16,    17,    63,    64,    65,    82,
      86,    20,     0,    65,    82,     4,    18,    18,    19,    13,
      19,    86,    88,    21,    21,     4,    19,    60,     1,     4,
      12,    36,    38,    39,    40,    41,    42,    55,    66,    67,
      68,    69,    70,    74,    75,    76,    77,    78,    79,    80,
      81,    84,    85,    86,    66,    21,    86,    58,    18,    29,
      56,    57,    59,    61,    18,    18,    18,    18,     3,     4,
       5,     6,    18,    21,    23,    24,    35,    49,    50,    51,
      52,    53,    54,    83,    89,    90,    91,    31,    22,    67,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
       4,    22,    66,     4,    19,    87,    89,    89,    89,    43,
      44,    46,    87,    89,    89,    68,    86,    18,    61,    89,
      87,    89,    18,    18,    18,    18,    18,    18,     7,     8,
       9,    10,    11,    25,    26,    27,    28,    31,    32,    33,
      34,    29,    86,    29,    59,    22,    19,    60,    30,    18,
      18,    18,    19,    19,    19,    58,     4,    19,    87,    45,
      47,    19,    22,     4,     4,     4,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    32,    89,    89,    89,    59,    89,    89,
      89,    21,    21,    89,    19,    18,    18,    19,    19,    19,
      19,    19,    19,    30,     4,    30,     4,    89,    19,    19,
      19,    66,    66,    58,    89,    19,    59,    29,    59,    29,
      22,    22,     4,    69,    81,    19,    29,    89,    29,    89,
      37,    71,    72,    73,    19,    19,    87,    30,    87,    30,
      21,    36,    72,    73,    21,    21,    30,    59,    30,    66,
      18,    66,    66,    89,    22,    89,    22,    22,    19,    21,
      66,    22
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    70,    70,    71,    71,
      72,    73,    73,    74,    75,    75,    76,    77,    78,    78,
      78,    78,    78,    78,    78,    79,    79,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     7,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     2,     2,     4,     3,     9,     8,     2,     1,
       8,     4,     0,     7,    11,    11,     1,     1,     9,     5,
       6,     6,     6,     9,     6,     9,    10,     4,     2,     2,
       8,     7,     4,     3,     4,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     4,     4,     2,     3,     5,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     1,
       4,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "id", "CADENA",
  "DECIMAL", "suma", "menos", "mult", "div", "modulo", "PRINTF", "tk_void",
  "tk_int", "tk_string", "tk_float", "tk_bool", "tk_PARA", "tk_PARC",
  "rmain", "tk_LLAVA", "tk_LLAVC", "tk_true", "tk_false", "tk_igualq",
  "tk_diferenteq", "tk_mayor_igual", "tk_menor_igual", "tk_CORCHA",
  "tk_CORCHC", "tk_menorq", "tk_mayorq", "tk_and", "tk_or", "tk_not",
  "res_IF", "res_ELSE", "res_WHILE", "res_FOR", "res_BREAK",
  "res_CONTINUE", "res_RETURN", "res_pushB", "res_pushF", "res_get",
  "res_remove", "res_size", "res_struct", "res_mean", "res_median",
  "res_mode", "res_atoi", "res_atof", "res_iota", "res_VECTOR", "mas_mas",
  "menos_menos", "';'", "'='", "','", "'.'", "$accept", "START",
  "LIST_FUNC", "MAIN", "LIST_INST", "INSTRUCTION", "DECLARAR", "ASIGNAR",
  "IF", "ELIF_LIST", "ELIF", "ELSE", "WHILE", "FOR", "BREAK", "CONT",
  "VECTOR", "MATRIZ", "PRINT", "INCREMENTO", "FUNC", "CALL_EXP",
  "LLAMADAF", "RETORNO", "TYPES", "LISTAEXP", "LISTPARAM", "EXP",
  "PRIMITIVE", "LIST_ARR", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   146,   146,   153,   161,   166,   175,   182,   187,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   205,
     206,   207,   208,   211,   214,   218,   223,   224,   227,   228,
     231,   237,   238,   242,   246,   247,   251,   253,   257,   258,
     259,   260,   261,   262,   264,   267,   268,   273,   276,   277,
     280,   281,   284,   285,   288,   289,   292,   293,   316,   317,
     318,   319,   320,   322,   327,   334,   339,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   366,   367,   370,   371,
     376,   377,   383,   384,   385,   386,   387,   388,   389,   390,
     393,   395
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 3015 "parser.cpp"

#line 397 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}




