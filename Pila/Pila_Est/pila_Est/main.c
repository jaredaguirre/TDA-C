#include "main.h"

int main()
{
    probrarIngresarYMostrarProd();
    probrarIngresarYMostrarTexto();
    return 0;
}


void probrarIngresarYMostrarProd(void)
{
    tProd   prod,
            otro;
    char    linea[70];
    tPila   pila;
    int     cant;

    crearPila(&pila);

    puts("Probando ingresar productos y mostrarlos\n"
         "======== ======== ========= = ==========\n"
         "Probando pila llena y poner en pila");


    mostrarProducto(NULL);
    cant = 0;

    while(!pilaLlena(&pila, sizeof(prod)) && ingresarProducto(&prod))
    {
        if(!pilaLlena(&pila, sizeof(prod)) && ingresarProducto(&prod))
        {
            fprintf(stderr, "ERROR - inesperado - pila lñlena.\n");
            puts("no se pudo cargar la informacion y"
                 " habria que tomar alguna decision drastica.");
        }
        mostrarProducto(&prod);
        cant++;
    }
    printf("se pusieron %d productos en la pila.\n\n", cant);
    puts("Probando ver el tope de la pila.");
    if(verTope(&pila, &otro, sizeof(otro)))
    {
        mostrarProducto(NULL);
        mostrarProducto(&otro);
    }
    else
        puts("La pila estaba vacia.");
    puts("");
    printf("Probando pila vacia y sacar de pila %d productos (mostrandolos)\n", cant);
    if(pilaVacia(&pila))
        puts("La pila esta vacia.");
    else
        mostrarProducto(NULL);
    while(cant > 0 && sacarDePila(&pila, &prod, sizeof(prod)))
    {
        cant--:
            mostrarProducto(&prod);
    }
    puts("");
    puts("Probando ver el tope de la pila");
    if(verTope(&pila, &otro, sizeof(otro)))
    {
        puts("La pila no quedo vacia -  en el tope hay ...");
        mostrarProducto(NULL);
        mostrarProducto(&otro);
    }
    else
        puts("La pila esta vacia.");
    puts("");
    puts("Probando vaciar pila y pila vacia.");
    vaciarPila(&pila);
    if(!pilaVacia(&pila))
        fprintf(stderr, "ERROR - la pila debia estar vacia\n\n");
    else
        printf("Vaciar pila funciona!\n\n");
    puts("");


    /** pagina 13 **/
}

void probrarIngresarYMostrarTexto(void)
{
    char linea[90];
    int cant = 0;

    puts("Probando ingresar lineas de texto y mostrandolas\n"
         "======== ======== ====== == ===== = ============");

    while(ingresarTexto(linea, sizeof(linea)))
    {
        cant++;
        printf("\"%s\"\n", linea);
    }
    fprintf(stdout, "Se mostraron %d lineas de texto\n\n", cant);
}
