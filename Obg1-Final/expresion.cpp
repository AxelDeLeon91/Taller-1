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
    mostrarArbolRecu(e.abbExpresion);
}
