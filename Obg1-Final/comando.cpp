#include "comando.h"

//EJECUTAR
void ejecutarComando(listaString lStr, ListaExp &lExp, char c){
    switch(c){
        case 'A':
            if(cantStrings(lStr)==2){
                if(validarAtomic(lStr)){
                        ejecutarAtomic(lStr,lExp);
                        break;
                }else
                    printf("\nComando Atomic mal escrito");
            }else
                printf("\nError en cantidad de parametros\nFormato Atomic: atomic valor");
            break;

        case 'H':
             if(cantStrings(lStr)==2){
                if(validarShow(lStr,lExp)){
                        ejecutarShow(lStr,lExp);
                        break;
                }else
                    printf("\nExpresion no existe");
             }else
                printf("\nError en cantidad de parametros\nFormato Show: show #expresion");
            break;

        case 'E':
            if(cantStrings(lStr)==2){
                if(validarEvaluate(lStr,lExp)){
                        ejecutarEvaluate(lStr,lExp);
                        break;
                }else{
                    printf("\nExpresion no existe");
                    break;
                }
            }else{
                printf("\nError en cantidad de parametros\nFormato Evaluate: evaluate #expresion");
                break;
            }

        case 'L':
            if(cantStrings(lStr)==2){
                if(validarLoad(lStr,lExp)){
                        ejecutarLoad(lStr,lExp);
                        break;
                }else
                    printf("\nComando Load mal escrito");
            }else
                printf("\nError en cantidad de parametros\nFormato Load: load nombrearchivo.dat");
            break;

        case 'C':
                if(cantStrings(lStr)==3){
                     if(validarCompound3(lStr,lExp)){
                        ejecutarCompound3(lStr,lExp);
                     }
                     else printf("\nCompound mal escrito");

                }else if(cantStrings(lStr)==4){
                        if(validarCompound4(lStr,lExp)){
                            ejecutarCompound4(lStr,lExp);
                        }else printf("\nCompound mal escrito");
                    }else
                        printf("\nError en cantidad de parametros\nFormato Compound AND/OR: compound #expresion AND/OR #expresion\nFormato Compound NOT: compound NOT #expresion");
                break;

        case 'S':
                if(cantStrings(lStr)==3){
                    if(validarSave(lStr,lExp)){
                         ejecutarSave(lStr,lExp);
                        }else
                            printf("\nComando Save mal escrito");
                }else
                    printf("\nError en cantidad de parametros\nFormato Save: save #expresion nombrearchivo.dat");
                break;
        case 'X':
                if(cantStrings(lStr)==1){
                        //Libero memoria
                }else
                    printf("\nError en cantidad de parametros\nFormato Exit: exit");

        default:
            printf("\nNo ingresa ningun comando");
            break;
        }
    }

void ejecutarAtomic(listaString lStr, ListaExp &lExp){
    arbol a;
    crear(a);
    lStr=lStr->sig;
    cargarArbolAtomic(a,lStr->str);

    //Creo la expresion
    expresion e;
    crearExpre(e);

    //Coloco el arbol en la expresion
    setArbol(e,a);

    //Coloco la expresion en listaExpre
    insFront(lExp,e);

    mostrarExpresion(lExp->exp);
}

void ejecutarCompound3(listaString lStr, ListaExp &lExp){
    lStr=lStr->sig;

    arbol a;
    crear(a);

    lStr=lStr->sig; //Avanzo al entero
    int i = stringAentero(lStr->str);
    expresion e = darExpresion(lExp,i);
    arbol abb=copiarArbol(darArbol(e));
    cargarArbolCompoundNOT(a,abb);
    expresion j;
    crearExpre(j);
    setArbol(j,a);
    insFront(lExp,j);
    mostrarExpresion(darExpresion(lExp));
}

void ejecutarCompound4(listaString lStr, ListaExp &lExp){
    lStr=lStr->sig;
    arbol a;
    crear(a);
    a = new nodoABB;

    int i=stringAentero(lStr->str);
    expresion e1 = darExpresion(lExp,i);
    lStr=lStr->sig;
    datoABB dat;
    setDiscriminante(dat,OPERADOR);

    if(saberOperador(lStr->str)== 'O'){
        setOR(dat);
    }else if(saberOperador(lStr->str)== 'A'){
            setAND(dat);
        }

    lStr=lStr->sig;
    int j=stringAentero(lStr->str);
    expresion e2 = darExpresion(lExp,j);
    arbol abb = copiarArbol(darArbol(e1));
    arbol abb2= copiarArbol(darArbol(e2));
    juntarArboles(abb,abb2,dat,a);
    expresion e;
    crearExpre(e);
    setArbol(e,a);
    insFront(lExp,e);
    mostrarExpresion(lExp->exp);
}

void ejecutarEvaluate(listaString lStr, ListaExp lExp){
    lStr=lStr->sig;
    expresion e= darExpresion(lExp,stringAentero(lStr->str));
    if(evaluarArbol(darArbol(e))==TRUE){
        printf("La Expresion %d vale:  TRUE", darNumero(e));
    }else
        printf("La Expresion %d vale:  FALSE",darNumero(e));
}

void ejecutarShow(listaString lStr, ListaExp lExp){
    lStr=lStr->sig;
    int i = stringAentero(lStr->str);
    mostrarExpresion(lExp,i);
}

void ejecutarSave(listaString lStr, ListaExp lExp){
    lStr = lStr->sig;
    int i = stringAentero(lStr->str);

    lStr = lStr->sig;
    FILE *f = fopen(lStr->str, "wb");
    expresion exp = darExpresion(lExp, i);
    numerarArbol(exp.abbExpresion);
    guardarExpresion(exp, f);
    fclose(f);
}

void ejecutarLoad(listaString lStr, ListaExp &lExp){
    expresion exp;
    crearExpre(exp);
    lStr=lStr->sig;
    FILE * f=fopen(lStr->str, "rb");
    levantarExpresion(exp,f);
    insFront(lExp,exp);
}

//FUNCIONALIDADES
boolean validarOperador(string s){
    boolean valida=FALSE;
    if(streq(s,"AND") || streq(s,"OR") || streq(s,"NOT")){
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

boolean validarCompound3(listaString lStr, ListaExp lExp){
    boolean valida= FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarOperador(aux->str)==TRUE){
        aux=aux->sig;
        if(esNumero(aux->str)){
            int num = stringAentero(aux->str);
            if(existeExpresion(lExp,num)==TRUE){
                valida=TRUE;
            }
        }
    }
    return valida;
}

boolean validarCompound4(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarEntero(aux->str)==TRUE){
        int num = stringAentero(aux->str);
            if(existeExpresion(lExp,num)==TRUE){
                aux=aux->sig;
                if(validarOperador(aux->str)==TRUE){
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

boolean validarEvaluate(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(esNumero(aux->str)){
        int num = stringAentero(aux->str);
        if(existeExpresion(lExp,num)==TRUE){
            valida=TRUE;
        }
    }
    return valida;
}

boolean validarShow(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(esNumero(aux->str)){
        int num = stringAentero(aux->str);
        if(existeExpresion(lExp,num)==TRUE){
            valida=TRUE;
            }
    }
    return valida;
}

boolean validarSave(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(esNumero(lStr->str)){
        int num = stringAentero(aux->str);
        if(existeExpresion(lExp,num)){
            lStr=lStr->sig;
            if(validarFormatoArchivo(aux->str)){
                valida=TRUE;
            }
        }
    }
    return valida;
}

boolean validarLoad(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarFormatoArchivo(aux->str)==TRUE){
        if(existeArchivo(aux->str)){
            valida=TRUE;
        }
    }
    return valida;
    return TRUE;
}

//FUNCIONALIDADES
boolean existeArchivo(string s) {
    boolean existe=FALSE;
    FILE *f = fopen(s, "r");

    if (f != NULL){
        existe=TRUE;
    }
    return existe;
}
