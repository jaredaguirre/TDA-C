#ifndef TIPOPRODUCTO_H_INCLUDED
#define TIPOPRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long id_producto;
    char descripcion[30];
    float precioUnitario;
    int cantidad;

}tProducto;

void crearProducto(tProducto *, long, char *, float, int);
void mostrarProducto(const void *);
int comparaProductoPorID(const void *, const void *);
int acumularProducto(void **, unsigned *, const void *, unsigned);

#endif // TIPOPRODUCTO_H_INCLUDED
