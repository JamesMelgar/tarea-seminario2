%option noyywrap
%{
#include <stdio.h>
#include "parser.h"
#include <iostream>
#include <QDebug>
#include <QMessageBox>
#include <vector>
#include <QString>
#include <string>
#include <algorithm>


using namespace std;
int columna=0;
%}

comentario "/*"[^'*']*"*/"
letra [a-zñA-ZÑ]
digito [0-9]
decimal {digito}+"."{digito}+
numero {digito}+
id {letra}({letra}|{digito}|"_")*

%%
"("             {return pari;}
")"             {return parf;}
","             {return coma;}
[+]             {return mas;}
[/]             {return divi;}
[*]              {return por;}
"-"              {return menos;}
{id}            {strcpy(yy1lval.TEXT, yytext);return id;}
{numero}        {strcpy(yy1lval.TEXT, yytext); return numero;}
{decimal}        {strcpy(yy1lval.TEXT, yytext); return decimal;}
"\n"             {columna++;}
{comentario}    { /*Se ignoran*/ }
[[:blank:]]     { /*Se ignoran*/ }


.               {
                    QMessageBox::information(NULL,"ERROR","ERROR LEXICO en linea: ");
                }

%%
