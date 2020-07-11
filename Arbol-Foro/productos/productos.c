#include "productos.h"

int ingresarProducto(tProd *d)
{
    static const tProd productos[] = {
        {1, "clavoro3/4", 1, 95374.00 },
        {2, "martillo3K", 45, 1973.99 },
        {3, "amyeso1",    17, 157.96 },
        {4, "rem-vid15",  4500, 22.00 },
        {5, "plom-telgo", 5, 86.50 },
        {6, "limagoma17", 190, 315.99 },
        {7, "ladracua",   15, 96.00 },
        {8, "inflaten",   3, 3426.20 }
        };


    static int posi = 0;

    if(posi == sizeof(productos) / sizeof(tProd))
    {
        posi = 0;
        return 0;
    }
    *d = productos[posi];
    posi++;

    return 1;
}


int ingresarMovimiento(tMov *d)
{
        static const tMov movimientos[] = {
                               {1, 10, 'V'},
                               {2, 10, 'V'},
                               {3, 10, 'V'},
                               {4, 10, 'V'},
                               {5, 10, 'V'},
                               {6, 10, 'V'},
                               {7, 10, 'V'},
                               {8, 10, 'V'},
                               {9, 10, 'V'},
                               {1, 5, 'R'},
                               {2, 5, 'R'},
                               {3, 5, 'R'},
                               {4, 5, 'R'},
                               {5, 5, 'R'},
                               {6, 5, 'R'},
                               {7, 5, 'R'},
                               {8, 5, 'R'},
                               {9, 5, 'R'},
                              };


    static int posi = 0;

    if(posi == sizeof(movimientos) / sizeof(tMov))
    {
        posi = 0;
        return 0;
    }
    *d = movimientos[posi];
    posi++;

    return 1;
}



int generarArchivos(FILE **fpMae, FILE **fpMov)
{
    tProd   prod;
    tMov    mov;

    // Generando archivo Maestro

    if(!(*fpMae = fopen("maestro.bin", "wb")))
    {
        fprintf(stderr, "Error!");
        return 0;
    }


    while(ingresarProducto(&prod))
    {
        fwrite(&prod,sizeof(tProd),1, *fpMae);
    }

    fclose(*fpMae);


    /****************************************/

    // Generando archivo Movimientos

    if(!(*fpMov = fopen("movimientos.txt", "wt")))
    {
        fprintf(stderr, "Error!");
        return 0;
    }


    while(ingresarMovimiento(&mov))
    {
        fprintf(*fpMov, "%d|%d|%c\n", mov.ID,
                                    mov.cantidad,
                                    mov.movimiento);
    }

    fclose(*fpMov);

    return 1;
}
