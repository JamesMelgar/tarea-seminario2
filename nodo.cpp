#include "nodo.h"

Nodo::Nodo()
{

}

void Nodo::addHijo(Nodo *hijo)
{
    hijos.push_back(*hijo);
}
