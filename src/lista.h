#ifndef LISTA_H
#define LISTA_H

#include "./producto.h"

void push(struct Nodo **inicio, Producto data);
void ordenar(struct Nodo *start);
void ordenarPorPeso(struct Nodo *start);

#endif