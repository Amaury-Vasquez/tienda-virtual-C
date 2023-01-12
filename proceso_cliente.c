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
  int borrar = 0;
  scanf("%d", &respuesta);
  Cliente cliente = menu(respuesta, clientes_compartidos);
  Carrito carrito;;
  if (respuesta == 2 || respuesta == 1) {
    char ruta[100] = "./carrito/datos/";
    strcat(ruta, cliente.name);
    if (respuesta == 2){
      guarda_cliente(cliente, "./cliente/");
      carrito = nuevo_carro();
    }
    else carrito = leer_carro(ruta);
    printf("Bienvenido de vuelta %s\n", cliente.name);
    imprimir_catalogo(*catalogo);
    ingresa_producto(&carrito, catalogo, &borrar);
    if (borrar) carrito = nuevo_carro();
    guardar_carro(carrito, ruta);
  }
  up(semaforo_servidor);
  return 0;
}