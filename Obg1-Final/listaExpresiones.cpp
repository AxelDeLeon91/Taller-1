#include <stdio.h>
#include "listaExpresiones.h"

boolean existeExpresion(ListaExp lista, int num){
    boolean existe=FALSE;
    if(lista==NULL){
        existe=FALSE;
    }else if(num<darNumero(lista->exp)){ //Deberia ser menor
            existe =TRUE;
        }
    return existe;
}
void crearLista(ListaExp l){
    l= NULL;
}

boolean listaVacia(ListaExp l){
    boolean es= FALSE;
    if(l==NULL)
        es = TRUE;
    return es;
}

void mostrarExpresion(ListaExp lExp,int i){
    while(darNumero(lExp->exp)!=i){
        lExp=lExp->sig;
    }

    mostrarExpresion(lExp->exp);
}

expresion darExpresion(ListaExp lExp, int i){

    while(darNumero(lExp->exp)!=i){
        lExp=lExp->sig;
    }
    return lExp->exp;
}

void insFront(ListaExp &l, expresion e){
    if(listaVacia(l)==TRUE){
        l = new nodoLista;
        l->exp=e;
        l->sig=NULL;
        l->exp.numExpresion=1;
    }else{
        ListaExp aux = new nodoLista;
        aux->exp= e;
        setNumExp(aux->exp,darNumero(l->exp)+1);
        aux->sig= l;
        l=aux;
    }
}





