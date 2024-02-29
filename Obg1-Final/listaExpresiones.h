#ifndef LISTAEXPRESIONES_H_INCLUDED
#define LISTAEXPRESIONES_H_INCLUDED
#include <stdio.h>
#include "expresion.h"

typedef struct nodoL{
           		expresion exp;
            	nodoL * sig;
        }nodoLista;

typedef nodoLista * ListaExp;

boolean existeExpresion(ListaExp lista, int num);
void crearLista(ListaExp &l);
boolean listaVacia(ListaExp l);
void insFront(ListaExp &lExp, expresion e);
void mostrarExpresion(ListaExp lExp, int i);
expresion darExpresion(ListaExp lExp, int i);
expresion darPrimerExpresion(ListaExp lExp);

void mostrarListaExp(ListaExp lExp);//PRUEBA
#endif // LISTAEXPRESIONES_H_INCLUDED
