#include <stdio.h>

#include "memoria/memoria.h"

int main() {
  int region_compartida = crear_region_carrito();
  Carrito *carrito = obtener_carrito_compartido(region_compartida);
  *carrito = leer_carro("./carrito/datos/2021630014.txt");
  imprimir_carro(*carrito);
  borrar_carro(carrito);
  sleep(30);
  return 0;
}