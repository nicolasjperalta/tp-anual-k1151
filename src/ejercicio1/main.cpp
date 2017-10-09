#include <iostream>
#include <stdio.h>
#include "../producto.h"

int main()
{
    FILE *fStock = fopen("./stock.dat", "wb+");
    Producto pActual;
    std::cout << "Ingrese id del producto. Ingrese -1 para finalizar la carga: ";
    std::cin >> pActual.IDProducto;

    while (pActual.IDProducto != -1)
    {
        std::cout << std::endl
                  << "Ingrese descripcion: ";

        std::cin.ignore();
        std::cin.getline(pActual.Descripcion, 128);

        std::cout << std::endl
                  << "Ingrese stock del producto: ";
        std::cin >> pActual.CantidadDeUnid;

        std::cout << std::endl
                  << "Ingrese peso del producto: ";
        std::cin >> pActual.Peso;

        fwrite(&pActual, sizeof(Producto), 1, fStock);

        std::cout << std::endl
                  << "Ingrese id del producto: ";
        std::cin >> pActual.IDProducto;
    }

    fclose(fStock);
    return 0;
}
