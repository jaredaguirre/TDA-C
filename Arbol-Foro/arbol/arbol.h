#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define CLA_DUP 0
#define SIN_MEM 0
#define SIN_INICIALIZAR 0
#define ERROR_ARCH 0
#define ERROR_ARBOL 0
#define TODO_BIEN 1


typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,
                      *der;
}tNodoArbol;

typedef tNodoArbol *tArbolBinBusq;



void crearArbolBinBusq(tArbolBinBusq *p);

int insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *));


#endif // ARBOL_H_INCLUDED
