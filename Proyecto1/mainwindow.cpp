#include "./mainwindow.h"
#include "Environment/ast.hpp"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "parserctx.hpp"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->textEdit->setText("int main(){\n\n}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void anterior(){
    QMessageBox *msg = new QMessageBox();
    //creando entorno global
    environment *GlobalEnv = new environment(nullptr,"MAIN");
    //creando ast
    ast *Root = new ast();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
//    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //ejecutar main
    analizador.Main->ejecutar(GlobalEnv, Root);
    //valio errores
    if(Root->ErrorOut == "")
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString(analizador.Salida));
        msg->exec();
//        ui.Consola->setText(QString::fromStdString(Root->ConsoleOut));
    }
    else
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
        msg->exec();
//        ui->Consola->setText(QString::fromStdString(Root->ErrorOut));
    }
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox *msg = new QMessageBox();
    QMessageBox *msg3 = new QMessageBox();
    //creando entorno global
    environment *GlobalEnv = new environment(NULL,"MAIN");
    //creando ast
    ast *Root = new ast();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //ejecutar funciones
    if(analizador.Functions != nullptr)
    {
       analizador.Functions->ejecutar(GlobalEnv, Root);
    }
    //ejecutar main
    analizador.Main->ejecutar(GlobalEnv, Root);
    //valio errores
    if(Root->ErrorOut == "")
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString(analizador.Salida));
        msg->exec();
        ui->Consola->setText(QString::fromStdString(Root->ConsoleOut));
    }
    else
    {
        //despliega el mensaje de error
        msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
        msg->exec();
        ui->Consola->setText(QString::fromStdString(Root->ErrorOut));
    }
}


















