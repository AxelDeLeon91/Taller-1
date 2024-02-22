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

#endif // DATOSARBOL_H_INCLUDED
