#ifndef INICIO_SESION_H
#define INICIO_SESION_H

#include "../cliente/cliente.h"

void imprime_solicitud_usuario();
void imprime_solicitud_contrasena();
void imprime_error();
char *lee_usuario();
char *lee_contrasena();
void imprime_menu();
Cliente menu(int);
Cliente inicio_sesion();
#endif