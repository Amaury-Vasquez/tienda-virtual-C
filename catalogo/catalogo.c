#include "catalogo.h"

Catalogo leer_catalogo() {
  Catalogo catalogo = leer_carro("./catalogo.txt");
  return catalogo;
}

Producto obtener_producto(Catalogo catalogo, char *id, int cantidad, int *existe) {
  Catalogo aux = catalogo;
  while (aux != NULL) {
    if (strcmp(aux->producto.id, id) == 0) {
      if(aux->cantidad >= cantidad) {
        *existe = 1;
        aux->cantidad -= cantidad;
      }
      else *existe = -1;
      return aux->producto;
    }
    aux = aux->sig;
  }
  *existe = 0;
  Producto producto;
  return producto;  
}

void imprimir_catalogo(Catalogo catalogo) {
  Catalogo aux = catalogo;
  printf("\n\t||\t\tCatalogo de productos\t\t||\n");
  while (aux != NULL) {
    imprimir_producto(aux->producto);
    printf("\t\tExistencias: %d\n", aux->cantidad);
    aux = aux->sig;
  }
  printf("\n");
}

void borrar_catalogo(Catalogo *catalogo) {
  borrar_carro(catalogo);
}