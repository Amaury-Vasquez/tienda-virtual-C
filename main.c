#include <stdio.h>

#include "carrito/carrito.h"

int main() {
  Carrito carro = leer_carro("./carrito/datos/2021630014.txt");
  imprimir_carro(carro);
  borrar_carro(&carro);
  return 0;
}