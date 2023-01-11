echo "\nIniciando compilación...\n"
gcc proceso_cliente.c carrito/carrito.c producto/producto.c leer_archivo/leer_archivo.c memoria/memoria.c semaforo/semaforo.c -o proceso_cliente
gcc proceso_servidor.c carrito/carrito.c producto/producto.c leer_archivo/leer_archivo.c memoria/memoria.c semaforo/semaforo.c -o proceso_servidor
echo "Compilación terminada\n\n"