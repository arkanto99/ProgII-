/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>

typedef short TELEMENTO;

typedef struct {
    TELEMENTO *datos;
    unsigned long int tam;
}STVECTOR;

typedef STVECTOR *vectorP;


void crear(vectorP *v1,unsigned long tam1)
{   
    unsigned long int i=0;
    
    *v1=(vectorP)malloc(sizeof(STVECTOR));
    
    if(*v1!=NULL){
    (*v1)->datos=(TELEMENTO*)malloc(tam1*sizeof(TELEMENTO));
    }
    
    if((*v1)->datos!=NULL){
        
    (*v1)->tam=tam1;
    for(i=0; i<tam1;i++)
        *((*v1)->datos+i)=0;
    }}

void asignar(vectorP *v1, unsigned long posicion,TELEMENTO valor)
{
    if(*v1!=NULL && (*v1)->datos!=NULL && posicion>=0 && posicion<(*v1)->tam)
    
            *((*v1)->datos+posicion)=valor;
            
           
   }   

TELEMENTO recuperar(vectorP v1, unsigned long posicion)
{
    TELEMENTO valor=0;
    
    if(v1!=NULL && v1->datos!=NULL){
        
        if(posicion>=0 && posicion<v1->tam)
            valor=*(v1->datos + posicion);
        }
    return valor;
}

unsigned long int tamano(vectorP v1)
{
        unsigned long int tamano=0;
        
        if(v1!=NULL)
            tamano=v1->tam;
        return tamano;
    
}

void liberar(vectorP *v1){ 
    
    if(*v1!=NULL && (*v1)->datos!=NULL)
        
        free((*v1)->datos);
        free(*v1);
        *v1=NULL;
}



