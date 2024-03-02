#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED
#include <stdio.h>

#include "string.h"

typedef struct nodoStr{
            		string str;
            		nodoStr *sig;
        		}nodoString;

typedef nodoString *listaString;

void imprimirLista(listaString lStr);
void limpiarLista(listaString &lstr);
void separarStringEnLista(string original, listaString &lstr);
void insBack(listaString &lista,string s);
int cantStrings(listaString lStr);
void crearListaString(listaString &lStr);
boolean listaVacia(listaString lStr);

void avanzarLstr(listaString &lStr);

#endif // LISTASTRING_H_INCLUDED
