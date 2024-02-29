#ifndef LISTAEXPRESIONES_H_INCLUDED
#define LISTAEXPRESIONES_H_INCLUDED
#include <stdio.h>
#include "expresion.h"

typedef struct nodoL{
           		expresion exp;
            	nodoL * sig;
        }nodoLista;

typedef nodoLista * ListaExp;

//DAR
expresion darExpresion(ListaExp lExp, int i);
expresion darExpresion(ListaExp lExp);

//FUNCIONALIDADES
void crearLista(ListaExp &l);
boolean listaVacia(ListaExp l);
boolean existeExpresion(ListaExp lista, int num);
void insFront(ListaExp &lExp, expresion e);

//MOSTRAR
void mostrarExpresion(ListaExp lExp, int i);
void mostrarListaExp(ListaExp lExp);//PRUEBA

#endif // LISTAEXPRESIONES_H_INCLUDED
