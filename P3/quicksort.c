/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   quicksort.c
 * Author: pablo
 *
 * Created on 4 de abril de 2018, 18:25
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectordinamico.h"


/*
 * 
 */
unsigned long choose_pivot(unsigned long i,unsigned long j)
{
    return((i+j)/2);
}

void quicksort(vectorP *pvector,unsigned long beg,unsigned long end)
{  
    if(end>beg+1)  
    {
        TELEMENTO piv=recuperar(*pvector,beg);
        unsigned long l=beg+1,r=end;


    
        while(l<r)
        {
            if (recuperar(*pvector,l)<=piv)
                l++;
            else
            {
                r--;
                swap(pvector,l,r);
            }
        }
        l--;
        swap(pvector,l,beg);
        quicksort(pvector,beg,l);
        quicksort(pvector,r,end);
    }
    
}