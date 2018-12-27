%{
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <QMessageBox>
#include <vector>
#include <string>
#include <algorithm>
#include <QString>

#include "scanner.h"
#include "nodo.h"

using namespace std;
extern int yy1lineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yy1text;
void yyerror(char *s);
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yy1text; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON


Nodo *raiz;
int CounNodo = 0;
%}

%union
{
    int entero;
    float num;
    char TEXT [256];
    struct Nodo *nodo;
}


%start S
%token <TEXT>numero
%token pari
%token parf
%token <TEXT> coma
%token mas
%token divi
%token por
%token menos
%token <TEXT> decimal
%token <TEXT> id


%type <nodo> S
%type <nodo> EXP
%type <nodo> VALOR

%left mas menos
%left por divi

%%

S: EXP
    {
        Nodo *tmp = new Nodo();
        tmp->etiqueta = "S";
        tmp->idNodo = CounNodo;
        CounNodo++;
        tmp->addHijo($1);
        raiz = tmp;
    };

EXP: EXP mas EXP {
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "+";
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;
                $$ = tmp;
                tmp->addHijo($1);
                tmp->addHijo($3);
                $$ = tmp;

    }
     | EXP menos EXP{
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "-";
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;
                $$ = tmp;

                tmp->addHijo($1);
                tmp->addHijo($3);
                $$ = tmp;
     }
     | EXP por EXP{
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "*";
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;
                $$ = tmp;

                tmp->addHijo($1);
                tmp->addHijo($3);
                $$ = tmp;

    }
     | EXP divi EXP{
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "/";
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;
                $$ = tmp;

                tmp->addHijo($1);
                tmp->addHijo($3);
                $$ = tmp;

    }
     | VALOR{
            $$ = $1;
     };

VALOR: numero {
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "numero";
                tmp->valor = $1;
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;
                $$ = tmp;
              }
        | id {
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "id";
                tmp->valor = $1;
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;

                QMessageBox::information(NULL,"ERROR","ERROR sintactico en:"+columna);
                $$ = tmp;
              }
        | coma{
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "coma";
                tmp->valor = $1;
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;
                $$ = tmp;
              }
        | decimal{
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "decimal";
                tmp->valor = $1;
                tmp->idNodo = CounNodo;
                tmp->columna = columna;
                CounNodo++;
                $$ = tmp;
              }
        | pari EXP parf{
            $$ = $2;
        }
        
%%

void yy1error(char *s)
{
    char* e = strdup(yy1text);
    std::string *val = new string(yy1text,yy1lineno);
    QString a = val->c_str();
    QMessageBox::information(NULL,"ERROR","ERROR sintactico en:"+a);
}

