#include <iostream>
#include <stdio.h>

#include "./../producto.h"
#include "./../lista.h"

int main()
{
    Nodo *listaProductos = NULL;

    FILE *fStock = fopen("./stock.dat", "rwb+");
    Producto prodActual;

    while (fread(&prodActual, sizeof(Producto), 1, fStock))
    {
        push(&listaProductos, prodActual);
    }

    ordenar(listaProductos);

    Nodo *actual = listaProductos;
    while (actual != NULL)
    {
        std::cout << "Producto:" << actual->data.IDProducto << std::endl
                  << "Peso" << actual->data.Peso << std::endl;
        fwrite(&actual->data, sizeof(Producto), 1, fStock);
        actual = actual->sgte;
    }

    fclose(fStock);
    return 0;
}
