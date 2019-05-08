/*
 * PROGRAMA PARA CALCULAR O FACTORIAL E A POTENCIA DE DOUS NÚMEROS ENTEIROS
 * PEDIDOS AO/Á USUARIO/A POR TECLADO.
 *
 * OBXECTIVO: DEPURAR USANDO AS FERRAMENTAS DO NETBEANS. 
 * O PROGRAMA TEN COMO MÍNIMO SEIS ERROS. DOCUMENTAR AS CORRECCIÓNS 
 * INTRODUCIDAS, POÑENDO UN COMENTARIO COA SENTENCIA INCORRECTA AO
 * LADO DA SENTENCIA CORRIXIDA
 * 
 * PROBAS: USAR OS CASOS
 * 0 0
 * 10 2
 * 2 10
 * 5.5 6.5
 * -2.3 -1
 * -5 1
 */
#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
float potencia(int n, int m); /*debemos cambiar aqui tamen "int" por "float"*/

int main(int argc, char** argv) {
    
    int a, b;
    int f;
    float p; /*"p" debe ser tipo float para o caso cando expoñente é negativo*/
    
    printf("Introduce dos números enteros: ");
    scanf("%d%d", &a, &b); /*faltaba "&" diante de "a"; substituín %f por %d, xa que "a" é un valor enteiro*/

    f = factorial(a);
    printf("Factorial(%d) = %d\n", a, f);
    
    p = potencia(a,b); /*o exponente debe ser un numero enteiro*/
    printf("Potencia(%d,%d) = %f \n", a, b, p); /*cambiamos %d por %f*/
    
    return (EXIT_SUCCESS);
}

