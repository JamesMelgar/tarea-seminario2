#ifndef GRAFO_H
#define GRAFO_H
#include "nodo.h"
#include "QString"
#include <fstream>
#include <vector>
#include <algorithm>

class Grafo
{
public:
    Grafo();

    void graficarArbol(Nodo *raiz);
    void concatenar(Nodo *tmp, QString &acum);
};

#endif // GRAFO_H
