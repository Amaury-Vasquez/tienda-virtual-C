#include <stdio.h>

#include "memoria/memoria.h"
#include "semaforo/semaforo.h"

int main() {
  int region_catalogo = crear_region_catalogo();
  Catalogo *catalogo = obtener_catalogo_compartido(region_catalogo);
  *catalogo = leer_catalogo("catalogo/catalogo.txt");
  imprimir_catalogo(*catalogo);
  int region_clientes = crear_region_clientes();
  Clientes_compartido *clientes_compartidos = obtener_cliente_compartido(region_clientes);
  int region_carrito = crear_region_carrito();
  Rutas_carrito *rutas_carrito = obtener_carrito_compartido(region_carrito);
  clientes_compartidos->num_clientes = carga_nombre_clientes("./cliente/clientes.txt", rutas_carrito->rutas);
  sleep(50);
  return 0;
}
  // for(int i = 0; i < clientes_compartidos->num_clientes; i++) {
  //   if(strcmp(rutas_carrito->rutas[i], "") != 0) {
  //     char ruta[100] = "./cliente/datos/";
  //     strcat(ruta, rutas_carrito->rutas[i]);
  //     FILE *archivo = fopen(ruta, "w");
  //     fclose(archivo);
  //   }
  // }