#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

void crearCola(tCola*);
void vaciarCola(tCola *);


int colaLLena(const tCola *, unsigned);
int colaVacia(const tCola *);


int ponerEnCola(tCola *, const void *, unsigned);
int sacarDeCola(tCola *, void *, unsigned);


int verPrimeroCola(const tCola *p, void *, unsigned);

#endif // COLA_H_INCLUDED
