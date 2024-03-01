#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED
#include <stdio.h>
#include "listaExpresiones.h"
#include "listaString.h"

typedef enum{
        error0, //NO HAY ERROR, SE EJECUTA FUNCION
        error1, //BOOLEAN NO VALIDO
        error2, //EXPRESION INGRESADA NO EXISTE
        error3, //LO INGRESADO NO ES UN ENTERO
        error4, //OPERADOR MAL ESCRITO
        error5, //CASO AND OR: segunda expresion no existe
        error6, //CASO AND OR: primera expresion no existe
        error7, //FORMATO ARCHIVO INVALIDO
        error8, //ARCHIVO NO EXISTE
        error9, //Cantidad de parametros erronea
}numError;

void mostrarError(numError e);
numError validarAtomic(listaString lStr);
numError validarCompound3(listaString lStr, ListaExp lExp);
numError validarCompound4(listaString lStr, ListaExp lExp);
numError validarEvaluate(listaString lStr, ListaExp lExp);
numError validarShow(listaString lStr, ListaExp lExp);
numError validarSave(listaString lStr, ListaExp lExp);
numError validarLoad(listaString lStr, ListaExp lExp);
#endif // ERROR_H_INCLUDED
