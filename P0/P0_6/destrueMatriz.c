#include "matriz.h"

void destrueMatriz(matriz *M) {
    if (M != 0) {
        free(M->datos);
        free(M);
        M->datos=NULL; /*debemos facer que o vector de punteiros apunte a NULL para librar a memoria correctamente*/
    }
}
