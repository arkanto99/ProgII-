/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enterosLargos.h
 * Author: pablo
 *
 * Created on 18 de abril de 2018, 18:25
 */

typedef unsigned long int TIPENTERO;

typedef void *entero;

void creaEnteroLargo (entero *e,unsigned long int tam);

void StringtoEnteroLargo (entero *e,char *argv);   

void imprimeEnteroLargo(entero e);

entero MayorEntero(entero x,entero y);

entero RestaEnteroLargo(entero x,entero y);

entero OperarEntero(entero x,entero y,char operacion); /*sumar: operacion='+' ;restar: operacion=='-'*/

void liberarEnteroLargo(entero* x);

TIPENTERO tamanoEntero(entero x);

void signoEntero(entero x,entero y,entero* z);

entero DyV(entero x,entero y);

entero Karatsuba(entero x,entero y);