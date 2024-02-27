#include <stdio.h>
#include "expresion.h"

int darNumero(expresion e){
    return e.numExpresion;
}

void crearExpre(expresion e){
    e.numExpresion=0;
    e.abbExpresion= NULL;
}
void mostrarExpresion(expresion e){
    printf("Expresion %d:", darNumero(e));
    mostrarArbolRecu(e.abbExpresion);
}

void setNumExp(expresion &e, int i){
    e.numExpresion=i;
}

void cargarArbolCompoundNOT(arbol &a,expresion e){
    a->hder=darArbol(e);
    colocarParentesis(a);
}

arbol darArbol(expresion e){
    return e.abbExpresion;
}
