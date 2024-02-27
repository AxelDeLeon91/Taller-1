#include <stdio.h>
#include "datosArbol.h"

tipoDato darDiscriminante(datoABB dat){
    return dat.discriminante;
}
void setNOT(datoABB dat){
    dat.numero=0;
    dat.discriminante=OPERADOR;
    dat.datos.op= 'N';
}
void setOR(datoABB dat){
    dat.numero=0;
    dat.discriminante=OPERADOR;
    dat.datos.op= 'O';
}
void setAND(datoABB dat){
    dat.numero=0;
    dat.discriminante=OPERADOR;
    dat.datos.op= 'A';
}

void setParentesis(datoABB dat,char parentesis){
    dat.numero=0;
    dat.discriminante=PARENTESIS;
    dat.datos.op=parentesis;
}
void setValor(datoABB dat, boolean b){
    dat.discriminante=VALOR;
    dat.numero=0;
    dat.datos.v = b;
}
//Funciona solo si es un Operador o un Parentesis
char darDatoChar(datoABB dat){
    char c;
    if(dat.discriminante==PARENTESIS){
        c=dat.datos.par;
    }else if(dat.discriminante==OPERADOR){
        c=dat.datos.op;
        }
    return c;
}

boolean darDatoBool(datoABB dat){
    boolean val;
    if(dat.discriminante==VALOR){
        val= dat.datos.v;
    }
    return val;
}

char darOperador(datoABB dat){
    return dat.datos.op;
}

//Separar cada uno en un MostrarOperador, MostrarValor y MostrarParentesis
void mostrarNodoAbb(datoABB dat){
    printf(" ");
    string s;
    strcrear(s);
    if(dat.discriminante==OPERADOR){
        switch(dat.datos.op){
            case 'A':
                charAString('A',s);
                print(s);
                break;
            case 'N':
                charAString('N',s);
                print(s);
                break;
            case 'O':
                charAString('O',s);
                print(s);
                break;
        }
    }else if(dat.discriminante==VALOR){
            boolean b=darDatoBool(dat);
            if(b==TRUE){
                booleanAString(b,s);
                print(s);
            }else{
                booleanAString(b,s);
                print(s);
                }
    }else if(dat.discriminante==PARENTESIS){
            if(darDatoChar(dat)=='('){
                printf(" ( ");
               }else
                    printf(" ) ");

    }

}
