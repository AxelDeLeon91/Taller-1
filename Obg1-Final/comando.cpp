#include "comando.h"
void ejecutarComando(listaString lStr, ListaExp lExp){
    int cantStr = cantStrings(lStr);
    char c = reconocerComando(lStr->str);
    switch(cantStr){
    case 1:
        if(c=='E'){
            //Ejecuto EXIT
        break;
    }
    case 2:
        switch(c){
            case 'A':
                if(validarAtomic(lStr)==TRUE){
                        ejecutarAtomic(lStr,lExp);
                    //Ejecuto Atomic
                }else
                    //Muestro mensaje error
                break;
            case 'S':
                //Ejecuto SHOW
                break;
            case 'E':
                //Ejecuto Evaluate
                break;
            case 'L':
                //Ejecuto Load
                break;
            default:
                //Muestro mensaje error
                break;
        }
        break;
    case 3:
        if(c=='C'){
            //Ejecuto Compound Version NOT
        }else if(c=='S'){
                //Ejecuto Save
                }
        break;
    case 4:
        if(c=='E'){
            //Ejecuto Compund Version AND/OR
        }
        break;
    default:
        //Muestro mensaje error
        break;
    }
}


boolean validarOperador(string s){
    boolean valida=TRUE;
    if(streq(s,"AND")==TRUE){
        valida=TRUE;
    }else if(streq(s,"OR")==TRUE){
            valida=TRUE;
    }else if(streq(s,"NOT")==TRUE){
            valida=TRUE;
    }
    return valida;
}

boolean validarAtomic(listaString lStr){
    boolean valida= FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarBool(aux->str)==TRUE){
        valida=TRUE;
    }
    return valida;
}

boolean validarCompound4(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;//Avanzo porque el primer string es el comando Compound
    if(validarEntero(aux->str)==TRUE){
        int num = stringAentero(aux->str);//Pasa un string a entero
            if(existeExpresion(lExp,num)==TRUE){//Chequea que exista la expresion
                aux=aux->sig;
                if(validarOperador(aux->str)==TRUE){//SABER SI ES AND O OR
                    aux=aux->sig;
                    num = stringAentero(aux->str);
                    if(existeExpresion(lExp,num)==TRUE){
                        valida=TRUE;
                    }
                }
            }
        }
    return valida;
}

boolean validarCompound3(listaString lStr, ListaExp lExp){
    boolean valida= FALSE;
    listaString aux=lStr;
    aux=aux->sig;
        if(validarOperador(aux->str)==TRUE){
            aux=aux->sig;
            int num = stringAentero(aux->str);
            if(existeExpresion(lExp,num)==TRUE){
                valida=TRUE;
            }
    return valida;
}
}

boolean validarShow(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux= lStr;
    aux=aux->sig;
    int num = stringAentero(aux->str);
    if(existeExpresion(lExp,num)==TRUE){
        valida=TRUE;
        }
    return valida;
}

boolean validarEvaluate(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux= lStr;
    aux=aux->sig;
    int num = stringAentero(aux->str);
    if(existeExpresion(lExp,num)==TRUE){
        valida=TRUE;
        }
    return valida;
}

boolean validarSave(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux= lStr;
    aux=aux->sig;
    int num = stringAentero(aux->str);
    if(existeExpresion(lExp,num)==TRUE){
        aux=aux->sig;
        if(validarFormatoArchivo(aux->str)==TRUE){
            valida==TRUE;
        }
    }

    return valida;
}

boolean validarLoad(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;

}

void ejecutarAtomic(listaString lStr, ListaExp &lExp){

    //Todo esto va en una funcion no?
    arbol a;
    crear(a);
    lStr=lStr->sig;
    a->info.discriminante=VALOR;
    a->info.numero=0;
    a->info.datos.v = stringAboolean(lStr->str);
    a->hder=NULL;
    a->hizq=NULL;

     //Creo la expresion
    expresion e;
    crearExpre(e);

    //Coloco el arbol en la expresion
    e.abbExpresion= a;

    //Coloco la expresion en listaExpre
    insFront(lExp,e);

    printf("\n Expresion %d:",darNumero(lExp->exp));
    mostrarExpresion(lExp->exp);
}
