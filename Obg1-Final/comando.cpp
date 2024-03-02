#include "comando.h"

//EJECUTAR
void ejecutarComando(listaString lStr, ListaExp &lExp, char c){
    switch(c){
        case 'A':
            if(cantStrings(lStr)==2){
                if(validarAtomic(lStr)==error0){
                        ejecutarAtomic(lStr,lExp);
                        break;
                }else{
                    mostrarError(validarAtomic(lStr));
                    break;
                }
            }else{
                mostrarError(error9);
                printf("\nFormato Atomic: atomic valor");
                break;
                }

        case 'H':
             if(cantStrings(lStr)==2){
                if(validarShow(lStr,lExp)==error0){
                        ejecutarShow(lStr,lExp);
                        break;
                }else{
                    mostrarError(validarShow(lStr,lExp));
                    break;
                }
             }else{
                mostrarError(error9);
                printf("\nFormato Show: show #expresion");
                break;
             }
        case 'E':
            if(cantStrings(lStr)==2){
                if(validarEvaluate(lStr,lExp)==error0){
                        ejecutarEvaluate(lStr,lExp);
                        break;
                }else{
                    mostrarError(validarEvaluate(lStr,lExp));
                    break;
                }
            }else{
                mostrarError(error9);
                printf("\nFormato Evaluate: evaluate #expresion");
                break;
            }

        case 'L':
            if(cantStrings(lStr)==2){
                if(validarLoad(lStr,lExp)==error0){
                        ejecutarLoad(lStr,lExp);
                        break;
                }else{
                    mostrarError(validarLoad(lStr,lExp));
                    break;
                }
            }else{
                mostrarError(error9);
                printf("\nFormato Load: load nombrearchivo.dat");
                break;
            }

        case 'C':
                if(cantStrings(lStr)==3){
                     if(validarCompound3(lStr,lExp)==error0){
                        ejecutarCompound3(lStr,lExp);
                        break;
                     }
                     else{
                        mostrarError(validarCompound3(lStr,lExp));
                        break;
                     }
                }else if(cantStrings(lStr)==4){
                        if(validarCompound4(lStr,lExp)==error0){
                            ejecutarCompound4(lStr,lExp);
                            break;
                        }else{
                            mostrarError(validarCompound4(lStr,lExp));
                            break;
                        }
                }else{
                    mostrarError(error9);
                    printf("\nFormato Compound AND/OR: compound #expresion AND/OR #expresion\nFormato Compound NOT: compound NOT #expresion");
                    break;
                    }

        case 'S':
                if(cantStrings(lStr)==3){
                    if(validarSave(lStr,lExp)==error0){
                         ejecutarSave(lStr,lExp);
                         break;
                        }else{
                            mostrarError(validarSave(lStr,lExp));
                            break;
                        }
                }else{
                    mostrarError(error9);
                    printf("\nFormato Save: save #expresion nombrearchivo.dat");
                    break;
                }
        case 'X':
                if(cantStrings(lStr)==1){
                        limpiarLista(lStr);
                        limpiarListaExp(lExp);
                        break;
                }else{
                    mostrarError(error9);
                    printf("\nError en cantidad de parametros\nFormato Exit: exit");
                    break;
                }
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

void ejecutarSave(listaString lStr, ListaExp lExp){
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
            expresion e = darExpresion(lExp,i);
            arbol a = darArbol(e);
            numerarArbol(a);
            guardarExpresion(e,f);
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
    insFront(lExp,exp);
    mostrarExpresion(darExpresion(lExp));
}



