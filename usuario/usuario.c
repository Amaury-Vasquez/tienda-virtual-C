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
  printf("Ingresa 0 para salir\n");
}

Cliente inicio_sesion() {
  Cliente cliente;
  cliente.carro = NULL;
  imprime_solicitud_usuario();
  strcpy(cliente.name, lee_usuario());
  imprime_solicitud_contraseña();
  strcpy(cliente.password, lee_contraseña());
  return cliente;
}

Cliente menu(int respuesta) {
  Cliente cliente;
  switch (respuesta) {
    case 1:
      
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