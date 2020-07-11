#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIN_MEM     0
#define TODO_BIEN   1
#define CLA_DUP     2

typedef struct sNodo
{
    void            *info;
    unsigned        tamInfo;
    struct sNodo    *sig,
                    *ant;
} tNodo;

typedef tNodo *tLista;



void crearLista(tLista *p);

int vaciarLista(tLista *p);

int listaVacia(const tLista *p);

int listaLlena(const tLista *p, unsigned cantBytes) ;

int insertarAlFinal(tLista *p, const void *d, unsigned cantBytes) ;

int insertarAlComienzo(tLista *p, const void *d, unsigned cantBytes) ;

int mostrarDeIzqADer(const tLista *p, void(*mostrar) (const void *));

int mostrarDeDerAIzq(const tLista *p, void(*mostrar) (const void *));

int insertarEnOrden(tLista *p, const void *d, unsigned cantBytes,
                    int (*comparar) (const void *, const void *),
                    int (*acumular) (void **, unsigned *,
                                     const void *, unsigned) );

void ordenarLista(tLista *p, int (*comparar) (const void *, const void *));
int eliminarPorClave(tLista *p, void *d, unsigned cantBytes,
                     int (*comparar) (const void *, const void *));


#endif // LISTADOBLE_H_INCLUDED
