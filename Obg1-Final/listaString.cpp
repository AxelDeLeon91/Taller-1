#include <stdio.h>
#include "listaString.h"

void insBack(listaString &lista, string s) {

    if (lista == NULL) {
        lista = new nodoString;
        strcop(lista->str, s);
        lista->sig = NULL;
    } else {
        listaString aux = lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new nodoString;
        strcop(aux->sig->str, s);
        aux->sig->sig = NULL;
    }
}


// Función para separar el string en una lista de strings
void separarStringEnLista(string original, listaString &lstr) {
    listaString listaAux = NULL;
    string palabra;
    strcrear(palabra);
    int i = 0;

    while (original[i] != '\0') {
        // Busco el inicio de alguna palabra
        while (original[i] == ' ' && original[i] != '\0') {
            i++;
        }

        // Cuento su largo
        int j = 0;
        while (original[i + j] != ' ' && original[i + j] != '\0') {
            j++;
        }

        // Copio la palabra de original en una palabra aux
        if (j > 0){
            palabra = new char [j+1];

            //La copio
            for (int k = 0; k < j; k++) {
                palabra[k] = original[i + k];
            }
            palabra[j] = '\0';

            // INSBACK en listaAux
            insBack(listaAux, palabra);
        }

        // Avanzar al próximo caracter en string Original
        i += j;
    }

    // Asignar la listaAux a lstr
    lstr = listaAux;
}

// Función para imprimir la lista de strings
void imprimirLista(nodoString *lista) {
    nodoString *temp = lista;
    while (temp != NULL) {
        print(temp->str);
        printf("\n");
        temp = temp->sig;
    }
}

// Función para liberar la memoria de la lista de strings
void liberarLista(nodoString *lista) {
    nodoString *temp = lista;
    while (temp != NULL) {
        strdestruir(temp->str);
        nodoString *next = temp->sig;
        delete temp;
        temp = next;
    }
}

int cantStrings(listaString lStr){
    int cant=0;
    while(lStr!=NULL){
        cant++;
        lStr=lStr->sig;
    }
    return cant;
}
/*
//TODO ESTO VA EN EL MAIN CREO
void ejecutarComando(listaString lStr){
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
                if(validarAtomic()==TRUE){
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
*/

/*
DONDE VA TODOS ESTOS VALIDAR??
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

boolean validarCompound4(listaString lStr){
    boolean valida=FALSE;
    listaString aux=lStr;
    aux=aux->sig;//Avanzo porque el primer string es el comando Compound
    int num = stringAEntero(aux->str);//Pasa un string a entero
        if(existeExpresion(num)==TRUE){//Chequea que exista la expresion
            aux=aux->sig;
            if(validarOperador(aux->str)==TRUE){//SABER SI ES AND O OR
                aux=aux->sig;
                num = stringAentero(aux->str);
                if(existeExpresion(num)==TRUE){
                    valida=TRUE;
                }
    }
}
    return valida;
}

boolean validarCompound3(listaString lStr){
    boolean valida= FALSE;
    listaString aux=lStr;
    aux=aux->sig;
        if(validarOperador(aux->str)==TRUE){
            aux=aux->sig;
            int num = stringAentero(aux->str);
            if(existeExpresion(num)==TRUE){
                valida=TRUE;
            }
    return valida;
}
}

boolean validarShow(listaString lStr){
    boolean valida=FALSE;
    listaString aux= lStr;
    aux=aux->sig;
    int num = stringAentero(aux->str);
    if(existeExpresion(num)==TRUE){
        valida=TRUE;
        }
    return valida;
}

boolean validarEvaluate(listaString lStr){
    boolean valida=FALSE;
    listaString aux= lStr;
    aux=aux->sig;
    int num = stringAentero(aux->str);
    if(existeExpresion(num)==TRUE){
        valida=TRUE;
        }
    return valida;
}

boolean validarSave(listaString lStr){
    boolean valida=FALSE;
    listaString aux= lStr;
    aux=aux->sig;
    int num = stringAentero(aux->str);
    if(existeExpresion(num)==TRUE){
        aux=aux->sig;
        if(validarFormatoArchivo(aux->str)==TRUE){
            valida==TRUE;
        }
    }

    return valida;
}
*/

