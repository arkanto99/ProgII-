/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   seleccion.c
 * Author: pablo
 *
 * Created on 4 de abril de 2018, 18:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"

/*
 * 
 */

   void Selec(vectorP *v1)
   {
unsigned long int e,i;
int PosMenor,aux;
for (e=0; e<(tamano(*v1)-1) ; e++)
 {
   PosMenor=e;
   for (i=e+1;i<tamano(*v1);i++)
    if (recuperar(*v1,i)<recuperar(*v1,PosMenor))
        PosMenor=i;
    aux=recuperar(*v1,e);                
    asignar(v1,e,recuperar(*v1,PosMenor));
    asignar(v1,PosMenor,aux);
 }
}
