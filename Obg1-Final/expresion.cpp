#include <stdio.h>
#include "expresion.h"

int darNumero(expresion e){
    return e.numExpresion;
}

void crearExpre(expresion &e){
    e.numExpresion=0;
    e.abbExpresion= NULL;
}
void mostrarExpresion(expresion e){
    printf("\nExpresion %d:", darNumero(e));
    mostrarArbolRecu(e.abbExpresion);
}
void setPrimerNum(expresion &e){
    e.numExpresion=1;
}
void setNumExp(expresion &e, int i){
    e.numExpresion=i;
}

void cargarArbolCompoundNOT(arbol &a,arbol abb){
    a = new nodoABB;
    setNOT(a->info);

    a->hder=abb;
    a->hizq==NULL;
    colocarParentesis(a);
}

arbol darArbol(expresion e){
    return e.abbExpresion;
}


void guardarExpresion(expresion exp, FILE *f) {     //tenia el cabezal con la expresion por referencia
    fwrite(&exp.numExpresion, sizeof(int), 1, f);
    guardarArbol(darArbol(exp), f);
}

void levantarExpresion(expresion &exp, FILE *f) {
    fread(&exp.numExpresion, sizeof(int), 1, f);
    levantarArbol(exp.abbExpresion, f);
}
