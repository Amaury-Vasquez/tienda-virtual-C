#include "semaforo.h"

int crea_semaforo(key_t llave, int valor_inicial) {
  int semid = semget(llave, 1, IPC_CREAT | PERMISOS);
  if (semid == -1)
    return -1;
  semctl(semid, 0, SETVAL, valor_inicial);
  return semid;
}

void down(int semid) {
  struct sembuf op_p[] = {0, -1, 0};
  semop(semid, op_p, 1);
}

void up(int semid) {
  struct sembuf op_v[] = {0, +1, 0};
  semop(semid, op_v, 1);
}

int obtener_semaforo_servidor() {
  key_t llave_servidor = ftok("llave_servidor", 's');
  return crea_semaforo(llave_servidor, 0);
}

int obtener_semaforo_cliente() {
  key_t llave_cliente = ftok("llave_cliente", 'c');
  return crea_semaforo(llave_cliente, 0);
}

int obtener_semaforo_espera() {
  key_t llave_espera = ftok("llave_espera", 'e');
  return crea_semaforo(llave_espera, 0);
}