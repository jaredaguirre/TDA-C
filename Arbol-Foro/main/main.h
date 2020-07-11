#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../productos/productos.h"
#include "../arbol/arbol.h"

typedef struct
{
    int ID;
    int posicion;
}tIndice;


int completarArbol(tArbolBinBusq *p, FILE *fp);

#endif // MAIN_H_INCLUDED
