#include "cliente.h"


int carga_nombre_clientes(char *ruta, char clientes[][CLIENT_NAME_MAX_SIZE]){
  FILE *flujo = abrir_archivo(ruta, "r");
  int i = 0;
  while(!feof(flujo)){
    leer_cadena(flujo, CLIENT_NAME_MAX_SIZE, &(clientes[i][0]));
    i++;
  }
  fclose(flujo);
  return i;
} 

int verifica_existencia(char cliente[NAME_MAX_SIZE], Cliente clientes[], int n) {
  int i;
  for(i = 0; i < n; i++){
    if(strcmp(cliente, clientes[i].name) == 0){
      return 1;
    }
  }
  return 0;
}

Cliente lee_nuevo_cliente(Cliente clientes[], int n){
  char nombre[CLIENT_NAME_MAX_SIZE];
  char auxcontraseña[PASSWORD_SIZE];
  Cliente nuevo;
  int aux;
  do {
    printf("Ingrese un nombre de usuario: ");
    scanf("%s", nuevo.name);
    aux = verifica_existencia(nuevo.name, clientes, n);
    if(aux)
      printf("Este nombre de usuario ya existe, ingrese otro\n");
  } while(aux);
  printf("Ingrese una contraseña: ");
  scanf("%s", nuevo.password);
  printf("Ingrese la contraseña nuevamente: ");
  scanf("%s", auxcontraseña);
  while(strcmp(nuevo.password, auxcontraseña) != 0) {
    printf("Las contraseñas no coinciden, por favor ingresela nuevamente: \n");
    scanf("%s", auxcontraseña);
  }
  printf("Los datos han sido registrados exitosamente \n");
  return nuevo;
}

void imprime_cliente(Cliente cliente){
  printf("Usuario:%s \n", cliente.name);
  printf("Password:%s \n\n", cliente.password);
}

void guarda_cliente(Cliente cliente, char *ruta){
  FILE *flujo;
  char ruta_flujo[50];
  strcpy(ruta_flujo, ruta);
  strcat(ruta_flujo, "clientes.txt");
  printf("%s\n", ruta_flujo);
  flujo = abrir_archivo(ruta_flujo, "a");
  fprintf(flujo, "%s\n", cliente.name);
  fclose(flujo);
  char ruta_archivo[100];
  strcpy(ruta_archivo, ruta);
  strcat(ruta_archivo, "datos/");
  strcat(ruta_archivo, cliente.name);
  printf("%s\n", ruta_archivo);
  FILE *archivo_cliente = abrir_archivo(ruta_archivo, "w");
  fprintf(archivo_cliente, "%s\n", cliente.password);
}