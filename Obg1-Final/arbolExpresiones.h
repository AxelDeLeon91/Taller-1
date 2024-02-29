#ifndef ARBOLEXPRESIONES_H_INCLUDED
#define ARBOLEXPRESIONES_H_INCLUDED
#include <stdio.h>
#include "datosArbol.h"

typedef struct nodoA{
                	datoABB info;
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
void juntarArboles(arbol a, arbol b, datoABB dat, arbol &c);
void mostrarArbolRecu(arbol a);
void cargarArbolAtomic(arbol &a, string s);
datoABB darInfo(arbol a);
boolean evaluarArbol(arbol a);
void mostrarDiscriminante(datoABB dat);
arbol copiarArbol(arbol original);

//Guardar y Levantar
void guardarArbolAux(arbol a, FILE * f);
void guardarArbol(arbol a, string s);
void insertarNodo(arbol &a, nodoABB nuevoNodo);
void levantarArbol(arbol &a, FILE *f);

#endif // ARBOLEXPRESIONES_H_INCLUDED
