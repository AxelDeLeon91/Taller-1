#ifndef DATOSARBOL_H_INCLUDED
#define DATOSARBOL_H_INCLUDED
#include <stdio.h>
#include "tipoDato.h"
#include "string.h"

typedef struct{
                int numero;
        		tipoDato discriminante;
           		union {
                	char op;
                	boolean v;
                	char par;
                 }datos;
            	}datoABB;

tipoDato darDiscriminante(datoABB dat);
void mostrarNodoAbb(datoABB dat);
void setNOT(datoABB &dat);
void setOR(datoABB &dat);
void setAND(datoABB &dat);
boolean darDatoBool(datoABB dat);
char darOperador(datoABB dat);
void setParentesis(datoABB &dat,char parentesis);
void setNumero(datoABB &dat, int i);
void setValor(datoABB &dat, boolean b);
int darNumero(datoABB dat);

void guardarNodo(datoABB dat, FILE *f);

//Guardar y Levantar
void guardarNodo(datoABB dat, FILE *f);
void levantarNodo(datoABB &dat, FILE *f);
#endif // DATOSARBOL_H_INCLUDED
