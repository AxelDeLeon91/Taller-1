#ifndef ARBOLEXPRESIONES_H_INCLUDED
#define ARBOLEXPRESIONES_H_INCLUDED
#include <stdio.h>
#include "datosArbol.h"

typedef struct nodoA{
                	datoABB info;
                	int numero;
                	nodoA * hizq;
                	nodoA * hder;
            }nodoABB;

typedef nodoABB * arbol;

void crear(arbol &a);
boolean arbolVacio(arbol a);
arbol darRaiz(arbol a);
arbol hijoIzq(arbol a);
arbol hijoDer(arbol a);
void numerarArbol(arbol &a);
void numerarRecursivo(arbol a , int &contador);
void colocarParentesis(arbol &a);
void colocarParIzq(arbol &a);
void colocarParDer(arbol &a);
void juntarArboles(arbol a, arbol b, nodoABB Raiz, arbol &c);
void mostrarArbol(arbol a);
void mostrarArbolRecu(arbol a);

int evaluarArbol(arbol a);
#endif // ARBOLEXPRESIONES_H_INCLUDED
