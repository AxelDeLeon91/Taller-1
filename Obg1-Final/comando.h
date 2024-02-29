#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include "listaExpresiones.h"
#include "listaString.h"

void ejecutarComando(listaString lStr, ListaExp &lExp, char c);
boolean validarAtomic(listaString lStr);
boolean validarCompound3(listaString lStr, ListaExp lExp);
boolean validarCompound4(listaString lStr, ListaExp lExp);
boolean validarShow(listaString lStr, ListaExp lExp);
boolean validarEvaluate(listaString lStr, ListaExp lExp);
boolean validarSave(listaString lStr, ListaExp lExp);
boolean validarLoad(listaString lStr, ListaExp lExp);

boolean validarOperador(string s);

void ejecutarAtomic(listaString lStr, ListaExp &lExp);
void ejecutarShow(listaString lStr, ListaExp lExp);
void ejecutarEvaluate(listaString lStr, ListaExp lExp);
void ejecutarLoad(listaString lStr, ListaExp &lExp);
void ejecutarSave(listaString lStr, ListaExp lExp);
void ejecutarCompound3(listaString lStr, ListaExp &lExp);
void ejecutarCompound4(listaString lStr, ListaExp &lExp);
#endif // COMANDO_H_INCLUDED
