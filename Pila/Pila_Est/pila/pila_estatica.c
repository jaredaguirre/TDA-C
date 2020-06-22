#include "pila_estatica.h"

void crearPila_MIO(tPila *p)
{
    p->tope = TAM_PILA;
}


int  pilaLlena_MIO(const tPila *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);
}


int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes)
{
    if(p->tope < cantBytes +sizeof(unsigned))
        return 0;
    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope , &cantBytes, sizeof(unsigned));
    return 1;
}


int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), minimo(cantBytes, tamInfo));
    return 1;
}


int  pilaVacia_MIO(const tPila *p)
{
    return p->tope == TAM_PILA;
}


int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, minimo(cantBytes, tamInfo));
    p->tope += tamInfo;
    return 1;
}


void vaciarPila_MIO(tPila *p)
{
    p->tope = TAM_PILA;
}
