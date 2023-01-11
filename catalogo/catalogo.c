#include "catalogo.h"

Catalogo leer_catalogo(char *ruta) {
  Catalogo catalogo;
  catalogo.num_productos = 0;
  FILE *archivo = abrir_archivo(ruta, "r");
  if (archivo != NULL) {
    Producto producto;
    int i, existencias;
    while(!feof(archivo) && catalogo.num_productos < MAX_PRODUCTOS) {
      i = catalogo.num_productos;
      producto = leer_producto_archivo(archivo);
      fscanf(archivo, "%d\n", &existencias);
      catalogo.productos[i].producto = producto;
      catalogo.productos[i].existencias = existencias;
      catalogo.num_productos++;
    }
  }
  return catalogo;
}

Producto obtener_producto(Catalogo catalogo, char *id, int cantidad, int *existe) {
  Catalogo aux = catalogo;
  int i = 0;
  while(i < catalogo.num_productos) {
    if (strcmp(catalogo.productos[i].producto.id, id) == 0) {
      if (catalogo.productos[i].existencias >= cantidad) {
        *existe = 1;
        return catalogo.productos[i].producto;
      }
    }
    i++;
  }
  *existe = 0;
  return producto_vacio();  
}

void imprimir_catalogo(Catalogo catalogo) {
  printf("\n\t||\t\tCatalogo de productos\t\t||\n");
  int i = 0;
  while (i < catalogo.num_productos) {
    imprimir_producto(catalogo.productos[i].producto);
    printf("\t\tExistencias: %d\n", catalogo.productos[i].existencias);
    i++;
  }
  printf("\n");
}

void guardar_catalogo(Catalogo catalogo, char *ruta) {
  int i = 0;
  FILE *archivo = abrir_archivo(ruta, "w");
  if (archivo != NULL) {
    while (i < catalogo.num_productos) {
      Producto tmp = catalogo.productos[i].producto;
      int cantidad = catalogo.productos[i].existencias;
      fprintf(archivo, "%s\n%s\n%.2f\n%d\n\n", tmp.id, tmp.nombre, tmp.precio, cantidad);
      i++;    
    }
  }
  fclose(archivo);
}