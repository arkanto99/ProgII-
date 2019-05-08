#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *datos;
    int filas, columnas;
} matriz;

void asignarElemento(int fila, int columna, float valor, matriz *M);
matriz* creaMatriz(int filas, int columnas);
void destrueMatriz(matriz *M);
void imprimeMatriz(matriz *M);
float obterElemento(int fila, int columna, matriz *M);
matriz* prodEscalar(float s, matriz *M);
matriz* produto(matriz *M1, matriz *M2);
matriz* suma(matriz *M1, matriz *M2);

