/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Polinomio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


pol Ler(){ /*PRE- Introducir números enteros*/
    pol polim;
    int i;
    printf("Introduce o grao do polinomio: ");
    scanf("%d",&polim.exponente);
    polim.coeficiente=(int*)malloc(polim.exponente*sizeof(int));
    for(i=0;i<=polim.exponente;i++){
        printf("Introduce o valor do elemento de grao %d: ",polim.exponente-i);
        scanf("%d",&*((polim.coeficiente+i)));
       
    }
    printf("\n");
 return polim;
    
} /*POS- Devolver un polinomio*/

void Escribir(pol polim){ /*PRE- Lectura válida do polinomio*/
    int i;
    printf("o polinomio: ");
    for(i=0;i<=polim.exponente;i++){
      
       printf("%dx^%d ",*(polim.coeficiente+i),(polim.exponente-i));}
    
     printf("\n");
}/*POS-Representación tradicional dun polinomio*/


int Avaliar(pol polim,int k){  /*PRE- Polinomio válido e un enteiro*/
    
    int i,*v,resultado;
     
    v=(int*)malloc((polim.exponente+1)*sizeof(int)); 
    
    for(i=0;i<=polim.exponente;i++){
      
        *(v+i)=*(polim.coeficiente+i)*pow(k,(polim.exponente-i));
        
    }   
    k=0;resultado=0;
     for(i=0;i<=polim.exponente;i++){
         
         k=*(v+i);
         resultado=resultado+k;
         
     }
   free(v); 
   return resultado; /*POS- Valor do polinomio no punto k*/
}

pol Derivar(pol polim){ /*PRE- Polinomio válido*/
    int i;pol derivado;
     
  derivado.exponente=polim.exponente-1; /*O exponente do polinomio derivado é o do orixinal-1*/
 
  derivado.coeficiente=(int*)malloc(derivado.exponente*sizeof(int)); /*reservamos memoria para os coeficientes do polinomio derivado*/
          
  for(i=0;i<=polim.exponente;i++){
        
        derivado.coeficiente[i]=(*(polim.coeficiente+i))*(polim.exponente-i);} 
  
  return derivado; 
   
 } /*POS-Devolve a función derivada*/



pol Sumar(pol polim,pol polom){ /*PRE- 2 polinomios válidos*/
    
    pol sum;int i,diferencia; 
 
    /********************************Igual exponente**********************/
    if(polim.exponente==polom.exponente){
        
        sum.coeficiente=(int*)malloc((polim.exponente+1)*sizeof(int)); 
        
        sum.exponente=polim.exponente;
        
          for(i=0;i<=sum.exponente;i++){
        
              *(sum.coeficiente+i)=*(polim.coeficiente+i)+*(polom.coeficiente+i);
        }
    }
    /*************************************************************************************/
    else if(polim.exponente>polom.exponente) {
        
        sum.coeficiente=(int*)malloc((polim.exponente+1)*sizeof(int)); 
        
        sum.exponente=polim.exponente;
        diferencia=polim.exponente-polom.exponente;
          
        for(i=0;i<=sum.exponente;i++){
              
              if(i<diferencia){   /*imprimimos os elementos que,polo grao, só están presentes nun dos polinomio*/
                  
                  *(sum.coeficiente+i)=*(polim.coeficiente+i);
              }
              
              else{
                  *(sum.coeficiente+i)=*(polim.coeficiente+i)+*(polom.coeficiente+(i-diferencia));
              }
              
          }
        }
    /**************************************************************************/
    else if (polim.exponente<polom.exponente){
        
        sum.coeficiente=(int*)malloc((polom.exponente+1)*sizeof(int)); 
        
        sum.exponente=polom.exponente;
        diferencia=polom.exponente-polim.exponente;
          for(i=0;i<=sum.exponente;i++){
              
                if(i<diferencia){

                    *(sum.coeficiente+i)=*(polom.coeficiente+i);
                }

                else{
                    *(sum.coeficiente+i)=*(polom.coeficiente+i)+*(polim.coeficiente+(i-diferencia));
                }
              
            }
          }
    
    return sum;
  
}/*POS-Devolve a sumas dos polinomios */

pol Multiplicar(pol polim,pol polom){ /*PRE-2 polinomios válidos*/

    int i,j;pol multiplex;
    
    multiplex.exponente=polim.exponente+polom.exponente;
    multiplex.coeficiente=(int*)malloc(multiplex.exponente*sizeof(int));
    for(i=0;i<=multiplex.exponente;i++){
       *(multiplex.coeficiente+(i))=0; 
    }
    
    for(i=0;i<=polim.exponente;i++){
     for(j=0;j<=polom.exponente;j++){
         *(multiplex.coeficiente+(i+j))=*(multiplex.coeficiente+(i+j))+(*(polim.coeficiente+i))*(*(polom.coeficiente+j));
     }   
    }
    return multiplex;
    
}/*POS-Devolve o resultado da multiplicación dos polinomios*/

pol Dividir(pol polim,pol polom){ /*PRE-2 polinomios válidos, tal que : 1º polinomio=Dividendo (maior grado), 2º polinomio=Divisor (menor grado)*/
    
    int i,j;pol resultado;
    
    resultado.exponente=polim.exponente-polom.exponente;
    
    resultado.coeficiente=(int*)malloc((resultado.exponente+1)*sizeof(int));
    
    for(i=0;i<=resultado.exponente;i++){
      *(resultado.coeficiente+i)=*(polim.coeficiente+i)/(*(polom.coeficiente+0));
                for(j=1;j<=polom.exponente;j++){
     *(polim.coeficiente+(i+j))=*(polim.coeficiente+(i+j))-(*(resultado.coeficiente+i))*(*(polom.coeficiente+j));
    
              }}
    
     return resultado;   
    }/*POS-Devolve o cociente da división*/