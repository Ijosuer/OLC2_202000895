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
#line 57 "parser.y"
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
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 662 "parser.cpp"
        break;

      case symbol_kind::S_id: // id
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 668 "parser.cpp"
        break;

      case symbol_kind::S_CADENA: // CADENA
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 674 "parser.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 680 "parser.cpp"
        break;

      case symbol_kind::S_suma: // suma
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 686 "parser.cpp"
        break;

      case symbol_kind::S_menos: // menos
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 692 "parser.cpp"
        break;

      case symbol_kind::S_mult: // mult
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 698 "parser.cpp"
        break;

      case symbol_kind::S_div: // div
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 704 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 710 "parser.cpp"
        break;

      case symbol_kind::S_tk_void: // tk_void
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 716 "parser.cpp"
        break;

      case symbol_kind::S_tk_int: // tk_int
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 722 "parser.cpp"
        break;

      case symbol_kind::S_tk_string: // tk_string
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 728 "parser.cpp"
        break;

      case symbol_kind::S_tk_float: // tk_float
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 734 "parser.cpp"
        break;

      case symbol_kind::S_tk_bool: // tk_bool
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 740 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARA: // tk_PARA
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 746 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARC: // tk_PARC
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 752 "parser.cpp"
        break;

      case symbol_kind::S_rmain: // rmain
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 758 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 764 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 770 "parser.cpp"
        break;

      case symbol_kind::S_tk_true: // tk_true
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 776 "parser.cpp"
        break;

      case symbol_kind::S_tk_false: // tk_false
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 782 "parser.cpp"
        break;

      case symbol_kind::S_tk_igualq: // tk_igualq
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 788 "parser.cpp"
        break;

      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 794 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 800 "parser.cpp"
        break;

      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 806 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 812 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 818 "parser.cpp"
        break;

      case symbol_kind::S_tk_menorq: // tk_menorq
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 824 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayorq: // tk_mayorq
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 830 "parser.cpp"
        break;

      case symbol_kind::S_tk_and: // tk_and
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 836 "parser.cpp"
        break;

      case symbol_kind::S_tk_or: // tk_or
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 842 "parser.cpp"
        break;

      case symbol_kind::S_tk_not: // tk_not
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 848 "parser.cpp"
        break;

      case symbol_kind::S_res_IF: // res_IF
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 854 "parser.cpp"
        break;

      case symbol_kind::S_res_ELSE: // res_ELSE
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 860 "parser.cpp"
        break;

      case symbol_kind::S_res_WHILE: // res_WHILE
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 866 "parser.cpp"
        break;

      case symbol_kind::S_res_FOR: // res_FOR
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 872 "parser.cpp"
        break;

      case symbol_kind::S_res_BREAK: // res_BREAK
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 878 "parser.cpp"
        break;

      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 884 "parser.cpp"
        break;

      case symbol_kind::S_res_RETURN: // res_RETURN
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 890 "parser.cpp"
        break;

      case symbol_kind::S_res_pushB: // res_pushB
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 896 "parser.cpp"
        break;

      case symbol_kind::S_res_pushF: // res_pushF
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 902 "parser.cpp"
        break;

      case symbol_kind::S_res_get: // res_get
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 908 "parser.cpp"
        break;

      case symbol_kind::S_res_remove: // res_remove
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 914 "parser.cpp"
        break;

      case symbol_kind::S_res_size: // res_size
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 920 "parser.cpp"
        break;

      case symbol_kind::S_res_struct: // res_struct
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 926 "parser.cpp"
        break;

      case symbol_kind::S_res_mean: // res_mean
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 932 "parser.cpp"
        break;

      case symbol_kind::S_res_median: // res_median
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 938 "parser.cpp"
        break;

      case symbol_kind::S_res_mode: // res_mode
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 944 "parser.cpp"
        break;

      case symbol_kind::S_res_atoi: // res_atoi
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 950 "parser.cpp"
        break;

      case symbol_kind::S_res_atof: // res_atof
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 956 "parser.cpp"
        break;

      case symbol_kind::S_res_iota: // res_iota
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 962 "parser.cpp"
        break;

      case symbol_kind::S_res_VECTOR: // res_VECTOR
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 968 "parser.cpp"
        break;

      case symbol_kind::S_mas_mas: // mas_mas
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 974 "parser.cpp"
        break;

      case symbol_kind::S_menos_menos: // menos_menos
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 980 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 986 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 992 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 998 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1004 "parser.cpp"
        break;

      case symbol_kind::S_DECLARAR: // DECLARAR
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1010 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1016 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1022 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1028 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1034 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1040 "parser.cpp"
        break;

      case symbol_kind::S_CONT: // CONT
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1046 "parser.cpp"
        break;

      case symbol_kind::S_VECTOR: // VECTOR
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1052 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1058 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENTO: // INCREMENTO
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1064 "parser.cpp"
        break;

      case symbol_kind::S_FUNC: // FUNC
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1070 "parser.cpp"
        break;

      case symbol_kind::S_LLAMADAF: // LLAMADAF
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1076 "parser.cpp"
        break;

      case symbol_kind::S_RETORNO: // RETORNO
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1082 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1088 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1094 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 106 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1100 "parser.cpp"
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
#line 114 "parser.y"
    {
      ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
      yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1449 "parser.cpp"
    break;

  case 3: // MAIN: tk_void rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 124 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1457 "parser.cpp"
    break;

  case 4: // LIST_INST: LIST_INST INSTRUCTION
#line 130 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1466 "parser.cpp"
    break;

  case 5: // LIST_INST: INSTRUCTION
#line 135 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1475 "parser.cpp"
    break;

  case 6: // INSTRUCTION: PRINT ';'
#line 141 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1481 "parser.cpp"
    break;

  case 7: // INSTRUCTION: DECLARAR ';'
#line 142 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1487 "parser.cpp"
    break;

  case 8: // INSTRUCTION: ASIGNAR ';'
#line 143 "parser.y"
                          {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1493 "parser.cpp"
    break;

  case 9: // INSTRUCTION: VECTOR ';'
#line 144 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1499 "parser.cpp"
    break;

  case 10: // INSTRUCTION: BREAK ';'
#line 145 "parser.y"
                        {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1505 "parser.cpp"
    break;

  case 11: // INSTRUCTION: CONT ';'
#line 146 "parser.y"
                       {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1511 "parser.cpp"
    break;

  case 12: // INSTRUCTION: RETORNO ';'
#line 147 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1517 "parser.cpp"
    break;

  case 13: // INSTRUCTION: INCREMENTO ';'
#line 148 "parser.y"
                             {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1523 "parser.cpp"
    break;

  case 14: // INSTRUCTION: LLAMADAF ';'
#line 149 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1529 "parser.cpp"
    break;

  case 15: // INSTRUCTION: FUNC
#line 150 "parser.y"
                    {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1535 "parser.cpp"
    break;

  case 16: // INSTRUCTION: WHILE
#line 151 "parser.y"
                     {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1541 "parser.cpp"
    break;

  case 17: // INSTRUCTION: FOR
#line 152 "parser.y"
                   {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1547 "parser.cpp"
    break;

  case 18: // INSTRUCTION: IF
#line 153 "parser.y"
                  {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1553 "parser.cpp"
    break;

  case 20: // DECLARAR: TYPES id
#line 157 "parser.y"
                    {std::cout<<"Declarando "<<yystack_[0].value.as < std::string > ()<<std::endl; }
#line 1559 "parser.cpp"
    break;

  case 21: // DECLARAR: TYPES id '=' EXP
#line 158 "parser.y"
                           {std::cout<<"Declarando con valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;
                            yylhs.value.as < instruction* > () = new declaracion(0,0,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1566 "parser.cpp"
    break;

  case 22: // ASIGNAR: id '=' EXP
#line 162 "parser.y"
                     {std::cout<<"Asignando valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;}
#line 1572 "parser.cpp"
    break;

  case 23: // ASIGNAR: id tk_LLAVA EXP tk_LLAVC '=' tk_LLAVA EXP tk_LLAVC
#line 163 "parser.y"
                                                               {std::cout<<"Asignando valor vector a: "<<yystack_[7].value.as < std::string > ()<<std::endl;}
#line 1578 "parser.cpp"
    break;

  case 24: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 168 "parser.y"
                                                             {std::cout<<"If sin nada "<<std::endl;}
#line 1584 "parser.cpp"
    break;

  case 25: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC res_ELSE IF
#line 169 "parser.y"
                                                                         {std::cout<<"If con elseif "<<std::endl;}
#line 1590 "parser.cpp"
    break;

  case 26: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC res_ELSE tk_LLAVA LIST_INST tk_LLAVC
#line 170 "parser.y"
                                                                                                  {std::cout<<"If con else "<<std::endl;}
#line 1596 "parser.cpp"
    break;

  case 27: // WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 173 "parser.y"
                                                                 {std::cout<<"While "<<std::endl;}
#line 1602 "parser.cpp"
    break;

  case 28: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 177 "parser.y"
                                                                                          {std::cout<<"FOR "<<std::endl;}
#line 1608 "parser.cpp"
    break;

  case 29: // BREAK: res_BREAK
#line 181 "parser.y"
                 {std::cout<<"Break"<<std::endl;}
#line 1614 "parser.cpp"
    break;

  case 30: // CONT: res_CONTINUE
#line 183 "parser.y"
                   {std::cout<<"continue"<<std::endl;}
#line 1620 "parser.cpp"
    break;

  case 31: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 187 "parser.y"
                                                                                 {std::cout<<"VECTOR con valores "<<std::endl;}
#line 1626 "parser.cpp"
    break;

  case 32: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id
#line 188 "parser.y"
                                                {std::cout<<"VECTOR empty "<<std::endl;}
#line 1632 "parser.cpp"
    break;

  case 33: // VECTOR: id '.' res_pushB tk_PARA EXP tk_PARC
#line 189 "parser.y"
                                             {std::cout<<"VECTOR.pushB "<<std::endl;}
#line 1638 "parser.cpp"
    break;

  case 34: // VECTOR: id '.' res_pushF tk_PARA EXP tk_PARC
#line 190 "parser.y"
                                             {std::cout<<"VECTOR.pushF "<<std::endl;}
#line 1644 "parser.cpp"
    break;

  case 35: // VECTOR: id '.' res_get tk_PARA EXP tk_PARC
#line 191 "parser.y"
                                           {std::cout<<"VECTOR.get "<<std::endl;}
#line 1650 "parser.cpp"
    break;

  case 36: // VECTOR: id '.' res_remove tk_PARA EXP tk_PARC
#line 192 "parser.y"
                                              {std::cout<<"VECTOR.remove "<<std::endl;}
#line 1656 "parser.cpp"
    break;

  case 37: // VECTOR: id '.' res_size tk_PARA tk_PARC
#line 193 "parser.y"
                                         {std::cout<<"VECTOR.size "<<std::endl;}
#line 1662 "parser.cpp"
    break;

  case 38: // PRINT: PRINTF tk_PARA EXP tk_PARC
#line 196 "parser.y"
                                   { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1668 "parser.cpp"
    break;

  case 39: // INCREMENTO: id mas_mas
#line 199 "parser.y"
                        {std::cout<<"masmas "<<std::endl;}
#line 1674 "parser.cpp"
    break;

  case 40: // INCREMENTO: id menos_menos
#line 200 "parser.y"
                             {std::cout<<"menosmenos "<<std::endl;}
#line 1680 "parser.cpp"
    break;

  case 41: // FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 203 "parser.y"
                                                                     {std::cout<<"funcion: "<<yystack_[6].value.as < std::string > ()<<std::endl;}
#line 1686 "parser.cpp"
    break;

  case 42: // FUNC: TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 204 "parser.y"
                                                           {std::cout<<"funcion: "<<yystack_[5].value.as < std::string > ()<<std::endl;}
#line 1692 "parser.cpp"
    break;

  case 43: // LLAMADAF: id tk_PARA LISTAEXP tk_PARC
#line 207 "parser.y"
                                      {std::cout<<"Llamando funcion: "<<yystack_[3].value.as < std::string > ()<<std::endl;}
#line 1698 "parser.cpp"
    break;

  case 44: // RETORNO: res_RETURN EXP
#line 210 "parser.y"
                        {std::cout<<"returno de : "<<yystack_[0].value.as < expression* > ()<<std::endl;}
#line 1704 "parser.cpp"
    break;

  case 45: // TYPES: tk_int
#line 213 "parser.y"
              { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1710 "parser.cpp"
    break;

  case 46: // TYPES: tk_string
#line 214 "parser.y"
                { yylhs.value.as < TipoDato > () = STRING; }
#line 1716 "parser.cpp"
    break;

  case 47: // TYPES: tk_float
#line 215 "parser.y"
               { yylhs.value.as < TipoDato > () = FLOAT; }
#line 1722 "parser.cpp"
    break;

  case 48: // TYPES: tk_bool
#line 216 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1728 "parser.cpp"
    break;

  case 53: // EXP: EXP suma EXP
#line 228 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1734 "parser.cpp"
    break;

  case 54: // EXP: EXP menos EXP
#line 229 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1740 "parser.cpp"
    break;

  case 55: // EXP: EXP mult EXP
#line 230 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1746 "parser.cpp"
    break;

  case 56: // EXP: EXP div EXP
#line 231 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1752 "parser.cpp"
    break;

  case 57: // EXP: EXP tk_menor_igual EXP
#line 232 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 1758 "parser.cpp"
    break;

  case 58: // EXP: EXP tk_menorq EXP
#line 233 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 1764 "parser.cpp"
    break;

  case 59: // EXP: EXP tk_mayor_igual EXP
#line 234 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 1770 "parser.cpp"
    break;

  case 60: // EXP: EXP tk_mayorq EXP
#line 235 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 1776 "parser.cpp"
    break;

  case 61: // EXP: EXP tk_igualq EXP
#line 236 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 1782 "parser.cpp"
    break;

  case 62: // EXP: EXP tk_diferenteq EXP
#line 237 "parser.y"
                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 1788 "parser.cpp"
    break;

  case 63: // EXP: EXP tk_and EXP
#line 238 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 1794 "parser.cpp"
    break;

  case 64: // EXP: EXP tk_or EXP
#line 239 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 1800 "parser.cpp"
    break;

  case 65: // EXP: EXP tk_not EXP
#line 240 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"); }
#line 1806 "parser.cpp"
    break;

  case 66: // EXP: tk_PARA EXP tk_PARC
#line 241 "parser.y"
                          { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 1812 "parser.cpp"
    break;

  case 67: // EXP: PRIMITIVE
#line 242 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1818 "parser.cpp"
    break;

  case 68: // PRIMITIVE: NUMERO
#line 245 "parser.y"
                   {  int num = stoi(yystack_[0].value.as < std::string > ()); yylhs.value.as < expression* > () = new primitive(0,0,INTEGER, "",num,false); }
#line 1824 "parser.cpp"
    break;

  case 69: // PRIMITIVE: CADENA
#line 247 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING,str2,0, false);
        }
#line 1834 "parser.cpp"
    break;

  case 70: // PRIMITIVE: id
#line 252 "parser.y"
               {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ());}
#line 1840 "parser.cpp"
    break;

  case 71: // PRIMITIVE: DECIMAL
#line 253 "parser.y"
                    {}
#line 1846 "parser.cpp"
    break;

  case 72: // PRIMITIVE: tk_true
#line 254 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,true); }
#line 1852 "parser.cpp"
    break;

  case 73: // PRIMITIVE: tk_false
#line 255 "parser.y"
                    { yylhs.value.as < expression* > () = new primitive(0,0,BOOL,"",0,false); }
#line 1858 "parser.cpp"
    break;

  case 74: // PRIMITIVE: res_mean tk_PARA id tk_PARC
#line 256 "parser.y"
                                      {std::cout<<"Media de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1864 "parser.cpp"
    break;

  case 75: // PRIMITIVE: res_median tk_PARA id tk_PARC
#line 257 "parser.y"
                                        {std::cout<<"Mediana de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1870 "parser.cpp"
    break;

  case 76: // PRIMITIVE: res_mode tk_PARA id tk_PARC
#line 258 "parser.y"
                                      {std::cout<<"Moda de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1876 "parser.cpp"
    break;


#line 1880 "parser.cpp"

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
       8,     4,    35,   -48,    28,   -48,    21,    32,     3,    -2,
      -9,    39,   -48,   -48,   -48,   -48,    41,    42,    55,   -48,
     -48,   324,    56,    95,   -48,    30,    34,   -48,   -48,   -48,
      40,    50,    58,    60,    65,   -48,    66,    72,    61,   -48,
     324,   324,   -48,   -48,   324,    25,   324,   324,   324,   148,
     -48,   -48,   -48,   -48,   324,   -48,   -48,    81,    88,    96,
     620,   -48,   148,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,    -8,    -6,   620,   335,   620,   114,
     120,   121,   122,   124,   368,   396,   424,    89,    85,   452,
     108,   143,   152,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   126,    48,   324,   -48,
     324,   101,   324,   324,   324,   324,   147,   -48,   146,   151,
     324,   109,   -48,   150,   155,   163,    -4,    -4,   157,   157,
      22,    22,   620,    22,    22,    22,   659,   631,   659,   184,
     169,   186,    -5,   620,   620,   176,   480,   508,   536,   564,
     -48,     3,     3,    94,   -48,   -48,   -48,   133,     3,   -48,
     177,   148,   324,   -48,   -48,   -48,   -48,   139,   171,   194,
     172,   203,     3,   195,   592,   166,   -48,   -19,   185,   324,
     -48,   235,   -48,   -48,   -10,   193,   -26,   -48,     3,   -48,
       3,   -48,   267,   299,   -48,   -48
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,    45,    46,    47,    48,     0,     0,     0,    29,
      30,     0,     0,     0,     5,     0,     0,    18,    16,    17,
       0,     0,     0,     0,     0,    15,     0,     0,     0,    19,
       0,     0,    39,    40,     0,     0,     0,     0,     0,     0,
      68,    70,    69,    71,     0,    72,    73,     0,     0,     0,
      44,    67,     0,     3,     4,     7,     8,    10,    11,     9,
       6,    13,    14,    12,    20,     0,    50,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,    20,    66,     0,     0,     0,    53,    54,    55,    56,
      61,    62,    59,    57,    58,    60,    63,    64,    65,     0,
       0,     0,     0,    21,    49,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    74,    75,    76,    32,     0,    52,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    27,     0,     0,     0,
      42,     0,    51,    23,     0,     0,     0,    41,     0,    25,
       0,    31,     0,     0,    26,    28
  };

  const short
  Parser::yypgoto_[] =
  {
     -48,   -48,   -48,    43,   -23,   156,   -48,    36,   -48,   -48,
     -48,   -48,   -48,   -48,    52,   -48,   -48,   -48,   -47,    44,
     -48,   -20,   -48
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     2,     3,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    75,
     142,    76,    61
  };

  const unsigned char
  Parser::yytable_[] =
  {
      64,    60,    88,   191,     9,    95,    96,    10,    40,   107,
     188,    41,   109,   160,    11,   106,    12,    13,    14,    15,
       1,    77,    99,     4,    78,    16,    84,    85,    86,    93,
      94,    95,    96,   110,    89,     5,    42,    43,    16,     7,
      17,    18,    19,    20,    21,     6,    42,    43,    99,    44,
     108,    45,     8,   110,   161,    39,    46,    22,    47,    48,
     141,    12,    13,    14,    15,    74,   140,    79,    80,    81,
      82,    83,    49,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    62,    65,   143,   121,
     144,    66,   146,   147,   148,   149,     9,    67,    90,    10,
     153,    93,    94,    95,    96,    91,    11,    68,    12,    13,
      14,    15,   123,    92,   173,    69,    63,    70,    97,    98,
      99,   100,    71,    72,   101,   102,   103,   104,   105,    73,
      16,   112,    17,    18,    19,    20,    21,   113,   114,   115,
       9,   116,   174,    10,    64,    64,   120,   124,    64,    22,
      11,   169,    12,    13,    14,    15,   125,   139,    64,   145,
     175,    12,    13,    14,    15,   150,   151,   108,   154,    64,
      64,   152,     9,   155,    16,    10,    17,    18,    19,    20,
      21,   156,    11,    99,    12,    13,    14,    15,   157,   158,
     159,   170,   176,    22,   167,   168,   162,   172,   177,   182,
     179,   171,   184,   185,     9,    87,    16,    10,    17,    18,
      19,    20,    21,   190,    11,   181,    12,    13,    14,    15,
     189,   178,     0,   186,   180,    22,     0,     0,     0,     0,
       0,   192,     0,   193,     0,     0,     9,     0,    16,    10,
      17,    18,    19,    20,    21,     0,    11,     0,    12,    13,
      14,    15,     0,     0,     0,     0,   187,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
      16,    10,    17,    18,    19,    20,    21,     0,    11,     0,
      12,    13,    14,    15,     0,     0,     0,     0,   194,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    16,    10,    17,    18,    19,    20,    21,     0,
      11,     0,    12,    13,    14,    15,     0,     0,     0,     0,
     195,    22,     0,     0,     0,     0,     0,    50,    51,    52,
      53,     0,     0,     0,    16,     0,    17,    18,    19,    20,
      21,    54,    93,    94,    95,    96,    55,    56,     0,     0,
       0,     0,     0,    22,     0,     0,   111,     0,     0,    97,
      98,    99,   100,     0,     0,   101,   102,   103,   104,   105,
       0,     0,    57,    58,    59,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,   101,   102,
     103,   104,   105,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,   118,     0,     0,     0,     0,     0,
      97,    98,    99,   100,     0,     0,   101,   102,   103,   104,
     105,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,   119,     0,     0,     0,     0,     0,    97,    98,
      99,   100,     0,     0,   101,   102,   103,   104,   105,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,    97,    98,    99,   100,
       0,     0,   101,   102,   103,   104,   105,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,     0,     0,    97,    98,    99,   100,     0,     0,
     101,   102,   103,   104,   105,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,     0,   164,     0,     0,     0,
       0,     0,    97,    98,    99,   100,     0,     0,   101,   102,
     103,   104,   105,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,   165,     0,     0,     0,     0,     0,
      97,    98,    99,   100,     0,     0,   101,   102,   103,   104,
     105,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,    97,    98,
      99,   100,     0,     0,   101,   102,   103,   104,   105,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,     0,     0,    97,    98,    99,   100,
       0,     0,   101,   102,   103,   104,   105,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,     0,     0,    97,    98,    99,   100,     0,     0,
     101,   102,   103,   104,   105,    97,    98,    99,   100,     0,
       0,   101,   102,   103,     0,   105,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,     0,     0,   101,
     102,     0,     0,   105
  };

  const short
  Parser::yycheck_[] =
  {
      23,    21,    49,    29,     1,     9,    10,     4,    17,    17,
      20,    20,    18,    18,    11,    62,    13,    14,    15,    16,
      12,    41,    26,    19,    44,    35,    46,    47,    48,     7,
       8,     9,    10,    59,    54,     0,    55,    56,    35,    18,
      37,    38,    39,    40,    41,    17,    55,    56,    26,    58,
      58,    60,    20,    59,    59,    57,    17,    54,    17,    17,
     107,    13,    14,    15,    16,     4,    18,    42,    43,    44,
      45,    46,    17,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    30,    57,   108,     4,
     110,    57,   112,   113,   114,   115,     1,    57,    17,     4,
     120,     7,     8,     9,    10,    17,    11,    57,    13,    14,
      15,    16,     4,    17,   161,    57,    21,    57,    24,    25,
      26,    27,    57,    57,    30,    31,    32,    33,    34,    57,
      35,    17,    37,    38,    39,    40,    41,    17,    17,    17,
       1,    17,   162,     4,   167,   168,    57,     4,   171,    54,
      11,    57,    13,    14,    15,    16,     4,    31,   181,    58,
      21,    13,    14,    15,    16,    18,    20,    58,    18,   192,
     193,    20,     1,    18,    35,     4,    37,    38,    39,    40,
      41,    18,    11,    26,    13,    14,    15,    16,     4,    20,
       4,    58,    21,    54,   151,   152,    20,    20,     4,     4,
      28,   158,    36,    18,     1,    49,    35,     4,    37,    38,
      39,    40,    41,    20,    11,   172,    13,    14,    15,    16,
     184,   169,    -1,   179,    21,    54,    -1,    -1,    -1,    -1,
      -1,   188,    -1,   190,    -1,    -1,     1,    -1,    35,     4,
      37,    38,    39,    40,    41,    -1,    11,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    21,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      35,     4,    37,    38,    39,    40,    41,    -1,    11,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    35,     4,    37,    38,    39,    40,    41,    -1,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      21,    54,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    35,    -1,    37,    38,    39,    40,
      41,    17,     7,     8,     9,    10,    22,    23,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    21,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    34,
      -1,    -1,    48,    49,    50,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    34,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      34,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    34,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    34,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    34,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      34,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    34,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    30,    31,    32,    33,    34,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    -1,    34,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      31,    -1,    -1,    34
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    12,    62,    63,    19,     0,    17,    18,    20,     1,
       4,    11,    13,    14,    15,    16,    35,    37,    38,    39,
      40,    41,    54,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    57,
      17,    20,    55,    56,    58,    60,    17,    17,    17,    17,
       3,     4,     5,     6,    17,    22,    23,    48,    49,    50,
      82,    83,    30,    21,    65,    57,    57,    57,    57,    57,
      57,    57,    57,    57,     4,    80,    82,    82,    82,    42,
      43,    44,    45,    46,    82,    82,    82,    66,    79,    82,
      17,    17,    17,     7,     8,     9,    10,    24,    25,    26,
      27,    30,    31,    32,    33,    34,    79,    17,    58,    18,
      59,    21,    17,    17,    17,    17,    17,    18,    18,    18,
      57,     4,    18,     4,     4,     4,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    31,
      18,    79,    81,    82,    82,    58,    82,    82,    82,    82,
      18,    20,    20,    82,    18,    18,    18,     4,    20,     4,
      18,    59,    20,    18,    18,    18,    18,    64,    64,    57,
      58,    64,    20,    79,    82,    21,    21,     4,    75,    28,
      21,    64,     4,    21,    36,    18,    80,    21,    20,    68,
      20,    29,    64,    64,    21,    21
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    61,    62,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    68,    68,    69,    70,    71,
      72,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    76,    76,    77,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     7,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     4,     3,     8,     7,     9,    11,     7,    11,     1,
       1,     9,     5,     6,     6,     6,     6,     5,     4,     2,
       2,     8,     7,     4,     2,     1,     1,     1,     1,     3,
       1,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "id", "CADENA",
  "DECIMAL", "suma", "menos", "mult", "div", "PRINTF", "tk_void", "tk_int",
  "tk_string", "tk_float", "tk_bool", "tk_PARA", "tk_PARC", "rmain",
  "tk_LLAVA", "tk_LLAVC", "tk_true", "tk_false", "tk_igualq",
  "tk_diferenteq", "tk_mayor_igual", "tk_menor_igual", "tk_CORCHA",
  "tk_CORCHC", "tk_menorq", "tk_mayorq", "tk_and", "tk_or", "tk_not",
  "res_IF", "res_ELSE", "res_WHILE", "res_FOR", "res_BREAK",
  "res_CONTINUE", "res_RETURN", "res_pushB", "res_pushF", "res_get",
  "res_remove", "res_size", "res_struct", "res_mean", "res_median",
  "res_mode", "res_atoi", "res_atof", "res_iota", "res_VECTOR", "mas_mas",
  "menos_menos", "';'", "'='", "','", "'.'", "$accept", "START", "MAIN",
  "LIST_INST", "INSTRUCTION", "DECLARAR", "ASIGNAR", "IF", "WHILE", "FOR",
  "BREAK", "CONT", "VECTOR", "PRINT", "INCREMENTO", "FUNC", "LLAMADAF",
  "RETORNO", "TYPES", "LISTAEXP", "LISTPARAM", "EXP", "PRIMITIVE", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   113,   113,   123,   129,   134,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     157,   158,   162,   163,   168,   169,   170,   173,   177,   181,
     183,   187,   188,   189,   190,   191,   192,   193,   196,   199,
     200,   203,   204,   207,   210,   213,   214,   215,   216,   220,
     221,   224,   225,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   245,   246,
     252,   253,   254,   255,   256,   257,   258
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
#line 2571 "parser.cpp"

#line 261 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

