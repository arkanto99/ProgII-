/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pablo
 *
 * Created on 13 de febrero de 2018, 12:10
 */

#include <stdio.h>
#include <stdlib.h>

/*Como o exercicio nos require expresar o array como un array de enteros, non se poden levar 
 * a cabo potencias de números negativos, xa que nese caso precisaríamos que fose dun tipo superior
 * ,como floats.
 * 
 */

int potencia(int base[4], int exponente) { 
    
    int i,j;
    int valor;
    
    for(j=0;j<4;j++){
        valor=1;
    for (i=1; i <= absoluto(exponente); i++) {
       valor = valor * base[j];  
      
            } 
    base[j]=valor;
    }}

int absoluto(int n) {
    return (n<0)? -n : n; 
}



int main(int argc, char** argv) {

   
    int a[4];int b,i;
    
    printf("Introduza os elementos do array\n");
    
    for(i=0;i<4;i++){
        printf("%dº elemento do array: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nIntroduza o exponente ao que quere elevar o array: ");
    scanf("%d",&b);
    
    potencia(a,b);
    
    for(i=0;i<4;i++){
        printf("\n%dº elemento do array elevado a %d é: %d",i+1,b,a[i]);
    }
    
    return (EXIT_SUCCESS);
}

