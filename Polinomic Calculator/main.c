/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Pablo Rodríguez Fernández y Samuel Suárez Marcote
 *
 * Created on 27 de noviembre de 2017, 16:26
 */

#include <stdio.h>
#include <stdlib.h>
#include "Polinomio.h"
/*
 * 
 */
int main(int argc, char** argv) { 
    
     int punto,aval,opcion,final;
     pol p,d,t;
    
    do{ printf("          |--------------------------------------------------|\n"
             "          |Introduza o código da acción que quere realizar:  |\n"
             "          |      1-Avaliar un polinomio nun punto            |\n"
             "          |      2-Derivar un polinomio                      |\n"
             "          |      3-Sumar dous polinomios                     |\n"
             "          |      4-Multiplizar dos polinomios                |\n"
             "          |      5.-Dividir dous polinomios                  |\n"
             "          |--------------------------------------------------|\n");
     
    scanf("%d",&opcion);
     
     switch(opcion){
             case(1): 
                    p=Ler();
                    Escribir(p);
                    printf("\n Introduza o punto a avaliar: \n");
                    scanf("%d",&punto);
                    aval=Avaliar(p,punto);
                    printf("\nO valor no punto %d é %d \n",punto,aval);
                    break;
                 
             case(2): 
                 p=Ler();
                 Escribir(p);
                 d=Derivar(p);
                 printf("\nA derivada é ");
                 Escribir(d);
                 break;
                 
             case(3): 
                 p=Ler();
                 Escribir(p);
                 t=Ler();
                 Escribir(t);
                 d=Sumar(p,t);
                 printf("\nA suma é ");
                 Escribir(d);
                 
                 break;
                 
             case(4):
                 p=Ler();
                 Escribir(p);
                 t=Ler();
                 Escribir(t);
                 d=Multiplicar(p,t);
                 printf("\nA multiplicación é ");
                 Escribir(d);
                 break;
     
             case(5):
                 p=Ler();
                 Escribir(p);
                 t=Ler();
                 Escribir(t);
                 d=Dividir(p,t);
                 printf("\nO cociente da división é ");
                 Escribir(d);
                 break;
            }
     
     printf("\n Que desexa facer?: \n"
             "1.-Realizar unha nova acción\n"
             "2.-Saír do programa\n");
     scanf("%d",&final);
    
    } while(final==1);        
    printf("Ata a próxima!");
    return (EXIT_SUCCESS);      
    }     
    