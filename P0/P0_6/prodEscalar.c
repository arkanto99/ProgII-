#include "matriz.h"

matriz* prodEscalar(float s, matriz *M) {
    matriz *aux = 0;
    int i;
    if (M != 0) {
        aux = creaMatriz(M->filas, M->columnas); /*filas e columnas estaban intercambiadas, polo que se se tiñan matrices 2x3, se creaban 3x2 ao multiplicar polo escalar*/

        for (i = 0; i < aux->filas * aux->columnas; i++) {
            *(aux->datos + i) = *(M->datos + i) * s;
        }

        return aux;
    } else
        printf("A matriz non existe!!\n");
return 0; /*É recomendable devolver sempre un valor naquelas funcións que o requiran, para evitar posibles erros*/

}
