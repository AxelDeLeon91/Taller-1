#include <stdio.h>
#include "datosArbol.h"
//SET
void setParentesis(datoABB &dat,char parentesis){ //Setea el datoABB como parentesis
    dat.numero=0;
    setDiscriminante(dat,PARENTESIS);
    dat.datos.par=parentesis;
}

void setNumero(datoABB &dat, int i){ //Setea el numero de datoABb como i
    dat.numero=i;
}

void setValor(datoABB &dat, boolean b){ //Setea el valor de datoABB
    setDiscriminante(dat,VALOR);
    dat.numero=0;
    dat.datos.v = b;
}

void setNOT(datoABB &dat){ //Setea el discriminante y su operador como NOT
    dat.numero=0;
    setDiscriminante(dat,OPERADOR);
    dat.datos.op= 'N';
}
void setOR(datoABB &dat){ //Setea el discriminante y su operador como OR
    dat.numero=0;
    setDiscriminante(dat,OPERADOR);
    dat.datos.op= 'O';
}
void setAND(datoABB &dat){ //Setea el discriminante y su operador como AND
    dat.numero=0;
    setDiscriminante(dat,OPERADOR);
    dat.datos.op= 'A';
}

void setDiscriminante(datoABB &dat, tipoDato tipo){ //Setea el discriminante
    dat.discriminante=tipo;
}

//DAR
tipoDato darDiscriminante(datoABB dat){ //Devuelve el discriminante de dat
    return dat.discriminante;
}

int darNumero(datoABB dat){ //Devuelve el numero de dat
    return dat.numero;
}

char darOperador(datoABB dat){ //Devuelve el operador de dat
    return dat.datos.op;
}
boolean darDatoBool(datoABB dat){ //Devuelve el valor de dat
    boolean val;
    if(dat.discriminante==VALOR){
        val= dat.datos.v;
    }
    return val;
}

char darParentesis(datoABB dat){ //Devuelve el char parentesis de dat
    return dat.datos.par;
}

char darDatoChar(datoABB dat){ //Devuelve el datochar que se encuentra en dat, ya sea parentesis o operador
    char c;
    if(dat.discriminante==PARENTESIS){
        c=dat.datos.par;
    }else if(dat.discriminante==OPERADOR){
        c=dat.datos.op;
        }
    return c;
}


//MOSTRAR
void mostrarNodoAbb(datoABB dat){ //Muestra lo que se encuentre en datoABB
        if(darDiscriminante(dat)==OPERADOR){
           mostrarOperador(dat);
        }else if(darDiscriminante(dat)==VALOR){
            mostrarValor(dat);
        }else if(darDiscriminante(dat)==PARENTESIS){
                mostrarPar(dat);
    }
}

void mostrarValor(datoABB dat){ //Muestra el dato booleano que hay en dat.union
    boolean b=darDatoBool(dat);
    if(b==TRUE){
        printf("true");
    }else{
        printf("false");
    }

}

void mostrarOperador(datoABB dat){ //Muestra el dato Operador que hay en dat.union
    switch (dat.datos.op){
        case 'A':
            printf(" AND ");
            break;
        case 'N':
            printf("NOT ");
            break;
        case 'O':
            printf(" OR ");
            break;
    }
}

void mostrarPar(datoABB dat){ //Muestra el dato Parentesis que hay en dat.union
    if(dat.datos.par =='('){
        printf("(");
    }else{
        printf(")");
    }
}

void mostrarDiscriminante(datoABB dat){ //Muestra el discriminante que hay en dat
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
void guardarNodo(datoABB dat, FILE *f){ //Guarda el datoabb en el file f
    fwrite(&dat.numero, sizeof(int),1,f);
    fwrite(&dat.discriminante,sizeof(tipoDato),1,f);
    switch (dat.discriminante){
        case OPERADOR:
            fwrite(&dat.datos.op,sizeof(char),1,f);
            break;
        case VALOR:
            fwrite(&dat.datos.v, sizeof(bool),1,f);
            break;
        case PARENTESIS:
            fwrite(&dat.datos.par, sizeof(char),1,f);
            break;
    }
}

void levantarNodo(datoABB &dat, FILE *f){ //Levanta el dato abb desde file f
    fread(&dat.numero, sizeof(int), 1, f);
    fread(&dat.discriminante, sizeof(tipoDato),1,f);
    switch (dat.discriminante){
        case OPERADOR:
            fread(&dat.datos.op, sizeof(char),1,f);
            break;
        case VALOR:
            fread(&dat.datos.v, sizeof(bool),1,f);
            break;
        case PARENTESIS:
            fread(&dat.datos.par, sizeof(char),1,f);
            break;
    }
}
