#ifndef INICIO_SESION_H
#define INICIO_SESION_H

#include "../cliente/cliente.h"
#include "../producto/producto.h"
#include "../catalogo/catalogo.h"

void imprime_solicitud_usuario();
void imprime_solicitud_contrasena();
void imprime_error();
char *lee_usuario();
char *lee_contrasena();
void imprime_menu();
Cliente menu(int, Clientes_compartido *);
Cliente inicio_sesion(Clientes_compartido *);
void ingresa_producto(Carrito *carrito, Catalogo *, int *);
double pagar(Carrito *carrito);
#endif