#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#include <string.h>

#ifndef minimo
#define minimo( X, Y ) ( ( X )  <= ( Y ) ? ( X ) : ( Y ) )
#endif // minimo

#define TAM_PILA 340



typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
}tPila;

void crearPila(tPila *p);
int  pilaLlena(const tPila *p, unsigned cantBytes);
int  ponerEnPila(tPila *p, const void *d, unsigned cantBytes);
int  verTope(const tPila *p, void *d, unsigned cantBytes);
int  pilaVacia(const tPila *p);
int  sacarDePila(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);

#endif // PILA_DINAMICA_H_INCLUDED
