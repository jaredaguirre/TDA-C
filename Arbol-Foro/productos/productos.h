#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <stdio.h>

typedef struct
{
    int ID;
    char nombre[46];
    int cantidad;
    float precio;
}tProd;

typedef struct
{
    int ID;
    int cantidad;
    char movimiento;
}tMov;


int ingresarProducto(tProd *d);
int ingresarMovimiento(tMov *d);
int generarArchivos(FILE **,FILE **);



#endif // PRODUCTOS_H_INCLUDED
