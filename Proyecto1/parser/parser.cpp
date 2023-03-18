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
#line 72 "parser.y"
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
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 718 "parser.cpp"
        break;

      case symbol_kind::S_id: // id
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 724 "parser.cpp"
        break;

      case symbol_kind::S_CADENA: // CADENA
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 730 "parser.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 736 "parser.cpp"
        break;

      case symbol_kind::S_suma: // suma
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 742 "parser.cpp"
        break;

      case symbol_kind::S_menos: // menos
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 748 "parser.cpp"
        break;

      case symbol_kind::S_mult: // mult
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 754 "parser.cpp"
        break;

      case symbol_kind::S_div: // div
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 760 "parser.cpp"
        break;

      case symbol_kind::S_modulo: // modulo
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 766 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 772 "parser.cpp"
        break;

      case symbol_kind::S_tk_void: // tk_void
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 778 "parser.cpp"
        break;

      case symbol_kind::S_tk_int: // tk_int
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 784 "parser.cpp"
        break;

      case symbol_kind::S_tk_string: // tk_string
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 790 "parser.cpp"
        break;

      case symbol_kind::S_tk_float: // tk_float
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 796 "parser.cpp"
        break;

      case symbol_kind::S_tk_bool: // tk_bool
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 802 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARA: // tk_PARA
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 808 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARC: // tk_PARC
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 814 "parser.cpp"
        break;

      case symbol_kind::S_rmain: // rmain
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 820 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 826 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 832 "parser.cpp"
        break;

      case symbol_kind::S_tk_true: // tk_true
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 838 "parser.cpp"
        break;

      case symbol_kind::S_tk_false: // tk_false
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 844 "parser.cpp"
        break;

      case symbol_kind::S_tk_igualq: // tk_igualq
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 850 "parser.cpp"
        break;

      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 856 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 862 "parser.cpp"
        break;

      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 868 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 874 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 880 "parser.cpp"
        break;

      case symbol_kind::S_tk_menorq: // tk_menorq
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 886 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayorq: // tk_mayorq
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 892 "parser.cpp"
        break;

      case symbol_kind::S_tk_and: // tk_and
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 898 "parser.cpp"
        break;

      case symbol_kind::S_tk_or: // tk_or
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 904 "parser.cpp"
        break;

      case symbol_kind::S_tk_not: // tk_not
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 910 "parser.cpp"
        break;

      case symbol_kind::S_res_IF: // res_IF
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 916 "parser.cpp"
        break;

      case symbol_kind::S_res_ELSE: // res_ELSE
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 922 "parser.cpp"
        break;

      case symbol_kind::S_res_WHILE: // res_WHILE
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 928 "parser.cpp"
        break;

      case symbol_kind::S_res_FOR: // res_FOR
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 934 "parser.cpp"
        break;

      case symbol_kind::S_res_BREAK: // res_BREAK
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 940 "parser.cpp"
        break;

      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 946 "parser.cpp"
        break;

      case symbol_kind::S_res_RETURN: // res_RETURN
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 952 "parser.cpp"
        break;

      case symbol_kind::S_res_pushB: // res_pushB
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 958 "parser.cpp"
        break;

      case symbol_kind::S_res_pushF: // res_pushF
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 964 "parser.cpp"
        break;

      case symbol_kind::S_res_get: // res_get
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 970 "parser.cpp"
        break;

      case symbol_kind::S_res_remove: // res_remove
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 976 "parser.cpp"
        break;

      case symbol_kind::S_res_size: // res_size
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 982 "parser.cpp"
        break;

      case symbol_kind::S_res_struct: // res_struct
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 988 "parser.cpp"
        break;

      case symbol_kind::S_res_mean: // res_mean
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 994 "parser.cpp"
        break;

      case symbol_kind::S_res_median: // res_median
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1000 "parser.cpp"
        break;

      case symbol_kind::S_res_mode: // res_mode
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1006 "parser.cpp"
        break;

      case symbol_kind::S_res_atoi: // res_atoi
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1012 "parser.cpp"
        break;

      case symbol_kind::S_res_atof: // res_atof
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1018 "parser.cpp"
        break;

      case symbol_kind::S_res_iota: // res_iota
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1024 "parser.cpp"
        break;

      case symbol_kind::S_res_VECTOR: // res_VECTOR
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1030 "parser.cpp"
        break;

      case symbol_kind::S_mas_mas: // mas_mas
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1036 "parser.cpp"
        break;

      case symbol_kind::S_menos_menos: // menos_menos
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1042 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1048 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1054 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1060 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1066 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1072 "parser.cpp"
        break;

      case symbol_kind::S_DECLARAR: // DECLARAR
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1078 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1084 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1090 "parser.cpp"
        break;

      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1096 "parser.cpp"
        break;

      case symbol_kind::S_ELIF: // ELIF
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1102 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1108 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1114 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1120 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1126 "parser.cpp"
        break;

      case symbol_kind::S_CONT: // CONT
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1132 "parser.cpp"
        break;

      case symbol_kind::S_VECTOR: // VECTOR
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1138 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1144 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENTO: // INCREMENTO
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1150 "parser.cpp"
        break;

      case symbol_kind::S_FUNC: // FUNC
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1156 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1162 "parser.cpp"
        break;

      case symbol_kind::S_LLAMADAF: // LLAMADAF
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1168 "parser.cpp"
        break;

      case symbol_kind::S_RETORNO: // RETORNO
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1174 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1180 "parser.cpp"
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1186 "parser.cpp"
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1192 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1198 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 130 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1204 "parser.cpp"
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
#line 138 "parser.y"
    {
      ctx.Main = yystack_[0].value.as < func_main* > ();
      ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
      yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1568 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 145 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1579 "parser.cpp"
    break;

  case 4: // LIST_FUNC: LIST_FUNC FUNC
#line 153 "parser.y"
            {
                yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > ();
            }
#line 1588 "parser.cpp"
    break;

  case 5: // LIST_FUNC: FUNC
#line 158 "parser.y"
         {
            yylhs.value.as < list_instruction* > ()= new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
         }
#line 1597 "parser.cpp"
    break;

  case 6: // MAIN: tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 167 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(yystack_[6].location.begin.line,yystack_[6].location.begin.column, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
    
}
#line 1606 "parser.cpp"
    break;

  case 7: // LIST_INST: LIST_INST INSTRUCTION
#line 174 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1615 "parser.cpp"
    break;

  case 8: // LIST_INST: INSTRUCTION
#line 179 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1624 "parser.cpp"
    break;

  case 9: // INSTRUCTION: PRINT ';'
#line 185 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1630 "parser.cpp"
    break;

  case 10: // INSTRUCTION: DECLARAR ';'
#line 186 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1636 "parser.cpp"
    break;

  case 11: // INSTRUCTION: ASIGNAR ';'
#line 187 "parser.y"
                          {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1642 "parser.cpp"
    break;

  case 12: // INSTRUCTION: VECTOR ';'
#line 188 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1648 "parser.cpp"
    break;

  case 13: // INSTRUCTION: BREAK ';'
#line 189 "parser.y"
                        {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1654 "parser.cpp"
    break;

  case 14: // INSTRUCTION: CONT ';'
#line 190 "parser.y"
                       {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1660 "parser.cpp"
    break;

  case 15: // INSTRUCTION: RETORNO ';'
#line 191 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1666 "parser.cpp"
    break;

  case 16: // INSTRUCTION: INCREMENTO ';'
#line 192 "parser.y"
                             {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1672 "parser.cpp"
    break;

  case 17: // INSTRUCTION: LLAMADAF ';'
#line 193 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1678 "parser.cpp"
    break;

  case 18: // INSTRUCTION: WHILE
#line 195 "parser.y"
                     {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1684 "parser.cpp"
    break;

  case 19: // INSTRUCTION: FOR
#line 196 "parser.y"
                   {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1690 "parser.cpp"
    break;

  case 20: // INSTRUCTION: IF
#line 197 "parser.y"
                  {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1696 "parser.cpp"
    break;

  case 21: // INSTRUCTION: error ';'
#line 198 "parser.y"
                       {}
#line 1702 "parser.cpp"
    break;

  case 22: // DECLARAR: TYPES id
#line 201 "parser.y"
                    {std::cout<<"Declarando "<<yystack_[0].value.as < std::string > ()<<std::endl; 
                            yylhs.value.as < instruction* > () = new declaracion(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),new primitive(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),"",0,0.0,0));
                    }
#line 1710 "parser.cpp"
    break;

  case 23: // DECLARAR: TYPES id '=' EXP
#line 204 "parser.y"
                           {std::cout<<"Declarando con valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;
                            yylhs.value.as < instruction* > () = new declaracion(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());
                            }
#line 1718 "parser.cpp"
    break;

  case 24: // ASIGNAR: id '=' EXP
#line 209 "parser.y"
                     {std::cout<<"Asignando valor a "<<yystack_[2].value.as < std::string > ()<<std::endl; yylhs.value.as < instruction* > () = new asignacion(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1724 "parser.cpp"
    break;

  case 25: // ASIGNAR: id tk_LLAVA EXP tk_LLAVC '=' tk_LLAVA EXP tk_LLAVC
#line 210 "parser.y"
                                                               {std::cout<<"Asignando valor vector a: "<<yystack_[7].value.as < std::string > ()<<std::endl;}
#line 1730 "parser.cpp"
    break;

  case 26: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELIF_LIST ELSE
#line 215 "parser.y"
                                                                            {yylhs.value.as < instruction* > () = new func_if(yystack_[8].location.begin.line,yystack_[8].location.begin.column,yystack_[6].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());}
#line 1736 "parser.cpp"
    break;

  case 27: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELSE
#line 216 "parser.y"
                                                                  {yylhs.value.as < instruction* > () = new func_if(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[5].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());}
#line 1742 "parser.cpp"
    break;

  case 28: // ELIF_LIST: ELIF_LIST ELIF
#line 219 "parser.y"
                          { yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1748 "parser.cpp"
    break;

  case 29: // ELIF_LIST: ELIF
#line 220 "parser.y"
                          { yylhs.value.as < list_instruction* > ()=new list_instruction(); yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); }
#line 1754 "parser.cpp"
    break;

  case 30: // ELIF: res_ELSE res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 224 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1762 "parser.cpp"
    break;

  case 31: // ELSE: res_ELSE tk_LLAVA LIST_INST tk_LLAVC
#line 229 "parser.y"
                                           { yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1768 "parser.cpp"
    break;

  case 32: // ELSE: %empty
#line 230 "parser.y"
             {}
#line 1774 "parser.cpp"
    break;

  case 33: // WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 234 "parser.y"
                                                                 {yylhs.value.as < instruction* > () = new func_while(yystack_[6].location.begin.line,yystack_[6].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1780 "parser.cpp"
    break;

  case 34: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' ASIGNAR tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 238 "parser.y"
                                                                                       {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line,yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < instruction* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1786 "parser.cpp"
    break;

  case 35: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 239 "parser.y"
                                                                                          {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line,yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < instruction* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1792 "parser.cpp"
    break;

  case 36: // BREAK: res_BREAK
#line 243 "parser.y"
                 {std::cout<<"Break"<<std::endl;}
#line 1798 "parser.cpp"
    break;

  case 37: // CONT: res_CONTINUE
#line 245 "parser.y"
                   {std::cout<<"continue"<<std::endl;}
#line 1804 "parser.cpp"
    break;

  case 38: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 249 "parser.y"
                                                                                 {yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[6].value.as < TipoDato > (),yystack_[4].value.as < std::string > (),new array_exp(0,0,yystack_[6].value.as < TipoDato > (),yystack_[1].value.as < list_expression* > ()));}
#line 1810 "parser.cpp"
    break;

  case 39: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id
#line 250 "parser.y"
                                                {std::cout<<"VECTOR empty "<<std::endl;}
#line 1816 "parser.cpp"
    break;

  case 40: // VECTOR: id '.' res_pushF tk_PARA EXP tk_PARC
#line 251 "parser.y"
                                             {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"push_front");}
#line 1822 "parser.cpp"
    break;

  case 41: // VECTOR: id '.' res_pushB tk_PARA EXP tk_PARC
#line 252 "parser.y"
                                             {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"push_back");}
#line 1828 "parser.cpp"
    break;

  case 42: // VECTOR: id '.' res_remove tk_PARA EXP tk_PARC
#line 253 "parser.y"
                                              {yylhs.value.as < instruction* > () = new vector(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"remove");}
#line 1834 "parser.cpp"
    break;

  case 43: // PRINT: PRINTF tk_PARA LISTAEXP tk_PARC
#line 255 "parser.y"
                                        { yylhs.value.as < instruction* > () = new print(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 1840 "parser.cpp"
    break;

  case 44: // INCREMENTO: id mas_mas
#line 258 "parser.y"
                        {yylhs.value.as < instruction* > () = new incremento(0,0,yystack_[1].value.as < std::string > (),"++");}
#line 1846 "parser.cpp"
    break;

  case 45: // INCREMENTO: id menos_menos
#line 259 "parser.y"
                             {yylhs.value.as < instruction* > () = new incremento(0,0,yystack_[1].value.as < std::string > (),"--");
                             }
#line 1853 "parser.cpp"
    break;

  case 46: // FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 263 "parser.y"
                                                                     {yylhs.value.as < instruction* > ()=new function(yystack_[7].location.begin.line,yystack_[7].location.begin.column,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1859 "parser.cpp"
    break;

  case 47: // FUNC: TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 264 "parser.y"
                                                           {yylhs.value.as < instruction* > ()=new function(yystack_[6].location.begin.line,yystack_[6].location.begin.column,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());}
#line 1865 "parser.cpp"
    break;

  case 48: // CALL_EXP: id tk_PARA LISTAEXP tk_PARC
#line 267 "parser.y"
                                       { yylhs.value.as < expression* > () = new call_exp(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 1871 "parser.cpp"
    break;

  case 49: // CALL_EXP: id tk_PARA tk_PARC
#line 268 "parser.y"
                            { yylhs.value.as < expression* > () = new call_exp(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),nullptr); }
#line 1877 "parser.cpp"
    break;

  case 50: // LLAMADAF: id tk_PARA LISTAEXP tk_PARC
#line 271 "parser.y"
                                      {yylhs.value.as < instruction* > ()= new call_inst(yystack_[3].location.begin.line,yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());}
#line 1883 "parser.cpp"
    break;

  case 51: // LLAMADAF: id tk_PARA tk_PARC
#line 272 "parser.y"
                             {yylhs.value.as < instruction* > ()= new call_inst(yystack_[2].location.begin.line,yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),nullptr);}
#line 1889 "parser.cpp"
    break;

  case 52: // RETORNO: res_RETURN EXP
#line 275 "parser.y"
                        {yylhs.value.as < instruction* > ()= new inst_return(yystack_[1].location.begin.line,yystack_[1].location.begin.column,yystack_[0].value.as < expression* > ());}
#line 1895 "parser.cpp"
    break;

  case 53: // RETORNO: res_RETURN
#line 276 "parser.y"
                      {yylhs.value.as < instruction* > ()= new inst_return(yystack_[0].location.begin.line,yystack_[0].location.begin.column,nullptr);}
#line 1901 "parser.cpp"
    break;

  case 54: // TYPES: tk_int
#line 279 "parser.y"
              { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1907 "parser.cpp"
    break;

  case 55: // TYPES: tk_string
#line 280 "parser.y"
                { yylhs.value.as < TipoDato > () = STRING; }
#line 1913 "parser.cpp"
    break;

  case 56: // TYPES: tk_float
#line 281 "parser.y"
               { yylhs.value.as < TipoDato > () = FLOAT; }
#line 1919 "parser.cpp"
    break;

  case 57: // TYPES: tk_bool
#line 282 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1925 "parser.cpp"
    break;

  case 58: // TYPES: tk_void
#line 283 "parser.y"
             { yylhs.value.as < TipoDato > () = NULO; }
#line 1931 "parser.cpp"
    break;

  case 59: // LISTAEXP: LISTAEXP ',' EXP
#line 286 "parser.y"
       {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1940 "parser.cpp"
    break;

  case 60: // LISTAEXP: EXP
#line 291 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1949 "parser.cpp"
    break;

  case 61: // LISTPARAM: LISTPARAM ',' TYPES id
#line 298 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > ()=yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1958 "parser.cpp"
    break;

  case 62: // LISTPARAM: TYPES id
#line 303 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
        }
#line 1967 "parser.cpp"
    break;

  case 63: // EXP: EXP suma EXP
#line 309 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+");}
#line 1973 "parser.cpp"
    break;

  case 64: // EXP: EXP menos EXP
#line 310 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1979 "parser.cpp"
    break;

  case 65: // EXP: EXP mult EXP
#line 311 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1985 "parser.cpp"
    break;

  case 66: // EXP: EXP div EXP
#line 312 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1991 "parser.cpp"
    break;

  case 67: // EXP: EXP modulo EXP
#line 313 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 1997 "parser.cpp"
    break;

  case 68: // EXP: tk_PARA EXP tk_PARC
#line 314 "parser.y"
                          { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2003 "parser.cpp"
    break;

  case 69: // EXP: EXP tk_menor_igual EXP
#line 315 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 2009 "parser.cpp"
    break;

  case 70: // EXP: EXP tk_menorq EXP
#line 316 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 2015 "parser.cpp"
    break;

  case 71: // EXP: EXP tk_mayor_igual EXP
#line 317 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 2021 "parser.cpp"
    break;

  case 72: // EXP: EXP tk_mayorq EXP
#line 318 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 2027 "parser.cpp"
    break;

  case 73: // EXP: EXP tk_igualq EXP
#line 319 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 2033 "parser.cpp"
    break;

  case 74: // EXP: EXP tk_diferenteq EXP
#line 320 "parser.y"
                            { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 2039 "parser.cpp"
    break;

  case 75: // EXP: EXP tk_and EXP
#line 321 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 2045 "parser.cpp"
    break;

  case 76: // EXP: EXP tk_or EXP
#line 322 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line,yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 2051 "parser.cpp"
    break;

  case 77: // EXP: res_atof tk_PARA EXP tk_PARC
#line 323 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "atof");}
#line 2057 "parser.cpp"
    break;

  case 78: // EXP: res_atoi tk_PARA EXP tk_PARC
#line 324 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "atoi");}
#line 2063 "parser.cpp"
    break;

  case 79: // EXP: res_iota tk_PARA EXP tk_PARC
#line 325 "parser.y"
                                   {yylhs.value.as < expression* > () = new operation(yystack_[3].location.begin.line,yystack_[3].location.begin.column, yystack_[1].value.as < expression* > (), yystack_[1].value.as < expression* > (), "iota");}
#line 2069 "parser.cpp"
    break;

  case 80: // EXP: tk_not EXP
#line 326 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line,yystack_[1].location.begin.column, yystack_[0].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"); }
#line 2075 "parser.cpp"
    break;

  case 81: // EXP: tk_LLAVA LISTAEXP tk_LLAVC
#line 327 "parser.y"
                                 { yylhs.value.as < expression* > () = new array_exp(0,0,NULO,yystack_[1].value.as < list_expression* > ()); }
#line 2081 "parser.cpp"
    break;

  case 82: // EXP: id '.' res_size tk_PARA tk_PARC
#line 328 "parser.y"
                                       {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[4].value.as < std::string > ()),nullptr,"size");}
#line 2087 "parser.cpp"
    break;

  case 83: // EXP: id '.' res_get tk_PARA EXP tk_PARC
#line 329 "parser.y"
                                         {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[5].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"get");}
#line 2093 "parser.cpp"
    break;

  case 84: // EXP: id tk_CORCHA EXP tk_CORCHC
#line 330 "parser.y"
                                 {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[3].value.as < std::string > ()),yystack_[1].value.as < expression* > (),"");}
#line 2099 "parser.cpp"
    break;

  case 85: // EXP: PRIMITIVE
#line 331 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2105 "parser.cpp"
    break;

  case 86: // EXP: CALL_EXP
#line 332 "parser.y"
      { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2111 "parser.cpp"
    break;

  case 87: // PRIMITIVE: NUMERO
#line 336 "parser.y"
                   {  int num = stoi(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,INTEGER, "",num,0.0,false);}
#line 2117 "parser.cpp"
    break;

  case 88: // PRIMITIVE: CADENA
#line 338 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,STRING,str2,0,0.0, false);
        }
#line 2127 "parser.cpp"
    break;

  case 89: // PRIMITIVE: id
#line 343 "parser.y"
               {yylhs.value.as < expression* > () = new access(yystack_[0].location.begin.line,yystack_[0].location.begin.column,yystack_[0].value.as < std::string > ());}
#line 2133 "parser.cpp"
    break;

  case 90: // PRIMITIVE: DECIMAL
#line 344 "parser.y"
                    {float num = stof(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,FLOAT, "",0,num,false);}
#line 2139 "parser.cpp"
    break;

  case 91: // PRIMITIVE: tk_true
#line 345 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,BOOL,"",0,0.0,true); }
#line 2145 "parser.cpp"
    break;

  case 92: // PRIMITIVE: tk_false
#line 346 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line,yystack_[0].location.begin.column,BOOL,"",0,0.0,false); }
#line 2151 "parser.cpp"
    break;

  case 93: // PRIMITIVE: res_mean tk_PARA id tk_PARC
#line 347 "parser.y"
                                      {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr,"mean");}
#line 2157 "parser.cpp"
    break;

  case 94: // PRIMITIVE: res_median tk_PARA id tk_PARC
#line 348 "parser.y"
                                        {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr,"median");}
#line 2163 "parser.cpp"
    break;

  case 95: // PRIMITIVE: res_mode tk_PARA id tk_PARC
#line 349 "parser.y"
                                      {yylhs.value.as < expression* > () = new array_access(0,0,new access(0,0,yystack_[1].value.as < std::string > ()),nullptr,"moda");}
#line 2169 "parser.cpp"
    break;


#line 2173 "parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -63;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     260,    -6,   -63,   -63,   -63,   -63,     6,   260,   -63,   -63,
      21,    14,   -63,   -63,   -63,    16,     9,   119,    17,   -63,
      39,    33,   -11,   142,   142,   -63,    47,   291,    19,   -14,
      57,    65,    66,    67,   -63,   -63,   487,    55,    40,   -63,
      30,    34,   -63,   -63,   -63,    35,    36,    38,    58,    60,
      68,    79,    87,   173,   142,   109,   -63,   428,   487,   -63,
     -63,   487,   -20,   487,   487,   487,   291,   -63,   -13,   -63,
     -63,   487,   487,   -63,   -63,   487,    97,   121,   123,   124,
     126,   127,   -63,   874,   -63,   291,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    90,   -63,   217,
     -63,   -63,    -2,   874,   545,   874,   132,   144,   145,     1,
     555,   583,   107,   450,   487,   -32,   611,    -1,   902,   162,
     165,   166,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   139,   487,
     -63,   -63,   487,   116,   487,   487,   487,   -63,   151,   155,
     487,   -63,     3,   624,   161,   174,   -63,   -63,   172,   175,
     182,   652,   680,   708,   113,   113,   176,   176,   176,   120,
     120,   874,    63,    63,    63,   902,   215,   189,   874,   874,
     181,   736,   764,   792,   142,   142,   517,   -63,   -63,   487,
     191,   -63,   -63,   -63,   -63,   -63,   -63,   149,   487,   -63,
     -63,   -63,   248,   279,   213,   820,   -63,   190,   833,   183,
     -63,    10,   208,   216,   -63,   487,   -63,    -9,   183,   -63,
     -63,   223,   224,     5,   142,   218,   -63,   -63,   142,   142,
     -63,   310,   487,   341,   372,   -63,   861,   -63,   -63,   229,
     142,   403,   -63
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    58,    54,    55,    56,    57,     0,     0,     2,     5,
       0,     0,     1,     3,     4,     0,     0,     0,     0,    58,
       0,     0,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    53,     0,     0,     8,
       0,     0,    20,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,    87,    89,    88,
      90,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,    86,    52,    85,     0,     6,     7,    10,    11,
      13,    14,    12,     9,    16,    17,    15,    22,    47,     0,
      61,    51,     0,    60,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    50,     0,     0,     0,     0,     0,    43,     0,     0,
       0,    49,     0,     0,     0,     0,    68,    81,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    73,
      74,    71,    69,    70,    72,    75,    76,     0,    23,    59,
       0,     0,     0,     0,     0,     0,     0,    48,    84,     0,
       0,    93,    94,    95,    78,    77,    79,    39,     0,    41,
      40,    42,     0,     0,     0,     0,    82,     0,     0,    32,
      33,     0,     0,     0,    83,     0,    25,     0,    32,    29,
      27,     0,     0,     0,     0,     0,    28,    26,     0,     0,
      38,     0,     0,     0,     0,    31,     0,    34,    35,     0,
       0,     0,    30
  };

  const short
  Parser::yypgoto_[] =
  {
     -63,   -63,   -63,   230,   -24,   -35,   185,    50,   -63,   -63,
      20,    48,   -63,   -63,   -63,   -63,   -63,   -63,    64,   262,
     -63,   -63,   -63,     2,   -62,   -63,   -25,   -63
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     6,     7,     8,    38,    39,    40,    41,    42,   218,
     219,   220,    43,    44,    45,    46,    47,    48,    49,     9,
      82,    50,    51,    52,   102,    22,   103,    84
  };

  const unsigned char
  Parser::yytable_[] =
  {
      53,   109,    10,    87,    57,   113,    12,    58,    26,    10,
     117,    83,   224,   154,    11,   155,   114,   141,    87,    21,
     147,   157,   187,   106,   107,    15,   108,   225,    18,    55,
      99,    58,    16,   104,    17,   230,   105,    25,    23,   110,
     111,    28,    59,    60,    29,    61,   116,    62,   115,    27,
     118,   152,    30,    19,     2,     3,     4,     5,   142,   142,
      24,   142,    86,   142,    87,   142,    59,    60,    54,    61,
     125,   126,   127,   128,   129,    63,    31,    56,    32,    33,
      34,    35,    36,    64,    65,    66,    85,   138,    88,   153,
     132,    97,    89,    90,    91,    37,    92,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   100,   178,   119,    93,   179,    94,   181,
     182,   183,   127,   128,   129,   186,    95,   125,   126,   127,
     128,   129,    19,     2,     3,     4,     5,    96,    20,   120,
     132,   121,   122,    28,   123,   124,    29,   132,   133,   139,
     144,   134,   135,   223,    30,    19,     2,     3,     4,     5,
     202,   203,   145,   146,   205,   150,   158,    87,    87,   159,
     160,   177,   184,   208,    28,   180,   185,    29,    31,   189,
      32,    33,    34,    35,    36,    30,    19,     2,     3,     4,
       5,   191,   190,   197,   192,    98,    87,    37,    87,    87,
     231,   193,   198,   132,   233,   234,    87,   236,   207,    31,
     206,    32,    33,    34,    35,    36,   241,   211,    28,   215,
     217,    29,   125,   126,   127,   128,   129,   221,    37,    30,
      19,     2,     3,     4,     5,   222,   232,    13,   226,   140,
     130,   131,   132,   133,   228,   229,   134,   135,   136,    28,
     240,   112,    29,    31,   212,    32,    33,    34,    35,    36,
      30,    19,     2,     3,     4,     5,   227,     0,   213,    14,
     209,     0,    37,     1,     2,     3,     4,     5,     0,     0,
      28,     0,     0,    29,    31,     0,    32,    33,    34,    35,
      36,    30,    19,     2,     3,     4,     5,     0,     0,     0,
       0,   210,     0,    37,    19,     2,     3,     4,     5,     0,
       0,    28,     0,     0,    29,    31,     0,    32,    33,    34,
      35,    36,    30,    19,     2,     3,     4,     5,     0,     0,
       0,     0,   235,     0,    37,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,    29,    31,     0,    32,    33,
      34,    35,    36,    30,    19,     2,     3,     4,     5,     0,
       0,     0,     0,   237,     0,    37,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,    29,    31,     0,    32,
      33,    34,    35,    36,    30,    19,     2,     3,     4,     5,
       0,     0,     0,     0,   238,     0,    37,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,    29,    31,     0,
      32,    33,    34,    35,    36,    30,    19,     2,     3,     4,
       5,     0,     0,     0,     0,   242,     0,    37,     0,     0,
       0,    67,    68,    69,    70,     0,     0,     0,     0,    31,
       0,    32,    33,    34,    35,    36,    71,   101,     0,    72,
       0,    73,    74,    67,    68,    69,    70,     0,    37,     0,
       0,     0,     0,    75,     0,     0,     0,     0,    71,   151,
       0,    72,     0,    73,    74,     0,     0,    76,    77,    78,
      79,    80,    81,     0,     0,    75,     0,     0,     0,     0,
      67,    68,    69,    70,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    71,     0,     0,    72,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,   130,   131,   132,   133,     0,     0,   134,   135,
     136,   137,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,   125,   126,   127,   128,   129,   143,     0,     0,
     130,   131,   132,   133,   148,   204,   134,   135,   136,   137,
     130,   131,   132,   133,     0,     0,   134,   135,   136,   137,
     125,   126,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,   130,   131,
     132,   133,     0,     0,   134,   135,   136,   137,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
     156,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       0,     0,   134,   135,   136,   137,     0,     0,     0,   130,
     131,   132,   133,     0,   188,   134,   135,   136,   137,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,     0,   130,   131,   132,
     133,     0,     0,   134,   135,   136,   137,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,   195,
       0,     0,     0,     0,     0,   130,   131,   132,   133,     0,
       0,   134,   135,   136,   137,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
       0,     0,     0,   130,   131,   132,   133,     0,     0,   134,
     135,   136,   137,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
       0,   130,   131,   132,   133,     0,     0,   134,   135,   136,
     137,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,   130,
     131,   132,   133,     0,     0,   134,   135,   136,   137,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,   201,     0,     0,     0,     0,     0,   130,   131,   132,
     133,     0,     0,   134,   135,   136,   137,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,   214,
     125,   126,   127,   128,   129,   130,   131,   132,   133,     0,
       0,   134,   135,   136,   137,   216,     0,     0,   130,   131,
     132,   133,     0,     0,   134,   135,   136,   137,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
     239,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       0,     0,   134,   135,   136,   137,     0,     0,     0,   130,
     131,   132,   133,     0,     0,   134,   135,   136,   137,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,     0,     0,   134,   135
  };

  const short
  Parser::yycheck_[] =
  {
      24,    63,     0,    38,    18,    18,     0,    21,    19,     7,
      72,    36,    21,    45,    20,    47,    29,    19,    53,    17,
      19,    22,    19,    43,    44,     4,    46,    36,    19,    27,
      54,    21,    18,    58,    18,    30,    61,     4,    21,    64,
      65,     1,    56,    57,     4,    59,    71,    61,    61,    60,
      75,   113,    12,    13,    14,    15,    16,    17,    60,    60,
      21,    60,    22,    60,    99,    60,    56,    57,    21,    59,
       7,     8,     9,    10,    11,    18,    36,    58,    38,    39,
      40,    41,    42,    18,    18,    18,    31,    85,    58,   114,
      27,     4,    58,    58,    58,    55,    58,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     4,   139,    18,    58,   142,    58,   144,
     145,   146,     9,    10,    11,   150,    58,     7,     8,     9,
      10,    11,    13,    14,    15,    16,    17,    58,    19,    18,
      27,    18,    18,     1,    18,    18,     4,    27,    28,    59,
      18,    31,    32,   215,    12,    13,    14,    15,    16,    17,
     184,   185,    18,    18,   189,    58,     4,   202,   203,     4,
       4,    32,    21,   198,     1,    59,    21,     4,    36,    18,
      38,    39,    40,    41,    42,    12,    13,    14,    15,    16,
      17,    19,    18,     4,    19,    22,   231,    55,   233,   234,
     224,    19,    21,    27,   228,   229,   241,   232,    59,    36,
      19,    38,    39,    40,    41,    42,   240,     4,     1,    29,
      37,     4,     7,     8,     9,    10,    11,    19,    55,    12,
      13,    14,    15,    16,    17,    19,    18,     7,   218,    22,
      25,    26,    27,    28,    21,    21,    31,    32,    33,     1,
      21,    66,     4,    36,   204,    38,    39,    40,    41,    42,
      12,    13,    14,    15,    16,    17,   218,    -1,   204,     7,
      22,    -1,    55,    13,    14,    15,    16,    17,    -1,    -1,
       1,    -1,    -1,     4,    36,    -1,    38,    39,    40,    41,
      42,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    -1,    55,    13,    14,    15,    16,    17,    -1,
      -1,     1,    -1,    -1,     4,    36,    -1,    38,    39,    40,
      41,    42,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,     4,    36,    -1,    38,    39,
      40,    41,    42,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,     4,    36,    -1,    38,
      39,    40,    41,    42,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,    36,    -1,
      38,    39,    40,    41,    42,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    -1,    55,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    41,    42,    18,    19,    -1,    21,
      -1,    23,    24,     3,     4,     5,     6,    -1,    55,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    18,    19,
      -1,    21,    -1,    23,    24,    -1,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    35,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    18,    -1,    -1,    21,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,     7,     8,     9,    10,    11,    22,    -1,    -1,
      25,    26,    27,    28,    19,    58,    31,    32,    33,    34,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,     7,     8,     9,    10,    11,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,     7,
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
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
       7,     8,     9,    10,    11,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    22,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,     7,     8,     9,    10,    11,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    14,    15,    16,    17,    63,    64,    65,    81,
      85,    20,     0,    65,    81,     4,    18,    18,    19,    13,
      19,    85,    87,    21,    21,     4,    19,    60,     1,     4,
      12,    36,    38,    39,    40,    41,    42,    55,    66,    67,
      68,    69,    70,    74,    75,    76,    77,    78,    79,    80,
      83,    84,    85,    66,    21,    85,    58,    18,    21,    56,
      57,    59,    61,    18,    18,    18,    18,     3,     4,     5,
       6,    18,    21,    23,    24,    35,    49,    50,    51,    52,
      53,    54,    82,    88,    89,    31,    22,    67,    58,    58,
      58,    58,    58,    58,    58,    58,    58,     4,    22,    66,
       4,    19,    86,    88,    88,    88,    43,    44,    46,    86,
      88,    88,    68,    18,    29,    61,    88,    86,    88,    18,
      18,    18,    18,    18,    18,     7,     8,     9,    10,    11,
      25,    26,    27,    28,    31,    32,    33,    34,    85,    59,
      22,    19,    60,    22,    18,    18,    18,    19,    19,    19,
      58,    19,    86,    88,    45,    47,    19,    22,     4,     4,
       4,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    32,    88,    88,
      59,    88,    88,    88,    21,    21,    88,    19,    30,    18,
      18,    19,    19,    19,    19,    19,    19,     4,    21,    19,
      19,    19,    66,    66,    58,    88,    19,    59,    88,    22,
      22,     4,    69,    80,    19,    29,    22,    37,    71,    72,
      73,    19,    19,    86,    21,    36,    72,    73,    21,    21,
      30,    66,    18,    66,    66,    22,    88,    22,    22,    19,
      21,    66,    22
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    73,    73,    74,    75,    75,    76,    77,    78,    78,
      78,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     7,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     4,     3,     8,     9,     8,     2,     1,
       8,     4,     0,     7,    11,    11,     1,     1,     9,     5,
       6,     6,     6,     4,     2,     2,     8,     7,     4,     3,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       2,     3,     5,     6,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4
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
  "VECTOR", "PRINT", "INCREMENTO", "FUNC", "CALL_EXP", "LLAMADAF",
  "RETORNO", "TYPES", "LISTAEXP", "LISTPARAM", "EXP", "PRIMITIVE", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   137,   137,   144,   152,   157,   166,   173,   178,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   195,   196,
     197,   198,   201,   204,   209,   210,   215,   216,   219,   220,
     223,   229,   230,   234,   238,   239,   243,   245,   249,   250,
     251,   252,   253,   255,   258,   259,   263,   264,   267,   268,
     271,   272,   275,   276,   279,   280,   281,   282,   283,   285,
     290,   297,   302,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   336,   337,   343,
     344,   345,   346,   347,   348,   349
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
#line 2934 "parser.cpp"

#line 352 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

