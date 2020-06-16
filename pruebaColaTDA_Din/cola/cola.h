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
void vaciarCola(tCola *);
int colaLLena(const tCola *, unsigned);
int colaVacia(const tCola *);
int ponerEnCola(tCola *, const void *, unsigned);
int sacarDeCola(tCola *, void *, unsigned);

int verPrimeroCola(const tCola *, void *, unsigned);

#endif // COLA_H_INCLUDED
