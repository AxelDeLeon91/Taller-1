#include <stdio.h>
#include "listaExpresiones.h"

//DAR
expresion darExpresion(ListaExp lExp, int i){
    while(darNumero(lExp->exp)!=i){
        lExp=lExp->sig;
    }
    return darExpresion(lExp);
}

expresion darExpresion(ListaExp lExp){
    return lExp->exp;
}

//FUNCIONALIDADES
void crearLista(ListaExp &l){
    l=NULL;
}

boolean listaVacia(ListaExp l){
    boolean es= FALSE;
    if(l==NULL)
        es=TRUE;
    return es;
}

boolean existeExpresion(ListaExp lista, int num){
    boolean existe=FALSE;
    if(lista==NULL){
        existe=FALSE;
    }else if(num<=darNumero(darExpresion(lista))){
            existe =TRUE;
        }
    return existe;
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

//MOSTRAR
void mostrarExpresion(ListaExp lExp,int i){
    while(darNumero(lExp->exp)!=i){
        lExp=lExp->sig;
    }

    mostrarExpresion(lExp->exp);
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




