#include <stdio.h>
#include <unistd.h>

#include "memoria/memoria.h"
#include "semaforo/semaforo.h"

volatile sig_atomic_t termina = 0;

void term(int sigum);

int main() {
  struct sigaction action;
  memset(&action, 0, sizeof(struct sigaction));
  action.sa_handler = term;
  sigaction(SIGTERM, &action, NULL);

  int region_catalogo = crear_region_catalogo();
  Catalogo *catalogo = obtener_catalogo_compartido(region_catalogo);
  *catalogo = leer_catalogo("catalogo/catalogo.txt");
  imprimir_catalogo(*catalogo);
  int region_clientes = crear_region_clientes();
  Clientes_compartido *clientes_compartidos = obtener_cliente_compartido(region_clientes);
  int region_carrito = crear_region_carrito();
  Rutas_carrito *rutas_carrito = obtener_carrito_compartido(region_carrito);
  clientes_compartidos->num_clientes = carga_nombre_clientes("./cliente/clientes.txt", rutas_carrito->rutas);
  for (int i = 0; i < clientes_compartidos->num_clientes; i++) {
    strcpy(clientes_compartidos->clientes[i].name, rutas_carrito->rutas[i]);
    char ruta[100] = "./cliente/datos/";
    strcat(ruta, rutas_carrito->rutas[i]);
    printf("%s", ruta);
    FILE *archivo = abrir_archivo(ruta, "r");
    leer_cadena(archivo, PASSWORD_SIZE, &(clientes_compartidos->clientes[i].password[0]));
    fclose(archivo);
  }
  for(int i = 0; i < clientes_compartidos->num_clientes; i++) {
    imprime_cliente(clientes_compartidos->clientes[i]);
  }
  int semaforo_servidor = obtener_semaforo_servidor();
  // int semaforo_cliente = obtener_semaforo_cliente();

  while (1) {
    printf("Esperando peticiones...");
    down(semaforo_servidor);
    guardar_catalogo(*catalogo, "catalogo/catalogo.txt");
  }
  shmdt(&clientes_compartidos);
  shmdt(&rutas_carrito);
  shmdt(&catalogo);
  return 0;
}

void term(int sigum) {
  printf("\nTerminando proceso...\n");
  termina = 1;
}
