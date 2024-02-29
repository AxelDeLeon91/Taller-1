#include <stdio.h>
#include "expresion.h"
//DAR
int darNumero(expresion e){ //Selectora para el numExpresion
    return e.numExpresion;
}

arbol darArbol(expresion e){ //Devuelve el arbol de la expresion e
    return e.abbExpresion;
}

//SET
void setArbol(expresion &e, arbol a){ //Setea el arbol a en la expresion e
    e.abbExpresion= a;
}

void setPrimerNum(expresion &e){ //Setea el numero de la primer expresion ingresada
    e.numExpresion=1;
}
void setNumExp(expresion &e, int i){ //Setea i como numExpresion de e
    e.numExpresion=i;
}

//FUNCIONALIDADES
void crearExpre(expresion &e){//Inicializa la expresion
    e.numExpresion=0;
    e.abbExpresion= NULL;
}

//MOSTRAR
void mostrarExpresion(expresion e){ //Muestra por pantalla la expresion
    printf("\nExpresion %d:", darNumero(e));
    mostrarArbolRecu(e.abbExpresion);
}

//CARGAR

//GUARDAR Y LEVANTAR
void guardarExpresion(expresion exp, FILE *f){ //Guarda la expresion exp en el file f
    fwrite(&exp.numExpresion, sizeof(int), 1, f);
    guardarArbol(darArbol(exp), f);
}
void levantarExpresion(expresion &exp, FILE *f){ //Levanta la expresion exp desde el file f
    fread(&exp.numExpresion, sizeof(int), 1, f);
    levantarArbol(exp.abbExpresion, f);
}
