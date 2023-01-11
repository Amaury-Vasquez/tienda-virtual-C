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
      else imprime_error();
      i++;
    }
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
      // imprime_registro();
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