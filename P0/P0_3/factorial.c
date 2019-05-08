#include <stdio.h>

int factorial(int n) {    /*faltaba o caso 0!=1*/
    int valor = 1;
    if (n > 0) {    
        int i;
        for (i=1; i <=n; i++) /*o bucle debe empezar en i=1*/
            valor = valor * i;    
    } 
    
    else if(n==0){
        valor=1;
    
    }
    
    else {
        printf("Error factorial: el parámetro (%d) no es un entero positivo\n",n); /*substiuín %f por %d, xa que o valor é un enteiro.Ademais, engadin ",n",xa que non se incluía na sentencia o elemento ao que facía referencia %d*/
    }
    return valor;
}

