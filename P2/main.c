/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pablo
 *
 * Created on 7 de marzo de 2018, 19:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "listas.h"

/*
 * 
 */

void liberaListaPluses(TLISTA *listaPluses) { 

   if(*listaPluses!=NULL){ 
     destruye(listaPluses);
    *listaPluses = NULL;}

}

void liberaColaEspera(TCOLA *colaEspera) {

    int fin;
    if(*colaEspera!=NULL){
    do {
        fin = EsColaVacia(*colaEspera);
        if (fin == 0)
            EliminarCola(colaEspera);
    } while (fin == 0);
    
    free(*colaEspera);
    *colaEspera = NULL;
}}

void imprimirCola(TCOLA colaEspera) { 

    TIPOELEMENTOCOLA e;
     if(EsColaVacia(colaEspera))
	printf("\nA cola non ten elementos");
    else{
         PrimeroCola(colaEspera, &e);
    printf("\nO seguinte elemento da cola e: %d", e);

    }}

void imprimirListaPluses(TLISTA listaPluses) { 

    int i;
    TIPOELEMENTOLISTA e = 1;
    TNODOLISTA p = NULL;

   if(esVacia(listaPluses))
   printf("\nA lista de pluses esta vacia actualmente");
   else{ p = primero(listaPluses);

    for (i = 0; i < longitud(listaPluses); i++) {

        recupera(listaPluses, p, &e);
        printf("-[%f]-", e);
        p = siguiente(listaPluses, p);
    }

}}

int comprobacionNumeroProductos(TIPOELEMENTOCOLA n) { 

    if (n <= 0) {
        printf("Error.Numero de productos non válido.");
        return 0;
    } else return 1;
}

int comprobacionValorARecaudar(TIPOELEMENTOLISTA v) { 

    if (v <= 0) {
        printf("Error. Cantidade de pluses non valida.");
        return 0;
    } else return 1;
}

TIPOELEMENTOLISTA totalPluses(TLISTA listaPluses) { 

    int i;
    TNODOLISTA p = NULL;
    TIPOELEMENTOLISTA total = 0, e = 0;

    p = primero(listaPluses);

    for (i = 0; i < longitud(listaPluses); i++) {

        recupera(listaPluses, p, &e);
        total = e + total;
        p = siguiente(listaPluses, p);
    }
    return total;


}

void recaudarPluses(TLISTA *listaPluses, TIPOELEMENTOLISTA dineroARecaudar) {

    TIPOELEMENTOLISTA e = 0, t, r = 0;
    TNODOLISTA p = NULL, q = NULL;
    int l, i;

    do {

        l = longitud(*listaPluses);
        p = primero(*listaPluses);
        recupera(*listaPluses, p, &t);
        q = p;


        for (i = 1; i < l; i++) {
            p = siguiente(*listaPluses, p);
            recupera(*listaPluses, p, &e);
            if (e > t)
                printf(" "); /*Nota: si no introducimos este printf, el resultado puede ser erroneo*/
                t = e; 
                q = p;
                
        }

        r = t + r;

        if (r > dineroARecaudar) {
            t = r - dineroARecaudar;

            modifica(listaPluses, q, t);
        } else {

            suprime(listaPluses, q);
        }
    } while(r<dineroARecaudar);

  }

int main(int argc, char** argv) {

    char opcion, opcion2 = 0;
    TIPOELEMENTOCOLA prod;
    TIPOELEMENTOLISTA pluses, recaudar;
    TCOLA cola = NULL;
    TNODOLISTA nodo = NULL;
    TLISTA lista = NULL;

    int aux;

    ColaVacia(&cola);
    crea(&lista);

    if (argc > 1) {

        for (aux = 1; aux < argc; aux++)
            
            if(atof(argv[aux])>0)
            
            AnadirCola(&cola, atof(argv[aux]));
    }


    do {
        printf("\n-------------------------------------\n");
        printf("\na) Anotarse na cola ");
        printf("\nb) Atender cliente");
        printf("\nc) Cobrar pluses");
        printf("\nd) Calcular pluses");
        printf("\nk) Sair do programa");

        printf("\nOpcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {

            case 'a': 

                do {
                    printf("\nIntroduza o numero de produtos: ");
                    scanf("%d", &prod);
                    aux = comprobacionNumeroProductos(prod);
                } while (aux == 0);
                AnadirCola(&cola, prod);
                break;

            case 'b': 

                aux = EsColaVacia(cola);

                if (aux == 0) {

                    imprimirCola(cola);
                    PrimeroCola(cola, &prod);
                    EliminarCola(&cola);

                    pluses = prod * 0.5;
                    nodo = primero(lista);
                    inserta(&lista, nodo, pluses);

                    printf("\nA listaxe de pluses e: ");
                    imprimirListaPluses(lista);
                    imprimirCola(cola);

                }
                else {
                    printf("\nA cola esta vacia");
                    imprimirListaPluses(lista);
                }

                break;

            case 'c':

                do {
                    printf("Introduza a cantidade de euros en pluses que quere retirar: ");
                    scanf("%f", &pluses);
                    aux = comprobacionValorARecaudar(pluses);
                } while (aux == 0);

                recaudar = totalPluses(lista);

                if (recaudar < pluses) {
                    printf("Non hai pluses dispoñibles neste momento");
                }
                else {

                    recaudarPluses(&lista, pluses);
                    printf("Operacion feita satisfactoriamente");
                }
                break;



            case 'd': 

                pluses = totalPluses(lista);

                if (pluses == 0)
                    printf("Non hai pluses dispoñibles neste momento");

                else printf("O total de pluses dispoñibles e: %f", pluses);
                break;


            case 'k': 

                printf("\nPulse k de novo para confirmar a saida do programa...:");
                getchar()!='\n';
                scanf("%c", &opcion2);

                if (opcion2 == opcion) {

                    liberaListaPluses(&lista);
                    liberaColaEspera(&cola);
                }
                break;




            default: printf("Opcion incorrecta");
        }

    } while (opcion2 != opcion);

    return (EXIT_SUCCESS);

}
