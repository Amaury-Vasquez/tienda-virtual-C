#include "../carrito/carrito.h"

#define CLIENT_ID_SIZE 20
#define CLIENT_NAME_MAX_SIZE 30
#define HISTORY_SIZE 100
#define PASSWORD_SIZE 20

typedef struct CLIENTE {
  Carrito carro;
  char id[CLIENT_ID_SIZE];
  char password[PASSWORD_SIZE];
  char name[CLIENT_NAME_MAX_SIZE];
  float historial_compras[HISTORY_SIZE];
} Cliente;

// Operaciones de administración del cliente
Cliente carga_cliente();
Cliente lee_cliente();
Cliente nuevo_cliente();
void guarda_cliente(Cliente);