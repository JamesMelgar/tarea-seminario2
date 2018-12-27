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
extern int yy1columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yy1text; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON


Nodo *raiz;
int CounNodo = 0;
%}

%union
{
    int entero;
    float num;
    std::string* str;
    struct Nodo *nodo;
}


%start S
%token <num> numero
%token pari
%token parf
%token coma

%type <nodo> S
%type <nodo> INICIO
%type <nodo> COORDENADA
%type <nodo> LST_COORDENADA

%%

S: INICIO
    {
        Nodo *tmp = new Nodo();
        tmp->etiqueta = "S";
        tmp->idNodo = CounNodo;
        CounNodo++;
        tmp->addHijo($1);
        raiz = tmp;
    };

INICIO: COORDENADA coma LST_COORDENADA{
            Nodo *tmp = new Nodo();
            tmp->etiqueta = "INICIO";
            tmp->idNodo = CounNodo;
            CounNodo++;
            tmp->addHijo($1);
            tmp->addHijo($3);
            $$ = tmp;
        };

LST_COORDENADA: LST_COORDENADA coma COORDENADA
                {
                    Nodo *tmp = $1;
                    tmp->addHijo($3);
                    $$ = tmp;
                }
               |COORDENADA
               {
                    Nodo *tmp = new Nodo();
                    tmp->etiqueta = "LST_COORDENADA";
                    tmp->idNodo = CounNodo;
                    CounNodo++;;
                    tmp->addHijo($1);
                    $$ = tmp;
               };

COORDENADA:   pari numero coma numero parf
              {
                Nodo *tmp = new Nodo();
                tmp->etiqueta = "COORDENADA";
                tmp->idNodo = CounNodo;
                CounNodo++;

                Nodo *tmp2 = new Nodo();
                tmp2->etiqueta = "numero";
                tmp2->valor = QString::number($2);
                tmp2->idNodo = CounNodo;
                CounNodo++;

                Nodo *tmp3 = new Nodo();
                tmp3->etiqueta = "numero";
                tmp3->valor = QString::number($2);
                tmp3->idNodo = CounNodo;
                CounNodo++;

                tmp->addHijo(tmp2);
                tmp->addHijo(tmp3);
                $$ = tmp;
              }

%%

void yy1error(char *s)
{
    char* e = strdup(yy1text);
    std::string *val = new string(yy1text,yy1lineno);
    QString a = val->c_str();
    QMessageBox::information(NULL,"ERROR","ERROR sintactico en:"+a);
}

