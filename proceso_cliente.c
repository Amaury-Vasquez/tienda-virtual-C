#include <stdio.h>

#include "semaforo/semaforo.h"
#include "memoria/memoria.h"
#include "usuario/usuario.h"

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
  int semaforo_servidor = obtener_semaforo_servidor();

  int respuesta;
  imprime_menu();
  scanf("%d", &respuesta);
  Cliente cliente = menu(respuesta, clientes_compartidos);
  imprime_cliente(cliente);
  up(semaforo_servidor);
  return 0;
}