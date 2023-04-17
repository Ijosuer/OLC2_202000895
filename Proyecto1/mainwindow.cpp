#include "./mainwindow.h"
#include "Environment/ast.hpp"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProcess>
#include <QFileInfo>>
#include "parserctx.hpp"
#include <iostream>
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->textEdit->setText("int main(){\n\n}");
    ui->Tabla->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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


void generatePNG(QString dotFilePath)
{
    // Obtener la ruta y el nombre del archivo PNG de salida
    QFileInfo fileInfo(dotFilePath);
    QString pngFilePath = fileInfo.path() + "/" + fileInfo.baseName() + ".png";

    // Ejecutar el comando dot
    QStringList args;
    args << "-Tpng" << dotFilePath << "-o" << pngFilePath;

    QProcess process;
    process.start("dot", args);
    process.waitForFinished(-1);

    // Comprobar si se generó el archivo PNG correctamente
    if (process.exitCode() != QProcess::NormalExit) {
        QMessageBox::warning(nullptr, "Error", "Failed to generate PNG file");
    } else {
        QMessageBox::information(nullptr, "Success", "PNG file generated successfully");
    }
}

void writeDOT(QString dotFilePath, QString dotText)
{
    QFile file(dotFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream out(&file);
        out << dotText;
        file.close();
    } else {
        // Error al abrir el archivo
        qDebug() << "Error al abrir el archivo" << dotFilePath;
    }
}


void crearGrafica(std::string graph){
    QProcess process;
       QStringList args;
       args << "-Tpng" << "/home/ijosuer/Escritorio/OLC2/Proyecto1/archivos/AST.dot" << "-o" << "/home/ijosuer/Escritorio/OLC2/Proyecto1/archivos/AST.png";

       process.start("dot", args);
       process.waitForFinished(-1);

       if (process.exitCode() != QProcess::NormalExit) {
           QMessageBox::warning(nullptr, "Error", "Failed to generate PNG file");
       } else {
           QMessageBox::information(nullptr, "Success", "PNG file generated successfully");
       }


//    system("dot -Tpng AST.dot -o AST.png");
//    string content = "digraph G{\n\n";
//    ofstream filename("AST.dot");
//    fstream file_out;

//    content += graph;
//    content +="}\n";
//    filename <<content;
//    filename.close();
//    std::cout<<"ACA"<<std::endl;

}

void MainWindow::on_pushButton_clicked()
{
    // Agregar las columnas y filas a la tabla...
    int rowCount = ui->Tabla->rowCount();

    // Eliminar todas las filas de la tabla
    for (int i = rowCount - 1; i >= 0; i--) {
        ui->Tabla->removeRow(i);
    }
    QMessageBox *msg = new QMessageBox();
//    QMessageBox *msg3 = new QMessageBox();
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
    
    //Crear Strcuts
    if(analizador.Structs != nullptr)
    {
       analizador.Structs->ejecutar(GlobalEnv, Root);
    }
    //ejecutar main
    analizador.Main->ejecutar(GlobalEnv, Root);
    //valio errores
    if(Root->ErrorOut == "")
    {
        //despliega el mensaje
//        msg->setText(QString::fromStdString(analizador.Salida));
//        msg->exec();
        ui->Consola->setText(QString::fromStdString(Root->ConsoleOut));
        std::string id = "";
        int line = 0;
        int col = 0;
        for (auto it = Root->TablaReporte.begin(); it != Root->TablaReporte.end(); ++it) {
            int row = ui->Tabla->rowCount();//Contador de filas
            ui->Tabla->insertRow(row);
            QTableWidgetItem *item1 = new QTableWidgetItem(); // Columna id
            QTableWidgetItem *item2 = new QTableWidgetItem(); // Columna tipo
            QTableWidgetItem *item3 = new QTableWidgetItem(); // Columna val
            QTableWidgetItem *item5 = new QTableWidgetItem(); // Columna linea
            QTableWidgetItem *item6 = new QTableWidgetItem(); // Columna col

            QString val = QString::fromStdString(static_cast<std::string>(it->Id));
            item1->setData(Qt::DisplayRole,val);
            ui->Tabla->setItem(row,0,item1);

            if(it->Tipo == INTEGER){
                item2->setData(Qt::DisplayRole,"Integer");
                ui->Tabla->setItem(row,1,item2);
                int val = *static_cast<int*>(it->Value);
                item3->setData(Qt::DisplayRole,val);
                ui->Tabla->setItem(row,2,item3);
            }
            else if(it->Tipo == STRING){
                item2->setData(Qt::DisplayRole,"String");
                ui->Tabla->setItem(row,1,item2);
                QString val = QString::fromStdString(*static_cast<std::string*>(it->Value));
                item3->setData(Qt::DisplayRole,val);
                ui->Tabla->setItem(row,2,item3);
            }
            else if(it->Tipo == BOOL){
                item2->setData(Qt::DisplayRole,"Bool");
                ui->Tabla->setItem(row,1,item2);
                bool flag = static_cast<bool>(it->Value);
                item3->setData(Qt::DisplayRole,flag);
                ui->Tabla->setItem(row,2,item3);
            }
            else if(it->Tipo == FLOAT){
                item2->setData(Qt::DisplayRole,"Float");
                ui->Tabla->setItem(row,1,item2);
                float val = *static_cast<float*>(it->Value);
                item3->setData(Qt::DisplayRole,val);
                ui->Tabla->setItem(row,2,item3);
            }
//            std::cout<<"Id "<<it->Id<<" Val "<<it->Value <<"Tipo "<<it->Tipo<<" Col "<< it->Col<< "Line: "<<it->Line<<std::endl;
            line = it->Line;
            item5->setData(Qt::DisplayRole,line);
            ui->Tabla->setItem(row,4,item5);
            col = it->Col;
            item6->setData(Qt::DisplayRole,col);
            ui->Tabla->setItem(row,5,item6);


        }

//        ui->Consola->setText(QString::fromStdString(Root->GraphOut));
            int row = 0;
            for(const std::string& itera: Root->TablaReporteEntorno){
                QTableWidgetItem *item4 = new QTableWidgetItem(); // Columna entorno
                QString str = QString::fromStdString(itera);
//                ui->Tabla->insertRow(row);
                item4->setData(Qt::DisplayRole, str);
                ui->Tabla->setItem(row,3,item4);
                row++;
            }
            //==============Instrucciones para AST==============
            std::string cadena ;
            Root->GraphOut+= "raiz[label=\"<RAIZ>\"]\n";

            for(const std::string& itera: Root->idNodos){
                cadena+="raiz -> "+itera+";\n";
//                std::cout<<itera<<std::endl;
            }
            Root->GraphOut+=cadena;
            std::string cad = "digraph G{\n";
            cad += Root->GraphOut+"\n}";
           QString dot =QString::fromStdString(cad);
            writeDOT(this->ruta,dot);
//            crearGrafica(Root->GraphOut);

    }
    else
    {
        //despliega el mensaje de error
        msg->setText(QString::fromStdString("Se encontraron algunos errores.."));
        msg->exec();
        ui->Consola->setText(QString::fromStdString(Root->ErrorOut));
    }
}

void MainWindow::on_pushButton_2_clicked(){
    generatePNG(this->ruta);
}

















