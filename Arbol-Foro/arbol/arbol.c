#include "arbol.h"


void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p = NULL;
}

/// Reservar Memoria Nodo
#define reservarMemoriaNodo( X , Y , Z , W ) ( ( ( X ) = (typeof( X ))malloc( Y ) ) == NULL || ( ( Z ) = malloc( W ) ) == NULL ? free( X ), 0 : 1 )

int insertarArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;
    int	rc;

    while(*p)
    {
        if((rc = cmp(d, (*p)->info)) < 0)
            p = &(*p)->izq;
        else if (rc > 0)
            p = &(*p)->der;
        else
        return CLA_DUP;
    }
    if(!reservarMemoriaNodo(nue, sizeof(tNodoArbol), nue->info, tam))
        return SIN_MEM;
    nue->tamInfo = tam;
    memcpy(nue->info, d, tam);
    nue->der = nue->izq = NULL;
    *p = nue;
    return TODO_BIEN;
}
