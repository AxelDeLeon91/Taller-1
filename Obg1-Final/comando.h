#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include "listaExpresiones.h"
#include "listaString.h"

//EJECUTAR
void ejecutarComando(listaString lStr, ListaExp &lExp, char c);
void ejecutarAtomic(listaString lStr, ListaExp &lExp);
void ejecutarCompound3(listaString lStr, ListaExp &lExp);
void ejecutarCompound4(listaString lStr, ListaExp &lExp);
void ejecutarEvaluate(listaString lStr, ListaExp lExp);
void ejecutarShow(listaString lStr, ListaExp lExp);
void ejecutarSave(listaString lStr, ListaExp lExp);
void ejecutarLoad(listaString lStr, ListaExp &lExp);
void ejecutarExit(listaString lStr);

//VALIDAR
boolean validarOperador(string s);
boolean validarAtomic(listaString lStr);
boolean validarCompound3(listaString lStr, ListaExp lExp);
boolean validarCompound4(listaString lStr, ListaExp lExp);
boolean validarEvaluate(listaString lStr, ListaExp lExp);
boolean validarShow(listaString lStr, ListaExp lExp);
boolean validarSave(listaString lStr, ListaExp lExp);
boolean validarLoad(listaString lStr, ListaExp lExp);

//FUNCIONALIDADES
boolean existeArchivo(string s);

#endif // COMANDO_H_INCLUDED
