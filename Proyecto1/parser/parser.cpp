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
#line 60 "parser.y"
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

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
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

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (that.value));
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

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (that.value);
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

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (that.value);
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
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 678 "parser.cpp"
        break;

      case symbol_kind::S_id: // id
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 684 "parser.cpp"
        break;

      case symbol_kind::S_CADENA: // CADENA
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 690 "parser.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 696 "parser.cpp"
        break;

      case symbol_kind::S_suma: // suma
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 702 "parser.cpp"
        break;

      case symbol_kind::S_menos: // menos
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 708 "parser.cpp"
        break;

      case symbol_kind::S_mult: // mult
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 714 "parser.cpp"
        break;

      case symbol_kind::S_div: // div
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 720 "parser.cpp"
        break;

      case symbol_kind::S_modulo: // modulo
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 726 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 732 "parser.cpp"
        break;

      case symbol_kind::S_tk_void: // tk_void
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 738 "parser.cpp"
        break;

      case symbol_kind::S_tk_int: // tk_int
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 744 "parser.cpp"
        break;

      case symbol_kind::S_tk_string: // tk_string
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 750 "parser.cpp"
        break;

      case symbol_kind::S_tk_float: // tk_float
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 756 "parser.cpp"
        break;

      case symbol_kind::S_tk_bool: // tk_bool
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 762 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARA: // tk_PARA
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 768 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARC: // tk_PARC
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 774 "parser.cpp"
        break;

      case symbol_kind::S_rmain: // rmain
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 780 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 786 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 792 "parser.cpp"
        break;

      case symbol_kind::S_tk_true: // tk_true
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 798 "parser.cpp"
        break;

      case symbol_kind::S_tk_false: // tk_false
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 804 "parser.cpp"
        break;

      case symbol_kind::S_tk_igualq: // tk_igualq
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 810 "parser.cpp"
        break;

      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 816 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 822 "parser.cpp"
        break;

      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 828 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 834 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 840 "parser.cpp"
        break;

      case symbol_kind::S_tk_menorq: // tk_menorq
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 846 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayorq: // tk_mayorq
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 852 "parser.cpp"
        break;

      case symbol_kind::S_tk_and: // tk_and
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 858 "parser.cpp"
        break;

      case symbol_kind::S_tk_or: // tk_or
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 864 "parser.cpp"
        break;

      case symbol_kind::S_tk_not: // tk_not
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 870 "parser.cpp"
        break;

      case symbol_kind::S_res_IF: // res_IF
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 876 "parser.cpp"
        break;

      case symbol_kind::S_res_ELSE: // res_ELSE
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 882 "parser.cpp"
        break;

      case symbol_kind::S_res_WHILE: // res_WHILE
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 888 "parser.cpp"
        break;

      case symbol_kind::S_res_FOR: // res_FOR
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 894 "parser.cpp"
        break;

      case symbol_kind::S_res_BREAK: // res_BREAK
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 900 "parser.cpp"
        break;

      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 906 "parser.cpp"
        break;

      case symbol_kind::S_res_RETURN: // res_RETURN
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 912 "parser.cpp"
        break;

      case symbol_kind::S_res_pushB: // res_pushB
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 918 "parser.cpp"
        break;

      case symbol_kind::S_res_pushF: // res_pushF
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 924 "parser.cpp"
        break;

      case symbol_kind::S_res_get: // res_get
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 930 "parser.cpp"
        break;

      case symbol_kind::S_res_remove: // res_remove
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 936 "parser.cpp"
        break;

      case symbol_kind::S_res_size: // res_size
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 942 "parser.cpp"
        break;

      case symbol_kind::S_res_struct: // res_struct
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 948 "parser.cpp"
        break;

      case symbol_kind::S_res_mean: // res_mean
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 954 "parser.cpp"
        break;

      case symbol_kind::S_res_median: // res_median
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 960 "parser.cpp"
        break;

      case symbol_kind::S_res_mode: // res_mode
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 966 "parser.cpp"
        break;

      case symbol_kind::S_res_atoi: // res_atoi
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 972 "parser.cpp"
        break;

      case symbol_kind::S_res_atof: // res_atof
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 978 "parser.cpp"
        break;

      case symbol_kind::S_res_iota: // res_iota
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 984 "parser.cpp"
        break;

      case symbol_kind::S_res_VECTOR: // res_VECTOR
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 990 "parser.cpp"
        break;

      case symbol_kind::S_mas_mas: // mas_mas
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 996 "parser.cpp"
        break;

      case symbol_kind::S_menos_menos: // menos_menos
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1002 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1008 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1014 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1020 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1026 "parser.cpp"
        break;

      case symbol_kind::S_DECLARAR: // DECLARAR
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1032 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1038 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1044 "parser.cpp"
        break;

      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1050 "parser.cpp"
        break;

      case symbol_kind::S_ELIF: // ELIF
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1056 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1062 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1068 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1074 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1080 "parser.cpp"
        break;

      case symbol_kind::S_CONT: // CONT
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1086 "parser.cpp"
        break;

      case symbol_kind::S_VECTOR: // VECTOR
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1092 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1098 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENTO: // INCREMENTO
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1104 "parser.cpp"
        break;

      case symbol_kind::S_FUNC: // FUNC
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1110 "parser.cpp"
        break;

      case symbol_kind::S_LLAMADAF: // LLAMADAF
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1116 "parser.cpp"
        break;

      case symbol_kind::S_RETORNO: // RETORNO
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1122 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1128 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1134 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 112 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1140 "parser.cpp"
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

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELIF_LIST: // ELIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< list_instruction* > ();
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
#line 120 "parser.y"
    {
      ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
      yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1493 "parser.cpp"
    break;

  case 3: // MAIN: tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 130 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1501 "parser.cpp"
    break;

  case 4: // LIST_INST: LIST_INST INSTRUCTION
#line 136 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1510 "parser.cpp"
    break;

  case 5: // LIST_INST: INSTRUCTION
#line 141 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1519 "parser.cpp"
    break;

  case 6: // INSTRUCTION: PRINT ';'
#line 147 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1525 "parser.cpp"
    break;

  case 7: // INSTRUCTION: DECLARAR ';'
#line 148 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1531 "parser.cpp"
    break;

  case 8: // INSTRUCTION: ASIGNAR ';'
#line 149 "parser.y"
                          {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1537 "parser.cpp"
    break;

  case 9: // INSTRUCTION: VECTOR ';'
#line 150 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1543 "parser.cpp"
    break;

  case 10: // INSTRUCTION: BREAK ';'
#line 151 "parser.y"
                        {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1549 "parser.cpp"
    break;

  case 11: // INSTRUCTION: CONT ';'
#line 152 "parser.y"
                       {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1555 "parser.cpp"
    break;

  case 12: // INSTRUCTION: RETORNO ';'
#line 153 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1561 "parser.cpp"
    break;

  case 13: // INSTRUCTION: INCREMENTO ';'
#line 154 "parser.y"
                             {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1567 "parser.cpp"
    break;

  case 14: // INSTRUCTION: LLAMADAF ';'
#line 155 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1573 "parser.cpp"
    break;

  case 15: // INSTRUCTION: FUNC
#line 156 "parser.y"
                    {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1579 "parser.cpp"
    break;

  case 16: // INSTRUCTION: WHILE
#line 157 "parser.y"
                     {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1585 "parser.cpp"
    break;

  case 17: // INSTRUCTION: FOR
#line 158 "parser.y"
                   {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1591 "parser.cpp"
    break;

  case 18: // INSTRUCTION: IF
#line 159 "parser.y"
                  {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1597 "parser.cpp"
    break;

  case 19: // INSTRUCTION: error ';'
#line 160 "parser.y"
                       {}
#line 1603 "parser.cpp"
    break;

  case 20: // DECLARAR: TYPES id
#line 163 "parser.y"
                    {std::cout<<"Declarando "<<yystack_[0].value.as < std::string > ()<<std::endl; 
                            yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),new primitive(0,0,yystack_[1].value.as < TipoDato > (),"",0,0.0,0));
                    }
#line 1611 "parser.cpp"
    break;

  case 21: // DECLARAR: TYPES id '=' EXP
#line 166 "parser.y"
                           {std::cout<<"Declarando con valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;
                            yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());
                            }
#line 1619 "parser.cpp"
    break;

  case 22: // ASIGNAR: id '=' EXP
#line 171 "parser.y"
                     {std::cout<<"Asignando valor a "<<yystack_[2].value.as < std::string > ()<<std::endl; yylhs.value.as < instruction* > () = new asignacion(0,0,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1625 "parser.cpp"
    break;

  case 23: // ASIGNAR: id tk_LLAVA EXP tk_LLAVC '=' tk_LLAVA EXP tk_LLAVC
#line 172 "parser.y"
                                                               {std::cout<<"Asignando valor vector a: "<<yystack_[7].value.as < std::string > ()<<std::endl;}
#line 1631 "parser.cpp"
    break;

  case 24: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELIF_LIST ELSE
#line 177 "parser.y"
                                                                            {yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[6].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());}
#line 1637 "parser.cpp"
    break;

  case 25: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC ELSE
#line 178 "parser.y"
                                                                  {yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[5].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());}
#line 1643 "parser.cpp"
    break;

  case 26: // ELIF_LIST: ELIF_LIST ELIF
#line 181 "parser.y"
                          { yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1649 "parser.cpp"
    break;

  case 27: // ELIF_LIST: ELIF
#line 182 "parser.y"
                          { yylhs.value.as < list_instruction* > ()=new list_instruction(); yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ()); }
#line 1655 "parser.cpp"
    break;

  case 28: // ELIF: res_ELSE res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 186 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1663 "parser.cpp"
    break;

  case 29: // ELSE: res_ELSE tk_LLAVA LIST_INST tk_LLAVC
#line 191 "parser.y"
                                           { yylhs.value.as < list_instruction* > ()=yystack_[1].value.as < list_instruction* > (); }
#line 1669 "parser.cpp"
    break;

  case 30: // ELSE: %empty
#line 192 "parser.y"
             {}
#line 1675 "parser.cpp"
    break;

  case 31: // WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 196 "parser.y"
                                                                 {yylhs.value.as < instruction* > () = new func_while(0,0,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1681 "parser.cpp"
    break;

  case 32: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 200 "parser.y"
                                                                                          {std::cout<<"FOR "<<std::endl;}
#line 1687 "parser.cpp"
    break;

  case 33: // BREAK: res_BREAK
#line 204 "parser.y"
                 {std::cout<<"Break"<<std::endl;}
#line 1693 "parser.cpp"
    break;

  case 34: // CONT: res_CONTINUE
#line 206 "parser.y"
                   {std::cout<<"continue"<<std::endl;}
#line 1699 "parser.cpp"
    break;

  case 35: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 210 "parser.y"
                                                                                 {std::cout<<"VECTOR con valores "<<std::endl;}
#line 1705 "parser.cpp"
    break;

  case 36: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id
#line 211 "parser.y"
                                                {std::cout<<"VECTOR empty "<<std::endl;}
#line 1711 "parser.cpp"
    break;

  case 37: // VECTOR: id '.' res_pushB tk_PARA EXP tk_PARC
#line 212 "parser.y"
                                             {std::cout<<"VECTOR.pushB "<<std::endl;}
#line 1717 "parser.cpp"
    break;

  case 38: // VECTOR: id '.' res_pushF tk_PARA EXP tk_PARC
#line 213 "parser.y"
                                             {std::cout<<"VECTOR.pushF "<<std::endl;}
#line 1723 "parser.cpp"
    break;

  case 39: // VECTOR: id '.' res_get tk_PARA EXP tk_PARC
#line 214 "parser.y"
                                           {std::cout<<"VECTOR.get "<<std::endl;}
#line 1729 "parser.cpp"
    break;

  case 40: // VECTOR: id '.' res_remove tk_PARA EXP tk_PARC
#line 215 "parser.y"
                                              {std::cout<<"VECTOR.remove "<<std::endl;}
#line 1735 "parser.cpp"
    break;

  case 41: // VECTOR: id '.' res_size tk_PARA tk_PARC
#line 216 "parser.y"
                                         {std::cout<<"VECTOR.size "<<std::endl;}
#line 1741 "parser.cpp"
    break;

  case 42: // PRINT: PRINTF tk_PARA EXP tk_PARC
#line 219 "parser.y"
                                   { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1747 "parser.cpp"
    break;

  case 43: // INCREMENTO: id mas_mas
#line 222 "parser.y"
                        {std::cout<<"masmas "<<std::endl;}
#line 1753 "parser.cpp"
    break;

  case 44: // INCREMENTO: id menos_menos
#line 223 "parser.y"
                             {std::cout<<"menosmenos "<<std::endl;}
#line 1759 "parser.cpp"
    break;

  case 45: // FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 226 "parser.y"
                                                                     {std::cout<<"funcion: "<<yystack_[6].value.as < std::string > ()<<std::endl;}
#line 1765 "parser.cpp"
    break;

  case 46: // FUNC: TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 227 "parser.y"
                                                           {std::cout<<"funcion: "<<yystack_[5].value.as < std::string > ()<<std::endl;}
#line 1771 "parser.cpp"
    break;

  case 47: // LLAMADAF: id tk_PARA LISTAEXP tk_PARC
#line 230 "parser.y"
                                      {std::cout<<"Llamando funcion: "<<yystack_[3].value.as < std::string > ()<<std::endl;}
#line 1777 "parser.cpp"
    break;

  case 48: // RETORNO: res_RETURN EXP
#line 233 "parser.y"
                        {std::cout<<"returno de : "<<yystack_[0].value.as < expression* > ()<<std::endl;}
#line 1783 "parser.cpp"
    break;

  case 49: // TYPES: tk_int
#line 236 "parser.y"
              { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1789 "parser.cpp"
    break;

  case 50: // TYPES: tk_string
#line 237 "parser.y"
                { yylhs.value.as < TipoDato > () = STRING; }
#line 1795 "parser.cpp"
    break;

  case 51: // TYPES: tk_float
#line 238 "parser.y"
               { yylhs.value.as < TipoDato > () = FLOAT; }
#line 1801 "parser.cpp"
    break;

  case 52: // TYPES: tk_bool
#line 239 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1807 "parser.cpp"
    break;

  case 57: // EXP: EXP suma EXP
#line 251 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1813 "parser.cpp"
    break;

  case 58: // EXP: EXP menos EXP
#line 252 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1819 "parser.cpp"
    break;

  case 59: // EXP: EXP mult EXP
#line 253 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1825 "parser.cpp"
    break;

  case 60: // EXP: EXP div EXP
#line 254 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1831 "parser.cpp"
    break;

  case 61: // EXP: EXP modulo EXP
#line 255 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 1837 "parser.cpp"
    break;

  case 62: // EXP: EXP tk_menor_igual EXP
#line 256 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 1843 "parser.cpp"
    break;

  case 63: // EXP: EXP tk_menorq EXP
#line 257 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 1849 "parser.cpp"
    break;

  case 64: // EXP: EXP tk_mayor_igual EXP
#line 258 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 1855 "parser.cpp"
    break;

  case 65: // EXP: EXP tk_mayorq EXP
#line 259 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 1861 "parser.cpp"
    break;

  case 66: // EXP: EXP tk_igualq EXP
#line 260 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 1867 "parser.cpp"
    break;

  case 67: // EXP: EXP tk_diferenteq EXP
#line 261 "parser.y"
                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 1873 "parser.cpp"
    break;

  case 68: // EXP: EXP tk_and EXP
#line 262 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 1879 "parser.cpp"
    break;

  case 69: // EXP: EXP tk_or EXP
#line 263 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 1885 "parser.cpp"
    break;

  case 70: // EXP: EXP tk_not EXP
#line 264 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"); }
#line 1891 "parser.cpp"
    break;

  case 71: // EXP: tk_PARA EXP tk_PARC
#line 265 "parser.y"
                          { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 1897 "parser.cpp"
    break;

  case 72: // EXP: PRIMITIVE
#line 266 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1903 "parser.cpp"
    break;

  case 73: // PRIMITIVE: NUMERO
#line 269 "parser.y"
                   {  int num = stoi(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(0,0,INTEGER, "",num,0.0,false); }
#line 1909 "parser.cpp"
    break;

  case 74: // PRIMITIVE: CADENA
#line 271 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING,str2,0,0.0, false);
        }
#line 1919 "parser.cpp"
    break;

  case 75: // PRIMITIVE: id
#line 276 "parser.y"
               {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ());}
#line 1925 "parser.cpp"
    break;

  case 76: // PRIMITIVE: DECIMAL
#line 277 "parser.y"
                    {float num = stof(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(0,0,FLOAT, "",0,num,false);}
#line 1931 "parser.cpp"
    break;

  case 77: // PRIMITIVE: tk_true
#line 278 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,0.0,true); }
#line 1937 "parser.cpp"
    break;

  case 78: // PRIMITIVE: tk_false
#line 279 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,0.0,false); }
#line 1943 "parser.cpp"
    break;

  case 79: // PRIMITIVE: res_mean tk_PARA id tk_PARC
#line 280 "parser.y"
                                      {std::cout<<"Media de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1949 "parser.cpp"
    break;

  case 80: // PRIMITIVE: res_median tk_PARA id tk_PARC
#line 281 "parser.y"
                                        {std::cout<<"Mediana de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1955 "parser.cpp"
    break;

  case 81: // PRIMITIVE: res_mode tk_PARA id tk_PARC
#line 282 "parser.y"
                                      {std::cout<<"Moda de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1961 "parser.cpp"
    break;


#line 1965 "parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -48;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      -9,     0,    13,   -48,     5,   -48,    17,    18,     2,    -4,
     -11,    33,   -48,   -48,   -48,   -48,    37,    38,    40,   -48,
     -48,   362,    28,    96,   -48,    14,    30,   -48,   -48,   -48,
      32,    34,    41,    49,    51,   -48,    56,    57,    94,   -48,
     362,   362,   -48,   -48,   362,    19,   362,   362,   362,   142,
     -48,   -48,   -48,   -48,   362,   -48,   -48,    42,    99,   101,
     712,   -48,   142,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -10,    -8,   712,   409,   712,   106,
     107,   113,   115,   121,   438,   467,   496,    90,   145,   525,
     150,   157,   158,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   132,   126,   362,
     -48,   362,   110,   362,   362,   362,   362,   152,   -48,   149,
     153,   362,   116,   -48,   160,   162,   163,    20,    20,    -2,
      -2,   712,    60,    60,   712,    60,    60,    60,   752,   741,
     752,   168,   156,   181,    -7,   712,   712,   167,   554,   583,
     612,   641,   -48,     2,     2,    95,   -48,   -48,   -48,   136,
       2,   -48,   179,   142,   362,   -48,   -48,   -48,   -48,   151,
     182,   197,   173,   213,     2,   199,   670,   170,   -48,   -24,
     186,   362,   -48,   244,   -48,   -48,     1,   170,   -48,   -48,
     187,   -25,   -48,     2,   191,   -48,   -48,     2,   -48,   275,
     362,   306,   -48,   699,   -48,   189,     2,   337,   -48
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,    49,    50,    51,    52,     0,     0,     0,    33,
      34,     0,     0,     0,     5,     0,     0,    18,    16,    17,
       0,     0,     0,     0,     0,    15,     0,     0,     0,    19,
       0,     0,    43,    44,     0,     0,     0,     0,     0,     0,
      73,    75,    74,    76,     0,    77,    78,     0,     0,     0,
      48,    72,     0,     3,     4,     7,     8,    10,    11,     9,
       6,    13,    14,    12,    20,     0,    54,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,    20,    71,     0,     0,     0,    57,    58,    59,
      60,    61,    66,    67,    64,    62,    63,    65,    68,    69,
      70,     0,     0,     0,     0,    21,    53,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    79,    80,    81,    36,
       0,    56,     0,     0,     0,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    31,     0,
       0,     0,    46,     0,    55,    23,     0,    30,    27,    25,
       0,     0,    45,     0,     0,    26,    24,     0,    35,     0,
       0,     0,    29,     0,    32,     0,     0,     0,    28
  };

  const short
  Parser::yypgoto_[] =
  {
     -48,   -48,   -48,   209,   -23,   164,   -48,   -48,   -48,    24,
      25,   -48,   -48,   -48,   -48,   -48,   -48,    44,   -48,   -48,
     -48,   -47,    35,   -48,   -20,   -48
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     2,     3,    23,    24,    25,    26,    27,   187,   188,
     189,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    75,   144,    76,    61
  };

  const unsigned char
  Parser::yytable_[] =
  {
      64,    60,    88,     9,     1,   198,    10,    40,   108,    97,
      41,   110,   162,     5,    11,   107,    12,    13,    14,    15,
       4,    77,   193,     6,    78,   100,    84,    85,    86,    95,
      96,    97,    42,    43,    89,   111,     7,   194,    16,     8,
      17,    18,    19,    20,    21,    42,    43,   100,    44,   109,
      45,    46,   111,   163,    39,    47,    48,    22,    49,    62,
      90,   143,    79,    80,    81,    82,    83,    93,    94,    95,
      96,    97,    65,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   100,    66,   145,
      67,   146,    68,   148,   149,   150,   151,     9,    74,    69,
      10,   155,    93,    94,    95,    96,    97,    70,    11,    71,
      12,    13,    14,    15,    72,    73,   175,    91,    63,    92,
      98,    99,   100,   101,   113,   114,   102,   103,   104,   105,
     106,   115,    16,   116,    17,    18,    19,    20,    21,   117,
      12,    13,    14,    15,   176,   142,    64,    64,   121,   122,
      64,    22,     9,   171,   124,    10,    12,    13,    14,    15,
      64,   125,   126,    11,   141,    12,    13,    14,    15,   147,
     153,   152,   159,   177,   154,   109,    64,   160,    64,   156,
     203,   157,   158,     9,    64,   161,    10,    16,   164,    17,
      18,    19,    20,    21,    11,   172,    12,    13,    14,    15,
     174,   179,   181,   184,   178,   190,    22,   186,   197,   200,
     206,   195,   196,    87,     9,   180,   191,    10,    16,     0,
      17,    18,    19,    20,    21,    11,     0,    12,    13,    14,
      15,     0,     0,     0,     0,   182,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     0,    10,    16,
       0,    17,    18,    19,    20,    21,    11,     0,    12,    13,
      14,    15,     0,     0,     0,     0,   192,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,    10,
      16,     0,    17,    18,    19,    20,    21,    11,     0,    12,
      13,    14,    15,     0,     0,     0,     0,   202,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     9,     0,     0,
      10,    16,     0,    17,    18,    19,    20,    21,    11,     0,
      12,    13,    14,    15,     0,     0,     0,     0,   204,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     9,     0,
       0,    10,    16,     0,    17,    18,    19,    20,    21,    11,
       0,    12,    13,    14,    15,     0,     0,     0,     0,   208,
       0,    22,   169,   170,     0,    50,    51,    52,    53,   173,
       0,     0,     0,    16,     0,    17,    18,    19,    20,    21,
      54,     0,     0,   183,     0,    55,    56,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,     0,   201,     0,     0,     0,
       0,    57,    58,    59,     0,   207,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,    98,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,   118,     0,     0,
       0,     0,     0,    98,    99,   100,   101,     0,     0,   102,
     103,   104,   105,   106,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     0,     0,
       0,     0,    98,    99,   100,   101,     0,     0,   102,   103,
     104,   105,   106,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,   120,     0,     0,     0,     0,
       0,    98,    99,   100,   101,     0,     0,   102,   103,   104,
     105,   106,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
      98,    99,   100,   101,     0,     0,   102,   103,   104,   105,
     106,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,     0,    98,
      99,   100,   101,     0,     0,   102,   103,   104,   105,   106,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,    98,    99,
     100,   101,     0,     0,   102,   103,   104,   105,   106,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,     0,     0,    98,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,     0,
     168,     0,     0,     0,     0,     0,    98,    99,   100,   101,
       0,     0,   102,   103,   104,   105,   106,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,     0,     0,    98,    99,   100,   101,     0,
       0,   102,   103,   104,   105,   106,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,     0,   205,    93,
      94,    95,    96,    97,    98,    99,   100,   101,     0,     0,
     102,   103,   104,   105,   106,     0,     0,    98,    99,   100,
     101,     0,     0,   102,   103,   104,   105,   106,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,    98,    99,   100,   101,
       0,     0,   102,   103,   104,     0,   106,    98,    99,   100,
     101,     0,     0,   102,   103,     0,     0,   106
  };

  const short
  Parser::yycheck_[] =
  {
      23,    21,    49,     1,    13,    30,     4,    18,    18,    11,
      21,    19,    19,     0,    12,    62,    14,    15,    16,    17,
      20,    41,    21,    18,    44,    27,    46,    47,    48,     9,
      10,    11,    56,    57,    54,    60,    19,    36,    36,    21,
      38,    39,    40,    41,    42,    56,    57,    27,    59,    59,
      61,    18,    60,    60,    58,    18,    18,    55,    18,    31,
      18,   108,    43,    44,    45,    46,    47,     7,     8,     9,
      10,    11,    58,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    27,    58,   109,
      58,   111,    58,   113,   114,   115,   116,     1,     4,    58,
       4,   121,     7,     8,     9,    10,    11,    58,    12,    58,
      14,    15,    16,    17,    58,    58,   163,    18,    22,    18,
      25,    26,    27,    28,    18,    18,    31,    32,    33,    34,
      35,    18,    36,    18,    38,    39,    40,    41,    42,    18,
      14,    15,    16,    17,   164,    19,   169,   170,    58,     4,
     173,    55,     1,    58,     4,     4,    14,    15,    16,    17,
     183,     4,     4,    12,    32,    14,    15,    16,    17,    59,
      21,    19,     4,    22,    21,    59,   199,    21,   201,    19,
     200,    19,    19,     1,   207,     4,     4,    36,    21,    38,
      39,    40,    41,    42,    12,    59,    14,    15,    16,    17,
      21,     4,    29,     4,    22,    19,    55,    37,    21,    18,
      21,   187,   187,    49,     1,   171,   181,     4,    36,    -1,
      38,    39,    40,    41,    42,    12,    -1,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,     4,    36,
      -1,    38,    39,    40,    41,    42,    12,    -1,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,     4,
      36,    -1,    38,    39,    40,    41,    42,    12,    -1,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
       4,    36,    -1,    38,    39,    40,    41,    42,    12,    -1,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,     4,    36,    -1,    38,    39,    40,    41,    42,    12,
      -1,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      -1,    55,   153,   154,    -1,     3,     4,     5,     6,   160,
      -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,    42,
      18,    -1,    -1,   174,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,   206,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
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
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    31,    32,    33,    34,
      35,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,
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
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,     7,
       8,     9,    10,    11,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    35,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    31,    32,    33,    -1,    35,    25,    26,    27,
      28,    -1,    -1,    31,    32,    -1,    -1,    35
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    63,    64,    20,     0,    18,    19,    21,     1,
       4,    12,    14,    15,    16,    17,    36,    38,    39,    40,
      41,    42,    55,    65,    66,    67,    68,    69,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    58,
      18,    21,    56,    57,    59,    61,    18,    18,    18,    18,
       3,     4,     5,     6,    18,    23,    24,    49,    50,    51,
      86,    87,    31,    22,    66,    58,    58,    58,    58,    58,
      58,    58,    58,    58,     4,    84,    86,    86,    86,    43,
      44,    45,    46,    47,    86,    86,    86,    67,    83,    86,
      18,    18,    18,     7,     8,     9,    10,    11,    25,    26,
      27,    28,    31,    32,    33,    34,    35,    83,    18,    59,
      19,    60,    22,    18,    18,    18,    18,    18,    19,    19,
      19,    58,     4,    19,     4,     4,     4,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    32,    19,    83,    85,    86,    86,    59,    86,    86,
      86,    86,    19,    21,    21,    86,    19,    19,    19,     4,
      21,     4,    19,    60,    21,    19,    19,    19,    19,    65,
      65,    58,    59,    65,    21,    83,    86,    22,    22,     4,
      79,    29,    22,    65,     4,    22,    37,    70,    71,    72,
      19,    84,    22,    21,    36,    71,    72,    21,    30,    65,
      18,    65,    22,    86,    22,    19,    21,    65,    22
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    62,    63,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    73,    74,    75,    76,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    79,    80,    80,    81,    82,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     7,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     4,     3,     8,     9,     8,     2,     1,     8,     4,
       0,     7,    11,     1,     1,     9,     5,     6,     6,     6,
       6,     5,     4,     2,     2,     8,     7,     4,     2,     1,
       1,     1,     1,     3,     1,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4
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
  "menos_menos", "';'", "'='", "','", "'.'", "$accept", "START", "MAIN",
  "LIST_INST", "INSTRUCTION", "DECLARAR", "ASIGNAR", "IF", "ELIF_LIST",
  "ELIF", "ELSE", "WHILE", "FOR", "BREAK", "CONT", "VECTOR", "PRINT",
  "INCREMENTO", "FUNC", "LLAMADAF", "RETORNO", "TYPES", "LISTAEXP",
  "LISTPARAM", "EXP", "PRIMITIVE", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   119,   119,   129,   135,   140,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     163,   166,   171,   172,   177,   178,   181,   182,   185,   191,
     192,   196,   200,   204,   206,   210,   211,   212,   213,   214,
     215,   216,   219,   222,   223,   226,   227,   230,   233,   236,
     237,   238,   239,   243,   244,   247,   248,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   269,   270,   276,   277,   278,   279,   280,
     281,   282
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
#line 2681 "parser.cpp"

#line 285 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

