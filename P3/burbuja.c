/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   burbuja.c
 * Author: pablo
 *
 * Created on 4 de abril de 2018, 18:37
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"


void Burb1(vectorP *v1)
{
unsigned long int e,i;
int aux;

for (e=0;e<(tamano(*v1)-1);e++)  
    for (i=0;i<(tamano(*v1)-e-1);i++)
        if (recuperar(*v1,i)>recuperar(*v1,i+1))
            {
                  aux=recuperar(*v1,i);
                  asignar(v1,i,recuperar(*v1,i+1));
                  asignar(v1,i+1,aux);
         }
}



