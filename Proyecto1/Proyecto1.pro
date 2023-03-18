QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += \
            pruebas/entrada.txt

SOURCES += \
Environment/ast.cpp \
    Environment/environment.cpp \
    Environment/symbol.cpp \
    Environment/func_symbol.cpp \
    Expression/operation.cpp \
    Expression/access.cpp \
    Expression/call_exp.cpp \
    Expression/list_expression.cpp \
    Expression/map_struct_dec.cpp \
    Expression/primitive.cpp \
    Expression/array_exp.cpp \
    Expression/array_access.cpp \
    Instruction/func_main.cpp \
    Instruction/list_instruction.cpp \
    Instruction/print.cpp \
    Instruction/declaracion.cpp \
    Instruction/func_if.cpp \
    Instruction/func_while.cpp \
    Instruction/asignacion.cpp \
    Instruction/call_inst.cpp \
    Instruction/func_return.cpp \
    Instruction/function.cpp \
    Instruction/func_for.cpp \
    Instruction/incremento.cpp \
    Instruction/vector.cpp \
    Interfaces/expression.cpp \
    Interfaces/expression.cpp \
    Interfaces/instruction.cpp \
    parser/lex.yy.c \
    parser/parser.cpp \
    main.cpp \
    mainwindow.cpp\
#    texteditlinenumber.cpp\
     parserctx.cpp

HEADERS += \
    Environment/ast.hpp \
   Environment/environment.hpp \
   Environment/symbol.hpp \
   Environment/func_symbol.hpp \
   Environment/type.h \
   Expression/access.hpp \
   Expression/call_exp.hpp \
   Expression/list_expression.hpp \
   Expression/map_struct_dec.hpp \
   Expression/operation.hpp \
   Expression/primitive.hpp \
   Expression/array_exp.hpp \
   Expression/array_access.hpp \
   Instruction/func_main.hpp \
   Instruction/list_instruction.hpp \
   Instruction/print.hpp \
   Instruction/func_if.hpp \
   Instruction/func_while.hpp \
   Instruction/declaracion.hpp \
   Instruction/asignacion.hpp \
   Instruction/call_inst.hpp \
   Instruction/func_return.hpp \
   Instruction/function.hpp \
   Instruction/func_for.hpp \
   Instruction/incremento.hpp \
   Instruction/vector.hpp \
   Interfaces/expression.hpp \
   Interfaces/expression.hpp \
   Interfaces/instruction.hpp \
   parser/lexer.l \
   parser/location.hh \
   parser/parser.hpp \
   parser/parser.y \
   parser/position.hh \
   parser/stack.hh \
   mainwindow.h\
#   texteditlinenumber.h\
   parserctx.hpp

FORMS += \
    mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
