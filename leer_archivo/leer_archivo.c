#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leer_archivo.h"

FILE *abrir_archivo(char *ruta, char *modo) {
  FILE *archivo = fopen(ruta, modo);
  if (archivo == NULL)
    printf("¡Error al abrir el archivo!\n");
  return archivo;
}

void leer_cadena(FILE *archivo, int size, char *cad) {
  fgets(cad, size, archivo);
  limpiar_cadena(cad);
}

void limpiar_cadena(char *cad) {
  int len = strlen(cad);
  cad[len - 1] = '\0';
}

// Lectura/Escritura de carrito
