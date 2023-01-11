#include "memoria.h"

void verifica(int region_compartida) {
  if (region_compartida == -1) {
    perror("Failed to create shared memory");
    exit(-1);
  }
}

key_t crear_llave(char nombre_region[], char llave_region) {
  key_t llave_memoria = ftok(nombre_region, llave_region);
  verifica(llave_memoria);
  return llave_memoria;
}

int crear_region_clientes() {
  key_t llave_memoria = crear_llave(ARCHIVO_CLIENTES, LLAVE_CLIENTES);
  int region_compartida = shmget(llave_memoria, sizeof(struct CLIENTE), PERMISOS);
  verifica(region_compartida);
  return region_compartida;
}

int crear_region_carrito() {
  key_t llave_memoria = crear_llave(ARCHIVO_CARRITO, LLAVE_CARRITO);
  int region_compartida = shmget(llave_memoria, sizeof(struct CARRO*), PERMISOS);
  verifica(region_compartida);
  return region_compartida;
}

int crear_region_catalogo() {
  key_t llave_memoria = crear_llave(ARCHIVO_CATALOGO, LLAVE_CATALOGO);
  int region_compartida = shmget(llave_memoria, sizeof(struct CARRO), PERMISOS);
  verifica(region_compartida);
  return region_compartida;
}

Cliente *obtener_cliente_compartido(int region_compartida) {
  return shmat(region_compartida, 0, 0);
}

Catalogo *obtener_catalogo_compartido(int region_compartida) {
  return shmat(region_compartida, 0, 0);
}

Carrito *obtener_carrito_compartido(int region_compartida) {
  return shmat(region_compartida, 0, 0);
}