#include <iostream>
#include <stdio.h>
#include "./../producto.h"
#include "./../lista.h"

#define MAX_MOSTRAR_PRODUCTOS 10

int main()
{
    Nodo *listaProductos = NULL;

    FILE *fStock = fopen("./stock.dat", "rb+");
    Producto prodActual;

    while (fread(&prodActual, sizeof(Producto), 1, fStock))
    {
        push(&listaProductos, prodActual);
    }

    ordenarPorPeso(listaProductos);

    Nodo *actual = listaProductos;

    int contador = 0;

    while (actual != NULL && contador < MAX_MOSTRAR_PRODUCTOS)
    {
        contador++;

        std::cout << "ID Producto:\t\t" << actual->data.IDProducto << std::endl
                  << "Descripcion:\t\t" << actual->data.Descripcion << std::endl
                  << "Cantidad de unidades:\t" << actual->data.CantidadDeUnid << std::endl;

        actual = actual->sgte;
    }

    fclose(fStock);
}