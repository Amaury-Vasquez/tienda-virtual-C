#include <stdio.h>
#include "carrito/carrito.h"

int main() {
  Carrito carro = nuevo_carro();
  Producto productos[5];
  int i;
  for (i = 0; i < 5; i++) {  
    productos[i] = leer_producto();
    add_al_carro(&carro, productos[i], i + 1);
  }
  imprimir_carro(carro);
  eliminar_del_carro(&carro, productos[4].id, 2);
  eliminar_del_carro(&carro, productos[2].id, 4);
  guardar_carro(carro, "./carrito/datos/2021630014.txt");
  imprimir_carro(carro);
  borrar_carro(&carro);
  return 0;
}