#include "grafo.h"

Grafo::Grafo()
{

}

void Grafo::graficarArbol(Nodo *raiz)
{
    QString acum = "digraph G{\n";
    concatenar(raiz,acum);
    acum += "\n}";

    ofstream archivoDot("Ast.dot");
    archivoDot<< acum.toStdString();
    archivoDot.close();
    system("dot Ast.dot -o Ast.png -Tpng");
}

void Grafo::concatenar(Nodo *tmp, QString &acum){

    if(tmp!=NULL){
        if(tmp->hijos.size() ==0)
        {
            if(tmp->valor == NULL){
                acum += QString::number(tmp->idNodo) +	"[label = \"" + tmp->etiqueta + "\"];  \n";
            }
            else{
                acum += QString::number(tmp->idNodo) + "[label = \"" + tmp->valor.replace("\"","")+"\"]; \n";
            }
        }
        else{
            acum += QString::number(tmp->idNodo) + "[label =\"" + tmp->etiqueta+"\"];\n";
        }
        for( int i=0; i < tmp->hijos.size(); ++i){
            acum += QString::number(tmp->idNodo) + "->" + QString::number((tmp->hijos[i]).idNodo)+";\n";
            concatenar(&(tmp->hijos[i]),acum);
        }
    }


}
