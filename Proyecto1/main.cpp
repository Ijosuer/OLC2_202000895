#include "mainwindow.h"

#include "Environment/ast.hpp"
#include "parserctx.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>

QString read_file(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "";

    QTextStream in(&file);
    QString content = in.readAll();

    file.close();

    return content;
}
void ejecutar(){
    environment *GlobalEnv = new environment(nullptr,"MAIN");
    //creando ast
    ast *Root = new ast();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    //Leemos el archivo de entrada
    QString entrada = read_file(":/pruebas/entrada.txt");
    analizador.Analizar(entrada.toStdString());
    //ejecutar main
    analizador.Main->ejecutar(GlobalEnv, Root);
    std::cout<<analizador.Salida<<std::endl;
    if(Root->ErrorOut == ""){
        //despliega el mensaje
        std::cout<<Root->ConsoleOut<<std::endl;
    }else{
        std::cout<<"Se encontraron errores.. "<<std::endl;
        std::cout<<Root->ErrorOut<<std::endl;
    }
}
void leer(){
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    //Leemos el archivo de entrada
    QString entrada = read_file(":/pruebas/entrada.txt");
    //    qDebug()<<entrada;
    analizador.Analizar(entrada.toStdString());
    std::cout<<analizador.Salida<<std::endl;
}

int main(int argc, char *argv[])
{

//    ejecutar();
//    return 0;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
