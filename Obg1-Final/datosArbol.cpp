#include <stdio.h>
#include "datosArbol.h"

tipoDato darDiscriminante(datoABB dat){
    return dat.discriminante;
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
