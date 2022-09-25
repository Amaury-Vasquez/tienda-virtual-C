#define ID_SIZE 30
#define NAME_MAX_SIZE 50

typedef struct Prod {
  float precio;
  char id[ID_SIZE];
  char nombre[NAME_MAX_SIZE];
} Producto;

Producto leer_producto();
void imprimir_producto(Producto);

