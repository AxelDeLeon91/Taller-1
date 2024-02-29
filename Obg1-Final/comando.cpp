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
    arbol a; //Declaro el arbol
    crear(a); //Creo el arbol
    lStr=lStr->sig;//
    cargarArbolAtomic(a,lStr->str);//Cargo el arbol con el valor
    expresion e;
    crearExpre(e);//Creo expresion
    setArbol(e,a);//Seteo arbol en la exp
    insFront(lExp,e);//Insfront en listaExp
    mostrarExpresion(lExp->exp);
}

void ejecutarCompound3(listaString lStr, ListaExp &lExp){
    lStr=lStr->sig;
    arbol a;//Declaro el arbol
    crear(a);//Creo el arbol
    lStr=lStr->sig;
    int i = stringAentero(lStr->str); //Paso el #expresion recibido mediante string a un entero
    expresion e = darExpresion(lExp,i); //Creo la expresion y le asigno la expresion.
    arbol abb=copiarArbol(darArbol(e));//Copio el arbol en un arbol auxiliar
    cargarArbolCompoundNOT(a,abb);//Cargo el arbol con el NOT y el valor/expresion
    expresion j;
    crearExpre(j);
    setArbol(j,a);//Seteo arbol en la exp
    insFront(lExp,j);//Insfront en listaExp
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
    setDiscriminante(dat,OPERADOR);//Seteo el discrimnante como OPERADOR
    if(saberOperador(lStr->str)== 'O'){//Averiguo si es operador OR o AND
        setOR(dat);
    }else if(saberOperador(lStr->str)== 'A'){
            setAND(dat);
        }
    lStr=lStr->sig;
    int j=stringAentero(lStr->str);
    expresion e2 = darExpresion(lExp,j);
    arbol abb = copiarArbol(darArbol(e1));
    arbol abb2= copiarArbol(darArbol(e2));
    juntarArboles(abb,abb2,dat,a); //Junto ambos arboles auxiliares con la raiz deseada
    expresion e;
    crearExpre(e);
    setArbol(e,a);//Seteo arbol en la exp
    insFront(lExp,e);//Insfront en listaExp
    mostrarExpresion(lExp->exp);
}

void ejecutarEvaluate(listaString lStr, ListaExp lExp){
    lStr=lStr->sig;
    expresion e= darExpresion(lExp,stringAentero(lStr->str));
    if(evaluarArbol(darArbol(e))){  //Evalua el arbol
        printf("La Expresion %d vale:  TRUE", darNumero(e));
    }else
        printf("La Expresion %d vale:  FALSE",darNumero(e));
}

void ejecutarShow(listaString lStr, ListaExp lExp){
    lStr=lStr->sig;
    int i = stringAentero(lStr->str);
    mostrarExpresion(lExp,i);
}

void ejecutarSave(listaString lStr, ListaExp lExp) {
    lStr = lStr->sig;
    int i = stringAentero(lStr->str);
    char c;
    lStr = lStr->sig;
    if (existeArchivo(lStr->str)){//Consulto existencia del archivo en disco
        printf("\nEl archivo ya existe, desea sobrescribirlo?\nSI - Ingrese S\nNO - Ingrese N\nRespuesta: ");
        obtenerRespuestaValida(c);//Scanea C y se fija si esta bien escrito, repregunta hasta tener respuesta valida
    }
    if(!existeArchivo(lStr->str) || c== 'S' || c== 's'){//Si no existe archivo o quiere sobreescribir, ejecuta el guardar expresion
        FILE *f = fopen(lStr->str,"wb");
        if (f != NULL){
            guardarExpresion(darExpresion(lExp,i),f);
            fclose(f);
            printf("\nExpresion %d respaldada correctamente en ",i);
            print(lStr->str);
        }
    }
    if(c== 'N' || c== 'n'){ //Si no quiere soobrescribir, muestra mensaje de operacion cancelada
        printf("Operacion de respaldo de Expresion %d cancelada",i);
    }
}

void ejecutarLoad(listaString lStr, ListaExp &lExp){
    expresion exp;
    crearExpre(exp);
    lStr=lStr->sig;
    FILE * f=fopen(lStr->str, "rb");
    levantarExpresion(exp,f);
    mostrarExpresion(exp);
    insFront(lExp,exp);
}

//FUNCIONALIDADES
boolean validarOperador(string s){ //Valida que el string ingresado este en mayuscula y sea uno de los existentes
    boolean valida=FALSE;
    if(streq(s,"AND") || streq(s,"OR") || streq(s,"NOT")){
        valida=TRUE;
    }
    return valida;
}

boolean validarAtomic(listaString lStr){ // valida que el valor booleano este bien escrito y en minuscula
    boolean valida= FALSE;
    listaString aux=lStr;
    aux=aux->sig;
    if(validarBool(aux->str)==TRUE){
        valida=TRUE;
    }
    return valida;
}

boolean validarCompound3(listaString lStr, ListaExp lExp){ //Valida que el formato del compound con 3 strings sea: compound NOT valor
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

boolean validarCompound4(listaString lStr, ListaExp lExp){//Valida que el formato del compound con 4 strings sea: compound #expresion AND/OR #expresion
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

boolean validarEvaluate(listaString lStr, ListaExp lExp){ //Valida que el formato del evaluate sea: evaluate #expresion
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

boolean validarShow(listaString lStr, ListaExp lExp){ //Valida que el formato del evaluate sea:
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

boolean validarSave(listaString lStr, ListaExp lExp){ //Valida que el formato del save sea: save #expresion nombrearchivo.dat
    boolean valida=FALSE;
    lStr = lStr->sig;
    if(esNumero(lStr->str)){
        int num = stringAentero(lStr->str);
        if(existeExpresion(lExp,num)==TRUE){
            lStr = lStr->sig;
            if(validarFormatoArchivo(lStr->str)==TRUE){
                valida=TRUE;
            }
        }
    }

    return valida;
}
boolean validarLoad(listaString lStr, ListaExp lExp){ //Valida que el formato del load sea: load nombrearchivo.dat
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
boolean existeArchivo(string s) { //Chequea la existencia del archivo en disco.
    boolean existe=FALSE;
    FILE *f = fopen(s, "r");

    if (f != NULL){
        existe=TRUE;
    }
    return existe;
}
