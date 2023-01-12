#include "usuario.h"

void imprime_solicitud_usuario() {
  printf("Ingrese su nombre de usuario: ");
}

void imprime_solicitud_contraseña() {
  printf("Ingrese su contraseña: ");
}

void imprime_error() {
  printf("El nombre de usuario o la contraseña son incorrectos\n");
}

char *lee_usuario() {
  char *usuario = malloc(sizeof(char) * CLIENT_NAME_MAX_SIZE);
  scanf("%s", usuario);
  return usuario;
}

char *lee_contraseña() {
  char *contraseña = malloc(sizeof(char) * PASSWORD_SIZE);
  scanf("%s", contraseña);
  return contraseña;
}

void imprime_menu() {
  printf("\t\t||\t\tBienvenido a la tienda virtual\t\t||\t\t\n\n");
  printf("Ingresa 1 para iniciar sesion\n");
  printf("Ingresa 2 para registrarte\n");
  printf("Ingresa cualquier caracter para salir\n");
}

Cliente inicio_sesion(Clientes_compartido *clientes_compartido) {
  Cliente cliente;
  cliente.carro = NULL;
  int limite = clientes_compartido->num_clientes;
  int existe = 0;
  while(!existe) {
    imprime_solicitud_usuario();
    strcpy(cliente.name, lee_usuario());
    imprime_solicitud_contraseña();
    strcpy(cliente.password, lee_contraseña());
    int i = 0;
    while(i < limite && !existe) {
      if(strcmp(cliente.name, clientes_compartido->clientes[i].name) == 0) {
        if(strcmp(cliente.password, clientes_compartido->clientes[i].password) == 0) {
          existe = 1;
          cliente = clientes_compartido->clientes[i];
          return cliente;
        }
      }
      i++;
    }
    imprime_error();
  }
  return cliente;
}

Cliente menu(int respuesta, Clientes_compartido *clientes_compartido) {
  Cliente cliente;
  switch (respuesta) {
    case 1:
      cliente = inicio_sesion(clientes_compartido);
      break;
    case 2:
      cliente = lee_nuevo_cliente(clientes_compartido->clientes, clientes_compartido->num_clientes);
      break;
    case 0:
      printf("Gracias por visitarnos\n");
      break;
    default:
      printf("Opcion invalida\n");
      break;
  }
  return cliente;
}

void ingresa_producto(Carrito *carrito, Catalogo *catalogo, int *borrar) {
  char id[ID_SIZE];
  int cantidad;
  while(1) {
    printf("\nEste es tu carrito de compras\n");
    imprimir_carro(*carrito);
    printf("Ingresa 0 para cerrar el programa\n");
    printf("Ingresa 1 pagar\n");
    printf("Ingresa -1 para robar los productos\n");
    printf("Ingresa el id del producto que deseas comprar: ");
    scanf("%s", id);
    if (strcmp("0", id) == 0)
      return;
    if (strcmp("-1", id) == 0) {
      printf("Robaste los productos con exito, pero tu carrito quedara guardado\n");
      return;
    }
    if (strcmp("1", id) == 0) {
      double total = pagar(carrito);
      printf("El total a pagar es: %f\n", total);
      printf("Pagado con exito\n");
      *borrar = 1;
      return;
    }
    printf("Ingresa la cantidad que deseas comprar: ");
    scanf("%d", &cantidad);
    getchar();
    int existe;
    Producto producto = obtener_producto(catalogo, id, cantidad, &existe);
    printf("\n");
    if (existe == 1) {
      add_al_carro(carrito, producto, cantidad);
      printf("Se añadio con éxito\n");
    }
    else if (existe == 0) printf("El producto no existo\n");
    else if (existe == -1) 
    printf("No existen suficientes productos en existencia\n");
  }
}

double pagar(Carrito *carrito) {
  double total = 0;
  Carrito aux = *carrito;
  while(aux != NULL) {
    total += aux->producto.precio * aux->cantidad;
    aux = aux->sig;
  }
  return total;
}