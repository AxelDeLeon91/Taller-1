#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED
#include <stdio.h>
#include "arbolExpresiones.h"

typedef struct{
            int numExpresion;
            arbol abbExpresion;
        }expresion;


//DAR
int darNumero(expresion e);
arbol darArbol(expresion e);

//SET
void setArbol(expresion &e, arbol a);
void setPrimerNum(expresion &e);
void setNumExp(expresion &e, int i);

//FUNCIONALIDADES
void crearExpre(expresion &e);

//MOSTRAR
void mostrarExpresion(expresion e);

//CARGAR




//GUARDAR Y LEVANTAR
void guardarExpresion(expresion &exp, FILE *f);
void levantarExpresion(expresion &exp, FILE *f);
#endif // EXPRESION_H_INCLUDED
