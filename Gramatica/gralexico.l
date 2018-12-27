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
%}

comentario "/*"[^'*']*"*/"
letra [a-zñA-ZÑ]
digito [0-9]
numero {digito}+

%%
"("             {return pari;}
")"             {return parf;}
","             {return coma;}
{numero}        {yy1lval.num = atof(yy1text); return numero;}

{comentario}    { /*Se ignoran*/ }
[[:blank:]]     { /*Se ignoran*/ }


.               {
                    QMessageBox::information(NULL,"ERROR","ERROR LEXICO en linea: ");
                }

%%
