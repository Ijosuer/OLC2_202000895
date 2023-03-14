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
#line 66 "parser.y"
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
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 718 "parser.cpp"
        break;

      case symbol_kind::S_id: // id
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 724 "parser.cpp"
        break;

      case symbol_kind::S_CADENA: // CADENA
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 730 "parser.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 736 "parser.cpp"
        break;

      case symbol_kind::S_suma: // suma
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 742 "parser.cpp"
        break;

      case symbol_kind::S_menos: // menos
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 748 "parser.cpp"
        break;

      case symbol_kind::S_mult: // mult
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 754 "parser.cpp"
        break;

      case symbol_kind::S_div: // div
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 760 "parser.cpp"
        break;

      case symbol_kind::S_modulo: // modulo
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 766 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 772 "parser.cpp"
        break;

      case symbol_kind::S_tk_void: // tk_void
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 778 "parser.cpp"
        break;

      case symbol_kind::S_tk_int: // tk_int
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 784 "parser.cpp"
        break;

      case symbol_kind::S_tk_string: // tk_string
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 790 "parser.cpp"
        break;

      case symbol_kind::S_tk_float: // tk_float
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 796 "parser.cpp"
        break;

      case symbol_kind::S_tk_bool: // tk_bool
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 802 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARA: // tk_PARA
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 808 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARC: // tk_PARC
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 814 "parser.cpp"
        break;

      case symbol_kind::S_rmain: // rmain
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 820 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 826 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 832 "parser.cpp"
        break;

      case symbol_kind::S_tk_true: // tk_true
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 838 "parser.cpp"
        break;

      case symbol_kind::S_tk_false: // tk_false
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 844 "parser.cpp"
        break;

      case symbol_kind::S_tk_igualq: // tk_igualq
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 850 "parser.cpp"
        break;

      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 856 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 862 "parser.cpp"
        break;

      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 868 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 874 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 880 "parser.cpp"
        break;

      case symbol_kind::S_tk_menorq: // tk_menorq
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 886 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayorq: // tk_mayorq
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 892 "parser.cpp"
        break;

      case symbol_kind::S_tk_and: // tk_and
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 898 "parser.cpp"
        break;

      case symbol_kind::S_tk_or: // tk_or
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 904 "parser.cpp"
        break;

      case symbol_kind::S_tk_not: // tk_not
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 910 "parser.cpp"
        break;

      case symbol_kind::S_res_IF: // res_IF
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 916 "parser.cpp"
        break;

      case symbol_kind::S_res_ELSE: // res_ELSE
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 922 "parser.cpp"
        break;

      case symbol_kind::S_res_WHILE: // res_WHILE
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 928 "parser.cpp"
        break;

      case symbol_kind::S_res_FOR: // res_FOR
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 934 "parser.cpp"
        break;

      case symbol_kind::S_res_BREAK: // res_BREAK
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 940 "parser.cpp"
        break;

      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 946 "parser.cpp"
        break;

      case symbol_kind::S_res_RETURN: // res_RETURN
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 952 "parser.cpp"
        break;

      case symbol_kind::S_res_pushB: // res_pushB
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 958 "parser.cpp"
        break;

      case symbol_kind::S_res_pushF: // res_pushF
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 964 "parser.cpp"
        break;

      case symbol_kind::S_res_get: // res_get
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 970 "parser.cpp"
        break;

      case symbol_kind::S_res_remove: // res_remove
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 976 "parser.cpp"
        break;

      case symbol_kind::S_res_size: // res_size
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 982 "parser.cpp"
        break;

      case symbol_kind::S_res_struct: // res_struct
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 988 "parser.cpp"
        break;

      case symbol_kind::S_res_mean: // res_mean
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 994 "parser.cpp"
        break;

      case symbol_kind::S_res_median: // res_median
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1000 "parser.cpp"
        break;

      case symbol_kind::S_res_mode: // res_mode
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1006 "parser.cpp"
        break;

      case symbol_kind::S_res_atoi: // res_atoi
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1012 "parser.cpp"
        break;

      case symbol_kind::S_res_atof: // res_atof
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1018 "parser.cpp"
        break;

      case symbol_kind::S_res_iota: // res_iota
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1024 "parser.cpp"
        break;

      case symbol_kind::S_res_VECTOR: // res_VECTOR
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1030 "parser.cpp"
        break;

      case symbol_kind::S_mas_mas: // mas_mas
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1036 "parser.cpp"
        break;

      case symbol_kind::S_menos_menos: // menos_menos
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1042 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1048 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1054 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1060 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1066 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1072 "parser.cpp"
        break;

      case symbol_kind::S_DECLARAR: // DECLARAR
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1078 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1084 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1090 "parser.cpp"
        break;

      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1096 "parser.cpp"
        break;

      case symbol_kind::S_ELIF: // ELIF
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1102 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1108 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1114 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1120 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1126 "parser.cpp"
        break;

      case symbol_kind::S_CONT: // CONT
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1132 "parser.cpp"
        break;

      case symbol_kind::S_VECTOR: // VECTOR
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1138 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1144 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENTO: // INCREMENTO
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1150 "parser.cpp"
        break;

      case symbol_kind::S_FUNC: // FUNC
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1156 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1162 "parser.cpp"
        break;

      case symbol_kind::S_LLAMADAF: // LLAMADAF
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1168 "parser.cpp"
        break;

      case symbol_kind::S_RETORNO: // RETORNO
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1174 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1180 "parser.cpp"
        break;

      case symbol_kind::S_LISTAEXP: // LISTAEXP
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1186 "parser.cpp"
        break;

      case symbol_kind::S_LISTPARAM: // LISTPARAM
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1192 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 123 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1198 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 123 "parser.y"
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
#line 131 "parser.y"
    {
      ctx.Main = yystack_[0].value.as < func_main* > ();
      ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
      yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1568 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 138 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1579 "parser.cpp"
    break;

  case 4: // LIST_FUNC: LIST_FUNC FUNC
#line 146 "parser.y"
            {
                yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
                yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > ();
            }
#line 1588 "parser.cpp"
    break;

  case 5: // LIST_FUNC: FUNC
#line 151 "parser.y"
         {
            yylhs.value.as < list_instruction* > ()= new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
         }
#line 1597 "parser.cpp"
    break;

  case 6: // MAIN: tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 160 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
    
}
#line 1606 "parser.cpp"
    break;

  case 7: // LIST_INST: LIST_INST INSTRUCTION
#line 167 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1615 "parser.cpp"
    break;

  case 8: // LIST_INST: INSTRUCTION
#line 172 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1624 "parser.cpp"
    break;

  case 9: // INSTRUCTION: PRINT ';'
#line 178 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1630 "parser.cpp"
    break;

  case 10: // INSTRUCTION: DECLARAR ';'
#line 179 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1636 "parser.cpp"
    break;

  case 11: // INSTRUCTION: ASIGNAR ';'
#line 180 "parser.y"
                          {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1642 "parser.cpp"
    break;

  case 12: // INSTRUCTION: VECTOR ';'
#line 181 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1648 "parser.cpp"
    break;

  case 13: // INSTRUCTION: BREAK ';'
#line 182 "parser.y"
                        {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1654 "parser.cpp"
    break;

  case 14: // INSTRUCTION: CONT ';'
#line 183 "parser.y"
                       {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1660 "parser.cpp"
    break;

  case 15: // INSTRUCTION: RETORNO ';'
#line 184 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1666 "parser.cpp"
    break;

  case 16: // INSTRUCTION: INCREMENTO ';'
#line 185 "parser.y"
                             {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1672 "parser.cpp"
    break;

  case 17: // INSTRUCTION: LLAMADAF ';'
#line 186 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1678 "parser.cpp"
    break;

  case 18: // INSTRUCTION: WHILE
#line 188 "parser.y"
                     {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1684 "parser.cpp"
    break;

  case 19: // INSTRUCTION: FOR
#line 189 "parser.y"
                   {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1690 "parser.cpp"
    break;

  case 20: // INSTRUCTION: IF
#line 190 "parser.y"
                  {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1696 "parser.cpp"
    break;

  case 21: // INSTRUCTION: error ';'
#line 191 "parser.y"
                       {}
#line 1702 "parser.cpp"
    break;

  case 22: // DECLARAR: TYPES id
#line 194 "parser.y"
                    {std::cout<<"Declarando "<<yystack_[0].value.as < std::string > ()<<std::endl; 
                            yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),new primitive(0,0,yystack_[1].value.as < TipoDato > (),"",0,0.0,0));
                    }
#line 1710 "parser.cpp"
    break;

  case 23: // DECLARAR: TYPES id '=' EXP
#line 197 "parser.y"
                           {std::cout<<"Declarando con valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;
                            yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());
                            }
#line 1718 "parser.cpp"
    break;

  case 24: // ASIGNAR: id '=' EXP
#line 202 "parser.y"
                     {std::cout<<"Asignando valor a "<<yystack_[2].value.as < std::string > ()<<std::endl; yylhs.value.as < instruction* > () = new asignacion(0,0,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1724 "parser.cpp"
    break;

  case 25: // ASIGNAR: id tk_LLAVA EXP tk_LLAVC '=' tk_LLAVA EXP tk_LLAVC
#line 203 "parser.y"
                                                               {std::cout<<"Asignando valor vector a: "<<yystack_[7].value.as < std::string > ()<<std::endl;}
#line 1730 "parser.cpp"
    break;

  case 26: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELIF_LIST ELSE
#line 208 "parser.y"
                                                                            {yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[6].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());}
#line 1736 "parser.cpp"
    break;

  case 27: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELSE
#line 209 "parser.y"
                                                                  {yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[5].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());}
#line 1742 "parser.cpp"
    break;

  case 28: // ELIF_LIST: ELIF_LIST ELIF
#line 212 "parser.y"
                          { yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1748 "parser.cpp"
    break;

  case 29: // ELIF_LIST: ELIF
#line 213 "parser.y"
                          { yylhs.value.as < list_instruction* > ()=new list_instruction(); yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); }
#line 1754 "parser.cpp"
    break;

  case 30: // ELIF: res_ELSE res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 217 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1762 "parser.cpp"
    break;

  case 31: // ELSE: res_ELSE tk_LLAVA LIST_INST tk_LLAVC
#line 222 "parser.y"
                                           { yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1768 "parser.cpp"
    break;

  case 32: // ELSE: %empty
#line 223 "parser.y"
             {}
#line 1774 "parser.cpp"
    break;

  case 33: // WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 227 "parser.y"
                                                                 {yylhs.value.as < instruction* > () = new func_while(0,0,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1780 "parser.cpp"
    break;

  case 34: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 231 "parser.y"
                                                                                          {std::cout<<"FOR "<<std::endl;}
#line 1786 "parser.cpp"
    break;

  case 35: // BREAK: res_BREAK
#line 235 "parser.y"
                 {std::cout<<"Break"<<std::endl;}
#line 1792 "parser.cpp"
    break;

  case 36: // CONT: res_CONTINUE
#line 237 "parser.y"
                   {std::cout<<"continue"<<std::endl;}
#line 1798 "parser.cpp"
    break;

  case 37: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 241 "parser.y"
                                                                                 {std::cout<<"VECTOR con valores "<<std::endl;}
#line 1804 "parser.cpp"
    break;

  case 38: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id
#line 242 "parser.y"
                                                {std::cout<<"VECTOR empty "<<std::endl;}
#line 1810 "parser.cpp"
    break;

  case 39: // VECTOR: id '.' res_pushB tk_PARA EXP tk_PARC
#line 243 "parser.y"
                                             {std::cout<<"VECTOR.pushB "<<std::endl;}
#line 1816 "parser.cpp"
    break;

  case 40: // VECTOR: id '.' res_pushF tk_PARA EXP tk_PARC
#line 244 "parser.y"
                                             {std::cout<<"VECTOR.pushF "<<std::endl;}
#line 1822 "parser.cpp"
    break;

  case 41: // VECTOR: id '.' res_get tk_PARA EXP tk_PARC
#line 245 "parser.y"
                                           {std::cout<<"VECTOR.get "<<std::endl;}
#line 1828 "parser.cpp"
    break;

  case 42: // VECTOR: id '.' res_remove tk_PARA EXP tk_PARC
#line 246 "parser.y"
                                              {std::cout<<"VECTOR.remove "<<std::endl;}
#line 1834 "parser.cpp"
    break;

  case 43: // VECTOR: id '.' res_size tk_PARA tk_PARC
#line 247 "parser.y"
                                         {std::cout<<"VECTOR.size "<<std::endl;}
#line 1840 "parser.cpp"
    break;

  case 44: // PRINT: PRINTF tk_PARA EXP tk_PARC
#line 250 "parser.y"
                                   { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1846 "parser.cpp"
    break;

  case 45: // INCREMENTO: id mas_mas
#line 253 "parser.y"
                        {std::cout<<"masmas "<<std::endl;}
#line 1852 "parser.cpp"
    break;

  case 46: // INCREMENTO: id menos_menos
#line 254 "parser.y"
                             {std::cout<<"menosmenos "<<std::endl;}
#line 1858 "parser.cpp"
    break;

  case 47: // FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 257 "parser.y"
                                                                     {yylhs.value.as < instruction* > ()=new function(0,0,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1864 "parser.cpp"
    break;

  case 48: // FUNC: TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 258 "parser.y"
                                                           {yylhs.value.as < instruction* > ()=new function(0,0,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());}
#line 1870 "parser.cpp"
    break;

  case 49: // CALL_EXP: id tk_PARA LISTAEXP tk_PARC
#line 261 "parser.y"
                                       { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 1876 "parser.cpp"
    break;

  case 50: // CALL_EXP: id tk_PARA tk_PARC
#line 262 "parser.y"
                            { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[2].value.as < std::string > (),nullptr); }
#line 1882 "parser.cpp"
    break;

  case 51: // LLAMADAF: id tk_PARA LISTAEXP tk_PARC
#line 265 "parser.y"
                                      {yylhs.value.as < instruction* > ()= new call_inst(0,0,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());}
#line 1888 "parser.cpp"
    break;

  case 52: // LLAMADAF: id tk_PARA tk_PARC
#line 266 "parser.y"
                             {yylhs.value.as < instruction* > ()= new call_inst(0,0,yystack_[2].value.as < std::string > (),nullptr);}
#line 1894 "parser.cpp"
    break;

  case 53: // RETORNO: res_RETURN EXP
#line 269 "parser.y"
                        {yylhs.value.as < instruction* > ()= new inst_return(0,0,yystack_[0].value.as < expression* > ());}
#line 1900 "parser.cpp"
    break;

  case 54: // RETORNO: res_RETURN
#line 270 "parser.y"
                      {yylhs.value.as < instruction* > ()= new inst_return(0,0,nullptr);}
#line 1906 "parser.cpp"
    break;

  case 55: // TYPES: tk_int
#line 273 "parser.y"
              { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1912 "parser.cpp"
    break;

  case 56: // TYPES: tk_string
#line 274 "parser.y"
                { yylhs.value.as < TipoDato > () = STRING; }
#line 1918 "parser.cpp"
    break;

  case 57: // TYPES: tk_float
#line 275 "parser.y"
               { yylhs.value.as < TipoDato > () = FLOAT; }
#line 1924 "parser.cpp"
    break;

  case 58: // TYPES: tk_bool
#line 276 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1930 "parser.cpp"
    break;

  case 59: // TYPES: tk_void
#line 277 "parser.y"
             { yylhs.value.as < TipoDato > () = NULO; }
#line 1936 "parser.cpp"
    break;

  case 60: // LISTAEXP: LISTAEXP ',' EXP
#line 280 "parser.y"
       {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1945 "parser.cpp"
    break;

  case 61: // LISTAEXP: EXP
#line 285 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1954 "parser.cpp"
    break;

  case 62: // LISTPARAM: LISTPARAM ',' TYPES id
#line 292 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > ()=yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1963 "parser.cpp"
    break;

  case 63: // LISTPARAM: TYPES id
#line 297 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
        }
#line 1972 "parser.cpp"
    break;

  case 64: // EXP: EXP suma EXP
#line 303 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1978 "parser.cpp"
    break;

  case 65: // EXP: EXP menos EXP
#line 304 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1984 "parser.cpp"
    break;

  case 66: // EXP: EXP mult EXP
#line 305 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1990 "parser.cpp"
    break;

  case 67: // EXP: EXP div EXP
#line 306 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1996 "parser.cpp"
    break;

  case 68: // EXP: EXP modulo EXP
#line 307 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 2002 "parser.cpp"
    break;

  case 69: // EXP: EXP tk_menor_igual EXP
#line 308 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 2008 "parser.cpp"
    break;

  case 70: // EXP: EXP tk_menorq EXP
#line 309 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 2014 "parser.cpp"
    break;

  case 71: // EXP: EXP tk_mayor_igual EXP
#line 310 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 2020 "parser.cpp"
    break;

  case 72: // EXP: EXP tk_mayorq EXP
#line 311 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 2026 "parser.cpp"
    break;

  case 73: // EXP: EXP tk_igualq EXP
#line 312 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 2032 "parser.cpp"
    break;

  case 74: // EXP: EXP tk_diferenteq EXP
#line 313 "parser.y"
                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 2038 "parser.cpp"
    break;

  case 75: // EXP: EXP tk_and EXP
#line 314 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 2044 "parser.cpp"
    break;

  case 76: // EXP: EXP tk_or EXP
#line 315 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 2050 "parser.cpp"
    break;

  case 77: // EXP: EXP tk_not EXP
#line 316 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"); }
#line 2056 "parser.cpp"
    break;

  case 78: // EXP: tk_PARA EXP tk_PARC
#line 317 "parser.y"
                          { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2062 "parser.cpp"
    break;

  case 79: // EXP: PRIMITIVE
#line 318 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2068 "parser.cpp"
    break;

  case 80: // EXP: CALL_EXP
#line 319 "parser.y"
      { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2074 "parser.cpp"
    break;

  case 81: // PRIMITIVE: NUMERO
#line 322 "parser.y"
                   {  int num = stoi(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(0,0,INTEGER, "",num,0.0,false); }
#line 2080 "parser.cpp"
    break;

  case 82: // PRIMITIVE: CADENA
#line 324 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING,str2,0,0.0, false);
        }
#line 2090 "parser.cpp"
    break;

  case 83: // PRIMITIVE: id
#line 329 "parser.y"
               {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ());}
#line 2096 "parser.cpp"
    break;

  case 84: // PRIMITIVE: DECIMAL
#line 330 "parser.y"
                    {float num = stof(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(0,0,FLOAT, "",0,num,false);}
#line 2102 "parser.cpp"
    break;

  case 85: // PRIMITIVE: tk_true
#line 331 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,0.0,true); }
#line 2108 "parser.cpp"
    break;

  case 86: // PRIMITIVE: tk_false
#line 332 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,0.0,false); }
#line 2114 "parser.cpp"
    break;

  case 87: // PRIMITIVE: res_mean tk_PARA id tk_PARC
#line 333 "parser.y"
                                      {std::cout<<"Media de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 2120 "parser.cpp"
    break;

  case 88: // PRIMITIVE: res_median tk_PARA id tk_PARC
#line 334 "parser.y"
                                        {std::cout<<"Mediana de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 2126 "parser.cpp"
    break;

  case 89: // PRIMITIVE: res_mode tk_PARA id tk_PARC
#line 335 "parser.y"
                                      {std::cout<<"Moda de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 2132 "parser.cpp"
    break;


#line 2136 "parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -110;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      59,    14,  -110,  -110,  -110,  -110,     7,    59,  -110,  -110,
      13,     4,  -110,  -110,  -110,    18,    12,   184,    19,  -110,
      21,    52,    -6,   360,   360,  -110,    37,   217,    25,   -13,
      47,    85,    90,    95,  -110,  -110,   414,    46,    11,  -110,
      56,    57,  -110,  -110,  -110,    58,    62,    63,    68,    69,
      70,    71,   132,   118,   360,   133,  -110,   385,   414,  -110,
    -110,   414,   218,   414,   414,   414,   217,  -110,   100,  -110,
    -110,   414,  -110,  -110,   120,   121,   124,  -110,   747,  -110,
     217,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,    89,  -110,   174,  -110,  -110,    -5,   747,   444,
     747,   135,   147,   148,   154,   159,   473,   502,   531,   122,
     407,   560,   177,   181,   189,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   163,
     414,  -110,  -110,   414,   143,   414,   414,   414,   414,   185,
    -110,   186,   187,   414,  -110,    -3,  -110,   192,   204,   206,
     114,   114,    -7,    -7,   747,    60,    60,   747,    60,    60,
      60,    53,   776,    53,   201,   747,   747,   203,   589,   618,
     647,   676,  -110,   360,   360,   136,  -110,  -110,  -110,  -110,
     167,   414,  -110,  -110,  -110,  -110,   205,   236,   224,   207,
     705,   198,  -110,    49,   219,   414,  -110,   -15,   198,  -110,
    -110,   221,   -19,   360,   237,  -110,  -110,   360,  -110,   267,
     414,   298,  -110,   734,  -110,   233,   360,   329,  -110
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    59,    55,    56,    57,    58,     0,     0,     2,     5,
       0,     0,     1,     3,     4,     0,     0,     0,     0,    59,
       0,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    36,    54,     0,     0,     8,
       0,     0,    20,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    81,    83,    82,
      84,     0,    85,    86,     0,     0,     0,    80,    53,    79,
       0,     6,     7,    10,    11,    13,    14,    12,     9,    16,
      17,    15,    22,    48,     0,    62,    52,     0,    61,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    51,     0,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,    50,     0,    78,     0,     0,     0,
      64,    65,    66,    67,    68,    73,    74,    71,    69,    70,
      72,    75,    76,    77,     0,    23,    60,     0,     0,     0,
       0,     0,    43,     0,     0,     0,    49,    87,    88,    89,
      38,     0,    39,    40,    41,    42,     0,     0,     0,     0,
       0,    32,    33,     0,     0,     0,    25,     0,    32,    29,
      27,     0,     0,     0,     0,    28,    26,     0,    37,     0,
       0,     0,    31,     0,    34,     0,     0,     0,    30
  };

  const short
  Parser::yypgoto_[] =
  {
    -110,  -110,  -110,   232,   -24,   -35,   190,  -110,  -110,  -110,
      61,    72,  -110,  -110,  -110,  -110,  -110,  -110,    78,   250,
    -110,  -110,  -110,     2,  -109,  -110,   -26,  -110
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     6,     7,     8,    38,    39,    40,    41,    42,   198,
     199,   200,    43,    44,    45,    46,    47,    48,    49,     9,
      77,    50,    51,    52,    97,    22,    98,    79
  };

  const unsigned char
  Parser::yytable_[] =
  {
      53,   145,    10,    82,   119,    57,   203,    12,    58,    10,
      78,   208,    28,    26,   132,    29,   176,    15,    82,    21,
     122,   204,    16,    30,    19,     2,     3,     4,     5,    55,
      94,    18,    99,    81,    11,   100,    17,   106,   107,   108,
      23,   133,    24,    59,    60,   111,    61,    31,    62,    32,
      33,    34,    35,    36,    27,   133,    25,   133,    54,    82,
     115,   116,   117,   118,   119,    63,    37,   115,   116,   117,
     118,   119,     1,     2,     3,     4,     5,    80,   120,   121,
     122,   123,   129,    56,   124,   125,   202,   122,   128,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    64,   165,    59,    60,   166,    65,   168,
     169,   170,   171,    66,    83,    84,    85,   175,   110,    28,
      86,    87,    29,   117,   118,   119,    88,    89,    90,    91,
      30,    19,     2,     3,     4,     5,    92,    95,   112,   113,
      93,   122,   114,   115,   116,   117,   118,   119,   130,   186,
     187,    82,    82,   135,    31,   190,    32,    33,    34,    35,
      36,   120,   121,   122,   123,   136,   137,   124,   125,   126,
     127,   128,   138,    37,    82,    28,    82,   139,    29,   209,
     143,   147,    82,   211,   213,   148,    30,    19,     2,     3,
       4,     5,   217,   149,   188,   164,   131,    19,     2,     3,
       4,     5,   167,    20,   172,   180,    28,   173,   174,    29,
      31,   177,    32,    33,    34,    35,    36,    30,    19,     2,
       3,     4,     5,   178,   181,   179,   189,   191,   193,    37,
      19,     2,     3,     4,     5,   197,   195,    28,   201,    13,
      29,    31,   207,    32,    33,    34,    35,    36,    30,    19,
       2,     3,     4,     5,   216,   210,   109,    14,   192,   205,
      37,   101,   102,   103,   104,   105,   194,     0,    28,     0,
     206,    29,    31,     0,    32,    33,    34,    35,    36,    30,
      19,     2,     3,     4,     5,     0,     0,     0,     0,   212,
       0,    37,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,    29,    31,     0,    32,    33,    34,    35,    36,
      30,    19,     2,     3,     4,     5,     0,     0,     0,     0,
     214,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,    29,    31,     0,    32,    33,    34,    35,
      36,    30,    19,     2,     3,     4,     5,     0,     0,     0,
       0,   218,     0,    37,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    29,    31,     0,    32,    33,    34,
      35,    36,    30,    19,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    67,    68,
      69,    70,     0,     0,     0,     0,    31,     0,    32,    33,
      34,    35,    36,    71,    96,     0,     0,     0,    72,    73,
      67,    68,    69,    70,     0,    37,     0,    67,    68,    69,
      70,     0,     0,     0,     0,    71,   144,     0,     0,     0,
      72,    73,    71,     0,    74,    75,    76,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,    74,    75,    76,     0,
       0,     0,     0,    74,    75,    76,   134,     0,     0,   120,
     121,   122,   123,     0,     0,   124,   125,   126,   127,   128,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,     0,     0,   120,   121,
     122,   123,     0,     0,   124,   125,   126,   127,   128,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,   120,   121,   122,
     123,     0,     0,   124,   125,   126,   127,   128,   115,   116,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,   124,   125,   126,   127,   128,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   146,
       0,     0,     0,     0,     0,   120,   121,   122,   123,     0,
       0,   124,   125,   126,   127,   128,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   182,     0,
       0,     0,     0,     0,   120,   121,   122,   123,     0,     0,
     124,   125,   126,   127,   128,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   183,     0,     0,
       0,     0,     0,   120,   121,   122,   123,     0,     0,   124,
     125,   126,   127,   128,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   184,     0,     0,     0,
       0,     0,   120,   121,   122,   123,     0,     0,   124,   125,
     126,   127,   128,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   185,     0,     0,     0,     0,
       0,   120,   121,   122,   123,     0,     0,   124,   125,   126,
     127,   128,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     120,   121,   122,   123,     0,     0,   124,   125,   126,   127,
     128,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   215,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,   124,   125,   126,   127,   128,
       0,     0,   120,   121,   122,   123,     0,     0,   124,   125,
     126,   127,   128,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,     0,     0,   124,   125,   126,
       0,   128
  };

  const short
  Parser::yycheck_[] =
  {
      24,   110,     0,    38,    11,    18,    21,     0,    21,     7,
      36,    30,     1,    19,    19,     4,    19,     4,    53,    17,
      27,    36,    18,    12,    13,    14,    15,    16,    17,    27,
      54,    19,    58,    22,    20,    61,    18,    63,    64,    65,
      21,    60,    21,    56,    57,    71,    59,    36,    61,    38,
      39,    40,    41,    42,    60,    60,     4,    60,    21,    94,
       7,     8,     9,    10,    11,    18,    55,     7,     8,     9,
      10,    11,    13,    14,    15,    16,    17,    31,    25,    26,
      27,    28,    80,    58,    31,    32,   195,    27,    35,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    18,   130,    56,    57,   133,    18,   135,
     136,   137,   138,    18,    58,    58,    58,   143,    18,     1,
      58,    58,     4,     9,    10,    11,    58,    58,    58,    58,
      12,    13,    14,    15,    16,    17,     4,     4,    18,    18,
      22,    27,    18,     7,     8,     9,    10,    11,    59,   173,
     174,   186,   187,    18,    36,   181,    38,    39,    40,    41,
      42,    25,    26,    27,    28,    18,    18,    31,    32,    33,
      34,    35,    18,    55,   209,     1,   211,    18,     4,   203,
      58,     4,   217,   207,   210,     4,    12,    13,    14,    15,
      16,    17,   216,     4,    58,    32,    22,    13,    14,    15,
      16,    17,    59,    19,    19,     4,     1,    21,    21,     4,
      36,    19,    38,    39,    40,    41,    42,    12,    13,    14,
      15,    16,    17,    19,    21,    19,    59,    22,     4,    55,
      13,    14,    15,    16,    17,    37,    29,     1,    19,     7,
       4,    36,    21,    38,    39,    40,    41,    42,    12,    13,
      14,    15,    16,    17,    21,    18,    66,     7,    22,   198,
      55,    43,    44,    45,    46,    47,   188,    -1,     1,    -1,
     198,     4,    36,    -1,    38,    39,    40,    41,    42,    12,
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
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    18,    19,    -1,    -1,    -1,    23,    24,
       3,     4,     5,     6,    -1,    55,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      23,    24,    18,    -1,    49,    50,    51,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,     9,    10,    11,    49,    50,    51,    -1,
      -1,    -1,    -1,    49,    50,    51,    22,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    31,    32,    33,    34,    35,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    34,    35,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    35,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    35,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      35,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,     7,     8,     9,    10,    11,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,    32,
      33,    34,    35,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      -1,    35
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
       6,    18,    23,    24,    49,    50,    51,    82,    88,    89,
      31,    22,    67,    58,    58,    58,    58,    58,    58,    58,
      58,    58,     4,    22,    66,     4,    19,    86,    88,    88,
      88,    43,    44,    45,    46,    47,    88,    88,    88,    68,
      18,    88,    18,    18,    18,     7,     8,     9,    10,    11,
      25,    26,    27,    28,    31,    32,    33,    34,    35,    85,
      59,    22,    19,    60,    22,    18,    18,    18,    18,    18,
      19,    19,    19,    58,    19,    86,    19,     4,     4,     4,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    32,    88,    88,    59,    88,    88,
      88,    88,    19,    21,    21,    88,    19,    19,    19,    19,
       4,    21,    19,    19,    19,    19,    66,    66,    58,    59,
      88,    22,    22,     4,    80,    29,    22,    37,    71,    72,
      73,    19,    86,    21,    36,    72,    73,    21,    30,    66,
      18,    66,    22,    88,    22,    19,    21,    66,    22
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    73,    73,    74,    75,    76,    77,    78,    78,    78,
      78,    78,    78,    78,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     7,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     4,     3,     8,     9,     8,     2,     1,
       8,     4,     0,     7,    11,     1,     1,     9,     5,     6,
       6,     6,     6,     5,     4,     2,     2,     8,     7,     4,
       3,     4,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4
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
       0,   130,   130,   137,   145,   150,   159,   166,   171,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   188,   189,
     190,   191,   194,   197,   202,   203,   208,   209,   212,   213,
     216,   222,   223,   227,   231,   235,   237,   241,   242,   243,
     244,   245,   246,   247,   250,   253,   254,   257,   258,   261,
     262,   265,   266,   269,   270,   273,   274,   275,   276,   277,
     279,   284,   291,   296,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   322,   323,   329,   330,   331,   332,   333,   334,   335
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
#line 2861 "parser.cpp"

#line 338 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

