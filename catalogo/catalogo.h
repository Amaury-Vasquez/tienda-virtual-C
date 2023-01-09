#ifndef CATALOGO_H
#define CATALOGO_H

#include <string.h>
#include "../producto/producto.h"
#include "../carrito/carrito.h"

typedef struct CARRO* Catalogo;

Catalogo leer_catalogo();
Producto obtener_producto(Catalogo, char *id, int, int *existe);
void imprimir_catalogo(Catalogo);
void borrar_catalogo(Catalogo *);

#endif