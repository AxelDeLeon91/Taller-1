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

#endif // EXPRESION_H_INCLUDED
