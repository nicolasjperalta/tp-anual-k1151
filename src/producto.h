#ifndef PRODUCTO_H
#define PRODUCTO_H

struct Producto
{
    int IDProducto;
    char Descripcion[128];
    int CantidadDeUnid;
    float Peso;
};

#endif