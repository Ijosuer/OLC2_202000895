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
#line 55 "parser.y"
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
      case symbol_kind::S_TYPES: // TYPES
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
      case symbol_kind::S_TYPES: // TYPES
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
      case symbol_kind::S_TYPES: // TYPES
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
      case symbol_kind::S_TYPES: // TYPES
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
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 642 "parser.cpp"
        break;

      case symbol_kind::S_id: // id
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 648 "parser.cpp"
        break;

      case symbol_kind::S_CADENA: // CADENA
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 654 "parser.cpp"
        break;

      case symbol_kind::S_DECIMAL: // DECIMAL
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 660 "parser.cpp"
        break;

      case symbol_kind::S_suma: // suma
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 666 "parser.cpp"
        break;

      case symbol_kind::S_menos: // menos
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 672 "parser.cpp"
        break;

      case symbol_kind::S_mult: // mult
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 678 "parser.cpp"
        break;

      case symbol_kind::S_div: // div
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 684 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 690 "parser.cpp"
        break;

      case symbol_kind::S_tk_void: // tk_void
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 696 "parser.cpp"
        break;

      case symbol_kind::S_tk_int: // tk_int
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 702 "parser.cpp"
        break;

      case symbol_kind::S_tk_string: // tk_string
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 708 "parser.cpp"
        break;

      case symbol_kind::S_tk_float: // tk_float
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 714 "parser.cpp"
        break;

      case symbol_kind::S_tk_bool: // tk_bool
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 720 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARA: // tk_PARA
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 726 "parser.cpp"
        break;

      case symbol_kind::S_tk_PARC: // tk_PARC
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 732 "parser.cpp"
        break;

      case symbol_kind::S_rmain: // rmain
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 738 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVA: // tk_LLAVA
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 744 "parser.cpp"
        break;

      case symbol_kind::S_tk_LLAVC: // tk_LLAVC
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 750 "parser.cpp"
        break;

      case symbol_kind::S_tk_true: // tk_true
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 756 "parser.cpp"
        break;

      case symbol_kind::S_tk_false: // tk_false
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 762 "parser.cpp"
        break;

      case symbol_kind::S_tk_igualq: // tk_igualq
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 768 "parser.cpp"
        break;

      case symbol_kind::S_tk_diferenteq: // tk_diferenteq
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 774 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayor_igual: // tk_mayor_igual
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 780 "parser.cpp"
        break;

      case symbol_kind::S_tk_menor_igual: // tk_menor_igual
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 786 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHA: // tk_CORCHA
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 792 "parser.cpp"
        break;

      case symbol_kind::S_tk_CORCHC: // tk_CORCHC
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 798 "parser.cpp"
        break;

      case symbol_kind::S_tk_menorq: // tk_menorq
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 804 "parser.cpp"
        break;

      case symbol_kind::S_tk_mayorq: // tk_mayorq
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 810 "parser.cpp"
        break;

      case symbol_kind::S_tk_and: // tk_and
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 816 "parser.cpp"
        break;

      case symbol_kind::S_tk_or: // tk_or
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 822 "parser.cpp"
        break;

      case symbol_kind::S_tk_not: // tk_not
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 828 "parser.cpp"
        break;

      case symbol_kind::S_res_IF: // res_IF
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 834 "parser.cpp"
        break;

      case symbol_kind::S_res_ELSE: // res_ELSE
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 840 "parser.cpp"
        break;

      case symbol_kind::S_res_WHILE: // res_WHILE
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 846 "parser.cpp"
        break;

      case symbol_kind::S_res_FOR: // res_FOR
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 852 "parser.cpp"
        break;

      case symbol_kind::S_res_BREAK: // res_BREAK
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 858 "parser.cpp"
        break;

      case symbol_kind::S_res_CONTINUE: // res_CONTINUE
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 864 "parser.cpp"
        break;

      case symbol_kind::S_res_RETURN: // res_RETURN
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 870 "parser.cpp"
        break;

      case symbol_kind::S_res_pushB: // res_pushB
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 876 "parser.cpp"
        break;

      case symbol_kind::S_res_pushF: // res_pushF
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 882 "parser.cpp"
        break;

      case symbol_kind::S_res_get: // res_get
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 888 "parser.cpp"
        break;

      case symbol_kind::S_res_remove: // res_remove
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 894 "parser.cpp"
        break;

      case symbol_kind::S_res_size: // res_size
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 900 "parser.cpp"
        break;

      case symbol_kind::S_res_struct: // res_struct
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 906 "parser.cpp"
        break;

      case symbol_kind::S_res_mean: // res_mean
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 912 "parser.cpp"
        break;

      case symbol_kind::S_res_median: // res_median
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 918 "parser.cpp"
        break;

      case symbol_kind::S_res_mode: // res_mode
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 924 "parser.cpp"
        break;

      case symbol_kind::S_res_atoi: // res_atoi
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 930 "parser.cpp"
        break;

      case symbol_kind::S_res_atof: // res_atof
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 936 "parser.cpp"
        break;

      case symbol_kind::S_res_iota: // res_iota
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 942 "parser.cpp"
        break;

      case symbol_kind::S_res_VECTOR: // res_VECTOR
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 948 "parser.cpp"
        break;

      case symbol_kind::S_mas_mas: // mas_mas
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 954 "parser.cpp"
        break;

      case symbol_kind::S_menos_menos: // menos_menos
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 960 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 966 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 972 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 978 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 984 "parser.cpp"
        break;

      case symbol_kind::S_DECLARAR: // DECLARAR
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 990 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 996 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1002 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1008 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1014 "parser.cpp"
        break;

      case symbol_kind::S_VECTOR: // VECTOR
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1020 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1026 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENTO: // INCREMENTO
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1032 "parser.cpp"
        break;

      case symbol_kind::S_FUNC: // FUNC
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1038 "parser.cpp"
        break;

      case symbol_kind::S_LLAMADAF: // LLAMADAF
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1044 "parser.cpp"
        break;

      case symbol_kind::S_RETORNO: // RETORNO
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1050 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1056 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1062 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 102 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1068 "parser.cpp"
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
      case symbol_kind::S_TYPES: // TYPES
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
#line 110 "parser.y"
    {
      ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
      yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1412 "parser.cpp"
    break;

  case 3: // MAIN: TYPES rmain tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 120 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1420 "parser.cpp"
    break;

  case 4: // LIST_INST: LIST_INST INSTRUCTION
#line 126 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1429 "parser.cpp"
    break;

  case 5: // LIST_INST: INSTRUCTION
#line 131 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1438 "parser.cpp"
    break;

  case 6: // INSTRUCTION: PRINT ';'
#line 137 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1444 "parser.cpp"
    break;

  case 7: // INSTRUCTION: DECLARAR ';'
#line 138 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1450 "parser.cpp"
    break;

  case 8: // INSTRUCTION: ASIGNAR ';'
#line 139 "parser.y"
                          {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1456 "parser.cpp"
    break;

  case 9: // INSTRUCTION: VECTOR ';'
#line 140 "parser.y"
                         {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1462 "parser.cpp"
    break;

  case 10: // INSTRUCTION: INCREMENTO ';'
#line 141 "parser.y"
                             {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1468 "parser.cpp"
    break;

  case 11: // INSTRUCTION: LLAMADAF ';'
#line 142 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1474 "parser.cpp"
    break;

  case 12: // INSTRUCTION: FUNC
#line 143 "parser.y"
                    {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1480 "parser.cpp"
    break;

  case 13: // INSTRUCTION: WHILE
#line 144 "parser.y"
                     {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1486 "parser.cpp"
    break;

  case 14: // INSTRUCTION: RETORNO ';'
#line 145 "parser.y"
                           {yylhs.value.as < instruction* > ()=yystack_[1].value.as < instruction* > ();}
#line 1492 "parser.cpp"
    break;

  case 15: // INSTRUCTION: FOR
#line 146 "parser.y"
                   {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1498 "parser.cpp"
    break;

  case 16: // INSTRUCTION: IF
#line 147 "parser.y"
                  {yylhs.value.as < instruction* > ()=yystack_[0].value.as < instruction* > ();}
#line 1504 "parser.cpp"
    break;

  case 18: // DECLARAR: TYPES id
#line 151 "parser.y"
                    {std::cout<<"Declarando "<<yystack_[0].value.as < std::string > ()<<std::endl;}
#line 1510 "parser.cpp"
    break;

  case 19: // DECLARAR: TYPES id '=' EXP
#line 152 "parser.y"
                           {std::cout<<"Declarando con valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;}
#line 1516 "parser.cpp"
    break;

  case 20: // ASIGNAR: id '=' EXP
#line 155 "parser.y"
                     {std::cout<<"Asignando valor a "<<yystack_[2].value.as < std::string > ()<<std::endl;}
#line 1522 "parser.cpp"
    break;

  case 21: // ASIGNAR: id tk_LLAVA EXP tk_LLAVC '=' tk_LLAVA EXP tk_LLAVC
#line 156 "parser.y"
                                                               {std::cout<<"Asignando valor vector a: "<<yystack_[7].value.as < std::string > ()<<std::endl;}
#line 1528 "parser.cpp"
    break;

  case 22: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 161 "parser.y"
                                                             {std::cout<<"If sin nada "<<std::endl;}
#line 1534 "parser.cpp"
    break;

  case 23: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC res_ELSE IF
#line 162 "parser.y"
                                                                         {std::cout<<"If con elseif "<<std::endl;}
#line 1540 "parser.cpp"
    break;

  case 24: // IF: res_IF tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC res_ELSE tk_LLAVA LIST_INST tk_LLAVC
#line 163 "parser.y"
                                                                                                  {std::cout<<"If con else "<<std::endl;}
#line 1546 "parser.cpp"
    break;

  case 25: // WHILE: res_WHILE tk_PARA EXP tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 166 "parser.y"
                                                                 {std::cout<<"While "<<std::endl;}
#line 1552 "parser.cpp"
    break;

  case 26: // FOR: res_FOR tk_PARA DECLARAR ';' EXP ';' INCREMENTO tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 170 "parser.y"
                                                                                          {std::cout<<"FOR "<<std::endl;}
#line 1558 "parser.cpp"
    break;

  case 27: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id '=' tk_CORCHA LISTAEXP tk_CORCHC
#line 174 "parser.y"
                                                                                 {std::cout<<"VECTOR con valores "<<std::endl;}
#line 1564 "parser.cpp"
    break;

  case 28: // VECTOR: res_VECTOR tk_menorq TYPES tk_mayorq id
#line 175 "parser.y"
                                                {std::cout<<"VECTOR empty "<<std::endl;}
#line 1570 "parser.cpp"
    break;

  case 29: // VECTOR: id '.' res_pushB tk_PARA EXP tk_PARC
#line 176 "parser.y"
                                             {std::cout<<"VECTOR.pushB "<<std::endl;}
#line 1576 "parser.cpp"
    break;

  case 30: // VECTOR: id '.' res_pushF tk_PARA EXP tk_PARC
#line 177 "parser.y"
                                             {std::cout<<"VECTOR.pushF "<<std::endl;}
#line 1582 "parser.cpp"
    break;

  case 31: // VECTOR: id '.' res_get tk_PARA EXP tk_PARC
#line 178 "parser.y"
                                           {std::cout<<"VECTOR.get "<<std::endl;}
#line 1588 "parser.cpp"
    break;

  case 32: // VECTOR: id '.' res_remove tk_PARA EXP tk_PARC
#line 179 "parser.y"
                                              {std::cout<<"VECTOR.remove "<<std::endl;}
#line 1594 "parser.cpp"
    break;

  case 33: // VECTOR: id '.' res_size tk_PARA tk_PARC
#line 180 "parser.y"
                                         {std::cout<<"VECTOR.size "<<std::endl;}
#line 1600 "parser.cpp"
    break;

  case 34: // PRINT: PRINTF tk_PARA EXP tk_PARC
#line 183 "parser.y"
                                   { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1606 "parser.cpp"
    break;

  case 35: // INCREMENTO: id mas_mas
#line 186 "parser.y"
                        {std::cout<<"masmas "<<std::endl;}
#line 1612 "parser.cpp"
    break;

  case 36: // INCREMENTO: id menos_menos
#line 187 "parser.y"
                             {std::cout<<"menosmenos "<<std::endl;}
#line 1618 "parser.cpp"
    break;

  case 37: // FUNC: TYPES id tk_PARA LISTPARAM tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 190 "parser.y"
                                                                     {std::cout<<"funcion: "<<yystack_[6].value.as < std::string > ()<<std::endl;}
#line 1624 "parser.cpp"
    break;

  case 38: // FUNC: TYPES id tk_PARA tk_PARC tk_LLAVA LIST_INST tk_LLAVC
#line 191 "parser.y"
                                                           {std::cout<<"funcion: "<<yystack_[5].value.as < std::string > ()<<std::endl;}
#line 1630 "parser.cpp"
    break;

  case 39: // LLAMADAF: id tk_PARA LISTAEXP tk_PARC
#line 194 "parser.y"
                                      {std::cout<<"Llamando funcion: "<<yystack_[3].value.as < std::string > ()<<std::endl;}
#line 1636 "parser.cpp"
    break;

  case 40: // RETORNO: res_RETURN EXP
#line 197 "parser.y"
                        {std::cout<<"returno de : "<<yystack_[0].value.as < expression* > ()<<std::endl;}
#line 1642 "parser.cpp"
    break;

  case 41: // TYPES: tk_void
#line 200 "parser.y"
                { yylhs.value.as < std::string > () = "void"; }
#line 1648 "parser.cpp"
    break;

  case 42: // TYPES: tk_int
#line 201 "parser.y"
             { yylhs.value.as < std::string > () = "int"; }
#line 1654 "parser.cpp"
    break;

  case 43: // TYPES: tk_string
#line 202 "parser.y"
                { yylhs.value.as < std::string > () = "string"; }
#line 1660 "parser.cpp"
    break;

  case 44: // TYPES: tk_float
#line 203 "parser.y"
               { yylhs.value.as < std::string > () = "float"; }
#line 1666 "parser.cpp"
    break;

  case 45: // TYPES: tk_bool
#line 204 "parser.y"
              { yylhs.value.as < std::string > () = "bool"; }
#line 1672 "parser.cpp"
    break;

  case 50: // EXP: EXP suma EXP
#line 215 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1678 "parser.cpp"
    break;

  case 51: // EXP: EXP menos EXP
#line 216 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1684 "parser.cpp"
    break;

  case 52: // EXP: EXP mult EXP
#line 217 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1690 "parser.cpp"
    break;

  case 53: // EXP: EXP div EXP
#line 218 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1696 "parser.cpp"
    break;

  case 54: // EXP: EXP tk_menor_igual EXP
#line 219 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 1702 "parser.cpp"
    break;

  case 55: // EXP: EXP tk_menorq EXP
#line 220 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 1708 "parser.cpp"
    break;

  case 56: // EXP: EXP tk_mayor_igual EXP
#line 221 "parser.y"
                             { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 1714 "parser.cpp"
    break;

  case 57: // EXP: EXP tk_mayorq EXP
#line 222 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 1720 "parser.cpp"
    break;

  case 58: // EXP: EXP tk_igualq EXP
#line 223 "parser.y"
                        { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 1726 "parser.cpp"
    break;

  case 59: // EXP: EXP tk_diferenteq EXP
#line 224 "parser.y"
                            { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 1732 "parser.cpp"
    break;

  case 60: // EXP: EXP tk_and EXP
#line 225 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 1738 "parser.cpp"
    break;

  case 61: // EXP: EXP tk_or EXP
#line 226 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 1744 "parser.cpp"
    break;

  case 62: // EXP: EXP tk_not EXP
#line 227 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!"); }
#line 1750 "parser.cpp"
    break;

  case 63: // EXP: tk_PARA EXP tk_PARC
#line 228 "parser.y"
                          { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 1756 "parser.cpp"
    break;

  case 64: // EXP: PRIMITIVE
#line 229 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1762 "parser.cpp"
    break;

  case 65: // PRIMITIVE: NUMERO
#line 232 "parser.y"
                   { yylhs.value.as < expression* > () = new primitive(0,0,INTEGER, "", std::stod(yystack_[0].value.as < std::string > ())); }
#line 1768 "parser.cpp"
    break;

  case 66: // PRIMITIVE: CADENA
#line 234 "parser.y"
        {
            std::string cadenita = yystack_[0].value.as < std::string > ().erase(0,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING, cadenita.erase(cadenita.length()-1,1), 0);
        }
#line 1777 "parser.cpp"
    break;

  case 67: // PRIMITIVE: id
#line 238 "parser.y"
               {}
#line 1783 "parser.cpp"
    break;

  case 68: // PRIMITIVE: DECIMAL
#line 239 "parser.y"
                    {}
#line 1789 "parser.cpp"
    break;

  case 71: // PRIMITIVE: res_mean tk_PARA id tk_PARC
#line 242 "parser.y"
                                      {std::cout<<"Media de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1795 "parser.cpp"
    break;

  case 72: // PRIMITIVE: res_median tk_PARA id tk_PARC
#line 243 "parser.y"
                                        {std::cout<<"Mediana de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1801 "parser.cpp"
    break;

  case 73: // PRIMITIVE: res_mode tk_PARA id tk_PARC
#line 244 "parser.y"
                                      {std::cout<<"Moda de: "<<yystack_[1].value.as < std::string > ()<<std::endl;}
#line 1807 "parser.cpp"
    break;


#line 1811 "parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -85;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     111,   -85,   -85,   -85,   -85,   -85,     9,   -85,    10,   -85,
      13,    14,    11,   290,   -21,    -7,    17,    18,    25,    26,
     344,    23,     3,   -85,    -2,    -1,   -85,   -85,   -85,     4,
       7,    29,   -85,    31,    36,    54,   -85,   344,   344,   -85,
     -85,   344,   129,   344,   344,   344,   111,   -85,   -85,   -85,
     -85,   344,   -85,   -85,    42,    77,    79,   629,   -85,   111,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -12,
     -15,   629,   347,   629,    83,    85,    87,    95,    96,   377,
     405,   433,    57,   107,   461,   117,   124,   126,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   102,   104,   344,   -85,   344,    76,   344,   344,   344,
     344,   118,   -85,   122,   123,   344,    80,   -85,   119,   127,
     128,     2,     2,   121,   121,    58,    58,   629,    58,    58,
      58,   668,   640,   668,   146,   131,   149,   -10,   629,   629,
     135,   489,   517,   545,   573,   -85,   290,   290,   308,   -85,
     -85,   -85,    98,   290,   -85,   138,   111,   344,   -85,   -85,
     -85,   -85,    94,   148,   164,   156,   166,   290,   172,   601,
     152,   -85,   -34,   173,   344,   -85,   210,   -85,   -85,    19,
     170,   -23,   -85,   290,   -85,   290,   -85,   228,   272,   -85,
     -85
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    41,    42,    43,    44,    45,     0,     2,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,    16,    13,    15,     0,
       0,     0,    12,     0,     0,     0,    17,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,    65,    67,    66,
      68,     0,    69,    70,     0,     0,     0,    40,    64,     0,
       3,     4,     7,     8,     9,     6,    10,    11,    14,    18,
       0,    47,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,    18,    63,     0,     0,
       0,    50,    51,    52,    53,    58,    59,    56,    54,    55,
      57,    60,    61,    62,     0,     0,     0,     0,    19,    46,
       0,     0,     0,     0,     0,    33,     0,     0,     0,    71,
      72,    73,    28,     0,    49,     0,     0,     0,    29,    30,
      31,    32,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    25,     0,     0,     0,    38,     0,    48,    21,     0,
       0,     0,    37,     0,    23,     0,    27,     0,     0,    24,
      26
  };

  const short
  Parser::yypgoto_[] =
  {
     -85,   -85,   -85,   -84,   -22,   147,   -85,    15,   -85,   -85,
     -85,   -85,    28,   -85,   -85,   -85,     1,    21,   -85,   -18,
     -85
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     6,     7,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    70,   137,    71,
      58
  };

  const unsigned char
  Parser::yytable_[] =
  {
      61,     8,    57,   104,    14,   102,   186,    15,   155,     9,
      37,    90,    91,    38,    16,     1,     2,     3,     4,     5,
      72,    39,    40,    73,    60,    79,    80,    81,    94,    10,
      11,    13,    12,    84,    43,    44,    36,   105,    17,   183,
      18,    19,    45,    46,    20,   105,   103,    83,    39,    40,
     156,    41,    42,    59,    17,    62,    63,    21,    69,    85,
     101,    64,   162,   163,    65,    88,    89,    90,    91,   166,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   176,    94,   138,    66,   139,    67,   141,
     142,   143,   144,    68,    86,    14,    87,   148,    15,   187,
     107,   188,   108,   136,   109,    16,     1,     2,     3,     4,
       5,   116,   110,   111,   115,   170,     1,     2,     3,     4,
       5,   118,   135,     1,     2,     3,     4,     5,   119,    17,
     120,    18,    19,   134,   140,    20,   145,   149,   103,   169,
      61,    61,   146,   147,    61,   150,   151,    94,    21,    14,
     152,   153,    15,   154,    61,   157,   165,   168,   167,    16,
       1,     2,     3,     4,     5,    61,    61,    14,   172,   171,
      15,    74,    75,    76,    77,    78,   177,    16,     1,     2,
       3,     4,     5,    17,   174,    18,    19,   175,   179,    20,
     185,   180,   173,    82,   184,   181,     0,     0,     0,     0,
       0,    17,    21,    18,    19,     0,     0,    20,     0,     0,
       0,    14,     0,     0,    15,     0,     0,     0,     0,     0,
      21,    16,     1,     2,     3,     4,     5,     0,     0,    14,
       0,   182,    15,     0,     0,     0,     0,     0,     0,    16,
       1,     2,     3,     4,     5,    17,     0,    18,    19,   189,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    21,    18,    19,     0,     0,    20,
       0,     0,     0,    14,     0,     0,    15,     0,     0,     0,
       0,     0,    21,    16,     1,     2,     3,     4,     5,     0,
       0,    14,     0,   190,    15,     0,     0,     0,     0,     0,
       0,    16,     1,     2,     3,     4,     5,    17,     0,    18,
      19,     0,     0,    20,     0,    88,    89,    90,    91,     0,
       0,     0,     0,     0,     0,    17,    21,    18,    19,     0,
       0,    20,    92,    93,    94,    95,     0,     0,    96,    97,
      98,    99,   100,     0,    21,     0,     0,    47,    48,    49,
      50,     0,     0,     0,    88,    89,    90,    91,     0,     0,
       0,    51,     0,     0,     0,   164,    52,    53,   106,     0,
       0,    92,    93,    94,    95,     0,     0,    96,    97,    98,
      99,   100,     0,     0,    88,    89,    90,    91,     0,     0,
       0,     0,    54,    55,    56,   112,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,     0,    96,    97,    98,
      99,   100,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,     0,    96,    97,    98,    99,   100,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,   114,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,     0,    96,    97,    98,    99,   100,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,   117,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
       0,    96,    97,    98,    99,   100,    88,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,     0,    96,
      97,    98,    99,   100,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,     0,    96,    97,    98,
      99,   100,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,   160,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,     0,    96,    97,    98,    99,   100,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,     0,    96,    97,    98,    99,   100,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   178,     0,     0,    92,    93,    94,    95,     0,
       0,    96,    97,    98,    99,   100,    88,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,     0,    92,    93,    94,    95,     0,     0,    96,
      97,    98,    99,   100,    92,    93,    94,    95,     0,     0,
      96,    97,    98,     0,   100,    88,    89,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,     0,    96,    97,
       0,     0,   100
  };

  const short
  Parser::yycheck_[] =
  {
      22,     0,    20,    18,     1,    17,    29,     4,    18,     0,
      17,     9,    10,    20,    11,    12,    13,    14,    15,    16,
      38,    55,    56,    41,    21,    43,    44,    45,    26,    19,
      17,    20,    18,    51,    17,    17,    57,    60,    35,    20,
      37,    38,    17,    17,    41,    60,    58,    46,    55,    56,
      60,    58,    59,    30,    35,    57,    57,    54,     4,    17,
      59,    57,   146,   147,    57,     7,     8,     9,    10,   153,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   167,    26,   103,    57,   105,    57,   107,
     108,   109,   110,    57,    17,     1,    17,   115,     4,   183,
      17,   185,    17,   102,    17,    11,    12,    13,    14,    15,
      16,     4,    17,    17,    57,    21,    12,    13,    14,    15,
      16,     4,    18,    12,    13,    14,    15,    16,     4,    35,
       4,    37,    38,    31,    58,    41,    18,    18,    58,   157,
     162,   163,    20,    20,   166,    18,    18,    26,    54,     1,
       4,    20,     4,     4,   176,    20,    58,   156,    20,    11,
      12,    13,    14,    15,    16,   187,   188,     1,     4,    21,
       4,    42,    43,    44,    45,    46,     4,    11,    12,    13,
      14,    15,    16,    35,    28,    37,    38,    21,    36,    41,
      20,    18,   164,    46,   179,   174,    -1,    -1,    -1,    -1,
      -1,    35,    54,    37,    38,    -1,    -1,    41,    -1,    -1,
      -1,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      54,    11,    12,    13,    14,    15,    16,    -1,    -1,     1,
      -1,    21,     4,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    35,    -1,    37,    38,    21,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    54,    37,    38,    -1,    -1,    41,
      -1,    -1,    -1,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    54,    11,    12,    13,    14,    15,    16,    -1,
      -1,     1,    -1,    21,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    35,    -1,    37,
      38,    -1,    -1,    41,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    54,    37,    38,    -1,
      -1,    41,    24,    25,    26,    27,    -1,    -1,    30,    31,
      32,    33,    34,    -1,    54,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    57,    22,    23,    21,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    34,    -1,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    48,    49,    50,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    34,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    34,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    34,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    34,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    34,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    34,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    34,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    34,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    33,    34,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      10,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    33,    34,    24,    25,    26,    27,    -1,    -1,
      30,    31,    32,    -1,    34,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,    31,
      -1,    -1,    34
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    12,    13,    14,    15,    16,    62,    63,    77,     0,
      19,    17,    18,    20,     1,     4,    11,    35,    37,    38,
      41,    54,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    57,    17,    20,    55,
      56,    58,    59,    17,    17,    17,    17,     3,     4,     5,
       6,    17,    22,    23,    48,    49,    50,    80,    81,    30,
      21,    65,    57,    57,    57,    57,    57,    57,    57,     4,
      78,    80,    80,    80,    42,    43,    44,    45,    46,    80,
      80,    80,    66,    77,    80,    17,    17,    17,     7,     8,
       9,    10,    24,    25,    26,    27,    30,    31,    32,    33,
      34,    77,    17,    58,    18,    60,    21,    17,    17,    17,
      17,    17,    18,    18,    18,    57,     4,    18,     4,     4,
       4,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    31,    18,    77,    79,    80,    80,
      58,    80,    80,    80,    80,    18,    20,    20,    80,    18,
      18,    18,     4,    20,     4,    18,    60,    20,    18,    18,
      18,    18,    64,    64,    57,    58,    64,    20,    77,    80,
      21,    21,     4,    73,    28,    21,    64,     4,    21,    36,
      18,    78,    21,    20,    68,    20,    29,    64,    64,    21,
      21
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    61,    62,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    70,    71,    71,    71,
      71,    71,    71,    71,    72,    73,    73,    74,    74,    75,
      76,    77,    77,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     7,     2,     1,     2,     2,     2,     2,
       2,     2,     1,     1,     2,     1,     1,     2,     2,     4,
       3,     8,     7,     9,    11,     7,    11,     9,     5,     6,
       6,     6,     6,     5,     4,     2,     2,     8,     7,     4,
       2,     1,     1,     1,     1,     1,     3,     1,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4
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
  "menos_menos", "';'", "'='", "'.'", "','", "$accept", "START", "MAIN",
  "LIST_INST", "INSTRUCTION", "DECLARAR", "ASIGNAR", "IF", "WHILE", "FOR",
  "VECTOR", "PRINT", "INCREMENTO", "FUNC", "LLAMADAF", "RETORNO", "TYPES",
  "LISTAEXP", "LISTPARAM", "EXP", "PRIMITIVE", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   109,   109,   119,   125,   130,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   151,   152,
     155,   156,   161,   162,   163,   166,   170,   174,   175,   176,
     177,   178,   179,   180,   183,   186,   187,   190,   191,   194,
     197,   200,   201,   202,   203,   204,   207,   208,   211,   212,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   232,   233,   238,   239,   240,
     241,   242,   243,   244
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
#line 2504 "parser.cpp"

#line 247 "parser.y"


/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

