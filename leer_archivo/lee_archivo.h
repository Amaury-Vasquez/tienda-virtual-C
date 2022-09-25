#include <stdio.h>

FILE *abrir_archivo(char *ruta, char *modo);

/* Formato de archivos esperado 
  //          catalogo.txt                  //
  // Id Nombre_producto Precio Existencia   //  

  //              Carrito                   //
  //              Id.txt                    //
  //      Id Nombre_producto Precio         //  
  //      Id Nombre_producto Precio         //  
  //                ...                     //  
  
  //             Cliente                    //
  //              Id.txt                    //
  //            contraseña                  //   
  //         Id_carrito  Nombre             //
*/

