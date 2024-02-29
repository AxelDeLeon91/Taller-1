#include <stdio.h>
#include "datosArbol.h"
//SET
void setParentesis(datoABB &dat,char parentesis){
    dat.numero=0;
    dat.discriminante=PARENTESIS;
    dat.datos.par=parentesis;
}

void setNumero(datoABB &dat, int i){
    dat.numero=i;
}

void setValor(datoABB &dat, boolean b){
    dat.discriminante=VALOR;
    dat.numero=0;
    dat.datos.v = b;
}

void setNOT(datoABB &dat){
    dat.numero=0;
    dat.discriminante=OPERADOR;
    dat.datos.op= 'N';
}
void setOR(datoABB &dat){
    dat.numero=0;
    dat.discriminante=OPERADOR;
    dat.datos.op= 'O';
}
void setAND(datoABB &dat){
    dat.numero=0;
    dat.discriminante=OPERADOR;
    dat.datos.op= 'A';
}

void setDiscriminante(datoABB &dat, tipoDato tipo){
    dat.discriminante=tipo;
}

//DAR
tipoDato darDiscriminante(datoABB dat){
    return dat.discriminante;
}

int darNumero(datoABB dat){
    return dat.numero;
}

char darOperador(datoABB dat){
    return dat.datos.op;
}
boolean darDatoBool(datoABB dat){
    boolean val;
    if(dat.discriminante==VALOR){
        val= dat.datos.v;
    }
    return val;
}

char darParentesis(datoABB dat){
    return dat.datos.par;
}

char darDatoChar(datoABB dat){
    char c;
    if(dat.discriminante==PARENTESIS){
        c=dat.datos.par;
    }else if(dat.discriminante==OPERADOR){
        c=dat.datos.op;
        }
    return c;
}


//MOSTRAR
void mostrarNodoAbb(datoABB dat){
    printf(" ");
        if(darDiscriminante(dat)==OPERADOR){
           mostrarOperador(dat);
        }else if(darDiscriminante(dat)==VALOR){
            mostrarValor(dat);
        }else if(darDiscriminante(dat)==PARENTESIS){
                mostrarPar(dat);
    }
}

void mostrarValor(datoABB dat){
    boolean b=darDatoBool(dat);
    if(b==TRUE){
        printf("TRUE");
    }else{
        printf("FALSE");
    }

}

void mostrarOperador(datoABB dat){
    switch (dat.datos.op){
        case 'A':
            printf("AND");
            break;
        case 'N':
            printf("NOT");
            break;
        case 'O':
            printf("OR");
            break;
    }
}

void mostrarPar(datoABB dat){
    if(dat.datos.par =='('){
        printf("(");
    }else{
        printf(")");
    }
}

void mostrarDiscriminante(datoABB dat){
    if(dat.discriminante==VALOR){
        printf("\nEs un valor");
    }else if(dat.discriminante==OPERADOR){
            printf("\nEs un OPERADOR");
    }else if(dat.discriminante==PARENTESIS){
            printf("\nEs un Parentesis");
    }else
        printf("\nError");
}

//GUARDAR Y LEVANTAR
void guardarNodo(datoABB dat, FILE *f) {
    fwrite(&dat.numero, sizeof(int), 1, f);
    fwrite(&dat.discriminante, sizeof(tipoDato), 1, f);
    switch (dat.discriminante){
        case OPERADOR:
            fwrite(&dat.datos.op, sizeof(char), 1, f);
            break;
        case VALOR:
            fwrite(&dat.datos.v, sizeof(bool), 1, f);
            break;
        case PARENTESIS:
            fwrite(&dat.datos.par, sizeof(char), 1, f);
            break;
    }
}

void levantarNodo(datoABB &dat, FILE *f) {
    fread(&dat.numero, sizeof(int), 1, f);
    fread(&dat.discriminante, sizeof(tipoDato), 1, f);
    switch (dat.discriminante) {
        case OPERADOR:
            fread(&dat.datos.op, sizeof(char), 1, f);
            break;
        case VALOR:
            fread(&dat.datos.v, sizeof(bool), 1, f);
            break;
        case PARENTESIS:
            fread(&dat.datos.par, sizeof(char), 1, f);
            break;
    }
}
