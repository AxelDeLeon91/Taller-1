#include <stdio.h>
#include "listaString.h"

void crearListaString(listaString &lStr){//Crea la ListaString
    lStr = NULL;
}

void insBack(listaString &lista, string s){//Inserta el string s al final de listaString
    if (lista == NULL){
        lista = new nodoString;
        strcop(lista->str,s);
        lista->sig = NULL;
    }else{
        listaString aux = lista;
        while (aux->sig!= NULL){
            aux = aux->sig;
        }
        aux->sig = new nodoString;
        strcop(aux->sig->str,s);
        aux->sig->sig = NULL;
    }
}

void avanzarLstr(listaString &lStr){ //Avanza lStr a su siguiente nodo
    lStr=lStr->sig;
}

void separarStringEnLista(string original, listaString &lstr){// Función para separar el string en una lista de strings
    listaString listaAux = NULL;
    string palabra;
    strcrear(palabra);
    int i = 0;
    while (original[i] != '\0'){
        while (original[i]== ' ' && original[i]!= '\0'){// Busco el inicio de alguna palabra
            i++;
        }
        int j = 0;
        while (original[i + j]!= ' ' && original[i + j]!= '\0'){// Cuento su largo
            j++;
        }
        if (j>0){
            palabra = new char [j+1];
            for (int k= 0; k<j; k++) {
                palabra[k] = original[i+k]; //Copio original en palabra
            }
            palabra[j]= '\0';
            insBack(listaAux, palabra);// INSBACK en listaAux
        }
        i += j;// Avanzar al próximo caracter en string Original
    }
    lstr = listaAux; // Asignar la listaAux a lstr
}

void imprimirLista(listaString lStr){ // Función para imprimir la lista de strings
    while (lStr != NULL) {
        printf("\n");
        print(lStr->str);
        lStr = lStr->sig;
    }
}

void limpiarLista(listaString &lstr){ // Función para liberar la memoria de la lista de strings
    while(lstr != NULL){
        listaString aux = lstr;
        lstr = aux->sig;
        delete aux;
    }
}

int cantStrings(listaString lStr){ //Devuelve la cantidad de string que hay en lStr, se utiliza para el chequeo de los comandos
    int cant=0;
    while(lStr!=NULL){
        cant++;
        lStr=lStr->sig;
    }
    return cant;
}


