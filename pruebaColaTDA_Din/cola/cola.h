#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef struct
{
    tNodo *pri;
    tNodo *ult;
}tCola;


void crearCola(tCola*);


#endif // COLA_H_INCLUDED
