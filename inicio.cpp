#include "inicio.h"
#include "ui_inicio.h"
#include "Gramatica/parser.h"
#include "Gramatica/scanner.h"
#include <QMessageBox>
#include <vector>
#include <QString>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <QTextStream>
#include <grafo.h>

extern Nodo *raiz;

inicio::inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
}

inicio::~inicio()
{
    delete ui;
}

void inicio::creararchivo(QString texto){
    ofstream fichero;

    fichero.open("entrada.txt",ofstream::out|ofstream::trunc);
    fichero << texto.toStdString();
    fichero.close();
}

void inicio::on_gramatica_clicked()
{
    QString text = ui->txt_entrada->toPlainText();
    creararchivo(text);
    yy1in = fopen("entrada.txt","rt");
    if(!yy1in){
        char*e = "hola";
        QMessageBox::information(NULL,"ERROR","Error al abrir el archivo");
    }

    yy1parse();
    Grafo *g = new Grafo();
    g->graficarArbol(raiz);

   // Ejecutar *e = new Ejecutar();
    //e->graficarArbol(raiz);

    //ui->txt_salida(e->getvalor());
}
