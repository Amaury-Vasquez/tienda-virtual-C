#include <stdio.h>
#include "cliente.h"

int main(){
  Cliente cliente;
  int i;
  int aux;
  char cad [100][CLIENT_NAME_MAX_SIZE];
  cliente=lee_cliente();
   imprime_cliente(cliente);
   guarda_cliente(cliente);
  aux=carga_clientes(&cad[0]);
  
  // for(i=0;i<=aux;i++){
  //   printf(" \t %s \n",cad[i]);
  // }

   return 0;
}

