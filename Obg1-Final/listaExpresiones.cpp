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

void mostrarExpresion(ListaExp lExp){
    mostrarExpresion(lExp->exp);
}

//Problemas aqui
void insFront(ListaExp &l, expresion e){

    if(listaVacia(l)==TRUE){
        l = new nodoLista;
        l->exp=e;
        l->sig=NULL;
        l->exp.numExpresion=1;
    }else{
        nodoLista nuevoNodo = new nodoLista;
        nuevoNodo.exp=e;
        nuevoNodo->sig = l;
        l=nuevoNodo;
        l->exp.numExpresion=darNumero(l->sig->exp) + 1;
    }
}





