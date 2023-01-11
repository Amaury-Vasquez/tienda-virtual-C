#include <stdio.h>

#include "catalogo/catalogo.h"

int main() {
  Catalogo catalogo = leer_catalogo("catalogo/catalogo.txt");
  imprimir_catalogo(catalogo);
  guardar_catalogo(catalogo, "catalogo/catalogo.txt");
  return 0;
}