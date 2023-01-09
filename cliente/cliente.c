#include "cliente.h"


int carga_clientes(char clientes[][CLIENT_NAME_MAX_SIZE]){
    FILE *flujo = abrir_archivo("clientes.txt","r");
    int i = 0;
    while(!feof(flujo)){
        leer_cadena(flujo, CLIENT_NAME_MAX_SIZE, &(clientes[i][0]));
        i++;
    }
    fclose(flujo);
    return i;
} 

int verifica_existencia(Cliente cliente){
    char cad[100][CLIENT_NAME_MAX_SIZE];
    int aux = carga_clientes(&cad[0]), i;
    for(i = 0; i < aux; i++){
        if(strcmp(cliente.name, cad[i]) == 0){
           return 1;
        }
    }
    return 0;
}



Cliente lee_cliente(){
    char nombre[CLIENT_NAME_MAX_SIZE];
    char contraseña[PASSWORD_SIZE];
    char auxcontraseña[PASSWORD_SIZE];
    Cliente nuevo;
    int aux;
    do {
        printf("Ingrese un nombre de usuario: ");
        scanf("%s", nuevo.name);
        aux = verifica_existencia(nuevo);
        if(aux)
         printf("Este nombre de usuario ya existe, ingrese otro\n");
    } while(aux);
    printf("Ingrese una contraseña: ");
    scanf("%s", nuevo.password);
    printf("Ingrese la contraseña nuevamente: ");
    scanf("%s", auxcontraseña);
    while(strcmp(nuevo.password, auxcontraseña) != 0){
        printf("Las contraseñas no coinciden, por favor ingresela nuevamente: \n");
        scanf("%s", auxcontraseña);
    }
    printf("Los datos han sido registrados exitosamente \n");
    return nuevo;
}

void imprime_cliente(Cliente cliente){
    printf("%s \n", cliente.name);
    printf("%s \n", cliente.password);
}

void guarda_cliente(Cliente cliente){
    FILE *flujo;
    flujo = abrir_archivo("clientes.txt","a");
    fprintf(flujo, "%s\n", cliente.name);
    fclose(flujo);
}