#ifndef MEMORIA_H
#define MEMORIA_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../carrito/carrito.h"
#include "../catalogo/catalogo.h"
#include "../cliente/cliente.h"

#define ARCHIVO_CLIENTES "./.clientes_archivo"
#define ARCHIVO_CATALOGO "./.catalogo_archivo"
#define ARCHIVO_CARRITO "./.carrito_archivo"
#define LLAVE_CLIENTES 'c'
#define LLAVE_CATALOGO 'p'
#define LLAVE_CARRITO 'u'
#define PERMISOS S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH | IPC_CREAT



void verifica(int);
key_t crear_llave(char *, char);
int crear_region_clientes(); 
int crear_region_catalogo();
int crear_region_carrito();

Clientes_compartido *obtener_cliente_compartido(int);
Catalogo *obtener_catalogo_compartido(int);
Rutas_carrito *obtener_carrito_compartido(int);

#endif