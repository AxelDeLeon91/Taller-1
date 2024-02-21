#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED
#include <stdio.h>

#include "string.h"

typedef struct nodoStr{
            		string str;
            		nodoStr *sig;
        		}nodoString;

typedef nodoString *listaString;

void imprimirLista(nodoString &lista);
void liberarLista(nodoString &lista);
void separarStringEnLista(string original, listaString &lstr);
void insBack(listaString &lista,string s);
int cantStrings(listaString lStr);

boolean validarAtomic(listaString lStr);
boolean validarCompound3(listaString lStr);
boolean validarCompound4(listaString lStr);
boolean validarShow(listaString lStr);
boolean validarEvaluate(listaString lStr);
boolean validarSave(listaString lStr);
boolean validarLoad(listaString lStr);

boolean validarOperador(string s);
#endif // LISTASTRING_H_INCLUDED
