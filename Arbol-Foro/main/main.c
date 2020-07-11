#include "main.h"

int main()
{
    FILE *fpMaestro;
    FILE *fpMovimientos;
    FILE *fpMovConError;

    tArbolBinBusq arbol;


    crearArbolBinBusq(&arbol);
    generarArchivos(&fpMaestro, &fpMovimientos);


    completarArbol(&arbol, &fpMaestro);


    if (!indexarArchivoMaestro(&ar, pMaestro))
    {
        fprintf(stderr, "ERROR: no se pudo indexar el archivo maestro");
        exit(1);
    }



    return 0;
}


int completarArbol(tArbolBinBusq *p, FILE *fp)
{
    tIndice indice;
    tProd prod;


    if (!(*fp=fopen("maestro.bin","rb"))
        return ERR_ARCH;

    indice.posicion = ftell(*fp);
    fread(&prod, sizeof(tProd), 1, fp);

    while(!feof(pb))
    {
        indice.ID = prod.ID;

        if(!insertarArbolBinBusq(p, &indice, sizeof(tIndice), &comparar))
            return ERROR_ARBOL;

        indice.posicion = ftell(*fp);
        fread(&prod, sizeof(tProd), 1, fp);
    }

    return TODO_BIEN;
}
