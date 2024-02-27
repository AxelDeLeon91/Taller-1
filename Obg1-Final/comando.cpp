#include "comando.h"

void ejecutarComando(listaString lStr, ListaExp lExp){
    int cantStr = cantStrings(lStr);
    char c = reconocerComando(lStr->str);
    switch(c){
        case 'A':
            if(cantStrings(lStr)==2){
                if(validarAtomic(lStr)==TRUE){
                        ejecutarAtomic(lStr,lExp);
                }else
                    printf("\nComando Atomic mal escrito");
            }else
                printf("\nError en cantidad de parametros");
            break;

        case 'H':
             if(cantStrings(lStr)==2){
                if(validarShow(lStr,lExp)==TRUE){
                        ejecutarShow(lStr,lExp);
                }else
                    printf("\nExpresion no existe");
             }else
                printf("\nError en cantidad de parametros");
            break;

        case 'E':
            if(cantStrings(lStr)==2){
                if(validarEvaluate(lStr,lExp)==TRUE){
                        ejecutarEvaluate(lStr,lExp);
                }else
                    printf("\nExpresion no existe");
            }else
                printf("\nError en cantidad de parametros");
            break;

        case 'L':
            if(cantStrings(lStr)==2){
                if(validarLoad(lStr,lExp)==TRUE){
                        ejecutarLoad(lStr,lExp);
                }else
                    printf("\nComando Load mal escrito");
            }else
                printf("\nError en cantidad de parametros");
            break;

        case 'C':
                if(cantStrings(lStr)==3){
                     if(validarCompound3(lStr,lExp)==TRUE){
                        ejecutarCompound3(lStr,lExp);
                     }
                     else printf("Compound mal escrito");

                }else if(cantStrings(lStr)==4){
                        if(validarCompound4(lStr,lExp)==TRUE){
                            ejecutarCompound4(lStr,lExp);
                        }
                    }else printf("Compound mal escrito");
                }else
                    printf("\Error en cantidad de parametros");


        case 'S':
                if(cantStrings(lStr)==3){
                    if(validarSave(lStr,lExp)==TRUE){
                            ejecutarSave(lStr,lExp);
                        }else
                            printf("\nComando Save mal escrito");
                }else
                    printf("\nError en cantidad de parametros");
                break;
        case 'X':
                if(cantStrings(lStr)==1){
                        //Libero memoria
                }else
                    printf("\nError en cantidad de parametros");

        default:
            printf("\nNo ingresa ningun comando");
            break;
        }

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
    }
    return valida;
}

boolean validarShow(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux= lStr;
    aux=aux->sig;
    //VALIDAR QUE EL STRING SEA SOLO NUMEROS ANTES
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
    //VALIDAR QUE EL STRING SEA SOLO NUMEROS ANTES
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
    //VALIDAR QUE EL STRING SEA SOLO NUMEROS ANTES
    int num = stringAentero(aux->str);
    if(existeExpresion(lExp,num)==TRUE){
        aux=aux->sig;
        if(validarFormatoArchivo(aux->str)==TRUE){
            valida=TRUE;
        }
    }

    return valida;
}

boolean validarLoad(listaString lStr, ListaExp lExp){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    //FALTA LABURAR
    return valida;
}

void ejecutarAtomic(listaString lStr, ListaExp &lExp){

    //Todo esto va en una funcion no?
    arbol a;
    crear(a);
    lStr=lStr->sig;
    cargarArbolAtomic(a,lStr->str);

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

void ejecutarShow(listaString lStr, ListaExp lExp){
    lStr=lStr->sig;
    int i = stringAentero(lStr->str);
    mostrarExpresion(lExp,i);
}

void ejecutarEvaluate(listaString lStr, ListaExp lExp){
    AYSFGDAGHSF
}
void ejecutarLoad(listaString lStr, ListaExp &lExp){
    //FALTA LABURAR
}
void ejecutarSave(listaString lStr, ListaExp lExp){
    //FALTA LABURAR
}
void ejecutarCompound3(listaString lStr, ListaExp &lExp){
    lStr=lStr->sig;
    arbol a;
    crear(a);
    a = new nodoABB;
    setNOT(a->info);

    lStr=lStr->sig;

    int i = stringAentero(lStr->str);
    expresion e = darExpresion(lExp,i);
    cargarArbolCompoundNOT(a,e);

    expresion j;
    crearExpre(j);
    j.abbExpresion=a;
    insFront(lExp,j);

    printf("\n Expresion %d:",darNumero(lExp->exp));
    mostrarExpresion(lExp->exp);
}



//Hacer funcion avanzarListaString?
void ejecutarCompound4(listaString lStr, ListaExp &lExp){
    lStr=lStr->sig;
    arbol a;
    crear(a);
    a = new nodoABB;

    int i=stringAentero(lStr->str);
    expresion e1 = darExpresion(lExp,i);


    lStr=lStr->sig;
    datoABB dat;
    dat.discriminante=OPERADOR;
    if(saberOperador(lStr->str)== 'O'){
        setOR(dat);
    }else if(saberOperador(lStr->str)== 'A'){
            setAND(dat);
        }


    lStr=lStr->sig;
    int j=stringAentero(lStr->str);
    expresion e2 = darExpresion(lExp,j);

    juntarArboles(e1.abbExpresion,e2.abbExpresion,dat,a);

    expresion e;
    crearExpre(e);
    e.abbExpresion=a;

    insFront(lExp,e);

    printf("\n Expresion %d:",darNumero(lExp->exp));
    mostrarExpresion(lExp->exp);
}
