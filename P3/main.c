/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pablo
 *
 * Created on 4 de abril de 2018, 18:23
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"
#include "burbuja.h"
#include "quicksort.h"
#include "seleccion.h"
#include <time.h>

/*
 * 
 */
int main(int argc, char** argv) { 
    
    unsigned long int tamanoinicio,tamanofin,paso,i;
   
    vectorP v1=NULL;
    clock_t inicio=-1, fin=-1;
    FILE *fp;
   
    
     /************************PASO POR PROGRAMA**********************************************/
    if(argc==1){
    
    int opcion;    
    
   do{
    
    printf("\nIntroduza o tamaño do primeiro vector: ");
    scanf("%lu",&tamanoinicio);
    printf("\nIntroduza o tamaño do ultimo vector: ");
    scanf("%lu",&tamanofin);
    printf("\nIntroduza o paso entre cada vector: ");
    scanf("%lu",&paso);
    
    printf("\nSeleccione un metodo de ordenacion: ");
    printf("\n1.-Quicksort");
    printf("\n2.-Burbuja");
    printf("\n3.-Seleccion");
    printf("\n4.-Salir del Programa\n----");
    scanf("%d",&opcion);
    
   i=tamanoinicio;
   
   if(opcion==1){
      
       
       fp=fopen("tiemposVectorDinamicoOrdenacionRapida", "w");
       
       for(i;i<=tamanofin;i=i+paso){
           
           int w=0;
           crear(&v1,i);
           inicializaVectorRand(&v1);
           inicio=clock();
           quicksort(&v1,0,i-1);  
           fin=clock();
           
           printf("n:%lu\tini.:%ld\tfin:%ld\ttiempo:%.4lf\n", i,fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
           fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero

           liberar(&v1);
        }
     fclose(fp);
        
    }
    
    else if(opcion==2){
     
      
        fp=fopen("tiemposOrdenacionVectorDinamicoBurbuja", "w");
        
        for(i;i<=tamanofin;i=i+paso){
           
           crear(&v1,i);
           inicializaVectorRand(&v1);
           inicio=clock();
           Burb1(&v1);
           fin=clock();
           
           printf("n:%lu\tini.:%ld\tfin:%ld\ttiempo:%.4lf\n", i,fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
           fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
           liberar(&v1);
        }
      fclose(fp);
        
    }
    
    else if(opcion==3){
        
     
        fp=fopen("tiemposseleccion", "w");
        
        for(i;i<=tamanofin;i=i+paso){
          
           crear(&v1,i);
           inicializaVectorRand(&v1);
           inicio=clock();
           Selec(&v1);
           fin=clock();
           
           printf("n:%lu\tini.:%ld\tfin:%ld\ttiempo:%.4lf\n", i,fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
           fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
           liberar(&v1);
        }
    fclose(fp);
   }
    
    else if(opcion==4)
    {
    printf("Saindo do programa...");
    return(EXIT_SUCCESS);
    }
      
   }while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4);
    
   } 
    
    /************************PASO POR LÍNEA DE COMANDOS**********************************************/
     /**NOTA: DE DEBE INTRODUCIR: TAMAÑO INICIAL TAMAÑO FINAL PASO OPCION**/
    /******OPCIONES:  1 (QUICKSORT)   2 (BURBUJA)    3  (SELECCION)*/
   else{
        char *prt;
       
       i=strtoul(argv[1],&prt,10); 
       
       if(strtoul(argv[4],&prt,10)==1){
      
       fp=fopen("tiemposVectorDinamicoOrdenacionRapida","w");
       
           for(i;i<=strtoul(argv[2],&prt,10);i=i+strtoul(argv[3],&prt,10)){
            
           
           crear(&v1,i);
           inicializaVectorRand(&v1);
           inicio=clock();
           quicksort(&v1,strtoul(argv[3],&prt,10),i+strtoul(argv[3],&prt,10));  
           fin=clock();
           
           printf("n:%lu\tini.:%ld\tfin:%ld\ttiempo:%.4lf\n",i,fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
           fprintf(fp,"%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero

           liberar(&v1);
           
        }
     fclose(fp);
        
    }
    
    else if(strtoul(argv[4],&prt,10)==2){
     
      
        fp=fopen("tiemposOrdenacionVectorDinamicoBurbuja","w");
       
        for(i;i<=strtoul(argv[2],&prt,10);i=i+strtoul(argv[3],&prt,10)){
           crear(&v1,i);
           inicializaVectorRand(&v1);
           inicio=clock();
           Burb1(&v1);
           fin=clock();
       
           printf("n:%lu\tini.:%ld\tfin:%ld\ttiempo:%.4lf\n", i,fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
           fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
           liberar(&v1);
           
        }
      fclose(fp);
        
    }
    
    else if(strtoul(argv[4],&prt,10)==3){
        
     
        fp=fopen("tiemposseleccion","w");
        
        for(i;i<=strtoul(argv[2],&prt,10);i=i+strtoul(argv[3],&prt,10)){
           crear(&v1,i);
           inicializaVectorRand(&v1);
           inicio=clock();
           Selec(&v1);
           fin=clock();
           
           printf("n:%lu\tini.:%ld\tfin:%ld\ttiempo:%.4lf\n", i,fin, inicio, (fin-inicio)/(double)CLOCKS_PER_SEC);
           fprintf(fp, "%lu\t%.4lf\n", i, (fin-inicio)/(double)CLOCKS_PER_SEC); //Salida de los datos n, t(n) a fichero
           liberar(&v1);
         
        }
    fclose(fp);
   
   }
    
}   
    return (EXIT_SUCCESS);
}

