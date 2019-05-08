#include "matriz.h"

matriz* creaMatriz(int filas, int columnas) {
    int i;
    matriz *mat = 0;

    if (filas <= 0 || columnas <= 0)
        return 0; /*finalizar programa+mensaje de error????*/

    mat = (matriz*) malloc(sizeof (matriz));

    if (mat != 0) {
        mat->filas = filas;
        mat->columnas = columnas;
        mat->datos = (float*) malloc(filas * columnas * sizeof (float)); /*filas * columnas en lugar de filas*filas*/
        
        for (i = 0; i < filas * columnas; i++) { /*mesmo erro que na anotación anterior*/
            *((mat->datos) + i) = 0;
        }
    } else
        printf("Erro na reserva de memoria para a matriz");

    return mat;
}
