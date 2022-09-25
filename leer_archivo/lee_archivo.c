#include <stdio.h>
#include <stdlib.h>

File *abrir_archivo(char *ruta, char *modo) {
  File *archivo = fopen(ruta, modo);
  if (archivo == NULL)
    printf("No se puede abrir el archivo\n")
  return archivo;
}
