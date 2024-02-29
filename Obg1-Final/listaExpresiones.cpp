#include <stdio.h>
#include "listaExpresiones.h"

boolean existeExpresion(ListaExp lista, int num){
    boolean existe=FALSE;
    if(lista==NULL){
        existe=FALSE;
    }else if(num<=darNumero(lista->exp)){
            existe =TRUE;
        }
    return existe;
}
void crearLista(ListaExp &l){
    l=NULL;
}

boolean listaVacia(ListaExp l){
    boolean es= FALSE;
    if(l==NULL)
        es=TRUE;
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
expresion darPrimerExpresion(ListaExp lExp){
    return lExp->exp;
}

void insFront(ListaExp &lExp, expresion e) {
    if (listaVacia(lExp) == TRUE) {
        lExp = new nodoLista;
        lExp->exp = e;
        setPrimerNum(lExp->exp);
        lExp->sig = NULL;
    } else {
        ListaExp aux = new nodoLista;
        aux->exp = e;
        setNumExp(aux->exp, darNumero(lExp->exp) + 1);
        aux->sig = lExp;
        lExp = aux;
    }

}

//PRUEBA
void mostrarListaExp(ListaExp lExp) {
    printf("\nListaExp: ");
    while (lExp != NULL) {
        mostrarExpresion(lExp->exp);
        lExp = lExp->sig;
        if (lExp != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}



