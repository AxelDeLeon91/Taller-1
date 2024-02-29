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

//SET
void setParentesis(datoABB &dat,char parentesis);
void setNumero(datoABB &dat, int i);
void setValor(datoABB &dat, boolean b);
void setNOT(datoABB &dat);
void setOR(datoABB &dat);
void setAND(datoABB &dat);
void setDiscriminante(datoABB &dat, tipoDato tipo);

//DAR
tipoDato darDiscriminante(datoABB dat);
int darNumero(datoABB dat);
char darOperador(datoABB dat);
boolean darDatoBool(datoABB dat);
char darParentesis(datoABB dat);
char darDatoChar(datoABB dat);

//MOSTRAR
void mostrarNodoAbb(datoABB dat);
void mostrarValor(datoABB dat);
void mostrarOperador(datoABB dat);
void mostrarPar(datoABB dat);
void mostrarDiscriminante(datoABB dat);

//GUARDAR Y LEVANTAR
void guardarNodo(datoABB dat, FILE *f);
void levantarNodo(datoABB &dat, FILE *f);
#endif // DATOSARBOL_H_INCLUDED
