#ifndef LLAVES_SEMAFORO_H
#define LLAVES_SEMAFORO_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/types.h>

#define PERMISOS 0644

int crea_semaforo(key_t llave, int valor_inicial);
void down(int semid);
void up(int semid);
int obtener_semaforo_servidor();
int obtener_semaforo_cliente();
int obtener_semaforo_espera();

#endif