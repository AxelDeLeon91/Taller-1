#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED
#include <stdio.h>
#include "error.h"

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


//FUNCIONALIDADES


#endif // COMANDO_H_INCLUDED
