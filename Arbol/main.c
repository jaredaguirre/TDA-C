#include "main.h"

int main()
{
    tArbolBinBusq ar;
	//int vec[] = {10,25,50,60,75,100,110,125,150,175,200};
	int vec[] = {25,50,75,100,125,150,175};
	int dato;
	crearArbolBinBusq(&ar);
	cargarDesdeDatosOrdenadosArbolBinBusq(&ar, vec, sizeof(vec)/sizeof(int),leerDesdeVectorEnteros,NULL);

	///eliminarRaizArbolBinBusq(&ar);

	recorrerEnOrdenArbolBinBusq(&ar,NULL,imprimir);
	printf("\n\n");
	recorrerPreOrdenArbolBinBusq(&ar,NULL,imprimir);
	printf("\n\n");
	recorrerPosOrdenArbolBinBusq(&ar,NULL,imprimir);
	printf("\n\n");
	recorrerEnOrdenInversoArbolBinBusq(&ar,NULL,imprimirConForma);
	printf("\n\n");
	if (esCompletoArbolBin(&ar))
        printf("\nCompleto");
	if (esBalanceadoArbolBin(&ar))
        printf("\nBalanceado");
	if (esAVLArbolBin(&ar))
        printf("\nAVL");
	printf("\n\n");
	if (esCompleto2ArbolBin(&ar))
        printf("\n2 Completo");
	if (esBalanceado2ArbolBin(&ar))
        printf("\n2 Balanceado");
	if (esAVL2ArbolBin(&ar))
        printf("\n2 AVL");
	mayorElemNoClaveArbolBinBusq(&ar, &dato, sizeof(dato),cmp_ent);
	printf("\n\nMayor No Clave: %d", dato);
	menorElemNoClaveArbolBinBusq(&ar, &dato, sizeof(dato),cmp_ent);
	printf("\n\nMenor No Clave: %d", dato);
	return 0;
}

void imprimirConForma(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int *) info;
    printf("%*s-%3d-\n",n*3,"", *i);
}

void imprimir(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int *) info;
    printf("-%d-", *i);
}

unsigned leerDesdeVectorEnteros(void ** d, void * vec, unsigned pos, void * params)
{
    *d = malloc(sizeof(int));
    if(!*d)
        return 0;
    memcpy(*d, vec+(sizeof(int)*pos), sizeof(int));
    return sizeof(int);
}

int	cmp_ent(const void *v1, const void *v2)
{
    return *((int*)v1)-*((int*)v2);
}
