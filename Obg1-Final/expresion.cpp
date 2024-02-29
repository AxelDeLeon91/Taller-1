#include <stdio.h>
#include "expresion.h"
//DAR
int darNumero(expresion e){
    return e.numExpresion;
}

arbol darArbol(expresion e){
    return e.abbExpresion;
}

//SET
void setArbol(expresion &e, arbol a){
    e.abbExpresion= a;
}

void setPrimerNum(expresion &e){
    e.numExpresion=1;
}
void setNumExp(expresion &e, int i){
    e.numExpresion=i;
}

//FUNCIONALIDADES
void crearExpre(expresion &e){
    e.numExpresion=0;
    e.abbExpresion= NULL;
}

//MOSTRAR
void mostrarExpresion(expresion e){
    printf("\nExpresion %d:", darNumero(e));
    mostrarArbolRecu(e.abbExpresion);
}

//CARGAR

//GUARDAR Y LEVANTAR
void guardarExpresion(expresion &exp, FILE * f) {
    fwrite(&exp.numExpresion, sizeof(int), 1, f);
    guardarArbol(darArbol(exp), f);
}

void levantarExpresion(expresion &exp, FILE *f) {
    fread(&exp.numExpresion, sizeof(int), 1, f);
    levantarArbol(exp.abbExpresion, f);
}
