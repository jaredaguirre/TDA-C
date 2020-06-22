#include "cola.h"

#define minimo(X,Y) ((X)<=(Y)?(X):(Y))

void crearCola(tCola *c)
{
    c->pri = NULL;
    c->ult = NULL;
}


int colaLLena(const tCola *p, unsigned cantBytes)
{
    /// se crea un nodo para chequear
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));

    /// y se le calcula el tamaño, obvio
    void *info = malloc(sizeof(cantBytes));

    ///se libera la memoria
    free(aux);
    free(info);

    ///pero si hubo lugar, creo que queda a donde apunta
    return aux == NULL || info == NULL;
}


int ponerEnCola(tCola *p, const void *dato, unsigned cantBytes)
{
    /// creamos el nodo donde se pondra el dato
    tNodo *nue = (tNodo *)malloc(sizeof(tNodo));

    /// cola llena?
    if(nue == NULL || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    /// se copia el dato en el nodo
    memcpy(nue->info, dato, cantBytes);


    /// se guardo cuando espacio ocupa el dato
    nue->tamInfo = cantBytes;

    /// al nuevo se lo apunta a nada porque es el ultimo
    nue->sig = NULL;

    /// si no es el ultimo, el ultimo de la pila pasa a apuntar a este
    if(p->ult)
        p->ult->sig = nue;
    else
        p->pri = nue; /// pero si la pila esta vacia, el nuevo sera el primero

    /// en cualquier caso, el nuevo pasa a ser el ultimo
    p->ult = nue;

    return 1;
}


void vaciarCola(tCola *p)
{
    /// mientras en el primer eslabon haya contenido se hara lo siguiente
    while(p->pri)
    {
        /// se guarda el primero en un auxiliar
        tNodo *aux = p->pri;
        /// el primero pasa a ser el siguiente
        p->pri = aux->sig;
        /// se borra la data del eslabon
        free(aux->info);
        /// se borra el eslabon
        free(aux);
    }

    /// se borra el puntero que indicaba al ultimo
    p->ult = NULL;
}



int colaVacia(const tCola *p)
{
    return p->pri == NULL;
}


int sacarDeCola(tCola *p, void *d, unsigned cantBytes)
{
    /// el primero se guarda en un auxiliar
    tNodo *aux = p->pri;

    /// si la cola esta vacia, se devuelve 0
    if(aux==NULL)
        return 0;

    /// el primero pasa a ser el segundo
    p->pri = aux->sig;

    /// se pone el dato del eslabon en el dato a mostrar
    memcpy(d, aux->info, minimo(aux->tamInfo, cantBytes));


    /// se libera la memoria de la info
    free(aux->info);

    /// se libera la memoria del dato
    free(aux);

    /// si se vacio la pila, el ultimo tiene que estar vacia
    if(p->pri == NULL)
        p->ult == NULL;

    return 1;
}


int verPrimeroCola(const tCola *p, void *d, unsigned cantBytes)
{
    /// si esta vacia, devuelve 0
    if(p->pri == NULL)
        return 0;

    /// copia la informacion del primer eslabon y se guarda en d
    memcpy(d, p->pri->info, minimo(p->pri->tamInfo,cantBytes));
    return 1;
}
