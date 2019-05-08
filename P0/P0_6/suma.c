
#include "matriz.h"

matriz* suma(matriz *M1, matriz *M2) {
    matriz *aux = 0;
    int i, k;

    if (M1 != 0 && M2 != 0) {
        if (M1->filas != M2->filas || M1->columnas != M2->columnas) {
            printf("O numero de filas e columnas deben ser os mesmos\n");
            return aux;
        }
        aux = creaMatriz(M1->filas, M1->columnas);
        for (i = 0; i < aux->filas; i++)
            for (k = 0; k < aux->columnas; k++) /*o bucle debe facer referencia ao número de columnas e non ao de filas*/
                *(aux->datos + i * aux->columnas + (k)) = *(M1->datos + i * M1->columnas + (k)) + *(M2->datos + i * M2->columnas + (k)); /*en ambos casos facíase referencia aos datos da matriz 2. Ademais, en ambas matrices facíase referencia ao elemento k-1 (fila-1), e non a k*/
        return aux;
    } else
        printf("Algunha das matrices non existe!!\n");
return 0; /*É recomendable devolver sempre un valor naquelas funcións que o requiran, para evitar posibles erros*/
}

