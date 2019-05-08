/*
 * PROGRAMA PARA REALIZAR OPERACIÓNS BÁSICAS CUNHA MATRIZ DINÁMICA
 *
 * OBXECTIVO: DEPURAR USANDO AS FERRAMENTAS DO NETBEANS. O PROGRAMA TEN COMO MÍNIMO SEIS ERROS
 * DOCUMENTAR AS CORRECCIÓNS INTRODUCIDAS, POÑENDO UN COMENTARIO COA SENTENCIA INCORRECTA AO
 * LADO DA SENTENCIA CORRIXIDA
 *
 * PROBAS:
 * - número de filas ou columnas: 0
 * - acceder a un dato con índices negativos
 * - verificar todas as operacións, para matrices pequenas (2,3 filas/cols)
 *      - número de filas e columnas distintos nas dúas matrices
 *      - número de filas igual e de columnas distinto
 *      - número de columnas igual e de filas distinto
 */


#include "matriz.h"

int main(int argc, char** argv) {
    int  f, c; /*aparecían tamén as variables k,i , que non eran utilizadas no main.c*/
    float valor;
    matriz *a = 0, *b = 0, *aux = 0;
    char opcion[1], resp[1];


    do {
        do {
            printf("---------------------Libreria matrices---------------------\n\n");
            printf("1-Crear matriz\n");
            printf("2-Asignar elementos\n");
            printf("3-Obter elemento\n");
            printf("4-Imprime matriz\n");
            printf("5-Sumar matrices\n");
            printf("6-Produto por un escalar\n");
            printf("7-Produto de matrices\n");
            printf("8-Eliminar matriz\n");
            printf("0-Sair\n");
            scanf("%s", opcion);
        } while (opcion[0] < '0' || opcion[0] > '8');

        switch (opcion[0]) { /*debemos incluír o caso no que o nº de filas ou columnas sexa menor ou igual a 0 (bucle do-while)*/
            case '1':
               do{ 
                  
                printf("Introduza o numero de filas da matriz 'a': ");
                scanf("%d", &f); /*debe ser %d e non %f*/
                printf("Introduza o numero de columnas da matriz 'a': ");
                scanf("%d", &c);
               if(f<=0 || c<=0)
               printf("\nÍndices non válidos, introduza de novo os índices\n");}while(f<=0 || c<=0);
                destrueMatriz(a); /*realiza a comprobación de se hai algunha matriz xa creada dunha execucion anterior: se é así, libera a súa memoria*/
                a = creaMatriz(f, c);
                
                do{printf("Introduza o numero de filas da matriz 'b': ");
                scanf("%d", &f); /*debe ser %d e non %f*/
                printf("Introduza o numero de columnas da matriz 'b': ");
                scanf("%d", &c);
                if(f<=0 || c<=0)
                printf("\nÍndices non válidos, introduza de novo os índices\n");}while(f<=0 || c<=0);
                destrueMatriz(b); /*igual que na nota anterior*/
                b = creaMatriz(f, c);
                
                break;
            case '2': 
                printf("Matriz A\n");
                for (f = 0; f < a->filas; f++)
                    for (c = 0; c < a->columnas; c++) {
                        printf("Introduza o valor da posicion %dx%d: ", f + 1, c + 1); 
                        scanf("%f", &valor);
                        asignarElemento(f, c, valor, a);
                    }
                printf("Matriz B\n");
                for (f = 0; f < b->filas; f++)
                    for (c = 0; c < b->columnas; c++) {
                        printf("Introduza o valor da posicion %dx%d: ", f + 1, c + 1);
                        scanf("%f", &valor);
                        asignarElemento(f, c, valor, b); /*debemos pasar a matriz b*/
                    }

                break;
            case '3': 
                do {
                    printf("De que matriz queres ver o elemento? (a/b): ");
                    fflush(stdin);
                    scanf("%s", &resp);
                } while (resp[0] != 'a' && resp[0] != 'b');
                printf("Introducir fila e columna (fila columna): ");
                scanf("%d %d", &f, &c);            
                if (resp[0] == 'a') { /*as matrices a e b estaban intercambiados ao chamar a función*/
                    valor = obterElemento(f, c, a);
                    printf("O valor da fila e columna seleccionada e: %f\n", valor);
                } else if (resp[0] == 'b') {
                    valor = obterElemento(f, c, b);
                    printf("O valor da fila e columna seleccionada e: %f\n", valor);
                }
                break;
            case '4': 
                printf("Matriz A\n");
                imprimeMatriz(a);
                printf("Matriz B\n");
                imprimeMatriz(b);
                break;
            case '5': 
                aux = suma(a, b);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                break;
            case '6': 
                printf("Escalar polo que sera multiplicada a matriz: ");
                scanf("%f", &valor);
                aux = prodEscalar(valor, a);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                aux = prodEscalar(valor, b);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                break;
            case '7':
                aux = produto(a, b);
                imprimeMatriz(aux);
                destrueMatriz(aux);
                break;
            case '8': 
                destrueMatriz(a);
                destrueMatriz(b);
                printf("Matrices eliminadas...\n");
                break;
        }
    } while (opcion[0] != '0');
    
    free(a); /*debemos liberar a memoria antes de finalizar o programa*/
    free(b); 

    return (EXIT_SUCCESS);
}
