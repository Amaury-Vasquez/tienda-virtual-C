#include "../producto/producto.h"

struct CARRO {
  Producto producto;
  int cantidad;
  struct CARRO *sig;
};

typedef struct CARRO* Carrito;

// Creacion del carro y elementos
Carrito nuevo_carro();
Carrito nuevo_elemento(Producto, int);

// Operaciones de modificacion del carro
void add_al_carro(Carrito *, Producto, int);
Carrito eliminar_del_carro(Carrito *, char id[ID_SIZE], int);

// Operaciones de impresion del carro
void imprimir_carro(Carrito);

// Guardar carro en archivo
void guardar_carro(Carrito, char []);

// Borrar carro y liberar memoria
void borrar_carro(Carrito *);