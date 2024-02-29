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

//FUNCIONALIADES
void crear(arbol &a);
boolean arbolVacio(arbol a);
void numerarArbol(arbol &a);
void numerarRecursivo(arbol a , int &contador);
void colocarParentesis(arbol &a);
void colocarParIzq(arbol &a);
void colocarParDer(arbol &a);
boolean evaluarArbol(arbol a);
arbol copiarArbol(arbol original);
void insertarNodo(arbol &a, nodoABB nuevoNodo);
void juntarArboles(arbol a, arbol b, datoABB dat, arbol &c);

//DAR
arbol darRaiz(arbol a);
arbol hijoIzq(arbol a);
arbol hijoDer(arbol a);
datoABB darInfo(arbol a);

//MOSTRAR
void mostrarArbolRecu(arbol a);

//CARGAR
void cargarArbolAtomic(arbol &a, string s);
void cargarArbolCompoundNOT(arbol &a,arbol abb);

//GUARDAR Y LEVANTAR
void guardarArbolAux(arbol a, FILE * f);
void guardarArbol(arbol a, FILE * f);
void levantarArbol(arbol &a, FILE *f);

#endif // ARBOLEXPRESIONES_H_INCLUDED
