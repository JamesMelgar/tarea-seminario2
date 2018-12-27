#ifndef NODO_H
#define NODO_H

#include <QString>
#include <vector>

using namespace std;

class Nodo
{
public:
    Nodo();
    QString etiqueta;
    QString valor;
    QString linea;
    QString columna;
    int idNodo;
    void addHijo(Nodo *hijo);
    vector<Nodo> hijos;
};

#endif // NODO_H
