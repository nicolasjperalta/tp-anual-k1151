#include <stdlib.h>
#include "./producto.h"
#include "./lista.h"

void push(struct Nodo **inicio, Producto data)
{
    struct Nodo *ptr1 = (struct Nodo *)malloc(sizeof(struct Nodo));
    ptr1->data = data;
    ptr1->sgte = *inicio;
    *inicio = ptr1;
}

void ordenar(struct Nodo *start)
{
    int cambio, i;
    struct Nodo *ptr1;
    struct Nodo *lptr = NULL;

    if (ptr1 == NULL)
    {
        return;
    }

    do
    {
        cambio = 0;
        ptr1 = start;

        while (ptr1->sgte != lptr)
        {
            if (ptr1->data.CantidadDeUnid < ptr1->sgte->data.CantidadDeUnid)
            {
                Producto temp = ptr1->data;
                ptr1->data = ptr1->sgte->data;
                ptr1->sgte->data = temp;

                cambio = 1;
            }
            ptr1 = ptr1->sgte;
        }
        lptr = ptr1;
    } while (cambio);
}

void ordenarPorPeso(struct Nodo *start)
{
    int cambio, i;
    struct Nodo *ptr1;
    struct Nodo *lptr = NULL;

    if (ptr1 == NULL)
    {
        return;
    }

    do
    {
        cambio = 0;
        ptr1 = start;

        while (ptr1->sgte != lptr)
        {
            if (ptr1->data.Peso < ptr1->sgte->data.Peso)
            {
                Producto temp = ptr1->data;
                ptr1->data = ptr1->sgte->data;
                ptr1->sgte->data = temp;

                cambio = 1;
            }
            ptr1 = ptr1->sgte;
        }
        lptr = ptr1;
    } while (cambio);
}