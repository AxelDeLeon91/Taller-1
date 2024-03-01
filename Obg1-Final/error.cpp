#include "error.h"
void mostrarError(numError e){
    switch(e){
    case error0:
        printf("\nPrograma ejecutandose");
        break;
    case error1:
        printf("\nValor booleano ingresado invalido o mal escrito");
        break;
    case error2:
        printf("\nExpresion ingresada no existe");
        break;
    case error3:
        printf("\nNumero ingresado no es un entero");
        break;
    case error4:
        printf("\nOperador mal escrito o escrito en minuscula");
        break;
    case error5:
        printf("\nSegunda expresion ingresada no existe");
        break;
    case error6:
        printf("\nPrimera expresion ingresada no existe");
        break;
    case error7:
        printf("\nFormato archivo invalido(nombrearchivo.dat)");
        break;
    case error8:
        printf("\nArchivo ingresado no existe");
        break;
    case error9:
        printf("\nCantidad de parametros erronea");
        break;
    default:
        break;
    }
}
numError validarAtomic(listaString lStr){ // valida que el valor booleano este bien escrito y en minuscula
    numError e=error0;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarBool(aux->str)){
        e=error0;
    }else{
        e=error1;//BOOLEAN NO VALIDO
    }
    return e;
}

numError validarCompound3(listaString lStr, ListaExp lExp){ //Valida que el formato del compound con 3 strings sea: compound NOT valor
    numError e=error0;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarNOT(aux->str)==TRUE){
        aux=aux->sig;
        if(esNumero(aux->str)){
            int num = stringAentero(aux->str);
            if(existeExpresion(lExp,num)==TRUE){
                e=error0;
            }else{
                e=error2;//EXPRESION INGRESADA NO EXISTE
            }
        }else{
            e=error3;//LO INGRESADO NO ES UN ENTERO
        }
    }else{
        e=error4;//OPERADOR MAL ESCRITO
    }
    return e;
}

numError validarCompound4(listaString lStr, ListaExp lExp){//Valida que el formato del compound con 4 strings sea: compound #expresion AND/OR #expresion
    numError e=error0;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarEntero(aux->str)==TRUE){
        int num = stringAentero(aux->str);
            if(existeExpresion(lExp,num)==TRUE){
                aux=aux->sig;
                if(validarOrAnd(aux->str)==TRUE){
                    aux=aux->sig;
                    if(validarEntero(aux->str)==TRUE){
                        num = stringAentero(aux->str);
                        if(existeExpresion(lExp,num)==TRUE){
                            e=error0;
                        }else{
                            e=error5;//CASO AND OR: segunda expresion no existe
                        }
                    }else{
                        e=error3;//LO INGRESADO NO ES UN ENTERO
                    }
                }else{
                    e=error4;//OPERADOR MAL ESCRITO
                }
            }else{
                e=error6;//CASO AND OR: primera expresion no existe
            }
        }else{
            e=error3;//LO INGRESADO NO ES UN ENTERO
        }
    return e;
}

numError validarEvaluate(listaString lStr, ListaExp lExp){ //Valida que el formato del evaluate sea: evaluate #expresion
    numError e=error0;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarEntero(aux->str)){
        int num = stringAentero(aux->str);
        if(existeExpresion(lExp,num)==TRUE){
            e=error0;
        }else{
            e=error2;//EXPRESION INGRESADA NO EXISTE
        }
    }else{
        e=error3;//LO INGRESADO NO ES UN ENTERO
    }
    return e;
}

numError validarShow(listaString lStr, ListaExp lExp){ //Valida que el formato del evaluate sea: evaluate #expresion
    numError e=error0;
    listaString aux=lStr;
    aux=aux->sig;
    if(esNumero(aux->str)){
        int num = stringAentero(aux->str);
        if(existeExpresion(lExp,num)==TRUE){
            e=error0;
        }else{
            e=error2;//EXPRESION INGRESADA NO EXISTE
            }
    }else{
        e=error3;//LO INGRESADO NO ES UN ENTERO
    }
    return e;
}

numError validarSave(listaString lStr, ListaExp lExp){ //Valida que el formato del save sea: save #expresion nombrearchivo.dat
    numError e=error0;
    lStr = lStr->sig;
    if(esNumero(lStr->str)){
        int num = stringAentero(lStr->str);
        if(existeExpresion(lExp,num)==TRUE){
            lStr = lStr->sig;
            if(validarFormatoArchivo(lStr->str)==TRUE){
                e=error0;
            }else{
                e=error7;//FORMATO ARCHIVO INVALIDO
            }
        }else{
            e=error2;//EXPRESION INGRESADA NO EXISTE
        }
    }else{
        e=error3;//LO INGRESADO NO ES UN ENTERO
    }

    return e;
}
numError validarLoad(listaString lStr, ListaExp lExp){ //Valida que el formato del load sea: load nombrearchivo.dat
    numError e=error0;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarFormatoArchivo(aux->str)==TRUE){
        if(existeArchivo(aux->str)){
            e=error0;
        }else{
            e=error8;//ARCHIVO NO EXISTE
        }
    }else{
        e=error7;//FORMATO ARCHIVO INVALIDO
    }
    return e;
}


