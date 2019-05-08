/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Polinomio.h
 * Author: Pablo Rodríguez Fernández y Samuel Suárez Marcote
 *
 * Created on 27 de noviembre de 2017, 16:13
 */

#ifndef POLINOMIO_H
#define POLINOMIO_H

#ifdef __cplusplus
extern "C" {
#endif
  struct{
        int exponente;
        int *coeficiente;
    }typedef pol;

    pol Ler( );

   void Escribir(pol polim );
    
   int Avaliar(pol polim,int k); 
    
    pol Derivar(pol polim); 
    
    pol Sumar(pol polim, pol polom);
    
    pol Multiplicar(pol polim, pol polom);

    pol Dividir(pol polim,pol polom);
#ifdef __cplusplus
    
}
#endif

#endif /* POLINOMIO_H */

