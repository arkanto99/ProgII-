/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include "vectordinamico.h"

typedef unsigned long int TIPENTERO;

typedef struct{
    
    short signo;
    vectorP cifras;
    
}REPRENTERO;

typedef REPRENTERO *entero;

void creaEnteroLargo (entero *e,unsigned long int tam){
    
    *e=(entero)malloc(sizeof(REPRENTERO));
    if(*e==NULL){
        printf("Erro ao reservar memoria");}
    
    else{
        
      (*e)->signo=1;
      crear(&((*e)->cifras),tam);
    }
    
 }
         
 void StringtoEnteroLargo (entero *e,char *argv){
     
     unsigned long int i;
     short u;
     
     
     if((argv[0]=='-')||(argv[0]=='+')){
   
        if(argv[0]=='-')  
        (*e)->signo=-1;
        
        for(i=0;i<(tamano((*e)->cifras));i++){   
            u=(unsigned short int)argv[i+1]-48; /*48 e o codigo ASCII do 0,por iso debese restar*/
            asignar(&((*e)->cifras),i,u);

        }
     
    }
     else
         for(i=0;i<tamano((*e)->cifras);i++){
              u=(unsigned short int)argv[i]-48;
              asignar(&((*e)->cifras),i,u);
                }
     
 }

void imprimeEnteroLargo(entero e){
    
   
    unsigned long int j,tam;
    if(e!=NULL){
    tam=tamano(e->cifras);
    printf("O numero e ");
    if(e->signo==-1)
        printf("-");
    for(j=0;j<tam;j++)
    { printf("%hi",recuperar(e->cifras,j));
    }
    printf("\n");
    }
    
    else
        printf("O enteiro non existe!!");

} 
 

void dividirEntero(entero x,entero* y,entero* z){    /*x=vector existente  y,z=vectores creados*/
    
    unsigned long int l,i;
    
    l=tamano(x->cifras);
    creaEnteroLargo(y,l/2);
    creaEnteroLargo(z,l/2);
    for(i=0;i<l/2;i++){
              asignar(&((*y)->cifras),i,recuperar(x->cifras,i));
              asignar(&((*z)->cifras),i,recuperar(x->cifras,i+(l/2)));
    }
    
}

entero multiplicarElemental(entero x,entero y){ 
    
   int n,r;                   /*Se o resultado ten unha soa cifra, enchese o oco cun cero*/
   entero z=NULL;
   n=recuperar(x->cifras,0)*recuperar(y->cifras,0);
   creaEnteroLargo(&z,2);
   
    r=n%10;
    asignar(&(z->cifras),1,r);
    r=n/10;
    asignar(&(z->cifras),0,r);

    
    return z;
        
    }

void liberarEnteroLargo(entero* x){
    
    if((*x)!=NULL && (*x)->cifras!=NULL)
        
        liberar(&((*x)->cifras));
        free(*x);
        *x=NULL;
  }

 

entero SumaEntero(entero x,entero y){ /*Precondicion: El entero de mas cifra debe ir en primer lugar*/
    
    int sumparcial1,sumparcial2,acarreo=0;
    unsigned long int tamx,tamy,tamz,i,tamdiferencia;
    entero z=NULL;
    
    tamx=tamano(x->cifras);
    tamy=tamano(y->cifras);
    tamdiferencia=tamx-tamy;
    creaEnteroLargo(&z,tamx+1);;/*+1 por si hay desbordamiento en la suma*/
    tamz=tamx+1;
    
    if(x->signo==-1)
        z->signo=x->signo;
    
    for(i=tamz;i>0;i--){ 
        
            if(i>tamdiferencia+1){
        
            sumparcial1=recuperar(x->cifras,i-2)+recuperar(y->cifras,i-2-tamdiferencia)+acarreo;
            sumparcial2=sumparcial1/10;

            if(sumparcial2==0){
                asignar(&(z->cifras),i-1,sumparcial1);
                acarreo=0;  }
            else{
                asignar(&(z->cifras),i-1,sumparcial1%10);
                acarreo=1;   }
            }
        
            else{
                if(i<=tamz-tamx){
            
                asignar(&(z->cifras),i-1,acarreo);
                acarreo=0;
            }
                
                else{    
                sumparcial1=recuperar(x->cifras,i-2)+acarreo;
                asignar(&(z->cifras),i-1,sumparcial1);
                acarreo=0;}
       
            }
    }
    
  return z;

}
        


entero MayorEntero(entero x,entero y){ /*tener cuidado en la liberacion de memoria en esta funcion*/
    
    unsigned long int i,tamx,tamy,tamdiferencia;
    entero z=NULL;
    
    tamx=tamano(x->cifras);
    tamy=tamano(y->cifras);
    
    if(tamx<tamy){     
        tamdiferencia=tamy-tamx;
        
        for(i=0;i<tamdiferencia;i++){
            
            if(recuperar(y->cifras,i)!=0)
                return z=y;
        }
        
        for(i=0;i<tamy-tamdiferencia;i++){
            
            if(recuperar(x->cifras,i)>recuperar(y->cifras,i+tamdiferencia))
                return z=x;
            else if(recuperar(x->cifras,i)<recuperar(y->cifras,i+tamdiferencia))
                return z=y;
         }
        return z=y;
      }
    
    else{
         tamdiferencia=tamx-tamy;
        
         for(i=0;i<tamdiferencia;i++){
            
            if(recuperar(x->cifras,i)!=0)
                return z=x;
        }                  
         
         for(i=0;i<tamx-tamdiferencia;i++){
            
            if(recuperar(x->cifras,i+tamdiferencia)<recuperar(y->cifras,i))
                return z=y;
            else if(recuperar(x->cifras,i+tamdiferencia)>recuperar(y->cifras,i))
                return z=x;
         }
         return  z=x;
    }
}


entero RestaEnteroLargo(entero x,entero y){
    
    entero z=NULL;
    unsigned long int tamx,tamy,tamdiferencia,i;
    short llevadas=0;
  
    tamx=tamano(x->cifras);  
    tamy=tamano(y->cifras);
    
    if(tamx>tamy){ /*********************************************/
    
        tamdiferencia=tamx-tamy;
        creaEnteroLargo(&z,tamx);
    
        
        if(x==MayorEntero(x,y)){
                        
            z->signo=x->signo;
            
            for(i=tamx;i>0;i--){ 

                if(i>tamdiferencia){

                    if(recuperar(x->cifras,i-1)>=recuperar(y->cifras,i-tamdiferencia-1)+llevadas){
                    asignar(&(z->cifras),i-1,(recuperar(x->cifras,i-1)-recuperar(y->cifras,i-tamdiferencia-1)-llevadas));
                    llevadas=0;}

                    else{
                    asignar(&(z->cifras),i-1,(recuperar(x->cifras,i-1)+10-recuperar(y->cifras,i-tamdiferencia-1)-llevadas));
                    llevadas=1;}
                }
                else{

                asignar(&(z->cifras),i-1,recuperar(x->cifras,i-1)-llevadas);
                llevadas=0;}
            }}
        
        else{ /***Caso A***/
            
                z->signo=(-1)*y->signo;  
            
                for(i=tamx;i>tamdiferencia;i--){
                    
                if((recuperar(x->cifras,i-1)+llevadas)>recuperar(y->cifras,i-tamdiferencia-1)){
                
                asignar(&(z->cifras),i-1,(recuperar(y->cifras,i-tamdiferencia-1)+10-recuperar(x->cifras,i-1)-llevadas));
                llevadas=1;}
                
                else{
                
                asignar(&(z->cifras),i-1,(recuperar(y->cifras,i-tamdiferencia-1)-recuperar(x->cifras,i-1)-llevadas));
                llevadas=0;}
                
                }
                
                for(i=tamdiferencia;i>0;i--){
                    
                    asignar(&(z->cifras),i-1,(recuperar((x->cifras),i-1)+llevadas));
                    llevadas=0;
                }                           
        }
    } /**************************************************************/   

    else if(tamy>tamx){
        
        tamdiferencia=tamy-tamx;
        creaEnteroLargo(&z,tamy);
        
        if(y==MayorEntero(x,y)){
        
        z->signo=y->signo;    
        
        for(i=tamy;i>0;i--){ 
            
            if(i>tamdiferencia){
           
                if(recuperar(x->cifras,i-tamdiferencia-1)+llevadas>recuperar(y->cifras,i-1)){
                asignar(&(z->cifras),i-1,(recuperar(y->cifras,i-1)+10-recuperar(x->cifras,i-tamdiferencia-1)-llevadas));
                llevadas=1;}
                
                else{
                asignar(&(z->cifras),i-1,(recuperar(y->cifras,i-1)-recuperar(x->cifras,i-tamdiferencia-1)-llevadas));
                llevadas=0;}
            }
            else{
            if(llevadas>recuperar(y->cifras,i-1)) 
            asignar(&(z->cifras),i-1,recuperar(y->cifras,i-1)+10-llevadas);
            
            else{
            asignar(&(z->cifras),i-1,recuperar(y->cifras,i-1)-llevadas);
            llevadas=0; }
         }
        }}
        
        else{ /***Caso B***/
            
            z->signo=(-1)*x->signo;
                for(i=tamy;i>tamdiferencia;i--){
                    
                if((recuperar(y->cifras,i-1)+llevadas)>recuperar(x->cifras,i-tamdiferencia-1)){
                
                asignar(&(z->cifras),i-1,(recuperar(x->cifras,i-tamdiferencia-1)+10-recuperar(y->cifras,i-1)-llevadas));
                llevadas=1;}
                
                else{
                
                asignar(&(z->cifras),i-1,(recuperar(x->cifras,i-tamdiferencia-1)-recuperar(y->cifras,i-1)-llevadas));
                llevadas=0;}
                
                }
                
                for(i=tamdiferencia;i>0;i--){
                    
                    asignar(&(z->cifras),i-1,(recuperar((y->cifras),i-1)+llevadas));
                    llevadas=0;
                }
            }
        }           
    
    else{ /************************************************************/
         
        creaEnteroLargo(&z,tamx);
        
        if(x==MayorEntero(x,y)){
        
        z->signo=x->signo;    
        
        for(i=tamx;i>0;i--){ 
             
                    if(recuperar(x->cifras,i-1)>=recuperar(y->cifras,i-1)+llevadas){
                    asignar(&(z->cifras),i-1,(recuperar(x->cifras,i-1)-recuperar(y->cifras,i-1)-llevadas));
                    llevadas=0;}

                    else{
                    asignar(&(z->cifras),i-1,(recuperar(x->cifras,i-1)+10-recuperar(y->cifras,i-1)-llevadas));
                    llevadas=1;}
               
        }}
        
        else{
          
        z->signo=(-1)*y->signo;    
            
        for(i=tamy;i>0;i--){ 
             
                    if(recuperar(y->cifras,i-1)>=recuperar(x->cifras,i-1)+llevadas){
                    asignar(&(z->cifras),i-1,(recuperar(y->cifras,i-1)-recuperar(x->cifras,i-1)-llevadas));
                    llevadas=0;}

                    else{
                    asignar(&(z->cifras),i-1,(recuperar(y->cifras,i-1)+10-recuperar(x->cifras,i-1)-llevadas));
                    llevadas=1;}           
            }}
    }      
    return z;
}



TIPENTERO tamanoEntero(entero x){
    
    if(x!=NULL)
        return tamano(x->cifras);
    
}

entero desplazamiento(entero x, unsigned long int tamano){
    
    entero z=NULL;
    TIPENTERO l,i;
    l=tamanoEntero(x);
    l=l+tamano;
    if(l%2!=0){
        
        creaEnteroLargo(&z,l+1);
        for(i=0;i<l;i++)
        asignar(&(z->cifras),i+1,recuperar(x->cifras,i));
    }
    
    else{
        
        creaEnteroLargo(&z,l);
        for(i=0;i<l;i++)
        asignar(&(z->cifras),i,recuperar(x->cifras,i));
    }   
    
    return z;
    
}

void signoEntero(entero x,entero y,entero* z){

short signo;
signo=(x->signo)*(y->signo);

(*z)->signo=signo;


}

entero OperarEntero(entero x,entero y,char operacion){
    
    short sigx,sigy;
    entero z=NULL;
    
    sigx=x->signo;
    sigy=y->signo;
    
    if(sigx==sigy){
                    if(operacion=='-'){
                        z=RestaEnteroLargo(x,y);
                        return z;}
        
                    else{
                        z=SumaEntero(x,y);
                        return z;}
    }
    
    else{        
                    if(operacion=='-'){            
                        z=SumaEntero(x,y);
                        return z;}
        
                    else{            
                        z=RestaEnteroLargo(x,y);
                        return z;}
            }
    }
     

entero DyV(entero x,entero y){
    
    entero a=NULL,b=NULL,c=NULL,d=NULL,ac=NULL,bd=NULL,ad=NULL,bc=NULL,xy=NULL;
    TIPENTERO l;
    char suma='+';
    
    l=tamanoEntero(x);
   
    if(l==1)
        return xy=multiplicarElemental(x,y);
    
    creaEnteroLargo(&ac,l);
    creaEnteroLargo(&bd,l);
    creaEnteroLargo(&ad,l);
    creaEnteroLargo(&bc,l);
    
    dividirEntero(x,&a,&b);
    dividirEntero(y,&c,&d);
    
    ac=DyV(a,c);
    //imprimeEnteroLargo(ac);
    bd=DyV(b,d);
    //imprimeEnteroLargo(bd);
    ad=DyV(a,d);
    //imprimeEnteroLargo(ad);
    bc=DyV(b,c);
    //imprimeEnteroLargo(bc);
    
    xy=OperarEntero(ad,bc,suma);
    //imprimeEnteroLargo(xy);
    xy=desplazamiento(xy,l/2);
    //imprimeEnteroLargo(xy);
    //imprimeEnteroLargo(bd);
    xy=OperarEntero(xy,bd,suma);
    //imprimeEnteroLargo(xy);
    ac=desplazamiento(ac,l);
    //imprimeEnteroLargo(ac);
    xy=OperarEntero(ac,xy,suma);

    liberarEnteroLargo(&a);
    liberarEnteroLargo(&b);
    liberarEnteroLargo(&c);
    liberarEnteroLargo(&d);
    liberarEnteroLargo(&ac);
    liberarEnteroLargo(&ad);
    liberarEnteroLargo(&bc);
    liberarEnteroLargo(&bd);
    
    return xy;
    
 }
     
entero Karatsuba(entero x,entero y){
    
    
   entero a=NULL,b=NULL,c=NULL,d=NULL,ab=NULL,ac=NULL,dc=NULL,bd=NULL,abdc=NULL,xy=NULL;
   TIPENTERO l;
   char suma='+',resta='-';
    
    l=tamanoEntero(x);
   
    if(l==1)
        return xy=multiplicarElemental(x,y);
    
    creaEnteroLargo(&ab,l);
    creaEnteroLargo(&dc,l);
    creaEnteroLargo(&ac,l);
    creaEnteroLargo(&bd,l);
    
    dividirEntero(x,&a,&b);
    dividirEntero(y,&c,&d);
    
    ac=Karatsuba(a,c);
    signoEntero(a,c,&ac);
    //imprimeEnteroLargo(ac);
    bd=Karatsuba(b,d);
    signoEntero(b,d,&bd);
    //imprimeEnteroLargo(bd);
    ab=OperarEntero(a,b,resta);
    //imprimeEnteroLargo(ab);
    dc=OperarEntero(d,c,resta);
    //imprimeEnteroLargo(dc);
    abdc=Karatsuba(ab,dc);
    //imprimeEnteroLargo(abdc);
    
    signoEntero(ab,dc,&abdc); 
    
    xy=OperarEntero(bd,ac,suma);
    //imprimeEnteroLargo(xy);
    xy=OperarEntero(abdc,xy,suma);
    //imprimeEnteroLargo(xy);
    xy=desplazamiento(xy,l/2);
    //imprimeEnteroLargo(xy);
    xy=OperarEntero(xy,bd,suma);
    ac=desplazamiento(ac,l);
    //imprimeEnteroLargo(ac);
    
    xy=OperarEntero(ac,xy,suma);

    liberarEnteroLargo(&a);
    liberarEnteroLargo(&b);
    liberarEnteroLargo(&c);
    liberarEnteroLargo(&d);
    liberarEnteroLargo(&ac);
    liberarEnteroLargo(&bd);
    liberarEnteroLargo(&ab);
    liberarEnteroLargo(&dc);
    liberarEnteroLargo(&abdc);
    
    return xy;
    
 } 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
