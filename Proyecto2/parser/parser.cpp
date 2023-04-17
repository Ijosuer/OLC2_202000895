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
#line 78 "parser.y"
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
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.YY_MOVE_OR_COPY< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_STRUC: // LIST_STRUC
      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
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
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.move< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_STRUC: // LIST_STRUC
      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
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
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.copy< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_STRUC: // LIST_STRUC
      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (that.value);
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
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
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        value.move< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_STRUC: // LIST_STRUC
      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (that.value);
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
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
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 742 "parser.cpp"
        break;

      case symbol_kind::S_id: // id
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 748 "parser.cpp"
        break;

      case symbol_kind::S_CADENA: // CADENA
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 754 "parser.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 760 "parser.cpp"
        break;

      case symbol_kind::S_suma: // suma
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 766 "parser.cpp"
        break;

      case symbol_kind::S_menos: // menos
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 772 "parser.cpp"
        break;

      case symbol_kind::S_mult: // mult
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 778 "parser.cpp"
        break;

      case symbol_kind::S_div: // div
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 784 "parser.cpp"
        break;

      case symbol_kind::S_modulo: // modulo
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 790 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 796 "parser.cpp"
        break;

      case symbol_kind::S_tk_void: // tk_void
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 802 "parser.cpp"
        break;

      case symbol_kind::S_tk_int: // tk_int
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 808 "parser.cpp"
        break;

      case symbol_kind::S_tk_string: // tk_string
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 814 "parser.cpp"
        break;

      case symbol_kind::S_tk_float: // tk_float
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 820 "parser.cpp"
        break;

      case symbol_kind::S_tk_bool: // tk_bool
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 826 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARA: // tk_PARA
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 832 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARC: // tk_PARC
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 838 "parser.cpp"
        break;

      case symbol_kind::S_rmain: // rmain
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 844 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 850 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 856 "parser.cpp"
        break;

      case symbol_kind::S_tk_true: // tk_true
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 862 "parser.cpp"
        break;

      case symbol_kind::S_tk_false: // tk_false
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 868 "parser.cpp"
        break;

      case symbol_kind::S_tk_igualq: // tk_igualq
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 874 "parser.cpp"
        break;

      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 880 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 886 "parser.cpp"
        break;

      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 892 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 898 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 904 "parser.cpp"
        break;

      case symbol_kind::S_tk_menorq: // tk_menorq
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 910 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayorq: // tk_mayorq
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 916 "parser.cpp"
        break;

      case symbol_kind::S_tk_and: // tk_and
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 922 "parser.cpp"
        break;

      case symbol_kind::S_tk_or: // tk_or
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 928 "parser.cpp"
        break;

      case symbol_kind::S_tk_not: // tk_not
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 934 "parser.cpp"
        break;

      case symbol_kind::S_res_IF: // res_IF
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 940 "parser.cpp"
        break;

      case symbol_kind::S_res_ELSE: // res_ELSE
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 946 "parser.cpp"
        break;

      case symbol_kind::S_res_WHILE: // res_WHILE
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 952 "parser.cpp"
        break;

      case symbol_kind::S_res_FOR: // res_FOR
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 958 "parser.cpp"
        break;

      case symbol_kind::S_res_BREAK: // res_BREAK
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 964 "parser.cpp"
        break;

      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 970 "parser.cpp"
        break;

      case symbol_kind::S_res_RETURN: // res_RETURN
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 976 "parser.cpp"
        break;

      case symbol_kind::S_res_pushB: // res_pushB
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 982 "parser.cpp"
        break;

      case symbol_kind::S_res_pushF: // res_pushF
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 988 "parser.cpp"
        break;

      case symbol_kind::S_res_get: // res_get
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 994 "parser.cpp"
        break;

      case symbol_kind::S_res_remove: // res_remove
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1000 "parser.cpp"
        break;

      case symbol_kind::S_res_size: // res_size
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1006 "parser.cpp"
        break;

      case symbol_kind::S_res_struct: // res_struct
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1012 "parser.cpp"
        break;

      case symbol_kind::S_res_mean: // res_mean
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1018 "parser.cpp"
        break;

      case symbol_kind::S_res_median: // res_median
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1024 "parser.cpp"
        break;

      case symbol_kind::S_res_mode: // res_mode
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1030 "parser.cpp"
        break;

      case symbol_kind::S_res_atoi: // res_atoi
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1036 "parser.cpp"
        break;

      case symbol_kind::S_res_atof: // res_atof
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1042 "parser.cpp"
        break;

      case symbol_kind::S_res_iota: // res_iota
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1048 "parser.cpp"
        break;

      case symbol_kind::S_res_VECTOR: // res_VECTOR
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1054 "parser.cpp"
        break;

      case symbol_kind::S_mas_mas: // mas_mas
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1060 "parser.cpp"
        break;

      case symbol_kind::S_menos_menos: // menos_menos
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1066 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1072 "parser.cpp"
        break;

      case symbol_kind::S_LIST_STRUC: // LIST_STRUC
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1078 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1084 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1090 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1096 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1102 "parser.cpp"
        break;

      case symbol_kind::S_DECLARAR: // DECLARAR
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1108 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1114 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1120 "parser.cpp"
        break;

      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1126 "parser.cpp"
        break;

      case symbol_kind::S_ELIF: // ELIF
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1132 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1138 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1144 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1150 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1156 "parser.cpp"
        break;

      case symbol_kind::S_CONT: // CONT
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1162 "parser.cpp"
        break;

      case symbol_kind::S_VECTOR: // VECTOR
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1168 "parser.cpp"
        break;

      case symbol_kind::S_MATRIZ: // MATRIZ
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1174 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1180 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENTO: // INCREMENTO
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1186 "parser.cpp"
        break;

      case symbol_kind::S_FUNC: // FUNC
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1192 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1198 "parser.cpp"
        break;

      case symbol_kind::S_LLAMADAF: // LLAMADAF
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1204 "parser.cpp"
        break;

      case symbol_kind::S_RETORNO: // RETORNO
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1210 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1216 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1222 "parser.cpp"
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1228 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1234 "parser.cpp"
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1240 "parser.cpp"
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1246 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1252 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1258 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 143 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1264 "parser.cpp"
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
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
        yylhs.value.emplace< list_expression* > ();
        break;

      case symbol_kind::S_LIST_STRUC: // LIST_STRUC
      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< list_instruction* > ();
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
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
#line 151 "parser.y"
    {
      ctx.Main = yystack_[0].value.as < func_main* > ();
      ctx.Functions = nullptr;
      ctx.Structs = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
      yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1635 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 159 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
      ctx.Structs = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1647 "parser.cpp"
    break;

  case 4: // START: LIST_FUNC LIST_STRUC MAIN
#line 167 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[2].value.as < list_instruction* > ();
      ctx.Structs = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1659 "parser.cpp"
    break;

  case 5: // START: LIST_STRUC LIST_FUNC MAIN
#line 175 "parser.y"
    {
      ctx.Structs = yystack_[2].value.as < list_instruction* > ();
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1671 "parser.cpp"
    break;

  case 6: // START: LIST_STRUC MAIN
#line 183 "parser.y"
    {
    std::cout<<"ENTRA EN struct y main"<<std::endl;
        ctx.Main = yystack_[0].value.as < func_main* > ();
      ctx.Structs = yystack_[1].value.as < list_instruction* > ();
        ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1684 "parser.cpp"
    break;

  case 7: // LIST_STRUC: LIST_STRUC STRUCT_DECLARATION
#line 194 "parser.y"
            {
                yystack_[1].value.as < list_instruction* > ()-> newInst(yystack_[0].value.as < instruction* > ());
                yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > ();
            }
#line 1693 "parser.cpp"
    break;

  case 8: // LIST_STRUC: STRUCT_DECLARATION
#line 199 "parser.y"
            {
                yylhs.value.as < list_instruction* > ()=new list_instruction();
                yylhs.value.as < list_instruction* > ()-> newInst(yystack_[0].value.as < instruction* > ());
            }
#line 1702 "parser.cpp"
    break;

  case 9: // LIST_FUNC: LIST_FUNC FUNC
#line 206 "parser.y"
            {
                yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > ();
            }
#line 1711 "parser.cpp"
    break;

  case 10: // LIST_FUNC: FUNC
#line 211 "parser.y"
         {
            yylhs.value.as < list_instruction* > ()= new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
         }
#line 1720 "parser.cpp"
    break;

  case 11: // MAIN: tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 220 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(yystack_[6].location.begin.line,yystack_[6].location.begin.column, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
    
}
#line 1729 "parser.cpp"
    break;

  case 12: // LIST_INST: LIST_INST INSTRUCTION
#line 227 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1738 "parser.cpp"
    break;

  case 13: // LIST_INST: INSTRUCTION
#line 232 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1747 "parser.cpp"
    break;

  case 14: // INSTRUCTION: PRINT ';'
#line 238 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1753 "parser.cpp"
    break;

  case 15: // INSTRUCTION: DECLARAR ';'
#line 239 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1759 "parser.cpp"
    break;

  case 16: // INSTRUCTION: ASIGNAR ';'
#line 240 "parser.y"
                          {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1765 "parser.cpp"
    break;

  case 17: // INSTRUCTION: VECTOR ';'
#line 241 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1771 "parser.cpp"
    break;

  case 18: // INSTRUCTION: MATRIZ ';'
#line 242 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1777 "parser.cpp"
    break;

  case 19: // INSTRUCTION: BREAK ';'
#line 243 "parser.y"
                        {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1783 "parser.cpp"
    break;

  case 20: // INSTRUCTION: CONT ';'
#line 244 "parser.y"
                       {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1789 "parser.cpp"
    break;

  case 21: // INSTRUCTION: RETORNO ';'
#line 245 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1795 "parser.cpp"
    break;

  case 22: // INSTRUCTION: INCREMENTO ';'
#line 246 "parser.y"
                             {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1801 "parser.cpp"
    break;

  case 23: // INSTRUCTION: LLAMADAF ';'
#line 247 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1807 "parser.cpp"
    break;

  case 24: // INSTRUCTION: STRUCT_CREATION
#line 248 "parser.y"
                              {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1813 "parser.cpp"
    break;

  case 25: // INSTRUCTION: WHILE
#line 249 "parser.y"
                     {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1819 "parser.cpp"
    break;

  case 26: // INSTRUCTION: FOR
#line 250 "parser.y"
                   {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1825 "parser.cpp"
    break;

  case 27: // INSTRUCTION: IF
#line 251 "parser.y"
                  {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1831 "parser.cpp"
    break;

  case 28: // INSTRUCTION: error ';'
#line 252 "parser.y"
                       {std::cout<<"Error sintactico."<<std::endl;}
#line 1837 "parser.cpp"
    break;

  case 29: // DECLARAR: TYPES id
#line 255 "parser.y"
                    {std::cout<<"Declarando "<<yystack_[0].value.as < std::string > ()<<std::endl; 
                            yylhs.value.as < instruction* > () = new declaracion(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),new primitive(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),"",0,0.0,0));
                    }
#line 1845 "parser.cpp"
    break;

  case 30: // DECLARAR: TYPES id '=' EXP
#line 258 "parser.y"
                           {std::cout<<"Declarando con valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;
                            yylhs.value.as < instruction* > () = new declaracion(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());
                            }
#line 1853 "parser.cpp"
    break;

  case 31: // ASIGNAR: id '=' EXP
#line 262 "parser.y"
                     {yylhs.value.as < instruction* > () = new asignacion(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > (), nullptr);}
#line 1859 "parser.cpp"
    break;

  case 32: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELIF_LIST ELSE
#line 267 "parser.y"
                                                                            {yylhs.value.as < instruction* > () = new func_if(yystack_[8].location.begin.line,yystack_[8].location.begin.column,yystack_[6].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());}
#line 1865 "parser.cpp"
    break;

  case 33: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELSE
#line 268 "parser.y"
                                                                  {yylhs.value.as < instruction* > () = new func_if(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[5].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());}
#line 1871 "parser.cpp"
    break;

  case 34: // ELIF_LIST: ELIF_LIST ELIF
#line 271 "parser.y"
                          { yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1877 "parser.cpp"
    break;

  case 35: // ELIF_LIST: ELIF
#line 272 "parser.y"
                          { yylhs.value.as < list_instruction* > ()=new list_instruction(); yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); }
#line 1883 "parser.cpp"
    break;

  case 36: // ELIF: res_ELSE res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 276 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1891 "parser.cpp"
    break;

  case 37: // ELSE: res_ELSE tk_LLAVA LIST_INST tk_LLAVC
#line 281 "parser.y"
                                           { yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1897 "parser.cpp"
    break;

  case 38: // ELSE: %empty
#line 282 "parser.y"
             {}
#line 1903 "parser.cpp"
    break;

  case 39: // WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 286 "parser.y"
                                                                 {yylhs.value.as < instruction* > () = new func_while(yystack_[6].location.begin.line,yystack_[6].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1909 "parser.cpp"
    break;

  case 40: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' ASIGNAR tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 290 "parser.y"
                                                                                       {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line,yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < instruction* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1915 "parser.cpp"
    break;

  case 41: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 291 "parser.y"
                                                                                          {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line,yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < instruction* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1921 "parser.cpp"
    break;

  case 42: // BREAK: res_BREAK
#line 295 "parser.y"
                 {std::cout<<"Break"<<std::endl;}
#line 1927 "parser.cpp"
    break;

  case 43: // CONT: res_CONTINUE
#line 297 "parser.y"
                   {std::cout<<"continue"<<std::endl;}
#line 1933 "parser.cpp"
    break;

  case 44: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 301 "parser.y"
                                                                                 {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[6].value.as < TipoDato > (),yystack_[4].value.as < std::string > (),new array_exp(0,0,yystack_[6].value.as < TipoDato > (),yystack_[1].value.as < list_expression* > ()));}
#line 1939 "parser.cpp"
    break;

  case 45: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id
#line 302 "parser.y"
                                                {std::cout<<"VECTOR empty "<<std::endl;}
#line 1945 "parser.cpp"
    break;

  case 46: // VECTOR: id '.' res_pushF tk_PARA EXP tk_PARC
#line 303 "parser.y"
                                             {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"push_front",nullptr);}
#line 1951 "parser.cpp"
    break;

  case 47: // VECTOR: id '.' res_pushB tk_PARA EXP tk_PARC
#line 304 "parser.y"
                                             {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"push_back",nullptr);}
#line 1957 "parser.cpp"
    break;

  case 48: // VECTOR: id '.' res_remove tk_PARA EXP tk_PARC
#line 305 "parser.y"
                                              {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"remove",nullptr);}
#line 1963 "parser.cpp"
    break;

  case 49: // VECTOR: id tk_CORCHA EXP tk_CORCHC '=' id tk_CORCHA EXP tk_CORCHC
#line 307 "parser.y"
        {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[8].value.as < std::string > ()),yystack_[6].value.as < expression* > (),"asignar",new array_access(0,0,new access(0,0,yystack_[3].value.as < std::string > ()),yystack_[1].value.as < expression* > ()));}
#line 1969 "parser.cpp"
    break;

  case 50: // VECTOR: id tk_CORCHA EXP tk_CORCHC '=' EXP
#line 308 "parser.y"
                                            {std::cout<<"[][]"<<std::endl; yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[3].value.as < expression* > (),"asignar",yystack_[0].value.as < expression* > ());}
#line 1975 "parser.cpp"
    break;

  case 51: // MATRIZ: TYPES id tk_CORCHA EXP tk_CORCHC '=' tk_LLAVA LISTAEXP tk_LLAVC
#line 311 "parser.y"
                                                                        {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[8].value.as < TipoDato > (),yystack_[7].value.as < std::string > (),new matriz_exp(0,0,yystack_[1].value.as < list_expression* > ()));}
#line 1981 "parser.cpp"
    break;

  case 52: // MATRIZ: TYPES id tk_CORCHA EXP tk_CORCHC tk_CORCHA EXP tk_CORCHC '=' EXP
#line 313 "parser.y"
                                                {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[9].value.as < TipoDato > (),yystack_[8].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1987 "parser.cpp"
    break;

  case 53: // MATRIZ: TYPES id tk_CORCHA EXP tk_CORCHC tk_CORCHA EXP tk_CORCHC tk_CORCHA EXP tk_CORCHC '=' EXP
#line 315 "parser.y"
                                                {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[12].value.as < TipoDato > (),yystack_[11].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1993 "parser.cpp"
    break;

  case 54: // PRINT: PRINTF tk_PARA EXP tk_PARC
#line 319 "parser.y"
                                   { yylhs.value.as < instruction* > () = new print(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ()); }
#line 1999 "parser.cpp"
    break;

  case 55: // INCREMENTO: id mas_mas
#line 322 "parser.y"
                        {yylhs.value.as < instruction* > () = new incremento(0,0,yystack_[1].value.as < std::string > (),"++");}
#line 2005 "parser.cpp"
    break;

  case 56: // INCREMENTO: id menos_menos
#line 323 "parser.y"
                             {yylhs.value.as < instruction* > () = new incremento(0,0,yystack_[1].value.as < std::string > (),"--");}
#line 2011 "parser.cpp"
    break;

  case 57: // FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 326 "parser.y"
                                                                     {yylhs.value.as < instruction* > ()=new function(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());}
#line 2017 "parser.cpp"
    break;

  case 58: // FUNC: TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 327 "parser.y"
                                                           {yylhs.value.as < instruction* > ()=new function(yystack_[6].location.begin.line,yystack_[6].location.begin.column,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());}
#line 2023 "parser.cpp"
    break;

  case 59: // CALL_EXP: id tk_PARA LISTAEXP tk_PARC
#line 330 "parser.y"
                                       { yylhs.value.as < expression* > () = new call_exp(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 2029 "parser.cpp"
    break;

  case 60: // CALL_EXP: id tk_PARA tk_PARC
#line 331 "parser.y"
                            { yylhs.value.as < expression* > () = new call_exp(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),nullptr); }
#line 2035 "parser.cpp"
    break;

  case 61: // LLAMADAF: id tk_PARA LISTAEXP tk_PARC
#line 334 "parser.y"
                                      {yylhs.value.as < instruction* > ()= new call_inst(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());}
#line 2041 "parser.cpp"
    break;

  case 62: // LLAMADAF: id tk_PARA tk_PARC
#line 335 "parser.y"
                             {yylhs.value.as < instruction* > ()= new call_inst(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),nullptr);}
#line 2047 "parser.cpp"
    break;

  case 63: // RETORNO: res_RETURN EXP
#line 338 "parser.y"
                        {yylhs.value.as < instruction* > ()= new inst_return(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[0].value.as < expression* > ());}
#line 2053 "parser.cpp"
    break;

  case 64: // RETORNO: res_RETURN
#line 339 "parser.y"
                      {yylhs.value.as < instruction* > ()= new inst_return(yystack_[0].location.begin.line,yystack_[0].location.begin.column,nullptr);}
#line 2059 "parser.cpp"
    break;

  case 65: // STRUCT_DECLARATION: res_struct id tk_LLAVA DEC_LIST tk_LLAVC
#line 343 "parser.y"
                    {
                        yylhs.value.as < instruction* > () = new dec_struct(0,0,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ());
                    }
#line 2067 "parser.cpp"
    break;

  case 66: // STRUCT_CREATION: res_struct id id '=' tk_LLAVA LISTAEXP tk_LLAVC ';'
#line 349 "parser.y"
                {
                    std::cout<<"ENTRA EN EL STRUCcreation"<<std::endl;
                    yylhs.value.as < instruction* > () = new create_struct(0,0,yystack_[6].value.as < std::string > (),yystack_[5].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());
                }
#line 2076 "parser.cpp"
    break;

  case 67: // DEC_LIST: DEC_LIST TYPES id ';'
#line 360 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2085 "parser.cpp"
    break;

  case 68: // DEC_LIST: TYPES id ';'
#line 365 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 2094 "parser.cpp"
    break;

  case 69: // TYPES: tk_int
#line 378 "parser.y"
              { yylhs.value.as < TipoDato > () = INTEGER; }
#line 2100 "parser.cpp"
    break;

  case 70: // TYPES: tk_string
#line 379 "parser.y"
                { yylhs.value.as < TipoDato > () = STRING; }
#line 2106 "parser.cpp"
    break;

  case 71: // TYPES: tk_float
#line 380 "parser.y"
               { yylhs.value.as < TipoDato > () = FLOAT; }
#line 2112 "parser.cpp"
    break;

  case 72: // TYPES: tk_bool
#line 381 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 2118 "parser.cpp"
    break;

  case 73: // TYPES: tk_void
#line 382 "parser.y"
             { yylhs.value.as < TipoDato > () = NULO; }
#line 2124 "parser.cpp"
    break;

  case 74: // TYPES: res_VECTOR tk_menorq TYPES tk_mayorq
#line 383 "parser.y"
                                           { yylhs.value.as < TipoDato > () = VECTOR; }
#line 2130 "parser.cpp"
    break;

  case 75: // LISTAEXP: LISTAEXP ',' EXP
#line 386 "parser.y"
       {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 2139 "parser.cpp"
    break;

  case 76: // LISTAEXP: EXP
#line 391 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 2148 "parser.cpp"
    break;

  case 77: // LISTPARAM: LISTPARAM ',' TYPES id
#line 410 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > ()=yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2157 "parser.cpp"
    break;

  case 78: // LISTPARAM: TYPES id
#line 415 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
        }
#line 2166 "parser.cpp"
    break;

  case 79: // EXP: EXP suma EXP
#line 421 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+");}
#line 2172 "parser.cpp"
    break;

  case 80: // EXP: EXP menos EXP
#line 422 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 2178 "parser.cpp"
    break;

  case 81: // EXP: EXP mult EXP
#line 423 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 2184 "parser.cpp"
    break;

  case 82: // EXP: EXP div EXP
#line 424 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 2190 "parser.cpp"
    break;

  case 83: // EXP: EXP modulo EXP
#line 425 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 2196 "parser.cpp"
    break;

  case 84: // EXP: tk_PARA EXP tk_PARC
#line 426 "parser.y"
                          { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2202 "parser.cpp"
    break;

  case 85: // EXP: EXP tk_menor_igual EXP
#line 427 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 2208 "parser.cpp"
    break;

  case 86: // EXP: EXP tk_menorq EXP
#line 428 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 2214 "parser.cpp"
    break;

  case 87: // EXP: EXP tk_mayor_igual EXP
#line 429 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 2220 "parser.cpp"
    break;

  case 88: // EXP: EXP tk_mayorq EXP
#line 430 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 2226 "parser.cpp"
    break;

  case 89: // EXP: EXP tk_igualq EXP
#line 431 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 2232 "parser.cpp"
    break;

  case 90: // EXP: EXP tk_diferenteq EXP
#line 432 "parser.y"
                            { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 2238 "parser.cpp"
    break;

  case 91: // EXP: EXP tk_and EXP
#line 433 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 2244 "parser.cpp"
    break;

  case 92: // EXP: EXP tk_or EXP
#line 434 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 2250 "parser.cpp"
    break;

  case 93: // EXP: res_atof tk_PARA EXP tk_PARC
#line 435 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "atof");}
#line 2256 "parser.cpp"
    break;

  case 94: // EXP: res_atoi tk_PARA EXP tk_PARC
#line 436 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "atoi");}
#line 2262 "parser.cpp"
    break;

  case 95: // EXP: res_iota tk_PARA EXP tk_PARC
#line 437 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "iota");}
#line 2268 "parser.cpp"
    break;

  case 96: // EXP: tk_not EXP
#line 438 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line,yystack_[1].location.begin.column, yystack_[0].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"); }
#line 2274 "parser.cpp"
    break;

  case 97: // EXP: tk_LLAVA LISTAEXP tk_LLAVC
#line 439 "parser.y"
                                 {yylhs.value.as < expression* > () = new matriz_exp(0,0,yystack_[1].value.as < list_expression* > ()); }
#line 2280 "parser.cpp"
    break;

  case 98: // EXP: id '.' res_size tk_PARA tk_PARC
#line 440 "parser.y"
                                       {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[4].value.as < std::string > ()),nullptr);}
#line 2286 "parser.cpp"
    break;

  case 99: // EXP: id '.' res_get tk_PARA EXP tk_PARC
#line 441 "parser.y"
                                         {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > ());}
#line 2292 "parser.cpp"
    break;

  case 100: // EXP: id '.' id
#line 442 "parser.y"
                { std::cout<<"ENTRA EN GRAMAR"<<std::endl; yylhs.value.as < expression* > () = new struct_access(0,0,new access(0,0,yystack_[2].value.as < std::string > ()),yystack_[0].value.as < std::string > ()); }
#line 2298 "parser.cpp"
    break;

  case 101: // EXP: PRIMITIVE
#line 443 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2304 "parser.cpp"
    break;

  case 102: // EXP: CALL_EXP
#line 444 "parser.y"
      { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2310 "parser.cpp"
    break;

  case 103: // PRIMITIVE: NUMERO
#line 449 "parser.y"
                   {  int num = stoi(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,INTEGER, "",num,0.0,false);}
#line 2316 "parser.cpp"
    break;

  case 104: // PRIMITIVE: CADENA
#line 451 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,STRING,str2,0,0.0, false);
        }
#line 2326 "parser.cpp"
    break;

  case 105: // PRIMITIVE: id
#line 456 "parser.y"
               {yylhs.value.as < expression* > () = new access(yystack_[0].location.begin.line,yystack_[0].location.begin.column,yystack_[0].value.as < std::string > ());}
#line 2332 "parser.cpp"
    break;

  case 106: // PRIMITIVE: DECIMAL
#line 457 "parser.y"
                    {float num = stof(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,FLOAT, "",0,num,false);}
#line 2338 "parser.cpp"
    break;

  case 107: // PRIMITIVE: tk_true
#line 458 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,BOOL,"",0,0.0,true); }
#line 2344 "parser.cpp"
    break;

  case 108: // PRIMITIVE: tk_false
#line 459 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,BOOL,"",0,0.0,false); }
#line 2350 "parser.cpp"
    break;

  case 109: // PRIMITIVE: res_mean tk_PARA id tk_PARC
#line 460 "parser.y"
                                      {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr);}
#line 2356 "parser.cpp"
    break;

  case 110: // PRIMITIVE: res_median tk_PARA id tk_PARC
#line 461 "parser.y"
                                        {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr);}
#line 2362 "parser.cpp"
    break;

  case 111: // PRIMITIVE: res_mode tk_PARA id tk_PARC
#line 462 "parser.y"
                                      {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr);}
#line 2368 "parser.cpp"
    break;

  case 112: // PRIMITIVE: LIST_ARR
#line 463 "parser.y"
                   {yylhs.value.as < expression* > ()=yystack_[0].value.as < expression* > ();}
#line 2374 "parser.cpp"
    break;

  case 113: // LIST_ARR: LIST_ARR tk_CORCHA EXP tk_CORCHC
#line 466 "parser.y"
                                            { yylhs.value.as < expression* > () = new array_access(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 2380 "parser.cpp"
    break;

  case 114: // LIST_ARR: id
#line 467 "parser.y"
             {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ()); }
#line 2386 "parser.cpp"
    break;


#line 2390 "parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -97;

  const signed char Parser::yytable_ninf_ = -115;

  const short
  Parser::yypact_[] =
  {
       9,    -9,   -97,   -97,   -97,   -97,     8,   -13,    13,     9,
       9,   -97,   -97,   -97,    29,    20,    45,    80,   -97,   145,
     -97,   -97,    -3,   -97,   -97,    47,    57,    80,   -97,    46,
     -97,    -9,   -97,    68,    65,   181,    76,   -97,    67,    86,
     -11,   601,   -97,    96,    43,   601,   -97,    99,    80,    66,
      -1,   108,   114,   119,   136,   -97,   -97,   686,   151,   125,
     130,   -97,   106,   115,   -97,   -97,   -97,   116,   133,   134,
     135,   144,   150,   156,   157,   -97,   177,   158,   -97,   241,
     601,   205,   -97,   627,   686,   -97,   -97,   686,   105,   686,
     686,   686,    80,   -97,   -15,   -97,   -97,   686,   686,   -97,
     -97,   686,   199,   206,   208,   212,   221,   223,   -97,   509,
     -97,   194,   239,    80,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -23,   -97,   -97,   286,
     -97,   -97,     2,   509,   240,   509,   226,   242,   243,   744,
     772,   800,   201,   258,   649,     5,   828,   -18,  1065,   260,
     265,   271,   686,   686,   686,   686,   686,   686,   686,   686,
     686,   686,   686,   686,   686,   686,   686,   686,   686,   217,
     246,   686,   686,   -97,   -97,   686,   225,   686,   686,   686,
     -97,   264,   267,   686,   227,   -97,    12,   -97,   279,   287,
     -97,   -97,   285,   288,   294,   856,   884,   912,    64,    64,
     292,   292,   292,   757,   757,   509,   211,   211,   211,  1065,
     554,   284,   299,   302,   329,   509,   509,   708,   940,   968,
     996,   601,   601,   179,   -97,   686,   304,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   686,   262,    39,    -2,   509,   -97,
     -97,   -97,   331,   376,   325,  1024,   -97,   -17,   301,   686,
     310,   686,   296,   -97,   123,   323,   330,   -97,   293,   686,
     374,   686,   419,    -6,   296,   -97,   -97,   337,   343,   -97,
      59,    40,     7,   -97,   601,   332,   -97,   -97,   601,   601,
     -97,   686,   686,   -97,   421,   686,   466,   511,   464,   509,
     -97,  1052,   -97,   -97,   306,   345,   686,   601,   509,   556,
     -97
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    73,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     2,    10,     8,     0,     0,     0,     0,     1,     0,
       6,     7,     0,     3,     9,     0,     0,     0,    73,     0,
       5,     0,     4,     0,     0,     0,     0,    74,     0,     0,
       0,     0,    65,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    64,     0,     0,
       0,    13,     0,     0,    27,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,    68,     0,
       0,     0,    28,     0,     0,    55,    56,     0,     0,     0,
       0,     0,     0,   103,   105,   104,   106,     0,     0,   107,
     108,     0,     0,     0,     0,     0,     0,     0,   102,    63,
     101,   112,     0,     0,    11,    12,    15,    16,    19,    20,
      17,    18,    14,    22,    23,    21,    29,    67,    58,     0,
      77,    62,     0,    76,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    61,     0,     0,     0,     0,     0,
      54,     0,     0,     0,    29,    60,     0,   100,     0,     0,
      84,    97,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    89,    90,    87,    85,    86,    88,    91,
      92,     0,     0,     0,     0,    30,    75,     0,     0,     0,
       0,     0,     0,     0,    59,     0,     0,   109,   110,   111,
      94,    93,    95,   113,     0,    45,     0,   105,    50,    47,
      46,    48,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,    38,    39,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,    38,    35,    33,     0,     0,    66,
       0,     0,     0,    49,     0,     0,    34,    32,     0,     0,
      44,     0,     0,    51,     0,     0,     0,     0,     0,    52,
      37,     0,    40,    41,     0,     0,     0,     0,    53,     0,
      36
  };

  const short
  Parser::yypgoto_[] =
  {
     -97,   -97,   342,   359,   131,   -45,   -59,   282,   132,   -97,
     -97,   111,   139,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     143,   120,   -97,   -97,   -97,    10,   -97,   -97,    44,   -96,
     -97,   -50,   -97,   -97
  };

  const short
  Parser::yydefgoto_[] =
  {
       0,     8,     9,    10,    11,    60,    61,    62,    63,    64,
     264,   265,   266,    65,    66,    67,    68,    69,    70,    71,
      72,    12,   108,    73,    74,    13,    75,    35,    76,   132,
      40,   133,   110,   111
  };

  const short
  Parser::yytable_[] =
  {
      79,   115,   147,   144,   191,   258,   171,   109,    47,   187,
      31,    15,    16,    18,  -114,   274,   144,    83,    17,    21,
     115,   174,     1,     2,     3,     4,     5,   251,    84,   283,
     275,   224,    21,    25,   134,   129,   172,   135,    26,   139,
     140,   141,   175,   175,    14,     6,   145,   146,   186,    48,
     188,   148,   189,    14,    14,    85,    86,     6,    87,   145,
      88,    29,   175,    14,     7,    33,    27,   175,   249,   281,
     115,    36,   175,   157,   158,   159,    34,    39,    37,    43,
      44,    28,     2,     3,     4,     5,    41,    38,    45,   280,
      46,   162,    81,    28,     2,     3,     4,     5,   250,   282,
      77,    78,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   175,
      80,   214,   215,     7,    82,   216,    89,   218,   219,   220,
      24,    49,    90,   223,    50,     7,   143,    91,   247,    24,
      20,    23,    51,    28,     2,     3,     4,     5,   136,   137,
      30,   138,   114,    32,    92,   112,   113,   170,     1,     2,
       3,     4,     5,   270,   116,   272,    52,   238,    53,    54,
      55,    56,    57,   117,   118,   245,   242,   243,    58,    85,
      86,   126,    87,   115,   115,    59,   155,   156,   157,   158,
     159,   119,   120,   121,    28,     2,     3,     4,     5,   260,
       7,   262,   122,    42,   160,   161,   162,   163,   123,   130,
     164,   165,   166,   167,   124,   125,   127,   149,   155,   156,
     157,   158,   159,   168,   150,   115,   151,   115,   115,   284,
     152,   288,   289,   286,   287,   291,     7,   244,   162,   153,
     115,   154,    49,   169,   177,    50,   298,   155,   156,   157,
     158,   159,   299,    51,    28,     2,     3,     4,     5,   183,
     178,   179,   184,   128,   192,   160,   161,   162,   163,   193,
     176,   164,   165,   166,   167,   194,   212,    52,   213,    53,
      54,    55,    56,    57,   217,   221,   172,    49,   222,    58,
      50,   155,   156,   157,   158,   159,    59,   225,    51,    28,
       2,     3,     4,     5,   227,   226,   235,   228,   173,   160,
     161,   162,   163,   229,   233,   164,   165,   166,   167,   162,
     234,   248,    52,   246,    53,    54,    55,    56,    57,   254,
     259,   261,    49,   263,    58,    50,   155,   156,   157,   158,
     159,    59,   267,    51,    28,     2,     3,     4,     5,   268,
     285,   269,    22,   252,   160,   161,   162,   163,   278,   236,
     164,   165,   166,   167,   279,   296,   297,    52,    19,    53,
      54,    55,    56,    57,   142,   276,   255,    49,     0,    58,
      50,   155,   156,   157,   158,   159,    59,   256,    51,    28,
       2,     3,     4,     5,     0,     0,     0,     0,   253,   160,
     161,   162,   163,   277,   271,   164,   165,   166,   167,     0,
       0,     0,    52,     0,    53,    54,    55,    56,    57,     0,
       0,     0,    49,     0,    58,    50,   155,   156,   157,   158,
     159,    59,     0,    51,    28,     2,     3,     4,     5,     0,
       0,     0,     0,   290,   160,   161,   162,   163,     0,   273,
     164,   165,   166,   167,     0,     0,     0,    52,     0,    53,
      54,    55,    56,    57,     0,     0,     0,    49,     0,    58,
      50,   155,   156,   157,   158,   159,    59,     0,    51,    28,
       2,     3,     4,     5,     0,     0,     0,     0,   292,   160,
     161,   162,   163,     0,   294,   164,   165,   166,   167,     0,
       0,     0,    52,     0,    53,    54,    55,    56,    57,     0,
       0,     0,    49,     0,    58,    50,   155,   156,   157,   158,
     159,    59,     0,    51,    28,     2,     3,     4,     5,     0,
       0,     0,     0,   293,   160,   161,   162,   163,     0,     0,
     164,   165,   166,   167,     0,     0,     0,    52,     0,    53,
      54,    55,    56,    57,     0,     0,     0,    49,     0,    58,
      50,   155,   156,   157,   158,   159,    59,     0,    51,    28,
       2,     3,     4,     5,     0,     0,     0,     0,   300,   160,
     161,   162,   163,     0,     0,   164,   165,   166,     0,     0,
       0,     0,    52,     0,    53,    54,    55,    56,    57,     0,
       0,     0,    49,     0,    58,    50,     0,     0,     0,     0,
       0,    59,     0,    51,    28,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,    96,     0,     0,     0,    52,     0,    53,
      54,    55,    56,    57,     0,    97,   131,     0,    98,    58,
      99,   100,    93,    94,    95,    96,    59,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,    97,   185,     0,
      98,     0,    99,   100,     0,     0,   102,   103,   104,   105,
     106,   107,     0,     0,   101,     0,     0,     0,     0,    93,
      94,    95,    96,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,    97,     0,     0,    98,     0,    99,
     100,    93,   237,    95,    96,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,    97,     0,     0,    98,
       0,    99,   100,     0,     0,   102,   103,   104,   105,   106,
     107,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   159,     0,   102,   103,   104,
     105,   106,   107,   180,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,   164,   165,   166,   167,   155,
     156,   157,   158,   159,   162,   163,     0,     0,   164,   165,
       0,   181,     0,     0,     0,     0,     0,   160,   161,   162,
     163,     0,     0,   164,   165,   166,   167,   155,   156,   157,
     158,   159,     0,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,   164,   165,   166,   167,   155,   156,   157,   158,   159,
       0,     0,     0,     0,     0,     0,     0,   190,     0,     0,
       0,     0,     0,   160,   161,   162,   163,     0,     0,   164,
     165,   166,   167,   155,   156,   157,   158,   159,     0,     0,
       0,     0,     0,     0,     0,   230,     0,     0,     0,     0,
       0,   160,   161,   162,   163,     0,     0,   164,   165,   166,
     167,   155,   156,   157,   158,   159,     0,     0,     0,     0,
       0,     0,     0,   231,     0,     0,     0,     0,     0,   160,
     161,   162,   163,     0,     0,   164,   165,   166,   167,   155,
     156,   157,   158,   159,     0,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,     0,     0,   160,   161,   162,
     163,     0,     0,   164,   165,   166,   167,   155,   156,   157,
     158,   159,     0,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,     0,     0,   160,   161,   162,   163,     0,
       0,   164,   165,   166,   167,   155,   156,   157,   158,   159,
       0,     0,     0,     0,     0,     0,     0,   240,     0,     0,
       0,     0,     0,   160,   161,   162,   163,     0,     0,   164,
     165,   166,   167,   155,   156,   157,   158,   159,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,     0,     0,
       0,   160,   161,   162,   163,     0,     0,   164,   165,   166,
     167,   155,   156,   157,   158,   159,     0,     0,     0,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,   160,
     161,   162,   163,     0,     0,   164,   165,   166,   167,   155,
     156,   157,   158,   159,     0,     0,     0,     0,     0,     0,
       0,   295,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,   164,   165,   166,   167,     0,     0,     0,
     160,   161,   162,   163,     0,     0,   164,   165
  };

  const short
  Parser::yycheck_[] =
  {
      45,    60,    98,    18,    22,    22,    29,    57,    19,     4,
      13,    20,     4,     0,    29,    21,    18,    18,    31,     9,
      79,    19,    13,    14,    15,    16,    17,    29,    29,    22,
      36,    19,    22,     4,    84,    80,    59,    87,    18,    89,
      90,    91,    60,    60,     0,    48,    61,    97,   144,    60,
      45,   101,    47,     9,    10,    56,    57,    48,    59,    61,
      61,    17,    60,    19,    55,    18,    21,    60,    29,    29,
     129,    27,    60,     9,    10,    11,    19,    33,    32,    35,
       4,    13,    14,    15,    16,    17,    21,    19,    21,    30,
       4,    27,    48,    13,    14,    15,    16,    17,    59,    59,
       4,    58,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    60,
      21,   171,   172,    55,    58,   175,    18,   177,   178,   179,
      10,     1,    18,   183,     4,    55,    92,    18,   234,    19,
       9,    10,    12,    13,    14,    15,    16,    17,    43,    44,
      19,    46,    22,    22,    18,     4,    31,   113,    13,    14,
      15,    16,    17,   259,    58,   261,    36,   217,    38,    39,
      40,    41,    42,    58,    58,   225,   221,   222,    48,    56,
      57,     4,    59,   242,   243,    55,     7,     8,     9,    10,
      11,    58,    58,    58,    13,    14,    15,    16,    17,   249,
      55,   251,    58,    22,    25,    26,    27,    28,    58,     4,
      31,    32,    33,    34,    58,    58,    58,    18,     7,     8,
       9,    10,    11,    29,    18,   284,    18,   286,   287,   274,
      18,   281,   282,   278,   279,   285,    55,    58,    27,    18,
     299,    18,     1,     4,    18,     4,   296,     7,     8,     9,
      10,    11,   297,    12,    13,    14,    15,    16,    17,    58,
      18,    18,     4,    22,     4,    25,    26,    27,    28,     4,
      30,    31,    32,    33,    34,     4,    59,    36,    32,    38,
      39,    40,    41,    42,    59,    21,    59,     1,    21,    48,
       4,     7,     8,     9,    10,    11,    55,    18,    12,    13,
      14,    15,    16,    17,    19,    18,     4,    19,    22,    25,
      26,    27,    28,    19,    30,    31,    32,    33,    34,    27,
      21,    59,    36,    19,    38,    39,    40,    41,    42,     4,
      29,    21,     1,    37,    48,     4,     7,     8,     9,    10,
      11,    55,    19,    12,    13,    14,    15,    16,    17,    19,
      18,    58,    10,    22,    25,    26,    27,    28,    21,    30,
      31,    32,    33,    34,    21,    59,    21,    36,     9,    38,
      39,    40,    41,    42,    92,   264,   244,     1,    -1,    48,
       4,     7,     8,     9,    10,    11,    55,   244,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    25,
      26,    27,    28,   264,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,     1,    -1,    48,     4,     7,     8,     9,    10,
      11,    55,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    42,    -1,    -1,    -1,     1,    -1,    48,
       4,     7,     8,     9,    10,    11,    55,    -1,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,     1,    -1,    48,     4,     7,     8,     9,    10,
      11,    55,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    42,    -1,    -1,    -1,     1,    -1,    48,
       4,     7,     8,     9,    10,    11,    55,    -1,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,     1,    -1,    48,     4,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    42,    -1,    18,    19,    -1,    21,    48,
      23,    24,     3,     4,     5,     6,    55,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    18,    19,    -1,
      21,    -1,    23,    24,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    -1,    35,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    18,    -1,    -1,    21,    -1,    23,
      24,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      -1,    23,    24,    -1,    -1,    49,    50,    51,    52,    53,
      54,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,     9,    10,    11,    -1,    49,    50,    51,
      52,    53,    54,    19,     7,     8,     9,    10,    11,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,     7,
       8,     9,    10,    11,    27,    28,    -1,    -1,    31,    32,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
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
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,     7,     8,     9,    10,    11,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    31,    32
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    14,    15,    16,    17,    48,    55,    63,    64,
      65,    66,    83,    87,    90,    20,     4,    31,     0,    65,
      66,    87,    64,    66,    83,     4,    18,    21,    13,    90,
      66,    13,    66,    18,    19,    89,    90,    32,    19,    90,
      92,    21,    22,    90,     4,    21,     4,    19,    60,     1,
       4,    12,    36,    38,    39,    40,    41,    42,    48,    55,
      67,    68,    69,    70,    71,    75,    76,    77,    78,    79,
      80,    81,    82,    85,    86,    88,    90,     4,    58,    67,
      21,    90,    58,    18,    29,    56,    57,    59,    61,    18,
      18,    18,    18,     3,     4,     5,     6,    18,    21,    23,
      24,    35,    49,    50,    51,    52,    53,    54,    84,    93,
      94,    95,     4,    31,    22,    68,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,     4,    58,    22,    67,
       4,    19,    91,    93,    93,    93,    43,    44,    46,    93,
      93,    93,    69,    90,    18,    61,    93,    91,    93,    18,
      18,    18,    18,    18,    18,     7,     8,     9,    10,    11,
      25,    26,    27,    28,    31,    32,    33,    34,    29,     4,
      90,    29,    59,    22,    19,    60,    30,    18,    18,    18,
      19,    19,    19,    58,     4,    19,    91,     4,    45,    47,
      19,    22,     4,     4,     4,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    59,    32,    93,    93,    93,    59,    93,    93,
      93,    21,    21,    93,    19,    18,    18,    19,    19,    19,
      19,    19,    19,    30,    21,     4,    30,     4,    93,    19,
      19,    19,    67,    67,    58,    93,    19,    91,    59,    29,
      59,    29,    22,    22,     4,    70,    82,    19,    22,    29,
      93,    21,    93,    37,    72,    73,    74,    19,    19,    58,
      91,    30,    91,    30,    21,    36,    73,    74,    21,    21,
      30,    29,    59,    22,    67,    18,    67,    67,    93,    93,
      22,    93,    22,    22,    30,    19,    59,    21,    93,    67,
      22
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    62,    63,    63,    63,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    74,    74,    75,
      76,    76,    77,    78,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    88,    89,    89,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     3,     2,     2,     1,     2,
       1,     7,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       4,     3,     9,     8,     2,     1,     8,     4,     0,     7,
      11,    11,     1,     1,     9,     5,     6,     6,     6,     9,
       6,     9,    10,    13,     4,     2,     2,     8,     7,     4,
       3,     4,     3,     2,     1,     5,     8,     4,     3,     1,
       1,     1,     1,     1,     4,     3,     1,     4,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     2,     3,     5,     6,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     1,     4,     1
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
  "LIST_STRUC", "LIST_FUNC", "MAIN", "LIST_INST", "INSTRUCTION",
  "DECLARAR", "ASIGNAR", "IF", "ELIF_LIST", "ELIF", "ELSE", "WHILE", "FOR",
  "BREAK", "CONT", "VECTOR", "MATRIZ", "PRINT", "INCREMENTO", "FUNC",
  "CALL_EXP", "LLAMADAF", "RETORNO", "STRUCT_DECLARATION",
  "STRUCT_CREATION", "DEC_LIST", "TYPES", "LISTAEXP", "LISTPARAM", "EXP",
  "PRIMITIVE", "LIST_ARR", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   150,   150,   158,   166,   174,   182,   193,   198,   205,
     210,   219,   226,   231,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   255,
     258,   262,   267,   268,   271,   272,   275,   281,   282,   286,
     290,   291,   295,   297,   301,   302,   303,   304,   305,   306,
     308,   311,   312,   314,   319,   322,   323,   326,   327,   330,
     331,   334,   335,   338,   339,   342,   348,   359,   364,   378,
     379,   380,   381,   382,   383,   385,   390,   409,   414,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   449,   450,   456,   457,   458,   459,   460,
     461,   462,   463,   466,   467
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
#line 3211 "parser.cpp"

#line 469 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}
