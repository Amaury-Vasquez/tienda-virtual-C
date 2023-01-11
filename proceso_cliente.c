#include <stdio.h>

#include "memoria/memoria.h"
#include "usuario/usuario.h"

int main() {
  int respuesta;
  imprime_menu();
  scanf("%d", &respuesta);
  
  // int region_compartida = crear_region_catalogo();
  // Catalogo *catalogo = obtener_catalogo_compartido(region_compartida);
  // imprimir_catalogo(*catalogo);
  return 0;
}