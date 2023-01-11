#include <stdio.h>

#include "memoria/memoria.h"

int main() {
  int region_catalogo = crear_region_catalogo();
  Catalogo *catalogo = obtener_catalogo_compartido(region_catalogo);
  *catalogo = leer_catalogo("catalogo/catalogo.txt");
  imprimir_catalogo(*catalogo);
  int region_clientes = crear_region_clientes();
  Clientes_compartido *clientes_compartidos = obtener_cliente_compartido(region_clientes);
  int region_carrito = crear_region_carrito();
  Rutas_carrito *rutas_carrito = obtener_carrito_compartido(region_carrito);
  int num_clientes = carga_nombre_clientes("./cliente/clientes.txt", rutas_carrito->rutas);
  printf("Numero de clientes: %d\n", num_clientes);
  int i;
  for(i = 0; i < num_clientes; i++) {
    printf("Cliente %d: %s\n", i, rutas_carrito->rutas[i]);
  }
  return 0;
}