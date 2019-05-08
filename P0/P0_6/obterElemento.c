#include "matriz.h"

float obterElemento(int fila, int columna, matriz *M) {
    
    float x; /*a funcion devolve un float,polo que x debe selo*/

    if (M != 0) {
        if ((fila < 0 || fila > M->filas) || (columna < 0 || columna > M->columnas)) {
            printf("Ese elemento non existe.\n");
            return 0;
        }
        x = *((M->datos) + (fila-1) * (M->columnas) + (columna-1));/*debemos introducir a corrección de -1 porque en C,a numeración das matrices empeza no elemento 0, non no 1*/
             
       return x;
       
    } else
        printf("A matriz non existe!!\n");
return 0; /*É recomendable devolver sempre un valor naquelas funcións que o requiran, para evitar posibles erros*/

}
