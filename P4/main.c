/* 
 * Created on 18 de abril de 2018, 18:21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "enterosLargos.h"
/*
 * 
 */

int main(int argc, char** argv) {
   
    unsigned long int l;
    entero e1=NULL,e2=NULL,e3=NULL,e4=NULL;
    clock_t inicio=-1, fin=-1;
    
    l=strlen(argv[1]);
    if((argv[1][0]=='-')||(argv[1][0]=='+')) /*Debese facer esta comprobacion, xa que se inclue signo a lonxitude do vector seria incorrecta*/
        l--;
    
    creaEnteroLargo(&e1,l);
    StringtoEnteroLargo(&e1,argv[1]);
    imprimeEnteroLargo(e1);
    creaEnteroLargo(&e2,l);
    StringtoEnteroLargo(&e2,argv[2]);
    imprimeEnteroLargo(e2);
    
    //e3=SumaEntero(e1,e2);
    //imprimeEnteroLargo(e3);
    inicio=clock();
    e3=DyV(e1,e2);
    fin=clock();
    signoEntero(e1,e2,&e3);
     printf("O algoritmo Divide e Venceras tarda %.4lf segundos, e \n",(fin-inicio)/(double)CLOCKS_PER_SEC);
    imprimeEnteroLargo(e3);
    liberarEnteroLargo(&e3);

    inicio=clock();
    e4=Karatsuba(e1,e2);
    fin=clock();
    signoEntero(e1,e2,&e4);
    printf("O algoritmo de Karatsuba tarda %.4lf segundos, e \n",(fin-inicio)/(double)CLOCKS_PER_SEC);
    imprimeEnteroLargo(e4);
    liberarEnteroLargo(&e4);
    
    liberarEnteroLargo(&e1);
    liberarEnteroLargo(&e2);
   
    
    
    
    
    

    return (EXIT_SUCCESS);
}


