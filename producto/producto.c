#include <stdio.h>
#include <string.h>

#include "../leer_archivo/leer_archivo.h"
#include "producto.h"

Producto leer_producto_archivo(FILE *archivo) {
  Producto prod;
  if (archivo != NULL && !feof(archivo)) {
    leer_cadena(archivo, ID_SIZE, &prod.id[0]);
    leer_cadena(archivo, NAME_MAX_SIZE, &prod.nombre[0]);
    fscanf(archivo, "%f\n", &prod.precio);
  }
  return prod;
}

Producto leer_producto_teclado() {
  float precio;
  char id[ID_SIZE], nombre[NAME_MAX_SIZE];

  // nombre
  printf("\tIngrese nombre: ");
  fgets(nombre, NAME_MAX_SIZE, stdin);
  int len = strlen(nombre);
  nombre[len - 1] = 0;
  // id
  printf("\tIngrese id: ");
  scanf("%s", id);
  // precio
  printf("\tIngrese precio: ");
  scanf("%f", &precio);
  // lee el \n del residuo
  getchar();

  Producto nuevo_producto;
  nuevo_producto.precio = precio;
  strcpy(nuevo_producto.id, id);
  strcpy(nuevo_producto.nombre, nombre);

  return nuevo_producto;
}

void imprimir_producto(Producto p) {
  printf("\n\t\tId: %s\n", p.id);
  printf("\t\tNombre de producto: %s\n", p.nombre);
  printf("\t\tPrecio: $%.2f\n", p.precio);
}