/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pablo
 *
 * Created on 21 de febrero de 2018, 19:31
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"

/*
 * 
 */
void imprimir(vectorP v1){
    
   
    short int j,tam;
    if(v1!=NULL){
    tam=tamano(v1);
    for(j=0;j<tam;j++)
    { printf("\nO valor da posicion %hd e %f",j,recuperar(v1,j));
    }}
    else
        printf("O vector non existe!!");

}



int main(int argc, char** argv) {

    vectorP v1=NULL;
    short tam1,i;
    TELEMENTO valor;
    char opcion;
  
   if (argc>1){
        crear(&v1,atof(argv[1]));
        for(i=1;i<argc;i++){
            asignar(&v1,i-2,atof(argv[i]));
	}
       imprimir(v1);

    }
 
    do{
        printf("\n-------------------------------------\n");
        printf("\na) Crear vector ");
        printf("\nb) Recuperar elemento");
        printf("\nc) Ver tamanho do vector");
        printf("\nd) Liberar memoria (borrar vector))");
        printf("\nk) Sair do programa");
        
        printf("\nOpcion: ");
        scanf(" %c",&opcion);
        
        switch(opcion){
           
            case 'a':
                
                printf("Introduce tamanho do vector: ");
                scanf(" %hd",&tam1);
                liberar(&v1);
                crear(&v1,tam1);
                for(i=0;i<tam1;i++){
                    printf("Elemento %hd do vector v1: ",i);
                    scanf("%f",&valor);
                    asignar(&v1,i,valor);
                 }  
                imprimir(v1);
                break;
                
            case 'b':
                
                printf("Introduza o elemento do vector que quere ver: ");
                scanf("%hd",&i);
                valor=recuperar(v1,i);
                printf("O valor da posicion %hd e %f",i,valor);
                break;
            
             case 'c':
                
                tam1=tamano(v1);
                printf("O tamanho do vector e %hd",tam1);
                break;
            
            case 'd':
               
                printf("Vector eliminado...");
                liberar(&v1);
                break;
                
            
            case 'k':
                
                printf("Saindo do programa...");
                liberar(&v1);
                break;
                        
            
            default: printf("Opcion incorrecta");
        }
    }while(opcion!= 'k');
    
    return (EXIT_SUCCESS);
                
   }
    
   
    
    
    
    
    
    
    
    
    
    
    

