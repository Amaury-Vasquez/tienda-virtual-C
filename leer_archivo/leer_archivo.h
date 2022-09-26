#ifndef LEER_ARCHIVO_H
#define LEER_ARCHIVO_H

#include <stdio.h>
#include "../carrito/carrito.h"

FILE *abrir_archivo(char *ruta, char *modo);
void leer_cadena(FILE *archivo, int size, char *cad);
void limpiar_cadena(char *cad);

#endif