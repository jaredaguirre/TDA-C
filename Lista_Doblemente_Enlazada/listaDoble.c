#include "listaDoble.h"



void crearLista(tLista *p)
{
    *p = NULL;
}


int vaciarLista(tLista *p)
{
    int cant = 0;
    tNodo *act = *p;

    if(act)
    {
        while (act->ant)
            act = act->ant;
        while (act)
        {
            tNodo *aux = act->sig;

            free(act->info);
            free(act);
            act = aux;
            cant++;
        }
        *p = NULL;
    }
    return cant;
}


int listaVacia(const tLista *p)
{
    return *p == NULL;
}



int listaLlena(const tLista *p, unsigned cantBytes)
{
    tNodo   *nue = (tNodo *)malloc(sizeof (tNodo));
    void    *aux = malloc(cantBytes);

    free (nue);
    free (aux);
    return aux == NULL || nue == NULL;
}





int insertarAlFinal(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo   *act = *p,
            *nue;

    if (act)
        while (act->sig)
            act = act->sig;
    if((nue = (tNodo *)malloc(sizeof (tNodo)) == NULL || (nue->info = malloc(cantBytes)) == NULL))
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    nue->ant = act;
    if(act)
        act->sig = nue;
    *p = nue;
    return 1;
}


int insertarAlComienzo(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo   *act = *p,
            *nue;

    if(act)
        while (act->ant)
            act = act->ant;
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL |
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy (nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = act;
    nue->ant = NULL;
    if(act)
        act->ant = nue;
    *p = nue;
    return 1;
}




int mostrarDeIzqADer(const tLista *p, void(*mostrar) (const void *))
{
    tNodo   *act = *p;
    int     cant = 0;

    if(act)
    {
        mostrar (NULL) ;
        while(act->ant)
            act = act->ant;
        while(act)
        {
            mostrar(act->info);
            act = act->sig;
            cant++;
        }
    }
    return cant;
}


int mostrarDeDerAIzq(const tLista *p, void(*mostrar) (const void *))
{
    tNodo   *act = *p;
    int     cant = 0;

    if(act)
    {
        mostrar(NULL);
        while(act->sig)
            act = act->sig;
        while(act)
        {
            mostrar(act->info);
            act = act->ant;
            cant++;
        }
    }
    return cant;
}



int insertarEnOrden(tLista *p, const void *d, unsigned cantBytes,
                    int (*comparar) (const void *, const void *),
                    int (*acumular) (void **, unsigned *,
                                     const void *, unsigned))
{
    tNodo   *act = *p,
            *sig,
            *ant,
            *nue;

    if(act == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        int aux;
        while(act->sig && comparar(act->info, d) < 0)
            act = act->sig;
        while(act->ant && comparar(act->info, d) > 0)
            act = act->ant;
        aux = comparar(act->info, d);
        if(aux == 0)
        {
            *p = act;
            if(acumular)
                if(acumular(&act->info, &act->tamInfo, d, cantBytes) == 0)
                    return SIN_MEM;
            return CLA_DUP;
        }
        if(aux < 0)
        {
            ant = act;
            sig = act->sig;
        }
        else
        {
            ant = act->ant;
            sig = act;
        }
    }
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free (nue);
        return SIN_MEM;
    }
    memcpy (nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = sig;
    nue->ant = ant;
    if(sig)
        sig->ant = nue;
    if(ant)
        ant->sig = nue;
    *p = nue;
    return TODO_BIEN;
}



void ordenarLista(tLista *p, int (*comparar) (const void *, const void *))
{

    tNodo   *act = *p,
            *sup = NULL,
            *inf = NULL;
    int     marca = 1;



    if(act == NULL)
        return;
    while(act->ant)
        act = act->ant;
    while(marca)
    {
        marca = 0;
        while(act->sig != sup)
        {
            if (comparar (act->info, act->sig->info) > 0)
            {
                void        *inf = act->info;
                unsigned    tam = act->tamInfo;

                marca = 1;
                act->info = act->sig->info;
                act->sig->info = inf;
                act->tamInfo = act->sig->tamInfo;
                act->sig->tamInfo = tam;
            }
            act = act->sig;
        }
        sup = act;
        while(act->ant != inf)
        {
            if(comparar(act->info, act->ant->info) < 0)
            {
                void *inf = act->info;
                unsigned tam = act->tamInfo;

                marca = 1;
                act->info = act->ant->info;
                act->ant->info = inf;
                act->tamInfo = act->ant->tamInfo;
                act->ant->tamInfo = tam;
            }
            act = act->ant;
        }
        inf = act;
    }
}




int eliminarPorClave(tLista *p, void *d, unsigned cantBytes,
                     int (*comparar) (const void *, const void *))
{
    tNodo   *act = *p;
    int     aux;

    if(act == NULL)
    {
    return 0; /** Lista vacia */
    }

    while(act->sig && comparar(act->info, d) < 0)
        act = act->sig;
    while(act->ant && comparar(act->info, d) > 0)
        act = act->ant;

    aux = comparar(act->info, d);

    if(aux == 0) /** Encontro la clave */
    {
        tNodo   *ant = act->ant,
                *sig = act->sig;

        if (ant)
            ant->sig = sig;
        if (sig)
        {
            sig->ant = ant;
            *p = sig;
        }
        else
            *p = ant;

        memcpy(d, act->info, cantBytes) ;
        free(act->info) ;
        free(act);
        return 1;
    }
    return 0;
}
