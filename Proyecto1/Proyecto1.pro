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
    Expression/operation.cpp \
    Expression/access.cpp \
    Expression/primitive.cpp \
    Instruction/func_main.cpp \
    Instruction/list_instruction.cpp \
    Instruction/print.cpp \
    Instruction/declaracion.cpp \
    Instruction/asignacion.cpp \
    Interfaces/expression.cpp \
    Interfaces/expression.cpp \
    Interfaces/instruction.cpp \
    parser/lex.yy.c \
    parser/parser.cpp \
    main.cpp \
    mainwindow.cpp\
     parserctx.cpp

HEADERS += \
    Environment/ast.hpp \
   Environment/environment.hpp \
   Environment/symbol.hpp \
   Environment/type.h \
   Expression/access.hpp \
   Expression/operation.hpp \
   Expression/primitive.hpp \
   Instruction/func_main.hpp \
   Instruction/list_instruction.hpp \
   Instruction/print.hpp \
   Instruction/declaracion.hpp \
   Instruction/asignacion.hpp \
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
   parserctx.hpp

FORMS += \
    mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
