#include "matriz.h"

matriz* produto(matriz *M1, matriz *M2) {
    matriz *aux = 0;
    int i, k, l;
    if (M1 != 0 && M2 != 0) {
        if (M1->columnas != M2->filas) { /*columas e filas estaban intercambiados*/
            printf("O numero de columnas da primeira matriz e de filas da segunda deben ser os mesmos");
            return aux;
        }

        aux = creaMatriz(M1->filas, M2->columnas);
        for (i = 0; i < M1->filas; i++)
            for (k = 0; k < M2->columnas; k++) {
                *(aux->datos + i * M2->columnas + k) = 0;
                for (l = 0; l < M1->columnas; l++) {
                    *(aux->datos + i * M2->columnas + k) += *(M1->datos + i * M1->columnas + l) * *(M2->datos + l * M2->columnas + k); /*las filas de M2 deben moverse a la misma velocidad que las columnas de M1, por eso es l*M2 columnas, y no i*M2 columnas*/
                }
            }

        return aux;
    } else
        printf("Algunha das matrices non existe!!\n");
return 0; /*É recomendable devolver sempre un valor naquelas funcións que o requiran, para evitar posibles erros*/
}
