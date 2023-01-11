#include <stdio.h>

#include "memoria/memoria.h"

int main() {
  int region_compartida = crear_region_carrito();
  Carrito *carrito = obtener_carrito_compartido(region_compartida);
  printf("Carrito obtenido");
  Carrito aux = *carrito;
  
  // printf("%d\n %d\n", aux->cantidad, (int) (aux->sig));
  imprimir_carro(*carrito);
  borrar_carro(carrito);
  return 0;
}