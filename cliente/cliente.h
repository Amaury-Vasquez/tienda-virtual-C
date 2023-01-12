#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../carrito/carrito.h"
#include "../leer_archivo/leer_archivo.h"

#define CLIENT_NAME_MAX_SIZE 30
#define HISTORY_SIZE 100
#define PASSWORD_SIZE 20

typedef struct CLIENTE {
  Carrito carro;
  char password[PASSWORD_SIZE];
  char name[CLIENT_NAME_MAX_SIZE];
} Cliente;

typedef struct CLIENTES_COMPARTIDO {
  Cliente clientes[100];
  int num_clientes;
} Clientes_compartido;

// Operaciones de administración del cliente
int carga_nombre_clientes(char *ruta, char [][CLIENT_NAME_MAX_SIZE]);
Cliente lee_nuevo_cliente(Cliente clientes[], int n);
// Cliente nuevo_cliente();
void guarda_cliente(Cliente, char *);
void imprime_cliente(Cliente);
int verifica_existencia(char nombre[CLIENT_NAME_MAX_SIZE], Cliente clientes[], int n);

#endif