#include "main.h"

int main()
{
    probrarIngresarYMostrarProd();
    probrarIngresarYMostrarTexto();
    return 0;
}


void probrarIngresarYMostrarProd(void)
{
    tProd   prod;
    int     cant = 0;

    puts("Probando ingresar productos y mostrarlos\n"
         "======== ======== ========= = ==========");

    if(ingresarProducto(&prod))
        mostrarProducto(NULL);
    do
    {
        mostrarProducto(&prod);
        cant++;
    }while(ingresarProducto(&prod));

    fprintf(stdout, "Se mostraron %d productos.\n\n", cant);
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
