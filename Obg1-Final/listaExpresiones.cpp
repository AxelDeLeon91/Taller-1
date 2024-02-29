#include <stdio.h>
#include "listaExpresiones.h"

//DAR
expresion darExpresion(ListaExp lExp, int i){ //Devuelve la expresion i de la listaExp
    while(darNumero(lExp->exp)!=i){
        lExp=lExp->sig;
    }
    return darExpresion(lExp);
}

expresion darExpresion(ListaExp lExp){ //Devuelve la expresion a la que apunta lExp
    return lExp->exp;
}

//FUNCIONALIDADES
void crearLista(ListaExp &l){ //Crea la listaExp
    l=NULL;
}

boolean listaVacia(ListaExp l){ //Devuelve TRUE si lExp esta vacia
    boolean es= FALSE;
    if(l==NULL)
        es=TRUE;
    return es;
}

boolean existeExpresion(ListaExp lista, int num){ //Chequea si existe la expresion num en lExp
    boolean existe=FALSE;
    if(lista==NULL){
        existe=FALSE;
    }else if(num<=darNumero(darExpresion(lista))){
            existe =TRUE;
        }
    return existe;
}

void insFront(ListaExp &lExp, expresion e){ //Inserta la expresion e al principio de lExp, asignandole un valor +1 a la ex
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
void mostrarExpresion(ListaExp lExp,int i){ //Busca la expresion I en lExp y la muestra por pantalla
    while(darNumero(lExp->exp)!=i){
        lExp=lExp->sig;
    }
    mostrarExpresion(lExp->exp);
}

//PRUEBA
void mostrarListaExp(ListaExp lExp){ //Para probar el programa, muestra toda la lExp
    printf("\nListaExp: ");
    while(lExp != NULL){
        mostrarExpresion(lExp->exp);
        lExp = lExp->sig;
        if (lExp!= NULL){
            printf(" -> ");
        }
    }
    printf("\n");
}




