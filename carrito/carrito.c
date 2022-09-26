#include <stdlib.h>
#include <string.h>

#include "carrito.h"
#include "../leer_archivo/leer_archivo.h"

// Creacion del carro y elementos

Carrito nuevo_carro() {return NULL;}

Carrito nuevo_elemento(Producto p, int n) {
  Carrito elemento = (Carrito) malloc(sizeof(struct CARRO));
  elemento->producto = p;
  elemento->cantidad = n;
  elemento->sig = NULL;
}


// Operaciones de modificacion del carro

void add_al_carro(Carrito *carro, Producto producto, int n) {
  if (*carro == NULL)
    *carro = nuevo_elemento(producto, n);
  else {
    Carrito p, q;
    int existe = 0;
    p = *carro;

    while (p != NULL) {
      q = p;
      /* Verifica que el producto no se encuentre en existencia
         En caso de ya encontrarse, solo añade la cantidad   */
      if (strcmp(producto.id, p->producto.id) == 0) {
        p->cantidad += n;
        existe = 1;
        p = NULL;
      }
      else 
        p = p->sig;
    }
    // En caso de ser un producto nuevo lo añade al final
    if (existe == 0 && q != NULL) 
      q->sig = nuevo_elemento(producto, n);
  }
}

Carrito eliminar_del_carro(Carrito *carro, char id[ID_SIZE], int cantidad) {
  if (*carro != NULL) {
    Carrito p = *carro, q = NULL;
    while (p != NULL) {

      // Se ejecuta si encuentra coincidencias
      if (strcmp(id, p->producto.id) == 0) {
        Carrito tmp =  p;
        int c = tmp->cantidad;

        // Elimina el elemento si la resta de cantidades es <= 0
        if (c - cantidad <= 0) {
          if (q != NULL)
            q->sig = p->sig;
          tmp->cantidad = 0;
          free(p);
        }

        // Si la resta es >= 0 actualiza la cantidad
        else {
          int aux = c - cantidad;
          tmp->cantidad = aux;
          p->cantidad = aux;
        }

        // Regresa el producto actualizado
        return tmp;
      }

      // Continua recorriendo la lista
      q = p;
      p = p->sig;
    }
  }
  // En caso de no encontrar coincidencias regresa un producto vacio
  return NULL;
}


// Operaciones de impresion del carro

void imprimir_carro(Carrito carro) {
  printf("\n\t||\t\tCarrito de compras\t\t||\n");
  if (carro == NULL)
    printf("\t\t\tEl carrito esta vacio\n");
  // Imprime toda la lista
  else {
    Carrito tmp = carro;
    while (tmp != NULL) {
      imprimir_producto(tmp->producto);
      printf("\t\tCantidad: %d\n", tmp->cantidad);
      tmp = tmp->sig;      
    }
  }
}


// Operaciones con archivo

/* Formato de archivo de carrito 
  id
  nombre
  precio
  cantidad
  
  id
  nombre
  ...
*/

//Guarda el carrito en la ruta correspondiente
void guardar_carro(Carrito carro, char ruta[25]) {
  FILE* archivo = abrir_archivo(ruta, "w");
  
  // Se ejecuta en caso de que se haya abierto el archivo correctamente
  if (archivo != NULL) {
    printf("\n\t\tArchivo de carrito abierto...\n");
    Carrito aux = carro;
    Producto tmp;

    while (aux != NULL) {
      tmp = aux->producto;
      fprintf(archivo, "%s\n%s\n%.2f\n%d\n\n", tmp.id, tmp.nombre, tmp.precio, aux->cantidad);
      aux = aux->sig;
    }
    fclose(archivo);
  }
  else
    printf("\n\t\t¡Error al guardar el carrito!\n");
}

// Lee el archivo de carrito, recibe la ruta del archivo
Carrito leer_carro(char ruta[]) {
  FILE *archivo = abrir_archivo(ruta, "r");
  Carrito carro = nuevo_carro();

  // Se ejecuta solo si el archivo se abre correctamente
  if (archivo != NULL) {
    Producto tmp;
    int cantidad;
    char cad[5];

    // Lee hasta el final del archivo
    while (!feof(archivo)) {
      // Lectura de producto y cantidad
      tmp = leer_producto_archivo(archivo);
      fscanf(archivo, "%d\n", &cantidad);
      // Creacion de objeto en el carrito
      add_al_carro(&carro, tmp, cantidad);
    } 
  }

  fclose(archivo);
  return carro;
}


// Eliminacion del carro y liberacion de memoria

void borrar_carro(Carrito *carro) {
  Carrito tmp;
  while (*carro != NULL) {
    tmp = (*carro)->sig;
    free(*carro);
    *carro = tmp;
  }
}