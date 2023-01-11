echo "Iniciando compilación..."
gcc proceso_cliente.c carrito/carrito.c catalogo/catalogo.c producto/producto.c leer_archivo/leer_archivo.c memoria/memoria.c semaforo/semaforo.c cliente/cliente.c usuario/usuario.c -o proceso_cliente
gcc proceso_servidor.c carrito/carrito.c catalogo/catalogo.c producto/producto.c leer_archivo/leer_archivo.c memoria/memoria.c semaforo/semaforo.c cliente/cliente.c -o proceso_servidor
echo "Compilación terminada"