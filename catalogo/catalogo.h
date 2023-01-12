#ifndef CATALOGO_H
#define CATALOGO_H

#define MAX_PRODUCTOS 1000

#include <stdio.h>
#include <string.h>
#include "../carrito/carrito.h"
#include "../producto/producto.h"
#include "../leer_archivo/leer_archivo.h"

typedef struct CAMPO_PRODUCTO {
  Producto producto;
  int existencias;
} Campo_Producto;

typedef struct CATALOGO {
  int num_productos;
  Campo_Producto productos[MAX_PRODUCTOS];
} Catalogo;

Catalogo leer_catalogo(char *);
Producto obtener_producto(Catalogo *, char *id, int, int *existe);
void imprimir_catalogo(Catalogo);
void guardar_catalogo(Catalogo, char*);

#endif