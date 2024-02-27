#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED
#include <stdio.h>
#include "arbolExpresiones.h"

typedef struct{
            int numExpresion;
            arbol abbExpresion;
        }expresion;


int darNumero(expresion e);
void crearExpre(expresion e);
void mostrarExpresion(expresion e);
void setNumExp(expresion &e, int i);
void cargarArbolCompoundNOT(arbol &a,expresion e);

arbol darArbol(expresion e);

#endif // EXPRESION_H_INCLUDED
