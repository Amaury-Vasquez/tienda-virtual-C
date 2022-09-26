#ifndef PRODUCTO_H
#define PRODUCTO_H

#define ID_SIZE 30
#define NAME_MAX_SIZE 50

typedef struct Prod {
  float precio;
  char id[ID_SIZE];
  char nombre[NAME_MAX_SIZE];
} Producto;

Producto leer_producto_archivo();
Producto leer_producto_teclado();
void imprimir_producto(Producto);

#endif