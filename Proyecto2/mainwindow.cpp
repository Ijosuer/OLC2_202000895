#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Environment/ast.hpp"
#include "Environment/environment.hpp"
#include <QMessageBox>
#include "parserctx.hpp"
#include <iostream>
#include <QClipboard>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Carga la imagen desde un archivo
    QPixmap pixmap(":/Archivos/portapapeles.png");
    // Ajusta el tamaño de la imagen utilizando la función scaled()
    QPixmap scaledPixmap = pixmap.scaled(QSize(50, 50)); // Cambia los valores 100, 100 por los tamaños deseados

    // Establece la imagen como fondo del botón
    ui->Clipboard->setIcon(QIcon(scaledPixmap));
    ui->Clipboard->setIconSize(scaledPixmap.size());

    // Establece los estilos de QPushButton
    ui->Clipboard->setFlat(true);  // Elimina el estilo de botón predeterminado
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox *msg = new QMessageBox();
    //creando entorno global
    environment *GlobalEnv = new environment(NULL, "Global");
    //creando ast
    ast *Root = new ast();
    //creando generador c3d
    generator_code *GeneratorC3D = new generator_code();
    //ejecuta el analizador
    OCL2Calc::ParserCtx analizador;
    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    //ejecutando funcinoes
    if(analizador.Functions != nullptr)
    {
       analizador.Functions->ejecutar(GlobalEnv, Root, GeneratorC3D);
    }
    //ejecutar main
    GeneratorC3D->MainCode = true;
    analizador.Main->ejecutar(GlobalEnv, Root, GeneratorC3D);
    GeneratorC3D->GenerateFinalCode();
    //valio errores
    if(Root->ErrorOut == "")
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString(analizador.Salida));
        msg->exec();
        ui->Consola->setText(QString::fromStdString(GeneratorC3D->FinalCode));
    }
    else
    {
        //despliega el mensaje
        msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
        msg->exec();
        ui->Consola->setText(QString::fromStdString(Root->ErrorOut));
    }
}

void MainWindow::on_Clipboard_clicked(){
    // Crea un objeto de portapapeles
    QClipboard *clipboard = QApplication::clipboard();

    // Define el texto que se copiará al portapapeles
    QString text = ui->Consola->toPlainText();

    // Copia el texto al portapapeles
    clipboard->setText(text);
}

